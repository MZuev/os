#ifndef __UTIL_H__
#define __UTIL_H__

#define bit(n) (1 << n)
#define bits2(a, b) ((1 << a) | (1 << b))
#define bits3(a, b, c) ((1 << a) | bits2(b, c))
#define bits4(a, b, c, d) ((1 << a) | bits3(b, c, d))
#define bits5(a, b, c, d, e) ((1 << a) | bits4(b, c, d, e))

#define get_bit(a, l, r)\
	((a >> l) & (((uint64_t)1 << (r - l + 1)) - 1))

#endif
