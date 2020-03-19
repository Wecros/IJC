#include "bitset.h"

extern int make_iso_compilers_happy;
#ifdef USE_INLINE
extern void bitset_free(bitset_t array);
extern unsigned bitset_size(bitset_t array);
extern void bitset_setbit(bitset_t array, bitset_index_t index, unsigned value);
extern unsigned bitset_getbit(bitset_t array, bitset_index_t index);
#endif  