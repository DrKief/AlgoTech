#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "tp2.h"

// Renvoie une position voisine de p = (i,j) de valeur strictement plus grande
// que G[i][j] si elle existe, ou renvoie (i,j) sinon. Donc voisin_max(G,p) = p
// si et seulement si p est un maximum local.
//
// On suppose que les positions voisines de p existent bel et bien, c'est-à-dire
// que p n'est pas sur le bord de G.
position voisin_max(grid G, position p) {
  // Check 3x3 neighborhood for strictly greater value.
  position r = p;
  double max_val = G[p.i][p.j];
  
  for (int i = p.i - 1; i <= p.i + 1; i++) {
    for (int j = p.j - 1; j <= p.j + 1; j++) {
      if (G[i][j] > max_val) {
        max_val = G[i][j];
        r.i = i;
        r.j = j;
      }
    }
  }
  return r; // Returns p if it's a local maximum.
}

// Algorithme naïf en O(k^2) pour la grille G[A..B] de taille k x k.
// Notez que k = (B.i - A.i + 1).
//
// On suppose que k>=1, que A et B ne sont pas sur le bord de G (ils ont donc
// chacun 8 voisins), et que G a au moins un maximum local situé dans G[A..B].
// Vous n'avez pas à vérifier ces conditions.
position algo_naif(grid G, position A, position B) {
  // Sequential traversal to find local max using voisin_max.
  for (int i = A.i; i <= B.i; i++) {
    for (int j = A.j; j <= B.j; j++) {
      position p = {i, j};
      position v = voisin_max(G, p);
      if (v.i == p.i && v.j == p.j) {
        return p;
      }
    }
  }
  return A; // Fallback, though max exists by constraints.
}

// Algorithme du gradient pour la grille complète G de taille n x n à partir de
// son "centre". Cet algorithme peut aussi être en O(n^2).
//
// On suppose que n >= 3.
position algo_grad(grid G, int n) {
  // Start at center, shift to highest neighbor until peak reached.
  position p = {n / 2, n / 2};
  while (1) {
    position v = voisin_max(G, p);
    if (v.i == p.i && v.j == p.j) {
      return p;
    }
    p = v;
  }
}

// Retourne une position contenant une valeur maximale dans la grille
position position_max_cadre(grid G, position A, position B) {
  // Analyze boundary elements (cadre) and cross.
  position r = A;
  double max_val = -1.0;
  
  int k = B.i - A.i + 1;
  int mid_i = A.i + k / 2;
  int mid_j = A.j + k / 2;

  #define UPDATE_MAX(r_i, r_j) \
    do { \
      if (G[(r_i)][(r_j)] > max_val) { \
        max_val = G[(r_i)][(r_j)]; \
        r.i = (r_i); \
        r.j = (r_j); \
      } \
    } while(0)

  // Scan rows (top, bottom, horizontal median, extension if k is even)
  for (int j = A.j; j <= B.j; j++) {
    UPDATE_MAX(A.i, j);
    UPDATE_MAX(B.i, j);
    UPDATE_MAX(mid_i, j);
    if (k % 2 == 0) UPDATE_MAX(A.i + 1, j);
  }

  // Scan columns (left, right, vertical median, extension if k is even)
  for (int i = A.i; i <= B.i; i++) {
    UPDATE_MAX(i, A.j);
    UPDATE_MAX(i, B.j);
    UPDATE_MAX(i, mid_j);
    if (k % 2 == 0) UPDATE_MAX(i, A.j + 1);
  }
  
  #undef UPDATE_MAX

  return r;
}

// Algorithme récursif en O(n). On fait les mêmes hypothèses que pour
// algo_naif().
position algo_rec(grid G, position A, position B) {
  int k = B.i - A.i + 1;
  
  // 1. Base case: size 4 or less, use naive.
  if (k <= 4) {
    return algo_naif(G, A, B);
  }

  // 2. Find maximum on the cadre/cross.
  position m = position_max_cadre(G, A, B);
  
  // 3. Check if it's a local maximum.
  position v = voisin_max(G, m);
  if (v.i == m.i && v.j == m.j) {
    return m;
  }

  // 4. Resolve boundaries for recursive descent based on greater neighbor.
  int mid_i = A.i + k / 2;
  int mid_j = A.j + k / 2;
  position a, b;

  if (v.i < mid_i) { // Top half
    a.i = (k % 2 == 0) ? A.i + 2 : A.i + 1;
    b.i = mid_i - 1;
  } else {           // Bottom half
    a.i = mid_i + 1;
    b.i = B.i - 1;
  }

  if (v.j < mid_j) { // Left half
    a.j = (k % 2 == 0) ? A.j + 2 : A.j + 1;
    b.j = mid_j - 1;
  } else {           // Right half
    a.j = mid_j + 1;
    b.j = B.j - 1;
  }

  // 5. Recursive call.
  return algo_rec(G, a, b);
}

int main(int argc, char *argv[]) {
  // Si vous modifiez le main(), faite attention que le correcteur
  // puisse, dans tous les cas, tester votre programme à travers la
  // ligne de commande comme défini dans l'usage, qui en particulier,
  // appelle le bon algorithme. Donc, sauf cas particulier, les tests
  // et débuggages sont plutôt à mettre directement dans vos fonctions
  // et pas dans le main().

  srandom(time(NULL));

  //
  // Usage
  //
  if (argc != 3) {
    printf("\n");
    printf(" Usage: %s [gen0|gen1|gen2] [number]\n", argv[0]);
    printf("        %s [naif|grad|rec] [file]\n", argv[0]);
    printf("\n");
    exit(1);
  }

  //
  // Génération de grilles
  //
  if (!strncmp(argv[1], "gen", 3)) {
    int n = atoi(argv[2]);
    if ((!isdigit(argv[2][0])) || (n < 3)) {
      printf("Parameter must be a number n>=3.\n");
      exit(1);
    }
    grid G = NULL;
    if (!strcmp(argv[1], "gen0"))
      G = grid_genrandom(n);
    if (!strcmp(argv[1], "gen1"))
      G = grid_gen1(n);
    if (!strcmp(argv[1], "gen2"))
      G = grid_gen2(n);
    if (G == NULL) {
      printf("Error for grid generating, or unknown generating method.\n");
      exit(1);
    }
    printf("%i\n", n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        printf(FORM " ", G[i][j]);
      printf("\n");
    }
    return 0;
  }

  //
  // Exécution de l'algorithme
  //
  int n;
  position r = {-1, 0};
  TopChrono(0);
  grid G     = grid_read(argv[2], &n);
  if (n < 3) {
    printf("Need n>=3.\n");
    exit(1);
  }
  printf("loading time=%s\n", TopChrono(0));

  position A = {1, 1};
  position B = {n - 2, n - 2};

  if (!strcmp(argv[1], "naif"))
    r = algo_naif(G, A, B);
  if (!strcmp(argv[1], "grad"))
    r = algo_grad(G, n);
  if (!strcmp(argv[1], "rec"))
    r = algo_rec(G, A, B);
  if (r.i < 0) {
    printf("Unknown algorithm.\n");
    exit(1);
  }

  print_resultat(G, n, r);
  printf("\ncomputing time=%s\n", TopChrono(0));
  TopChrono(-1);
  for (int i = 0; i < n; i++)
    free(G[i]);
  free(G);
  return 0;
}
