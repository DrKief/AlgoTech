#include "tools.h"

double dist(point A, point B) {
    return hypot(A.x - B.x, A.y - B.y);
}

double value(point *V, int n, int *P) {
    double sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += dist(V[P[i]], V[P[i + 1]]);
    }
    sum += dist(V[P[n - 1]], V[P[0]]); // Return to start
    return sum;
}

double tsp_brute_force(point *V, int n, int *Q) {
    int *P = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) P[i] = i;

    double min_val = -1;
    do {
        double current_val = value(V, n, P);
        if (min_val < 0 || current_val < min_val) {
            min_val = current_val;
            for (int i = 0; i < n; i++) Q[i] = P[i];
        }
    } while (NextPermutation(P, n) && running);

    free(P);
    return min_val;
}

void MaxPermutation(int *P, int n, int k) {
    // Reverses the suffix of the array from index k to n-1
    // This jumps to the lexicographically largest permutation sharing the same prefix of size k.
    int p = k, q = n - 1;
    while (p < q) {
        int tmp = P[p];
        P[p] = P[q];
        P[q] = tmp;
        p++;
        q--;
    }
}

double value_opt(point *V, int n, int *P, double w) {
    double sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += dist(V[P[i]], V[P[i + 1]]);
        // If partial tour + distance back to start exceeds current best w
        if (sum + dist(V[P[i + 1]], V[P[0]]) >= w) {
            return -(i + 1); // Return negative of the edge count where it exceeded
        }
    }
    sum += dist(V[P[n - 1]], V[P[0]]);
    if (sum >= w) return -n;
    
    return sum;
}

double tsp_brute_force_opt(point *V, int n, int *Q) {
    int *P = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) P[i] = i;

    double min_val = -1;
    do {
        if (min_val < 0) {
            min_val = value(V, n, P);
            for (int i = 0; i < n; i++) Q[i] = P[i];
            continue;
        }

        double current_val = value_opt(V, n, P, min_val);
        
        if (current_val < 0) {
            int k = -current_val;
            MaxPermutation(P, n, k); // Skip useless permutations
        } else if (current_val < min_val) {
            min_val = current_val;
            for (int i = 0; i < n; i++) Q[i] = P[i];
        }
    } while (NextPermutation(P + 1, n - 1) && running); // P+1, n-1 fixes the first element

    free(P);
    return min_val;
}