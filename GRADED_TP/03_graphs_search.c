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
