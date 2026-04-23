=========================================
Project Path: /home/lucas/Documents/S6/AlgoTech/GRADED_TP/Sheets
Project Directory Structure
=========================================
```
.:
01_syntax_utils.c
02_data_structs.c
03_graphs_search.c
04_algo_paradigms.c
Cheatsheets.md
combinedCodebase.md
```


=========================================
System Information
=========================================
```bash


                    -`
                   .o+`
                  `ooo/
                 `+oooo:
                `+oooooo:
                -+oooooo+:
              `/:-:++oooo+:
             `/++++/+++++++:
            `/++++++++++++++:
           `/+++ooooooooooooo/`
          ./ooosssso++osssssso+`
         .oossssso-````/ossssss+`
        -osssssso.      :ssssssso.
       :osssssss/        osssso+++.
      /ossssssss/        +ssssooo/-
    `/ossssso+/:-        -:/+osssso+-
   `+sso+:-`                 `.-/+oso:
  `++:.                           `-/+/
  .`                                 `/[1G[20A[62COS  Arch Linux x86_64
[62CHost  Laptop 13 (AMD Ryzen 7040Series) (A5)
[62CKernel  Linux 6.19.12-zen1-1-zen
[62CUptime  23 hours, 7 mins
[62CProcesses  417
[62CPackages  1383 (pacman), 11 (flatpak)
[62CShell  fish 4.6.0
[62CDisplay  2880x1920 @ 2x in 13", 120 Hz [Built-in]
[62CLM  sddm 0.21.0 (Wayland)
[62CDE  KDE Plasma 6.6.4
[62CWM  KWin (Wayland)
[62CTerminal  ghostty 1.3.1-arch2
[62CCPU  AMD Ryzen 5 7640U (12) @ 3.50 GHz
[62CGPU  AMD Radeon 760M Graphics [Integrated]
[62CMemory  10.58 GiB / 27.21 GiB (39%)
[62CDisk (/)  562.00 GiB / 930.50 GiB (60%) - btrfs
[62CBattery  48% (2 hours, 24 mins remaining) [Discharging]
[62CLocal IP  10.32.6.208/24
[62CDNS  10.32.6.1
[62CDate & Time  2026-26-4 01:1:01
[62C
[62C● ● ● ● ● ● ● ●
```


=========================================
here how this was made :
=========================================
```bash
#!/bin/bash

OUTPUT="combinedCodebase.md"
SCRIPT_SOURCE=$(realpath "$0")

echo "Running code combiner in: $(pwd)"

if [ -f "$OUTPUT" ]; then
    rm "$OUTPUT"
fi

{
    echo "========================================="
    echo "Project Path: $(pwd)"
    echo "Project Directory Structure"
    echo "========================================="
    echo '```'
    ls -R
    echo '```'
    echo -e "\n"

    echo "========================================="
    echo "System Information"
    echo "========================================="
    echo '```bash'
    fastfetch
    echo '```'
    echo -e "\n"

    echo "========================================="
    echo "here how this was made :"
    echo "========================================="
    echo '```bash'
    cat "$SCRIPT_SOURCE"
    echo '```'
    echo -e "\n"

    EXCLUDES=(
        # --- 1. Version Control & Script Output ---
        -not -path '*/.git/*'
        -not -name "diff.md"
        -not -name "$OUTPUT"

        # --- 2. Build & Dependency Directories ---
        -not -path '*/node_modules/*'
        -not -path '*/build/*'
        -not -path '*/target/*'
        -not -path '*/dist/*'
        -not -path '*/dist-ssr/*'
        -not -path '*/bin/*'
        -not -path '*/venv/*'

        # --- 3. Package Manager & Wrappers ---
        -not -name "package-lock.json"
        -not -name "mvnw"
        -not -name "mvnw.cmd"
        -not -path "*/.mvn/*"

        # --- 4. Binaries, Archives & Compiled Code ---
        -not -name "*.exe"
        -not -name "*.jar"
        -not -name "*.class"
        -not -name "*.o"
        -not -name "*.a"
        -not -name "*.out"

        # --- 5. Media & Images ---
        -not -name "*.pdf"
        -not -name "*.ico"
        -not -name "*.png"
        -not -name "*.jpg"
        -not -name "*.jpeg"
        -not -name "*.svg"

        # --- 6. Logs & Debugging ---
        -not -path "*/logs/*"
        -not -name "*.log"
        -not -name "npm-debug.log*"
        -not -name "yarn-debug.log*"
        -not -name "yarn-error.log*"
        -not -name "pnpm-debug.log*"
        -not -name "lerna-debug.log*"
        -not -name "hs_err_pid*"
        -not -name "replay_pid*"

        # --- 7. IDE, OS & Editor Files ---
        -not -name ".DS_Store"
        -not -name ".DS_Store?"
        -not -name "._*"
        -not -name ".Spotlight-V100"
        -not -name ".Trashes"
        -not -name "ehthumbs.db"
        -not -name "Thumbs.db"
        -not \( -path "*/.vscode/*" -a -not -name "extensions.json" \)
        -not -path "*/.idea/*"
        -not -path "*/.settings/*"
        -not -path "*/.apt_generated/*"
        -not -path "*/.sts4-cache/*"
        -not -path "*/nbproject/private/*"
        -not -path "*/nbbuild/*"
        -not -path "*/nbdist/*"
        -not -path "*/.nb-gradle/*"
        -not -name ".classpath"
        -not -name ".factorypath"
        -not -name ".project"
        -not -name ".springBeans"
        -not -name "*.iws"
        -not -name "*.iml"
        -not -name "*.ipr"
        -not -name "*.suo"
        -not -name "*.ntvs*"
        -not -name "*.njsproj"
        -not -name "*.sln"
        -not -name "*.sw?"
        -not -name "*.local"

        # --- 8. OCaml / Language Specific Temp Files ---
        -not -path "*/_build/*"
        -not -path "*/.merlin-conf/*"
        -not -path "*/.*.objs/*"
        -not -name "*_generated.ml"
        -not -name "*.cmly"
        -not -name "*.conflicts"
        -not -name "*.automaton"
        -not -name "*.dot"
        -not -name "*.cmi"
        -not -name "*.cmo"
        -not -name "*.cmt"
        -not -name "*.cmti"
        -not -name "*.cmx"
        -not -name "*.cma"
        -not -name "*.cmxa"
        -not -name "*.cmxs"
        -not -name "*.ml-gen"
        -not -name "*.all-deps"
        -not -name "*.d"
        -not -name "*.mock"
        -not -name "*.inferred"
        -not -name "Cmly.ml"

        # --- 9. Project Specific Exclusions ---
        -not -path "*/mini_ml/examples/*"
        -not -path "*/models/*"
        -not -path "*/install/*"
        -not -path "*/programs/*"
        -not -name "HELP.md"
        -not \( -name ".env*" -a -not -name ".env.example" \)
    )

    find . -type f "${EXCLUDES[@]}" \
        -exec grep -Iq . {} \; \
        -print0 | while IFS= read -r -d '' file; do
            echo "========================================="
            echo "File: $file"
            echo "========================================="
            cat "$file"
            echo -e "\n"
        done

} > "$OUTPUT"

