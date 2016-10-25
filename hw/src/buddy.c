#include "buddy.h"
#include "mem_init.h"

extern mmap_entry mmap_table[];
extern uint32_t mmap_table_length;
int max_heads;

list_node desc_heads[MAX_ORD];

uint64_t get_max_reg(mmap_entry entry) {
	uint64_t end_entry = entry.len + entry.addr - 1;
	uint64_t l = 1, r = entry.len / BUDDY_PAGE_SIZE, ans = 0;
	while (l <= r) {
		uint64_t mid = (l + r) >> 1;
		uint64_t size = mid * sizeof(buddy_desc);
		uint64_t start_addr = ualign(entry.addr, sizeof(buddy_desc)) + size;
		if (start_addr > ualign(start_addr, BUDDY_PAGE_SIZE)) {
			r = mid - 1;
			continue;
		}
		start_addr = ualign(start_addr, BUDDY_PAGE_SIZE);
		if (start_addr <= end_entry && end_entry - start_addr + 1 >= mid * BUDDY_PAGE_SIZE) 
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	return ans;
}


void init_entry(mmap_entry entry) {
	if (entry.type != 1)
		return;
	uint64_t cnt_reg = get_max_reg(entry);
	if (!cnt_reg)
		return;
	uint64_t pos_desc = ualign(entry.addr, sizeof(buddy_desc));
	uint64_t start_addr = ualign(pos_desc + cnt_reg * sizeof(buddy_desc), BUDDY_PAGE_SIZE);
	for (uint64_t i = 0; i < cnt_reg; ++i) {
		buddy_desc * cur_desc = (void*)pos_desc;
		cur_desc->num = start_addr / BUDDY_PAGE_SIZE;
		cur_desc->is_free = 1;
		cur_desc->ord = 0;
		add_prev(desc_heads, (list_node*)cur_desc);
		pos_desc += sizeof(buddy_desc);
		start_addr += BUDDY_PAGE_SIZE;
	}
	return;
}

void init_buddy() {
	for (int i = 0; i < MAX_ORD; ++i)
		desc_heads[i].next = desc_heads[i].prev = (desc_heads + i);
	for (uint32_t i = 0; i < mmap_table_length; ++i)
		init_entry(mmap_table[i]);
	for (int ord = 0; ord < MAX_ORD; ++ord) {
		list_node *cur_node = desc_heads[ord].next;
		while (cur_node != &desc_heads[ord] && cur_node->next != &desc_heads[ord]) {
			buddy_desc * cur_desc = (buddy_desc*)cur_node;
			buddy_desc * next_desc = (buddy_desc*)(cur_node->next);
			if ((cur_desc->num ^ bit(ord)) != next_desc->num) {
				cur_node = cur_node->next;
				continue;			
			}
			list_node *tmp = cur_node->next->next;
			erase_cur(&cur_desc->node);
			erase_cur(&next_desc->node);
			++(cur_desc->ord);
			add_prev(desc_heads + ord + 1, &cur_desc->node);
			cur_node = tmp;
		}
	}
	for (int ord = 0; ord < MAX_ORD;++ord) {
		if (!empty_list(desc_heads + ord))
			max_heads = ord;
	}
	return;
}

list_node * lower_bound(list_node *start_node, uint64_t num) {
	list_node* cur_node = start_node->next;
	while (cur_node != start_node) {
		if (((buddy_desc*)cur_node)->num >= num)
			break;
		cur_node = cur_node->next;
	}
	return cur_node;
}

void add_list(list_node* start_node, buddy_desc *cur_desc) {
	list_node *cur_node = lower_bound(start_node, cur_desc->num);
	add_prev(cur_node, &(cur_desc->node));
	return;
}

uint64_t buddy_alloc(int max_ord, int min_ord) {
	list_node *cur_node = (desc_heads + max_ord)->next;
	erase_cur(cur_node);
	for (;max_ord != min_ord; --max_ord) {
		buddy_desc *l_desc = (buddy_desc*)cur_node;
		buddy_desc *r_desc = l_desc + bit(max_ord - 1);
		r_desc->ord = max_ord - 1;
		r_desc->is_free = 1;
		add_list(desc_heads + max_ord - 1, r_desc);
		cur_node = &(l_desc->node);
	}
	buddy_desc* cur_desc = (buddy_desc*)cur_node;
	cur_desc->is_free = 0;
	cur_desc->ord = min_ord;
	return cur_desc->num * BUDDY_PAGE_SIZE;
}

uint64_t alloc(uint64_t size) {
	int ord = 0;
	uint64_t cur_size = BUDDY_PAGE_SIZE;
	for (; cur_size < size && ord < MAX_ORD; ++ord, cur_size <<= 1);
	for (int tmp_ord = ord;ord < MAX_ORD; ++ord) {
		if (empty_list(desc_heads + ord))
			continue;
		return buddy_alloc(ord, tmp_ord);	
	}
	return 0;
}

uint64_t find_start(uint64_t addr) {
	for (uint32_t i = 0; i < mmap_table_length; ++i) {
		if (mmap_table[i].type != 1)
			continue;
		if (mmap_table[i].addr <= addr && mmap_table[i].addr + mmap_table[i].len > addr)
			return mmap_table[i].addr;
	}
	return 0;
}

void buddy_free(buddy_desc* cur_desc) {
	int cur_ord = cur_desc->ord;
	cur_desc->is_free = 1;
	for (; cur_ord < MAX_ORD; ++cur_ord) {
		list_node * next_node = lower_bound(desc_heads + cur_ord, cur_desc->num);
		uint64_t buddies = cur_desc->num ^ bit(cur_ord); 
		if (cur_desc->num & bit(cur_ord)) {
			next_node = next_node->prev;
			if ((next_node == desc_heads + cur_ord) || ((buddy_desc*)next_node)->num != buddies) {
				add_next(next_node, &cur_desc->node);
				return;
			}
			erase_cur(next_node);
			cur_desc = (buddy_desc*)next_node;
		}
		else {
			if ((next_node == desc_heads + cur_ord) || ((buddy_desc*)next_node)->num != buddies) {
				add_prev(next_node, &cur_desc->node);
				return;	
			}
			erase_cur(next_node);
		}
		++cur_desc->ord;
	}
	return;
}

void free(uint64_t addr) {
	if (addr % BUDDY_PAGE_SIZE)
		return;
	buddy_desc* start_desc = (buddy_desc*)ualign(find_start(addr), sizeof(buddy_desc));
	uint64_t start_addr = start_desc->num * BUDDY_PAGE_SIZE;
	uint64_t len = (addr - start_addr) / BUDDY_PAGE_SIZE;
	start_desc += len;
	if (start_desc->is_free)
		return;
	buddy_free(start_desc);
}

void print_some_buddy(int max_ord) {
	for (int ord = 0; ord <= max_ord && ord < MAX_ORD; ++ord)
		print_list(ord);
}

void print_list(int ord) {
	puts("Level buddy ");
	put_int(ord);
	putc('\n');
	list_node * cur_node = desc_heads[ord].next;
	while (cur_node != &desc_heads[ord]) {
		buddy_desc *cur_desc = (buddy_desc*)cur_node;
		puts("number ");
		put_uint64(cur_desc->num, 10, 0);
		puts(" addr ");
		put_uint64(cur_desc->num * BUDDY_PAGE_SIZE, 16, 16);
		puts(" len ");
		put_uint64(cur_desc->num * (BUDDY_PAGE_SIZE << ord), 10, 0);
		putc('\n');
		cur_node = cur_node->next;
	}
}
