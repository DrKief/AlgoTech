/*
================================================================================
ULTIMATE CHEAT SHEET
Keep this open during the exam. You can use Ctrl+F to instantly find what you need.
Variables and structures match the Bordeaux TAP classes.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* =============================================================================
   DUMMY DEFINITIONS TO MAKE VS CODE HAPPY (Ignore these during exam)
   ============================================================================= */
typedef struct _config { int n; double cost; double score; struct _config* parent; } *config;
typedef struct { double weight; } edge;
typedef struct _heap { int n; void** array; int (*f)(const void*, const void*); } *heap;
typedef struct { double x, y; } point;
typedef struct { int i, j; } position;
typedef double** grid;
typedef double (*heuristic)(config);

// Dummy function declarations to avoid implicit declaration warnings
int can_win(config S);
heap heap_create(int size, int (*f)(const void*, const void*));
void heap_add(heap h, void* element);
void* heap_pop(heap h);
int heap_empty(heap h);
double h1(config C);
int is_marked(config C);
config move(config C, char m);
double dist(int a, int b);
double dist_pt(point a, point b);

/*
================================================================================
PART 1: Syntax & Quirks
================================================================================
*/

/* 1. Hidden Pointers in typedef (CRITICAL)
   typedef struct _config *config; 
   Whenever you see a type name without a * but represents a complex object, 
   it is already a pointer.
*/
void hidden_pointers_example() {
    // WRONG: config C; C.n = 5; 
    // RIGHT:
    config C = malloc(sizeof(*C)); // Allocate the struct
    C->n = 5;                      // Access using ->
}

/* 2. void* and Generic Pointers (Casting)
   In Heaps and Hash Tables, data is stored as void *. 
   When writing a compare function or fetching data, you MUST cast it back.
*/
// Example: Comparator for a Heap storing 'config' objects
int fcmp_config(const void *A, const void *B) {
    // Cast void* (which is pointer-to-pointer here) to (config*), then dereference with *
    config cA = *(config*)A;
    config cB = *(config*)B;
    
    if (cA->score < cB->score) return -1;
    if (cA->score > cB->score) return 1;
    return 0;
}

/* 3. Comparing Doubles in qsort (AVOID THE TRAP)
   If you return (int)(a - b), 0.5 - 0.3 becomes 0. This breaks qsort.
*/
int compEdge(const void *e1, const void *e2) {
    double x = ((edge *)e1)->weight;
    double y = ((edge *)e2)->weight;
    // Returns -1 if x < y, 0 if x == y, 1 if x > y
    return (x > y) - (x < y); 
}

/* 4. 2D Arrays (Pointer to Pointers)
   Grids are almost always type **G.
*/
void array_2d_example() {
    // ALLOCATION
    int n = 10;
    int **G = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        G[i] = calloc(n, sizeof(int)); // calloc initializes to 0!
    }

    // COPYING A 2D ARRAY
    int **G_copy = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        G_copy[i] = malloc(n * sizeof(int));
        memcpy(G_copy[i], G[i], n * sizeof(int)); // Fast row copy!
    }
}

/* 5. Bitwise Sets (For Dynamic Programming / TSP)
   An integer S represents a set of visited cities.
*/
void bitwise_example() {
    int i = 3;
    int S = 0;             // Empty set
    S = S | (1 << i);      // ADD city 'i' to set S
    S = S & ~(1 << i);     // REMOVE city 'i' from set S
    if (S & (1 << i)) { }  // CHECK if city 'i' is in set S
}


/*
================================================================================
PART 2: Core Data Structures (Copy-Paste Ready)
================================================================================
*/

/* 1. Union-Find (For Kruskal / Graphs) */
void union_find_init(int n) {
    // 1. Initialization
    int *parent = malloc(n * sizeof(int));
    int *rank = malloc(n * sizeof(int));
    for (int u = 0; u < n; u++) {
        parent[u] = u;
        rank[u] = 0;
    }
}

// 2. Find with path compression
int Find(int u, int *parent) {
    if (u != parent[u])
        parent[u] = Find(parent[u], parent);
    return parent[u];
}

// 3. Union by rank
void Union(int x, int y, int *parent, int *rank) {
    int rootX = Find(x, parent);
    int rootY = Find(y, parent);
    if (rootX == rootY) return;

    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) rank[rootY]++;
    }
}

/* 2. Min-Heap (Array-Based, for A* or Dijkstra) 
   If you have to write heap_add or heap_pop, here is the exact logic.
*/
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

void heap_logic_example(heap h) {
    // Inside heap_add (sift up):
    int i = h->n++; // Place at end
    while (i > 0 && h->f(h->array[i], h->array[PARENT(i)]) < 0) {
        void *tmp = h->array[i];
        h->array[i] = h->array[PARENT(i)];
        h->array[PARENT(i)] = tmp;
        i = PARENT(i);
    }

    // Inside heap_pop (sift down):
    void *root = h->array[0];
    h->array[0] = h->array[--h->n]; // Move last to root
    i = 0;
    while (LEFT(i) < h->n) {
        int min_child = LEFT(i);
        if (RIGHT(i) < h->n && h->f(h->array[RIGHT(i)], h->array[LEFT(i)]) < 0) {
            min_child = RIGHT(i);
        }
        if (h->f(h->array[i], h->array[min_child]) <= 0) break;
        
        void *tmp = h->array[i];
        h->array[i] = h->array[min_child];
        h->array[min_child] = tmp;
        i = min_child;
    }
    // return root;
}


/*
================================================================================
PART 3: The Big Algorithms
================================================================================
*/