echo "Success! All code combined into: $(pwd)/$OUTPUT"
```


=========================================
File: ./01_syntax_utils.c
=========================================
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(x, y, tmp) (tmp) = (x), (x) = (y), (y) = (tmp)

/* ==================================================================
   1. HIDDEN POINTERS & GENERIC CASTING
   ================================================================== */
// ALGO DESCRIPTION: Used for generic sorting (qsort) or priority queues. 
// Casts a void pointer back to the original struct type to compare values.
// @@CHANGE_ME@@_DATATYPE: If the TP uses 'struct node' or 'vertex' instead of 'config',
// change the cast here. Check if the TP sorts by 'int weight' or 'double cost'
// and adjust the '.score' field.
typedef struct _config { int n; double score; } *config;

int fcmp_config(const void *A, const void *B) {
    // Cast void* to config*, then dereference
    config cA = *(config*)A;
    config cB = *(config*)B;
    if (cA->score < cB->score) return -1;
    if (cA->score > cB->score) return 1;
    return 0;
}

/* ==================================================================
   2. PROPER DOUBLE COMPARISON (For qsort)
   ================================================================== */
// ALGO DESCRIPTION: A safe comparison function for floating-point numbers.
// Avoids the standard casting trap `return (int)(x - y)` which fails for decimals < 1.
// @@CHANGE_ME@@_FIELD: 'weight' might be 'distance', 'cost', or 'ratio' 
// depending on the greedy algorithm or graph tested.
typedef struct { double weight; } edge;
int compEdge(const void *e1, const void *e2) {
    double x = ((edge *)e1)->weight;
    double y = ((edge *)e2)->weight;
    return (x > y) - (x < y); // SAFE: Returns -1, 0, or 1
}

/* ==================================================================
   3. 2D ARRAYS (POINTERS TO POINTERS)
   ================================================================== */
void array_2d_example(int n) {
    // Allocation
    int **G = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) G[i] = calloc(n, sizeof(int)); // calloc = 0

    // Deep Copy
    int **G_copy = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        G_copy[i] = malloc(n * sizeof(int));
        memcpy(G_copy[i], G[i], n * sizeof(int)); 
    }
}

/* ==================================================================
   4. BITWISE SETS (For TSP DP)
   ================================================================== */
// ALGO DESCRIPTION: Uses integers as lightweight boolean arrays (sets).
// A 1 at the i-th bit means element 'i' is in the set. Essential for DP states.
// @@CHANGE_ME@@_VARS: Ensure the bitshift `(1 << i)` uses `1LL` if 'n' > 31 
// (e.g., `1LL << i`) to avoid overflow on long bitmasks.
void bitwise_example() {
    int i = 3;
    int S = 0;             // Empty set
    S = S | (1 << i);      // ADD city 'i'
    S = S & ~(1 << i);     // REMOVE city 'i'
    if (S & (1 << i)) { }  // CHECK if city 'i' is in set S
}

/* ==================================================================
   5. STANDARD DISTANCES
   ================================================================== */
typedef struct { double x, y; } point;
typedef struct { int i, j; } position;

void distances(point ptA, point ptB, position A, position B) {
    double dist_euclid = hypot(ptA.x - ptB.x, ptA.y - ptB.y);
    int dist_manhattan = abs(A.i - B.i) + abs(A.j - B.j);
    int dist_chebyshev = fmax(abs(A.i - B.i), abs(A.j - B.j));
}


=========================================
File: ./02_data_structs.c
=========================================
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


=========================================
File: ./03_graphs_search.c
=========================================
#include <stdlib.h>
#include <string.h>

// Dummies
typedef struct _config { int n; double cost; double score; struct _config* parent; } *config;
typedef struct { int n; int *deg; int **list; } graph;
double h1(config C); int is_marked(config C); int can_win(config S);
config move(config C, char m);
typedef struct _heap* heap; heap heap_create(int, void*); void heap_add(heap, void*); void* heap_pop(heap); int heap_empty(heap);

/* ==================================================================
   1. A* SEARCH ALGORITHM
   ================================================================== */
// ALGO DESCRIPTION: Heuristic-guided Best-First Search. Uses a priority queue 
// to explore the state space, expanding nodes with the lowest f = cost + heuristic.
// @@CHANGE_ME@@_VARS: 'config' is a dummy state. The TP might call it 'state', 'node', or 'board'.
// @@CHANGE_ME@@_MOVES: 'char moves[] = "bdgh"' is puzzle-specific. Change this 
// to an array of coordinate offsets (di, dj) if routing on a grid.
config solve_astar(config S, double (*heuristic)(config), void* fcmp_config) {
    if (!can_win(S)) return NULL;

    heap H = heap_create(100, fcmp_config);
    S->cost = 0; S->score = heuristic(S);
    heap_add(H, S);

    while (!heap_empty(H)) {
        config C = heap_pop(H);
        
        if (h1(C) == 0) return C; // GOAL REACHED
        if (is_marked(C)) continue; // Lazy deletion (already visited)

        char moves[] = "bdgh";
        for (int i = 0; i < 4; i++) {
            config V = move(C, moves[i]);
            if (V == NULL) continue; 
            
            V->cost = C->cost + 1; // Or + weight of edge
            V->score = V->cost + heuristic(V);
            V->parent = C;
            heap_add(H, V);
        }
    }
    return NULL;
}

/* ==================================================================
   2. KOSARAJU'S STRONGLY CONNECTED COMPONENTS
   Requires 'transpose_graph' from 02_data_structs.c
   ================================================================== */
// ALGO DESCRIPTION: Finds independent cyclic subnetworks. 
// Pass 1: DFS computes finishing times (post-order push to stack). 
// Pass 2: DFS explores transposed graph in reverse finishing order.
// @@CHANGE_ME@@_OUTPUT: Instead of returning `max_scc_size`, the TP might ask you to 
// assign component IDs. Pass an `int *scc_id` array and increment `id` per stack pop.
void kosaraju_dfs1(graph G, int u, int *visited, int *stack, int *top) {
    visited[u] = 1;
    for (int i = 0; i < G.deg[u]; i++) {
        if (!visited[G.list[u][i]]) kosaraju_dfs1(G, G.list[u][i], visited, stack, top);
    }
    stack[(*top)++] = u; // Push POST-order
}

void kosaraju_dfs2(graph G_rev, int u, int *visited, int *curr_size) {
    visited[u] = 1;
    (*curr_size)++;
    for (int i = 0; i < G_rev.deg[u]; i++) {
        if (!visited[G_rev.list[u][i]]) kosaraju_dfs2(G_rev, G_rev.list[u][i], visited, curr_size);
    }
}

int largest_scc(graph G, graph G_rev) {
    int *visited = calloc(G.n, sizeof(int));
    int *stack = malloc(G.n * sizeof(int));
    int top = 0;

    for (int i = 0; i < G.n; i++) 
        if (!visited[i]) kosaraju_dfs1(G, i, visited, stack, &top);

    memset(visited, 0, G.n * sizeof(int));
    int max_scc_size = 0;

    while (top > 0) {
        int u = stack[--top];
        if (!visited[u]) {
            int curr_size = 0;
            kosaraju_dfs2(G_rev, u, visited, &curr_size);
            if (curr_size > max_scc_size) max_scc_size = curr_size;
        }
    }
    return max_scc_size; 
}

/* ==================================================================
   3. GRID TRAVERSAL (4-way / 8-way)
   ================================================================== */
// ALGO DESCRIPTION: Generates neighboring coordinates safely without going out of bounds.
// @@CHANGE_ME@@_DIRS: If the TP asks for diagonal movement, switch to the 8-way arrays.
// If the grid uses (x, y) instead of (row, col), ensure bounds check `cols` for x and `rows` for y.
void grid_traversal(int rows, int cols, int i, int j, double **G) {
    int di[] = {-1, 1, 0, 0}; // Add {-1, -1, 1, 1} for 8-way
    int dj[] = {0, 0, -1, 1}; // Add {-1, 1, -1, 1} for 8-way

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
            // Safe to access G[ni][nj]
        }
    }
}


=========================================
File: ./04_algo_paradigms.c
=========================================
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* ==================================================================
   1. DIVIDE & CONQUER: Maximum Subarray (O(n log n))
   ================================================================== */
// ALGO DESCRIPTION: Recursively halves the array to find the contiguous 
// subarray with the highest sum. Checks left half, right half, and the cross-section.
// @@CHANGE_ME@@_VARS: 'arr' might need to be 'double*' if the TP uses float values.
// Update the `-2147483648` (INT_MIN) sentinel to `-1e9` if switching to doubles.
int max_crossing(int *arr, int low, int mid, int high) {
    int left_sum = -2147483648, sum = 0;
    for (int i = mid; i >= low; i--) { sum += arr[i]; if (sum > left_sum) left_sum = sum; }
    
    int right_sum = -2147483648; sum = 0;
    for (int i = mid + 1; i <= high; i++) { sum += arr[i]; if (sum > right_sum) right_sum = sum; }
    
    return left_sum + right_sum;
}

int max_subarray(int *arr, int low, int high) {
    if (low == high) return arr[low];
    int mid = (low + high) / 2;
    int ml = max_subarray(arr, low, mid);
    int mr = max_subarray(arr, mid + 1, high);
    int mc = max_crossing(arr, low, mid, high);
    return MAX(MAX(ml, mr), mc);
}

/* ==================================================================
   2. DYNAMIC PROGRAMMING 1: Ribbon Cutting (1D Array)
   ================================================================== */
// ALGO DESCRIPTION: Bottom-up 1D Dynamic Programming. Builds optimal answers 
// from smaller subproblems to find max pieces a ribbon can be cut into.
// @@CHANGE_ME@@_VARS: If the TP gives an array of options (like knapsack weights) 
// instead of specific integers a,b,c, replace the 3 if-statements with a nested `for` loop.
int ribbon_cutting(int n, int a, int b, int c) {
    int *dp = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) dp[i] = -2147483648; // -Infinity
    dp[0] = 0; 

    for (int i = 1; i <= n; i++) {
        if (i >= a && dp[i - a] != -2147483648) dp[i] = MAX(dp[i], dp[i - a] + 1);
        if (i >= b && dp[i - b] != -2147483648) dp[i] = MAX(dp[i], dp[i - b] + 1);
        if (i >= c && dp[i - c] != -2147483648) dp[i] = MAX(dp[i], dp[i - c] + 1);
    }
    return dp[n]; 
}

/* ==================================================================
   3. GREEDY: Set Cover
   ================================================================== */
// ALGO DESCRIPTION: Iteratively selects the subset that covers the most 
// remaining uncovered elements until all elements are covered.
// @@CHANGE_ME@@_INPUT: TPs represent sets as a 2D boolean matrix 
// `grid[set_id][element_id]` instead of a ragged array. Modify the inner 
// `if (uncovered[sets[i][j]] == 1)` loop to check `if (grid[i][j] == 1 && uncovered[j])`.
int greedy_set_cover(int N, int num_sets, int **sets, int *sizes) {
    int *uncovered = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) uncovered[i] = 1; 
    
    int *used_sets = calloc(num_sets, sizeof(int)); 
    int elements_left = N, sets_picked = 0;
    
    while (elements_left > 0) {
        int best_set = -1, max_covered = 0;
        
        for (int i = 0; i < num_sets; i++) {
            if (used_sets[i]) continue; 
            int count = 0;
            for (int j = 0; j < sizes[i]; j++) {
                if (uncovered[sets[i][j]] == 1) count++;
            }
            if (count > max_covered) { max_covered = count; best_set = i; }
        }
        
        if (best_set == -1) return -1; // Impossible to cover all
        
        used_sets[best_set] = 1;
        sets_picked++;
        for (int j = 0; j < sizes[best_set]; j++) {
            if (uncovered[sets[best_set][j]] == 1) {
                uncovered[sets[best_set][j]] = 0;
                elements_left--;
            }
        }
    }
    return sets_picked;
}

/* ==================================================================
   4. LOCAL SEARCH: TSP 2-Opt Flip
   ================================================================== */
// ALGO DESCRIPTION: Local Search heuristic for Traveling Salesperson. Uncrosses 
// a self-intersecting path by swapping two edges and reversing the sequence between them.
// @@CHANGE_ME@@_DISTANCE: Replace `dist_pt` with the actual distance matrix `G[v1][v2]` 
// or euclidean distance logic depending on the TP.
// Reverse sub-array
void reverse(int *T, int p, int q) {
    while (p < q) { int tmp = T[p]; T[p] = T[q]; T[q] = tmp; p++; q--; }
}

// Calculate gain of swapping edges
double dist_pt(int a, int b); // Dummy
double gain(int *V, int n, int *P, int i, int j) {
    int v1 = P[i], v2 = P[(i + 1) % n], v3 = P[j], v4 = P[(j + 1) % n];
    double old_dist = dist_pt(V[v1], V[v2]) + dist_pt(V[v3], V[v4]);
    double new_dist = dist_pt(V[v1], V[v3]) + dist_pt(V[v2], V[v4]); 
    return old_dist - new_dist; // > 0 means improvement
}

/* ==================================================================
   5. HASHING / RANDOM: Cantor Pairing & Fisher-Yates Shuffle
   ================================================================== */
int cantor_map(int i, int j) {
    return j + ((i + j) * (i + j + 1)) / 2;
}

void random_permutation(int *P, int k) {
    for (int i = 0; i < k; i++) P[i] = i;
    for (int i = k - 1; i > 0; i--) {
        int j = random() % (i + 1);
        int tmp = P[i]; P[i] = P[j]; P[j] = tmp;
    }
}


=========================================
File: ./Cheatsheets.md
=========================================
=========================================
Project Path: /home/lucas/Documents/S6/AlgoTech/GRADED_TP/Sheets
Project Directory Structure
=========================================
```
.:
01_syntax_utils.c
02_data_structs.c
03_graphs_search.c
04_algo_paradigms.c
combinedCodebase.md
```


=========================================
System Information
=========================================
```bash


                    -`
                   .o+`
                  `ooo/
                 `+oooo:
                `+oooooo:
                -+oooooo+:
              `/:-:++oooo+:
             `/++++/+++++++:
            `/++++++++++++++:
           `/+++ooooooooooooo/`
          ./ooosssso++osssssso+`
         .oossssso-````/ossssss+`
        -osssssso.      :ssssssso.
       :osssssss/        osssso+++.
      /ossssssss/        +ssssooo/-
    `/ossssso+/:-        -:/+osssso+-
   `+sso+:-`                 `.-/+oso:
  `++:.                           `-/+/
  .`                                 `/[1G[20A[62COS  Arch Linux x86_64
[62CHost  Laptop 13 (AMD Ryzen 7040Series) (A5)
[62CKernel  Linux 6.19.12-zen1-1-zen
[62CUptime  22 hours, 57 mins
[62CProcesses  413
[62CPackages  1383 (pacman), 11 (flatpak)
[62CShell  fish 4.6.0
[62CDisplay  2880x1920 @ 2x in 13", 120 Hz [Built-in]
[62CLM  sddm 0.21.0 (Wayland)
[62CDE  KDE Plasma 6.6.4
[62CWM  KWin (Wayland)
[62CTerminal  ghostty 1.3.1-arch2
[62CCPU  AMD Ryzen 5 7640U (12) @ 3.50 GHz
[62CGPU  AMD Radeon 760M Graphics [Integrated]
[62CMemory  10.20 GiB / 27.21 GiB (37%)
[62CDisk (/)  562.00 GiB / 930.50 GiB (60%) - btrfs
[62CBattery  51% (2 hours, 38 mins remaining) [Discharging]
[62CLocal IP  10.32.6.208/24
[62CDNS  10.32.6.1
[62CDate & Time  2026-26-4 01:1:01
[62C
[62C● ● ● ● ● ● ● ●
```


=========================================
here how this was made :
=========================================
```bash
#!/bin/bash

OUTPUT="combinedCodebase.md"
SCRIPT_SOURCE=$(realpath "$0")

echo "Running code combiner in: $(pwd)"

if [ -f "$OUTPUT" ]; then
    rm "$OUTPUT"
fi

{
    echo "========================================="
    echo "Project Path: $(pwd)"
    echo "Project Directory Structure"
    echo "========================================="
    echo '```'
    ls -R
    echo '```'
    echo -e "\n"

    echo "========================================="
    echo "System Information"
    echo "========================================="
    echo '```bash'
    fastfetch
    echo '```'
    echo -e "\n"

    echo "========================================="
    echo "here how this was made :"
    echo "========================================="
    echo '```bash'
    cat "$SCRIPT_SOURCE"
    echo '```'
    echo -e "\n"

    EXCLUDES=(
        # --- 1. Version Control & Script Output ---
        -not -path '*/.git/*'
        -not -name "diff.md"
        -not -name "$OUTPUT"

        # --- 2. Build & Dependency Directories ---
        -not -path '*/node_modules/*'
        -not -path '*/build/*'
        -not -path '*/target/*'
        -not -path '*/dist/*'
        -not -path '*/dist-ssr/*'
        -not -path '*/bin/*'
        -not -path '*/venv/*'

        # --- 3. Package Manager & Wrappers ---
        -not -name "package-lock.json"
        -not -name "mvnw"
        -not -name "mvnw.cmd"
        -not -path "*/.mvn/*"

        # --- 4. Binaries, Archives & Compiled Code ---
        -not -name "*.exe"
        -not -name "*.jar"
        -not -name "*.class"
        -not -name "*.o"
        -not -name "*.a"
        -not -name "*.out"

        # --- 5. Media & Images ---
        -not -name "*.pdf"
        -not -name "*.ico"
        -not -name "*.png"
        -not -name "*.jpg"
        -not -name "*.jpeg"
        -not -name "*.svg"

        # --- 6. Logs & Debugging ---
        -not -path "*/logs/*"
        -not -name "*.log"
        -not -name "npm-debug.log*"
        -not -name "yarn-debug.log*"
        -not -name "yarn-error.log*"
        -not -name "pnpm-debug.log*"
        -not -name "lerna-debug.log*"
        -not -name "hs_err_pid*"
        -not -name "replay_pid*"

        # --- 7. IDE, OS & Editor Files ---
        -not -name ".DS_Store"
        -not -name ".DS_Store?"
        -not -name "._*"
        -not -name ".Spotlight-V100"
        -not -name ".Trashes"
        -not -name "ehthumbs.db"
        -not -name "Thumbs.db"
        -not \( -path "*/.vscode/*" -a -not -name "extensions.json" \)
        -not -path "*/.idea/*"
        -not -path "*/.settings/*"
        -not -path "*/.apt_generated/*"
        -not -path "*/.sts4-cache/*"
        -not -path "*/nbproject/private/*"
        -not -path "*/nbbuild/*"
        -not -path "*/nbdist/*"
        -not -path "*/.nb-gradle/*"
        -not -name ".classpath"
        -not -name ".factorypath"
        -not -name ".project"
        -not -name ".springBeans"
        -not -name "*.iws"
        -not -name "*.iml"
        -not -name "*.ipr"
        -not -name "*.suo"
        -not -name "*.ntvs*"
        -not -name "*.njsproj"
        -not -name "*.sln"
        -not -name "*.sw?"
        -not -name "*.local"

        # --- 8. OCaml / Language Specific Temp Files ---
        -not -path "*/_build/*"
        -not -path "*/.merlin-conf/*"
        -not -path "*/.*.objs/*"
        -not -name "*_generated.ml"
        -not -name "*.cmly"
        -not -name "*.conflicts"
        -not -name "*.automaton"
        -not -name "*.dot"
        -not -name "*.cmi"
        -not -name "*.cmo"
        -not -name "*.cmt"
        -not -name "*.cmti"
        -not -name "*.cmx"
        -not -name "*.cma"
        -not -name "*.cmxa"
        -not -name "*.cmxs"
        -not -name "*.ml-gen"
        -not -name "*.all-deps"
        -not -name "*.d"
        -not -name "*.mock"
        -not -name "*.inferred"
        -not -name "Cmly.ml"

        # --- 9. Project Specific Exclusions ---
        -not -path "*/mini_ml/examples/*"
        -not -path "*/models/*"
        -not -path "*/install/*"
        -not -path "*/programs/*"
        -not -name "HELP.md"
        -not \( -name ".env*" -a -not -name ".env.example" \)
    )

    find . -type f "${EXCLUDES[@]}" \
        -exec grep -Iq . {} \; \
        -print0 | while IFS= read -r -d '' file; do
            echo "========================================="
            echo "File: $file"
            echo "========================================="
            cat "$file"
            echo -e "\n"
        done

} > "$OUTPUT"

echo "Success! All code combined into: $(pwd)/$OUTPUT"
```


=========================================
File: ./01_syntax_utils.c
=========================================
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(x, y, tmp) (tmp) = (x), (x) = (y), (y) = (tmp)

/* ==================================================================
   1. HIDDEN POINTERS & GENERIC CASTING
   ================================================================== */
// ALGO DESCRIPTION: Used for generic sorting (qsort) or priority queues. 
// Casts a void pointer back to the original struct type to compare values.
// @@CHANGE_ME@@_DATATYPE: If the TP uses 'struct node' or 'vertex' instead of 'config',
// change the cast here. Check if the TP sorts by 'int weight' or 'double cost'
// and adjust the '.score' field.
typedef struct _config { int n; double score; } *config;

int fcmp_config(const void *A, const void *B) {
    // Cast void* to config*, then dereference
    config cA = *(config*)A;
    config cB = *(config*)B;
    if (cA->score < cB->score) return -1;
    if (cA->score > cB->score) return 1;
    return 0;
}

/* ==================================================================
   2. PROPER DOUBLE COMPARISON (For qsort)
   ================================================================== */
// ALGO DESCRIPTION: A safe comparison function for floating-point numbers.
// Avoids the standard casting trap `return (int)(x - y)` which fails for decimals < 1.
// @@CHANGE_ME@@_FIELD: 'weight' might be 'distance', 'cost', or 'ratio' 
// depending on the greedy algorithm or graph tested.
typedef struct { double weight; } edge;
int compEdge(const void *e1, const void *e2) {
    double x = ((edge *)e1)->weight;
    double y = ((edge *)e2)->weight;
    return (x > y) - (x < y); // SAFE: Returns -1, 0, or 1
}

/* ==================================================================
   3. 2D ARRAYS (POINTERS TO POINTERS)
   ================================================================== */
void array_2d_example(int n) {
    // Allocation
    int **G = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) G[i] = calloc(n, sizeof(int)); // calloc = 0

    // Deep Copy
    int **G_copy = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        G_copy[i] = malloc(n * sizeof(int));
        memcpy(G_copy[i], G[i], n * sizeof(int)); 
    }
}

/* ==================================================================
   4. BITWISE SETS (For TSP DP)
   ================================================================== */
// ALGO DESCRIPTION: Uses integers as lightweight boolean arrays (sets).
// A 1 at the i-th bit means element 'i' is in the set. Essential for DP states.
// @@CHANGE_ME@@_VARS: Ensure the bitshift `(1 << i)` uses `1LL` if 'n' > 31 
// (e.g., `1LL << i`) to avoid overflow on long bitmasks.
void bitwise_example() {
    int i = 3;
    int S = 0;             // Empty set
    S = S | (1 << i);      // ADD city 'i'
    S = S & ~(1 << i);     // REMOVE city 'i'
    if (S & (1 << i)) { }  // CHECK if city 'i' is in set S
}

/* ==================================================================
   5. STANDARD DISTANCES
   ================================================================== */
typedef struct { double x, y; } point;
typedef struct { int i, j; } position;

void distances(point ptA, point ptB, position A, position B) {
    double dist_euclid = hypot(ptA.x - ptB.x, ptA.y - ptB.y);
    int dist_manhattan = abs(A.i - B.i) + abs(A.j - B.j);
    int dist_chebyshev = fmax(abs(A.i - B.i), abs(A.j - B.j));
}


=========================================
File: ./02_data_structs.c
=========================================
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


=========================================
File: ./03_graphs_search.c
=========================================
#include <stdlib.h>
#include <string.h>

// Dummies
typedef struct _config { int n; double cost; double score; struct _config* parent; } *config;
typedef struct { int n; int *deg; int **list; } graph;
double h1(config C); int is_marked(config C); int can_win(config S);
config move(config C, char m);
typedef struct _heap* heap; heap heap_create(int, void*); void heap_add(heap, void*); void* heap_pop(heap); int heap_empty(heap);

/* ==================================================================
   1. A* SEARCH ALGORITHM
   ================================================================== */
// ALGO DESCRIPTION: Heuristic-guided Best-First Search. Uses a priority queue 
// to explore the state space, expanding nodes with the lowest f = cost + heuristic.
// @@CHANGE_ME@@_VARS: 'config' is a dummy state. The TP might call it 'state', 'node', or 'board'.
// @@CHANGE_ME@@_MOVES: 'char moves[] = "bdgh"' is puzzle-specific. Change this 
// to an array of coordinate offsets (di, dj) if routing on a grid.
config solve_astar(config S, double (*heuristic)(config), void* fcmp_config) {
    if (!can_win(S)) return NULL;

    heap H = heap_create(100, fcmp_config);
    S->cost = 0; S->score = heuristic(S);
    heap_add(H, S);

    while (!heap_empty(H)) {
        config C = heap_pop(H);
        
        if (h1(C) == 0) return C; // GOAL REACHED
        if (is_marked(C)) continue; // Lazy deletion (already visited)

        char moves[] = "bdgh";
        for (int i = 0; i < 4; i++) {
            config V = move(C, moves[i]);
            if (V == NULL) continue; 
            
            V->cost = C->cost + 1; // Or + weight of edge
            V->score = V->cost + heuristic(V);
            V->parent = C;
            heap_add(H, V);
        }
    }
    return NULL;
}

/* ==================================================================
   2. KOSARAJU'S STRONGLY CONNECTED COMPONENTS
   Requires 'transpose_graph' from 02_data_structs.c
   ================================================================== */
// ALGO DESCRIPTION: Finds independent cyclic subnetworks. 
// Pass 1: DFS computes finishing times (post-order push to stack). 
// Pass 2: DFS explores transposed graph in reverse finishing order.
// @@CHANGE_ME@@_OUTPUT: Instead of returning `max_scc_size`, the TP might ask you to 
// assign component IDs. Pass an `int *scc_id` array and increment `id` per stack pop.
void kosaraju_dfs1(graph G, int u, int *visited, int *stack, int *top) {
    visited[u] = 1;
    for (int i = 0; i < G.deg[u]; i++) {
        if (!visited[G.list[u][i]]) kosaraju_dfs1(G, G.list[u][i], visited, stack, top);
    }
    stack[(*top)++] = u; // Push POST-order
}

void kosaraju_dfs2(graph G_rev, int u, int *visited, int *curr_size) {
    visited[u] = 1;
    (*curr_size)++;
    for (int i = 0; i < G_rev.deg[u]; i++) {
        if (!visited[G_rev.list[u][i]]) kosaraju_dfs2(G_rev, G_rev.list[u][i], visited, curr_size);
    }
}

int largest_scc(graph G, graph G_rev) {
    int *visited = calloc(G.n, sizeof(int));
    int *stack = malloc(G.n * sizeof(int));
    int top = 0;

    for (int i = 0; i < G.n; i++) 
        if (!visited[i]) kosaraju_dfs1(G, i, visited, stack, &top);

    memset(visited, 0, G.n * sizeof(int));
    int max_scc_size = 0;

    while (top > 0) {
        int u = stack[--top];
        if (!visited[u]) {
            int curr_size = 0;
            kosaraju_dfs2(G_rev, u, visited, &curr_size);
            if (curr_size > max_scc_size) max_scc_size = curr_size;
        }
    }
    return max_scc_size; 
}

/* ==================================================================
   3. GRID TRAVERSAL (4-way / 8-way)
   ================================================================== */
// ALGO DESCRIPTION: Generates neighboring coordinates safely without going out of bounds.
// @@CHANGE_ME@@_DIRS: If the TP asks for diagonal movement, switch to the 8-way arrays.
// If the grid uses (x, y) instead of (row, col), ensure bounds check `cols` for x and `rows` for y.
void grid_traversal(int rows, int cols, int i, int j, double **G) {
    int di[] = {-1, 1, 0, 0}; // Add {-1, -1, 1, 1} for 8-way
    int dj[] = {0, 0, -1, 1}; // Add {-1, 1, -1, 1} for 8-way

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
            // Safe to access G[ni][nj]
        }
    }
}


=========================================
File: ./04_algo_paradigms.c
=========================================
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* ==================================================================
   1. DIVIDE & CONQUER: Maximum Subarray (O(n log n))
   ================================================================== */
// ALGO DESCRIPTION: Recursively halves the array to find the contiguous 
// subarray with the highest sum. Checks left half, right half, and the cross-section.
// @@CHANGE_ME@@_VARS: 'arr' might need to be 'double*' if the TP uses float values.
// Update the `-2147483648` (INT_MIN) sentinel to `-1e9` if switching to doubles.
int max_crossing(int *arr, int low, int mid, int high) {
    int left_sum = -2147483648, sum = 0;
    for (int i = mid; i >= low; i--) { sum += arr[i]; if (sum > left_sum) left_sum = sum; }
    
    int right_sum = -2147483648; sum = 0;
    for (int i = mid + 1; i <= high; i++) { sum += arr[i]; if (sum > right_sum) right_sum = sum; }
    
    return left_sum + right_sum;
}

int max_subarray(int *arr, int low, int high) {
    if (low == high) return arr[low];
    int mid = (low + high) / 2;
    int ml = max_subarray(arr, low, mid);
    int mr = max_subarray(arr, mid + 1, high);
    int mc = max_crossing(arr, low, mid, high);
    return MAX(MAX(ml, mr), mc);
}

/* ==================================================================
   2. DYNAMIC PROGRAMMING 1: Ribbon Cutting (1D Array)
   ================================================================== */
// ALGO DESCRIPTION: Bottom-up 1D Dynamic Programming. Builds optimal answers 
// from smaller subproblems to find max pieces a ribbon can be cut into.
// @@CHANGE_ME@@_VARS: If the TP gives an array of options (like knapsack weights) 
// instead of specific integers a,b,c, replace the 3 if-statements with a nested `for` loop.
int ribbon_cutting(int n, int a, int b, int c) {
    int *dp = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) dp[i] = -2147483648; // -Infinity
    dp[0] = 0; 

    for (int i = 1; i <= n; i++) {
        if (i >= a && dp[i - a] != -2147483648) dp[i] = MAX(dp[i], dp[i - a] + 1);
        if (i >= b && dp[i - b] != -2147483648) dp[i] = MAX(dp[i], dp[i - b] + 1);
        if (i >= c && dp[i - c] != -2147483648) dp[i] = MAX(dp[i], dp[i - c] + 1);
    }
    return dp[n]; 
}

/* ==================================================================
   3. GREEDY: Set Cover
   ================================================================== */
// ALGO DESCRIPTION: Iteratively selects the subset that covers the most 
// remaining uncovered elements until all elements are covered.
// @@CHANGE_ME@@_INPUT: TPs represent sets as a 2D boolean matrix 
// `grid[set_id][element_id]` instead of a ragged array. Modify the inner 
// `if (uncovered[sets[i][j]] == 1)` loop to check `if (grid[i][j] == 1 && uncovered[j])`.
int greedy_set_cover(int N, int num_sets, int **sets, int *sizes) {
    int *uncovered = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) uncovered[i] = 1; 
    
    int *used_sets = calloc(num_sets, sizeof(int)); 
    int elements_left = N, sets_picked = 0;
    
    while (elements_left > 0) {
        int best_set = -1, max_covered = 0;
        
        for (int i = 0; i < num_sets; i++) {
            if (used_sets[i]) continue; 
            int count = 0;
            for (int j = 0; j < sizes[i]; j++) {
                if (uncovered[sets[i][j]] == 1) count++;
            }
            if (count > max_covered) { max_covered = count; best_set = i; }
        }
        
        if (best_set == -1) return -1; // Impossible to cover all
        
        used_sets[best_set] = 1;
        sets_picked++;
        for (int j = 0; j < sizes[best_set]; j++) {
            if (uncovered[sets[best_set][j]] == 1) {
                uncovered[sets[best_set][j]] = 0;
                elements_left--;
            }
        }
    }
    return sets_picked;
}

/* ==================================================================
   4. LOCAL SEARCH: TSP 2-Opt Flip
   ================================================================== */
// ALGO DESCRIPTION: Local Search heuristic for Traveling Salesperson. Uncrosses 
// a self-intersecting path by swapping two edges and reversing the sequence between them.
// @@CHANGE_ME@@_DISTANCE: Replace `dist_pt` with the actual distance matrix `G[v1][v2]` 
// or euclidean distance logic depending on the TP.
// Reverse sub-array
void reverse(int *T, int p, int q) {
    while (p < q) { int tmp = T[p]; T[p] = T[q]; T[q] = tmp; p++; q--; }
}

// Calculate gain of swapping edges
double dist_pt(int a, int b); // Dummy
double gain(int *V, int n, int *P, int i, int j) {
    int v1 = P[i], v2 = P[(i + 1) % n], v3 = P[j], v4 = P[(j + 1) % n];
    double old_dist = dist_pt(V[v1], V[v2]) + dist_pt(V[v3], V[v4]);
    double new_dist = dist_pt(V[v1], V[v3]) + dist_pt(V[v2], V[v4]); 
    return old_dist - new_dist; // > 0 means improvement
}

/* ==================================================================
   5. HASHING / RANDOM: Cantor Pairing & Fisher-Yates Shuffle
   ================================================================== */
int cantor_map(int i, int j) {
    return j + ((i + j) * (i + j + 1)) / 2;
}

void random_permutation(int *P, int k) {
    for (int i = 0; i < k; i++) P[i] = i;
    for (int i = k - 1; i > 0; i--) {
        int j = random() % (i + 1);
        int tmp = P[i]; P[i] = P[j]; P[j] = tmp;
    }
}




