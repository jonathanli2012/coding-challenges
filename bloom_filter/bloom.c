#include "hash.h"
#include "bloom.h"
#include <stdio.h>
#include <stdlib.h>

bloom_filter_t* new_bloom_filter(uint32_t count) {
    bloom_filter_t* b = malloc(sizeof(bloom_filter_t));
    uint32_t* filters = malloc(sizeof(uint32_t)*count);
    uint32_t* hash_k = malloc(sizeof(int)*count);

    b->bloom_filter = filters;
    b->hash_k = hash_k;
    b->elems_added = 0;
    b->filter_count = count;

    for(uint32_t i = 0; i < count; i++) {
        b->hash_k[i] = get_hash_k();
        b->bloom_filter[i] = 0;
    }

    return b;
}

int lookup(bloom_filter_t* b, char* string, int length) {
    int return_val = 0;
    for(uint32_t i = 0; i < b->filter_count; i++) {
        uint32_t hashed_val = string_hash(string, length, b->hash_k[i]);

        if((hashed_val & b->bloom_filter[i]) == hashed_val) {
            return_val += 1;
        }
    }
    return return_val;
}

void add_string(bloom_filter_t* b, char* string, int length) {
    for(uint32_t i = 0; i < b->filter_count; i++) {
        uint32_t hashed_val = string_hash(string, length, b->hash_k[i]);
        b->bloom_filter[i] = b->bloom_filter[i] | hashed_val;
    }
}

int main() {
    bloom_filter_t* b = new_bloom_filter(3);
    add_string(b, "big bessie", 10);
    add_string(b, "Goran",  5);


    printf("check filter %u\n", b->bloom_filter[0]);
    printf("lookup of term %d\n", lookup(b,"big bessie", 10));
    printf("lookup of term %d\n", lookup(b,"Kushal", 6));
    printf("lookup of term %d\n", lookup(b,"Aditya", 6));
    printf("lookup of term %d\n", lookup(b,"mabxo", 5));


    return 0;
}