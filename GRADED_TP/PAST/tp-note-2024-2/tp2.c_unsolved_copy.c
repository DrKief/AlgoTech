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
  position r = p;
  ;
  ;
  ;
  return r;
}

// Algorithme naïf en O(k^2) pour la grille G[A..B] de taille k x k.
// Notez que k = (B.i - A.i + 1).
//
// On suppose que k>=1, que A et B ne sont pas sur le bord de G (ils ont donc
// chacun 8 voisins), et que G a au moins un maximum local situé dans G[A..B].
// Vous n'avez pas à vérifier ces conditions.
position algo_naif(grid G, position A, position B) {
  position r = {0, 0};
  ;
  ;
  ;
  return r;
}

// Algorithme du gradient pour la grille complète G de taille n x n à partir de
// son "centre". Cet algorithme peut aussi être en O(n^2).
//
// On suppose que n >= 3.
position algo_grad(grid G, int n) {
  position r = {0, 0};
  ;
  ;
  ;
  return r;
}

// Retourne une position contenant une valeur maximale dans la grille
position position_max_cadre(grid G, position A, position B) {
  position r = {0, 0};
  ;
  ;
  ;
  return r;
}

// Algorithme récursif en O(n). On fait les mêmes hypothèses que pour
// algo_naif().
position algo_rec(grid G, position A, position B) {
  position r = {0, 0};
  ;
  ;
  ;
  return r;
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
