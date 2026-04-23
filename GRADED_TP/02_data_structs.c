#include <stdlib.h>

/* ==================================================================
   1. GRAPH REPRESENTATION (Adjacency List)
   ================================================================== */
typedef struct {
    int n;         // Number of vertices
    int *deg;      // deg[u] = number of neighbors
    int **list;    // list[u][i] = the i-th neighbor of u
} graph;

// Reverses all edges in a directed graph (Needed for Kosaraju SCC)
graph transpose_graph(graph G) {
    graph G_rev;
    G_rev.n = G.n;
    G_rev.deg = calloc(G.n, sizeof(int));
    G_rev.list = malloc(G.n * sizeof(int*));
    
    for (int u = 0; u < G.n; u++) 
        for (int i = 0; i < G.deg[u]; i++) 
            G_rev.deg[G.list[u][i]]++; // Count in-degrees
            
    for (int u = 0; u < G.n; u++) {
        G_rev.list[u] = malloc(G_rev.deg[u] * sizeof(int));
        G_rev.deg[u] = 0; // Reset to use as index
    }
    
    for (int u = 0; u < G.n; u++) 
        for (int i = 0; i < G.deg[u]; i++) {
            int v = G.list[u][i];
            G_rev.list[v][G_rev.deg[v]++] = u; // Insert v -> u
        }
    return G_rev;
}

/* ==================================================================
   2. UNION-FIND (For Kruskal's MST)
   ================================================================== */
int Find(int u, int *parent) {
    if (u != parent[u]) parent[u] = Find(parent[u], parent);
    return parent[u];
}

void Union(int x, int y, int *parent, int *rank) {
    int rootX = Find(x, parent), rootY = Find(y, parent);
    if (rootX == rootY) return;
    if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
    else {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) rank[rootY]++;
    }
}

/* ==================================================================
   3. MIN-HEAP LOGIC (If required to code it manually)
   ================================================================== */
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

typedef struct _heap { int n; void** array; int (*f)(const void*, const void*); } *heap;

void heap_sift_up(heap h) {
    int i = h->n++; 
    while (i > 0 && h->f(h->array[i], h->array[PARENT(i)]) < 0) {
        void *tmp = h->array[i];
        h->array[i] = h->array[PARENT(i)];
        h->array[PARENT(i)] = tmp;
        i = PARENT(i);
    }
}

void* heap_sift_down(heap h) {
    void *root = h->array[0];
    h->array[0] = h->array[--h->n]; 
    int i = 0;
    while (LEFT(i) < h->n) {
        int min = LEFT(i);
        if (RIGHT(i) < h->n && h->f(h->array[RIGHT(i)], h->array[LEFT(i)]) < 0)
            min = RIGHT(i);
        if (h->f(h->array[i], h->array[min]) <= 0) break;
        void *tmp = h->array[i]; h->array[i] = h->array[min]; h->array[min] = tmp;
        i = min;
    }
    return root;
}
