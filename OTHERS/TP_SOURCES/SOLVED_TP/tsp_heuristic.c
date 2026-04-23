#include "tools.h"
#include "tsp_brute_force.h"
#include <float.h>

void reverse(int *T, int p, int q) {
    while (p < q) {
        int tmp = T[p];
        T[p] = T[q];
        T[q] = tmp;
        p++; q--;
    }
}

double first_flip(point *V, int n, int *P) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 2; j < n; j++) {
            if (i == 0 && j == n - 1) continue; 
            
            int v1 = P[i], v2 = P[i + 1];
            int v3 = P[j], v4 = P[(j + 1) % n];
            
            double old_dist = dist(V[v1], V[v2]) + dist(V[v3], V[v4]);
            double new_dist = dist(V[v1], V[v3]) + dist(V[v2], V[v4]);
            
            if (old_dist - new_dist > 1e-9) { 
                reverse(P, i + 1, j);
                return old_dist - new_dist;
            }
        }
    }
    return 0.0;
}

double tsp_flip(point *V, int n, int *P) {
    for (int i = 0; i < n; i++) P[i] = i;
    double gain;
    do {
        gain = first_flip(V, n, P);
    } while (gain > 0);
    return value(V, n, P);
}

double tsp_greedy(point *V, int n, int *P) {
    int *visited = calloc(n, sizeof(int));
    P[0] = 0;
    visited[0] = 1;
    
    for (int i = 1; i < n; i++) {
        int best_next = -1;
        double min_dist = DBL_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                double d = dist(V[P[i - 1]], V[j]);
                if (d < min_dist) {
                    min_dist = d;
                    best_next = j;
                }
            }
        }
        P[i] = best_next;
        visited[best_next] = 1;
    }
    free(visited);
    return value(V, n, P);
}