/* 1. A* Search (Grid)
   Exactly what you need for the Taquin puzzle or Grid Navigation.
*/
config solve(config S, heuristic h) {
    if (!can_win(S)) return NULL;

    heap H = heap_create(100, fcmp_config);
    heap_add(H, S);
    S->cost = 0;
    S->score = h(S);

    // standard A* loop
    while (!heap_empty(H)) {
        config C = heap_pop(H);
        
        // Goal check
        if (h1(C) == 0) return C; // Or whatever your goal condition is
        
        // Lazy deletion check (if we already visited this exact state, skip)
        if (is_marked(C)) continue; 

        char moves[] = "bdgh";
        for (int i = 0; i < 4; i++) {
            config V = move(C, moves[i]);
            if (V == NULL) continue; // Invalid move
            
            V->cost = C->cost + 1; // + distance
            V->score = V->cost + h(V);
            V->parent = C;
            
            heap_add(H, V);
        }
    }
    return NULL;
}

/* 2. TSP Dynamic Programming (Bitmask) */
typedef struct { double length; int pred; } dp_cell;

void tsp_dp_example(int n, int* V, dp_cell** D) {
    // D[t][S] = length of shortest path from V[n-1] to V[t] visiting exactly subset S.
    // To fill table D:
    for (int S = 1; S < (1 << (n - 1)); S++) {
        for (int t = 0; t < n - 1; t++) {
            // If t is NOT in S, skip
            if (!(S & (1 << t))) continue;

            int prev_S = S & ~(1 << t); // Remove t from S
            
            // Base case: S contains ONLY t
            if (prev_S == 0) {
                D[t][S].length = dist(V[n - 1], V[t]);
                D[t][S].pred = n - 1;
                continue;
            }

            // Find best previous node 'x'
            double min_len = 1e9; // Infinity
            int best_pred = -1;
            for (int x = 0; x < n - 1; x++) {
                if (!(prev_S & (1 << x))) continue; // x must be in prev_S
                
                double cand = D[x][prev_S].length + dist(V[x], V[t]);
                if (cand < min_len) {
                    min_len = cand;
                    best_pred = x;
                }
            }
            D[t][S].length = min_len;
            D[t][S].pred = best_pred;
        }
    }
}

/* 3. TSP Local Search (2-opt Flip)
   If you need to optimize a path by untangling crossed lines.
*/
// Reverses a section of array T between index p and q (inclusive)
void reverse(int *T, int p, int q) {
    while (p < q) {
        int tmp = T[p];
        T[p] = T[q];
        T[q] = tmp;
        p++; q--;
    }
}

// Checks if flipping edges (i, i+1) and (j, j+1) improves the path length
double gain(point *V, int n, int *P, int i, int j) {
    int v1 = P[i];
    int v2 = P[(i + 1) % n];
    int v3 = P[j];
    int v4 = P[(j + 1) % n];
    
    double old_dist = dist_pt(V[v1], V[v2]) + dist_pt(V[v3], V[v4]);
    double new_dist = dist_pt(V[v1], V[v3]) + dist_pt(V[v2], V[v4]); // Cross-connect
    
    return old_dist - new_dist; // Positive means we gained (reduced distance)
}

/* 4. Cantor Pairing Function (For Hash Tables / PPPP algorithm)
   Maps a 2D coordinate (i, j) to a 1D integer for hash tables.
*/
int map(int i, int j) {
    // Maps (i, j) to a unique integer.
    // Sum of diagonal lengths + j
    return j + ((i + j) * (i + j + 1)) / 2;
}


/*
================================================================================
PART 4: Utility Snippets
================================================================================
*/

/* 1. Grid Traversal (The "4-way" or "8-way" Loop) */
void grid_traversal_example(int rows, int cols, int i, int j) {
    // 4-way traversal (Up, Down, Left, Right)
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        
        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
            // Do something with G[ni][nj]
        }
    }
}

/* 2. Random Fisher-Yates Shuffle */
void random_permutation(int *P, int k) {
    // 1. Initialize to identity
    for (int i = 0; i < k; i++) P[i] = i;
    
    // 2. Shuffle backwards
    for (int i = k - 1; i > 0; i--) {
        int j = random() % (i + 1);
        int tmp = P[i];
        P[i] = P[j];
        P[j] = tmp;
    }
}

/* 3. Standard Distances */
void distance_examples(position A, position B, point ptA, point ptB) {
    // Euclidean (Real world distance)
    double dist_e = hypot(ptA.x - ptB.x, ptA.y - ptB.y);

    // Manhattan (Grid distance, no diagonals)
    int dist_m = abs(A.i - B.i) + abs(A.j - B.j);

    // Chebyshev (Grid distance, diagonals allowed = King in Chess)
    int dist_c = fmax(abs(A.i - B.i), abs(A.j - B.j));
}

/* 4. Quick Local Max checking */
position voisin_max(grid G, position p) {
    position best = p;
    double max_val = G[p.i][p.j];
    
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (G[p.i + di][p.j + dj] > max_val) {
                max_val = G[p.i + di][p.j + dj];
                best.i = p.i + di;
                best.j = p.j + dj;
            }
        }
    }
    return best; // If best == p, it is a local max.
}

/*
================================================================================
Final Exam Strategy Checklist
================================================================================
1. Compilation > Logic: If a function is hard, write `return 0;` or `return NULL;` 
   so the rest of the file compiles. A compiling file with failing tests is better 
   than a 0.
2. Ignore free() unless required: Memory leaks are often allowed in these exams 
   (e.g. 2025 Taquin). Don't waste time on `free()` logic. `malloc` and move on.
3. Infinite loop safeguard: Put a hard stop in while loops if testing visually:
   `int limit=10000; while(!heap_empty && limit--) {...}`.
================================================================================
*/
