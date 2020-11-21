#include<stdint.h>

typedef struct bloom_filter bloom_filter_t;

struct bloom_filter {
    uint32_t* bloom_filter;
    int* hash_k;
    uint32_t filter_count;
    uint32_t elems_added;
};