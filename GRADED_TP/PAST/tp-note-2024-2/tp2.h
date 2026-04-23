#ifndef TP2_H
#define TP2_H

// format d'affichage des valeurs pour printf/scanf
#define FORM "%.08lf"


typedef struct{ // couple d'indices dans une grille
  int i,j;
} position;


typedef double** grid; // une grille de valeurs


// Affiche la position solution P et les valeurs autour.
extern void print_resultat(grid G, int n, position P);


// Alloue une grille carrée n x n.
// Renvoie NULL en cas de problème.
extern grid grid_alloc(int n);


// Lit une grille carrée de n x n valeurs et renvoie n.
// S'arrête (exit) par une erreur si problème.
extern grid grid_read(char *file, int *n);

//Génère une grille aléatoire de  n>=3 valeurs dans [0,1[, tirées uniformément et indépendamment.
extern grid grid_genrandom(int n);

// Génère une grille aléatoire de n>=3 valeurs dans [0,1[ dont le bord
// est à 0. Renvoie NULL en cas de problème. Le principe est le
// suivant: on choisit une position P aléatoire de la grille qui n'est
// pas sur le bord, puis pour chaque position on calcule une valeur
// dans ]0,1[ proportionnelle à la distance à P avec une petite
// pertubation aléatoire. En principe le maximum local est unique, et
// sa position est précisément P.
extern grid grid_gen1(int n);


// Variante de grid_random() où l'algorithme du gradient doit prendre
// un temps en O(n^2). Toute les valeurs sont à 0 et on creuse
// progressivement un fossé du center en spirale (avec un espacement
// entre deux bras de la spirale) jusqu'à toucher le bord.
extern grid grid_gen2(int n);


// Renvoie le temps écoulé entre deux appels consécutifs à la
// fonction, i étant le numéro du chronomètre (i=0..CHRONOMAX-1).
extern char *TopChrono(int i);

#endif
