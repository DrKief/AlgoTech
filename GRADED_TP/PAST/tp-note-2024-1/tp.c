#include "tp.h"
#include "htable.h"

//
// Paire de Points les Plus Proches
//
// Vous avez 5 fonctions à compléter: dist(), pppp_naive(), map(),
// pppp_random() et pppp_random2(). N'attendez pas la dernière minute pour
// les compiler et les tester.
//
// Chaque fonction du type pppp_xxx() doit renvoyer le couple {i,j}
// d'indices des deux points les plus proches.
//
// -> la structure "point" est définie dans "tools.h"
// -> la structure "couple" est définie dans "tp.h"
//

// Calculate Euclidean distance between points A and B
double dist(point A, point B) {
  double dx = A.x - B.x;
  double dy = A.y - B.y;
  return sqrt(dx * dx + dy * dy);
}

// O(n^2) brute force minimum distance search
couple pppp_naive(point *V, int n) {
  couple result = {-1, -1};
  if (n < 2) return result;
  
  double min_d = INFINITY;
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double d = dist(V[i], V[j]);
      if (d < min_d) {
        min_d = d;
        result.i = i;
        result.j = j;
      }
    }
  }
  return result;
}

// clang-format off

// map: N^2 -> N définit pour toute paire d'entiers (i,j) un entier
// unique. Il faut i,j >= 0. Il correspond à la somme des longueurs
// des diagonales montantes de la forme (t,0) -> (0,t), partant de
// (0,0), et jusqu'à atteindre le point (i,j) sans le compter. La
// longueur de la diagonale est le nombre de points qu'elle contient.
//
//       | | | | | |
//     4 .-.-.-.-.-.-
//       | | | | | |
//     3 o-.-.-.-.-.-
//       |\| | | | |
//     2 o-o-.-.-.-.-
//       |\|\| | | |
// j = 1 o-o-o-X-.-.-    Ex: map(i,j) = map(3,1) = (#o) = 11
//       |\|\|\|\| |
//     0 o-o-o-o-o-.-
//       0 1 2 3 4 5
//             i
//

// clang-format on

// Closed-form formula mapping 2D coord to 1D integer
int map(int i, int j) {
  if (i < 0 || j < 0) return -1;
  int sum = i + j;
  return j + (sum * (sum + 1)) / 2;
}

// Point de vigilance. Attention à ce que les cellules voisines
// tombent dans le premier quadrant (i,j >= 0), sinon map(i,j) ne
// marchera pas.
// Expected O(n) randomized algo with hash table grid
couple pppp_random(point *V, int n) {
  couple result = {0, 1};
  if (n < 2) return result;
  
  double dmin = dist(V[0], V[1]);
  htable T = ht_create();
  
restart: ;
  double delta = dmin / sqrt(2.0);
  ht_reset(T);
  
  for (int t = 0; t < n; t++) {
    int ix = (int)(V[t].x / delta);
    int iy = (int)(V[t].y / delta);
    
    int best_q = -1;
    double best_d = dmin;
    
    // Check the 25 neighboring cells
    for (int a = -2; a <= 2; a++) {
      for (int b = -2; b <= 2; b++) {
        int nx = ix + a;
        int ny = iy + b;
        
        if (nx < 0 || ny < 0) continue;
        
        int h = map(nx, ny);
        point *ptr = (point *)ht_read(T, h);
        
        if (ptr != NULL) {
          int q = ptr - V; // Pointer arithmetic to recover index
          double d = dist(V[t], V[q]);
          if (d < best_d) {
            best_d = d;
            best_q = q;
          }
        }
      }
    }
    
    // Closer point found, update dmin and restart
    if (best_q != -1) {
      dmin = best_d;
      result.i = best_q;
      result.j = t;
      goto restart;
    }
    
    ht_write(T, map(ix, iy), &V[t]);
  }
  
  ht_free(T);
  return result;
}

// Version optimisée de pppp_random() comportant les deux extensions
// suivantes:
//
// . Il est possible de maintenir l'indice du dernier échec, disons tf
// (initialisée à -1), de sorte que les instructions (3b) et (3c)
// doivent être exécutée seulement si t>tf. Faire attention, lors
// d'un échec, de bien chercher le point q le plus proche dans le
// voisinage, sinon il y aura des échecs plusieurs fois au même
// indice.
//
// . Optimisez le nombre de cellules voisines en passant de 25 à 21
// cellules à explorer. Comparez.
//
// Optimized expected O(n) skipping t <= tf and checking 21 cells
couple pppp_random2(point *V, int n) {
  couple result = {0, 1};
  if (n < 2) return result;
  
  double dmin = dist(V[0], V[1]);
  htable T = ht_create();
  int tf = -1; // Failure index to skip unnecessary checks
  
restart: ;
  double delta = dmin / sqrt(2.0);
  ht_reset(T);
  
  for (int t = 0; t < n; t++) {
    int ix = (int)(V[t].x / delta);
    int iy = (int)(V[t].y / delta);
    
    if (t > tf) {
      int best_q = -1;
      double best_d = dmin;
      
      // Check 21 neighboring cells
      for (int a = -2; a <= 2; a++) {
        for (int b = -2; b <= 2; b++) {
          if (abs(a) == 2 && abs(b) == 2) continue; // Skip the 4 corners
          
          int nx = ix + a;
          int ny = iy + b;
          if (nx < 0 || ny < 0) continue;
          
          int h = map(nx, ny);
          point *ptr = (point *)ht_read(T, h);
          
          if (ptr != NULL) {
            int q = ptr - V;
            double d = dist(V[t], V[q]);
            if (d < best_d) {
              best_d = d;
              best_q = q;
            }
          }
        }
      }
      
      if (best_q != -1) {
        dmin = best_d;
        result.i = best_q;
        result.j = t;
        tf = t; // Update the failure index
        goto restart;
      }
    }
    
    ht_write(T, map(ix, iy), &V[t]);
  }
  
  ht_free(T);
  return result;
}
