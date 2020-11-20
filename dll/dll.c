#include"dll.h"

dll_t* dll_new() {
    dll_t *d = malloc(sizeof(dll_t));

    //malloc error handling
    if(d == NULL) {
        exit(-1);
    }

    d->size = 0;
    d->head = NULL;
    d->tail = NULL;
    
    return d;
}

dll_node_t* dll_node_alloc(uint32_t val) {
    dll_node_t* node = malloc(sizeof(dll_node_t));
    node->next = NULL;
    node->prev = NULL;
    node->value = val;
    return node;
}

void dll_free(dll_t *d) {
    if(d->size > 0) {
        dll_node_t* curr = d->head;
        while(curr != NULL) {
            free(curr);
            curr = curr->next;
        }
    }
    free(d);
}

uint32_t dll_size(dll_t *d) {
    return d->size;
}

void dll_insert_head(dll_t *d, uint32_t val) {
    dll_node_t* new_node = dll_node_alloc(val);

    if(d->size == 0) {
        d->head = new_node;
        d->tail = new_node;
    }
    else {
        dll_node_t*tmp_node = d->head;
        d->head->prev = new_node;
        d->head = new_node;
        d->head->next = tmp_node;
        d->head->prev = NULL;
    }

    //increment size
    d->size ++;
}

void dll_insert_tail(dll_t *d, uint32_t val) {
    dll_node_t* new_node = dll_node_alloc(val);

    if(d->size == 0) {
        d->head = new_node;
        d->tail = new_node;
    }
    else {
        dll_node_t* tmp_node = d->tail;
        d->tail->next = new_node;
        d->tail = new_node;
        d->tail->prev = tmp_node;
        d->tail->next = NULL;
    }
    //increment size
    d->size ++;
}


uint32_t dll_delete_head(dll_t *d) {
    if(d->size == 0) {
        return 0;
    }
    uint32_t return_val = d->head->value;

    if(d->size == 1) {
        free(d->head);
        d->head = NULL;
        d->tail = NULL;
    }
    else {
        dll_node_t *new_head = d->head->next;
        free(d->head);
        d->head = new_head;
        d->head->prev = NULL;
    }

    d->size --;
    return return_val;
}

uint32_t dll_delete_tail(dll_t *d) {
    if(d->size == 0) {
        return 0;
    }
    uint32_t return_val = d->tail->value;

    if(d->size == 1) {
        free(d->tail);
        d->head = NULL;
        d->tail = NULL;
    }
    else {
        dll_node_t *new_tail = d->tail->prev;
        free(d->tail);
        d->tail = new_tail;
        d->tail->next = NULL;
    }

    d->size --;
    return return_val;
}

void dll_verbose_print(dll_t *d) {
    printf("printing dll\n");
    printf("dll size: %u\n", d->size);
    if(d->size != 0) {
        printf("dll head: %u\n", d->head->value);
        printf("dll tail: %u\n", d->tail->value);
    }
    return;
}

int main(){
    dll_t* d = dll_new();
    dll_insert_tail(d, 69); //d == 69
    dll_insert_tail(d, 420); //d == 69 420
    dll_insert_head(d, 690); //d == 690 69 420
    dll_insert_head(d, 4200); //d == 4200 690 69 420
    dll_verbose_print(d);
    dll_delete_head(d);
    dll_verbose_print(d);
    dll_delete_tail(d);
    dll_verbose_print(d);
    dll_delete_head(d);
    dll_verbose_print(d);
    dll_delete_tail(d);
    dll_verbose_print(d);
    dll_free(d);
}