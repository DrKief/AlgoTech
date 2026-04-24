/* =============================================================================
   FILE 5: BASIC ALGORITHMS & FUNDAMENTALS
   SEARCH ALIASES: Dijkstra, Plus court chemin, Shortest path, Binary Search, 
   Recherche dichotomique, Dicho, Merge Sort, Tri fusion, Tri, Fast Exponentiation, 
   Exponentiation rapide, Puissance, Backtracking, Brute force, Exhaustive.
   ============================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Dummies
typedef struct { int n; int *deg; int **list; double **weight; } graph;
typedef struct _heap* heap; heap heap_create(int, void*); void heap_add(heap, void*); void* heap_pop(heap); int heap_empty(heap);

/* -----------------------------------------------------------------------------
   1. DIJKSTRA'S ALGORITHM (Shortest Path on a Graph)
   Finds the shortest path from 'start' to 'target' using an Adjacency List.
   ----------------------------------------------------------------------------- */
typedef struct { int id; double cost; int parent; } node_state;

int fcmp_dijkstra(const void *A, const void *B) {
    double cA = (*(node_state**)A)->cost;
    double cB = (*(node_state**)B)->cost;
    return (cA > cB) - (cA < cB);
}

// Returns the shortest distance, or -1 if unreachable
double dijkstra(graph G, int start, int target, int *parent_array) {
    double *dist = malloc(G.n * sizeof(double));
    int *visited = calloc(G.n, sizeof(int));
    for (int i = 0; i < G.n; i++) dist[i] = 1e9; // Infinity
    
    heap H = heap_create(G.n * 2, fcmp_dijkstra);
    
    node_state *S = malloc(sizeof(node_state));
    S->id = start; S->cost = 0; S->parent = start;
    heap_add(H, S);
    dist[start] = 0;
    
    while (!heap_empty(H)) {
        node_state *curr = heap_pop(H);
        int u = curr->id;
        
        if (visited[u]) { free(curr); continue; }
        visited[u] = 1;
        parent_array[u] = curr->parent;
        
        if (u == target) {
            double res = curr->cost;
            // Memory leak allowed, but you can free(H) here
            return res; 
        }
        
        for (int i = 0; i < G.deg[u]; i++) {
            int v = G.list[u][i];
            double edge_weight = G.weight[u][i]; // @@CHANGE_ME@@_WEIGHT: Adjust to your edge struct
            
            if (!visited[v] && dist[u] + edge_weight < dist[v]) {
                dist[v] = dist[u] + edge_weight;
                node_state *next = malloc(sizeof(node_state));
                next->id = v;
                next->cost = dist[v];
                next->parent = u;
                heap_add(H, next);
            }
        }
        free(curr);
    }
    return -1.0; // Unreachable
}

/* -----------------------------------------------------------------------------
   2. BINARY SEARCH (Recherche Dichotomique)
   Finds an element in a SORTED array in O(log n) time.
   ----------------------------------------------------------------------------- */
int binary_search(int *T, int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents overflow
        
        if (T[mid] == target) return mid; // Found
        
        if (T[mid] < target) low = mid + 1; // Search right half
        else                 high = mid - 1; // Search left half
    }
    return -1; // Not found
}

/* -----------------------------------------------------------------------------
   3. MERGE SORT (Tri Fusion) - O(n log n)
   Exactly as written in the professor's course book (page 36/178).
   ----------------------------------------------------------------------------- */
// Auxiliary fusion function
void fusion(double T[], int i, int m, int j, double A[]) {
    int k = i, p = i, q = m, *r;
    while (k < j) {
        if (p == m) r = &q;
        else if (q == j) r = &p;
        else r = (T[p] < T[q]) ? &p : &q; // @@CHANGE_ME@@_COMPARE: Change < to > for descending
        A[k++] = T[(*r)++];
    }
    memcpy(T + i, A + i, (j - i) * sizeof(double));
}

// Recursive sort
void merge_sort_rec(double T[], int i, int j, double A[]) {
    if (j - i < 2) return;
    int m = (i + j) / 2;
    merge_sort_rec(T, i, m, A);
    merge_sort_rec(T, m, j, A);
    fusion(T, i, m, j, A);
}

// Main wrapper
void merge_sort(double T[], int n) {
    double *A = malloc(n * sizeof(double));
    merge_sort_rec(T, 0, n, A);
    free(A);
}

/* -----------------------------------------------------------------------------
   4. FAST EXPONENTIATION (Exponentiation Rapide)
   Calculates (base^exp) % mod in O(log exp) time.
   ----------------------------------------------------------------------------- */
long long fast_expo(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) // If exp is odd
            res = (res * base) % mod;
            
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

/* -----------------------------------------------------------------------------
   5. BACKTRACKING TEMPLATE (Recherche Exhaustive / Brute Force)
   Generates all permutations/subsets. Essential for Chapter 1 "Brute Force".
   ----------------------------------------------------------------------------- */
// Example: Generating all paths/permutations of length N
// Call with: backtrack(0, N, current_path, visited);
void backtrack(int step, int N, int *path, int *visited) {
    // 1. Base Case: We formed a complete solution
    if (step == N) {
        // @@CHANGE_ME@@_PROCESS: Evaluate the path here (e.g., check TSP distance)
        // double cost = evaluate(path, N);
        // if (cost < min_cost) min_cost = cost;
        return;
    }
    
    // 2. Recursive Case: Try all possible next steps
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            // "Do"
            visited[i] = 1;
            path[step] = i;
            
            // "Recurse"
            backtrack(step + 1, N, path, visited);
            
            // "Undo" (Backtrack)
            visited[i] = 0;
        }
    }
}
