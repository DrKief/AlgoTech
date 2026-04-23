#include <stdlib.h>

/* ==================================================================
   1. GRAPH REPRESENTATION (Adjacency List)
   ================================================================== */
// ALGO DESCRIPTION: Adjacency list optimal for sparse graphs. `transpose_graph` 
// builds a reversed copy of all directed edges, required for Kosaraju's SCC.
// @@CHANGE_ME@@_STRUCT: If the TP requires coordinates or weights, add 
// `double *x, *y;` or `double **weights;` to the graph struct and allocate them
// in the initialization loops.
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
// ALGO DESCRIPTION: Tracks disjoint sets for Kruskal's MST. 
// `Find` uses path compression (flattens tree to root for O(1) future lookups).
// `Union` links trees by rank to prevent deep, inefficient chains.
// @@CHANGE_ME@@_VARS: Arrays `parent` and `rank` must be allocated to size `n` before calling.
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
// ALGO DESCRIPTION: Array-based binary tree. `sift_up` moves smaller elements 
// up the tree (used on insertion). `sift_down` moves larger elements down (used on extraction).
// @@CHANGE_ME@@_POINTERS: If the TP prohibits void pointers, change `void** array` 
// to `edge** array` or `int* array` and replace the generic function pointer `h->f` 
// with a direct comparison `<` or `>`.
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
