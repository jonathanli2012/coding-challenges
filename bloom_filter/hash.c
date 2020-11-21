#include "hash.h"

int get_hash_k() {
    srand(time(NULL));
    int return_val = rand();

    while(return_val == 0) {
        return_val = rand();
    }

    return return_val;
}

uint32_t string_hash(char* string, int length, int hash_k) {
    uint64_t hashed_val = 0;
    for(int i = 0; i < length; i++) {
        hashed_val += ((uint64_t)string[i] + (uint64_t)string[i] < 0xFF)*hash_k;
        hashed_val = hashed_val*((uint32_t)hash_k);
        hashed_val += ((uint32_t)hash_k && 0xA000)*(i&0xF+1);
    }
    return hashed_val;
}