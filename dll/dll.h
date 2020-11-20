#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct dll_node dll_node_t;

struct dll_node {
    dll_node_t* prev;
    uint32_t value;
    dll_node_t* next;
};

typedef struct dll dll_t;

struct dll{
    dll_node_t* head;
    dll_node_t* tail;
    uint32_t size;
};

dll_t* dll_new();

void dll_free(dll_t *d);

void dll_push(dll_t *d, uint32_t val);

void dll_insert_head(dll_t *d, uint32_t val);

void dll_insert_tail(dll_t *d, uint32_t val);

uint32_t dll_delete_head(dll_t *d);

uint32_t dll_delete_tail(dll_t *d);

uint32_t dll_size(dll_t *d);