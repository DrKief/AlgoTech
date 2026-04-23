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
