#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* ==================================================================
   1. DIVIDE & CONQUER: Maximum Subarray (O(n log n))
   ================================================================== */
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
