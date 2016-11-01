#include <util.h>

uint64_t min(uint64_t a, uint64_t b) { if (a < b) return a; return b;}

uint64_t max(uint64_t a, uint64_t b) { if (a > b) return a; return b;}

void * palign(void *p, uint64_t m) {
	return (char*)p + ((m - (uint64_t)p % m) % m);
}
uint64_t ualign(uint64_t p, uint64_t m) {
	return p + ((m - (p % m)) % m);
}
