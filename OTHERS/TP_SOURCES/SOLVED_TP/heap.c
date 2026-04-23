#include "heap.h"
#include <stdlib.h>

#define PARENT(i) ((i) / 2)
#define LEFT(i)   (2 * (i))
#define RIGHT(i)  (2 * (i) + 1)

heap heap_create(int k, int (*f)(const void *, const void *)) {
    heap h = malloc(sizeof(struct _heap)); // or sizeof(*h) depending on compiler strictness
    if (!h) return NULL;
    h->array = malloc((k + 1) * sizeof(void *)); // Index 0 is unused
    if (!h->array) { free(h); return NULL; }
    h->n = 0;
    h->nmax = k;
    h->f = f;
    return h;
}

void heap_destroy(heap h) {
    if (!h) return;
    free(h->array);
    free(h);
}

bool heap_empty(heap h) {
    return h->n == 0;
}

bool heap_add(heap h, void *object) {
    if (h->n >= h->nmax) return true; // Heap is full
    
    int i = ++(h->n);
    while (i > 1 && h->f(object, h->array[PARENT(i)]) < 0) {
        h->array[i] = h->array[PARENT(i)];
        i = PARENT(i);
    }
    h->array[i] = object;
    return false;
}

void *heap_top(heap h) {
    if (heap_empty(h)) return NULL;
    return h->array[1];
}

void *heap_pop(heap h) {
    if (heap_empty(h)) return NULL;
    
    void *root = h->array[1];
    void *last = h->array[(h->n)--];
    int i = 1;
    
    while (LEFT(i) <= h->n) {
        int min_child = LEFT(i);
        if (RIGHT(i) <= h->n && h->f(h->array[RIGHT(i)], h->array[LEFT(i)]) < 0) {
            min_child = RIGHT(i);
        }
        if (h->f(last, h->array[min_child]) <= 0) break;
        
        h->array[i] = h->array[min_child];
        i = min_child;
    }
    h->array[i] = last;
    return root;
}