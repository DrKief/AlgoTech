//
// TAP - TP NOTE 2021
// HEURISTIQUE CHEAPEST INSERTION
//

#include "tp.h"

// Constantes à utiliser dans la fonction tsp_cheapest pour l'animation
#define ANIMATION 1        // Animation on/off pour algo cheapest.
#define ANIMATION_DELAY 2  // Pause, en secondes

////////////////////////
// FONCTIONS FOURNIES //
////////////////////////

// Distance Euclidienne
double dist(point A, point B);

// Valeur d'une tournée P de taille n.
double value(point *V, int n, int *P);

// Affichage d'un tableau d'entiers P de n cases.
void print_tab(int *P, int n);

//////////////////////////////////////////
// FONCTIONS A COMPLETER A PARTIR D'ICI //
//////////////////////////////////////////

// Exercice 1
void nearest_points(point *V, int n, int *first_ptr, int *second_ptr) {
    return;
}

// Exercice 2
void init_tour(point *V, int n, int *P) {
   return;
}

// Exercice 5
double score(point *V, int m, int *P, int i, int *pred_ptr) {
    return 0.0;
}

// Exercice 6
int new_point(point *V, int n, int m, int *P, int *pred_ptr) {
    return 0;
}

// Exercice 7
void rotate_right(int *P, int p, int q) {
    return;
}

// Exercice 8
double tsp_cheapest(point *V, int n, int *P) {
    // Pour visualiser les points et la tournée obtenue à chaque insertion,
    // ajouter dans votre boucle d'insertion le code suivant :
    //        if (running && ANIMATION) {
    //            drawPartialTour(V, n, P, m);
    //            sleep(ANIMATION_DELAY);
    //        }
    return 0;
}

// Exercice 10
double gain(point *V, int n, int *P, int i, int j) {
    return 0;
}

// Exercice 11
double first_flip25(point *V, int n, int *P) {
    return 0;
}

// Exercice 12
double tsp_flip25(point *V, int n, int *P) {
    return 0;
}
