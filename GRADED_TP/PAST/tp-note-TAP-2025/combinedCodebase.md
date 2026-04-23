=========================================
Project Path: /home/lucas/Documents/S6/AlgoTech/GRADED_TP/PAST/tp-note-TAP-2025
Project Directory Structure
=========================================
```
.
├── Makefile
├── misc.h
├── misc.o
├── sujet_uk.pdf
├── taquin.c
├── taquin.h
└── translation_taquin_dot_c
```


=========================================
here how this was made :
=========================================
```bash
#!/bin/bash

OUTPUT="combinedCodebase.md"
SCRIPT_SOURCE=$(realpath "$0")

echo "Running code combiner in: $(pwd)"

if [ -f "$OUTPUT" ]; then
    rm "$OUTPUT"
fi

{
    echo "========================================="
    echo "Project Path: $(pwd)"
    echo "Project Directory Structure"
    echo "========================================="
    echo '```'
    if command -v tree &> /dev/null; then
        # Added gitignore directories (logs, dist, .idea, etc.) to the tree exclusion list
        tree -a -I ".git|node_modules|build|bin|target|venv|logs|dist|dist-ssr|.vscode|.idea|nbproject|nbbuild|nbdist|.nb-gradle|.settings|.apt_generated|.sts4-cache|$OUTPUT" --noreport
    else
        echo "Error: 'tree' command not installed."
    fi
    echo '```'
    echo -e "\n"

    echo "========================================="
    echo "here how this was made :"
    echo "========================================="
    echo '```bash'
    cat "$SCRIPT_SOURCE"
    echo '```'
    echo -e "\n"

    EXCLUDES=(
        # --- 1. Version Control & Script Output ---
        -not -path '*/.git/*'
        -not -name "diff.md"
        -not -name "$OUTPUT"

        # --- 2. Build & Dependency Directories ---
        -not -path '*/node_modules/*'
        -not -path '*/build/*'
        -not -path '*/target/*'
        -not -path '*/dist/*'
        -not -path '*/dist-ssr/*'
        -not -path '*/bin/*'
        -not -path '*/venv/*'

        # --- 3. Package Manager & Wrappers ---
        -not -name "package-lock.json"
        -not -name "mvnw"
        -not -name "mvnw.cmd"
        -not -path "*/.mvn/*"

        # --- 4. Binaries, Archives & Compiled Code ---
        -not -name "*.exe"
        -not -name "*.jar"
        -not -name "*.class"
        -not -name "*.o"
        -not -name "*.a"
        -not -name "*.out"

        # --- 5. Media & Images ---
        -not -name "*.pdf"
        -not -name "*.ico"
        -not -name "*.png"
        -not -name "*.jpg"
        -not -name "*.jpeg"
        -not -name "*.svg"

        # --- 6. Logs & Debugging ---
        -not -path "*/logs/*"
        -not -name "*.log"
        -not -name "npm-debug.log*"
        -not -name "yarn-debug.log*"
        -not -name "yarn-error.log*"
        -not -name "pnpm-debug.log*"
        -not -name "lerna-debug.log*"
        -not -name "hs_err_pid*"
        -not -name "replay_pid*"

        # --- 7. IDE, OS & Editor Files ---
        -not -name ".DS_Store"
        -not -name ".DS_Store?"
        -not -name "._*"
        -not -name ".Spotlight-V100"
        -not -name ".Trashes"
        -not -name "ehthumbs.db"
        -not -name "Thumbs.db"
        -not \( -path "*/.vscode/*" -a -not -name "extensions.json" \)
        -not -path "*/.idea/*"
        -not -path "*/.settings/*"
        -not -path "*/.apt_generated/*"
        -not -path "*/.sts4-cache/*"
        -not -path "*/nbproject/private/*"
        -not -path "*/nbbuild/*"
        -not -path "*/nbdist/*"
        -not -path "*/.nb-gradle/*"
        -not -name ".classpath"
        -not -name ".factorypath"
        -not -name ".project"
        -not -name ".springBeans"
        -not -name "*.iws"
        -not -name "*.iml"
        -not -name "*.ipr"
        -not -name "*.suo"
        -not -name "*.ntvs*"
        -not -name "*.njsproj"
        -not -name "*.sln"
        -not -name "*.sw?"
        -not -name "*.local"

        # --- 8. OCaml / Language Specific Temp Files ---
        -not -path "*/_build/*"
        -not -path "*/.merlin-conf/*"
        -not -path "*/.*.objs/*"
        -not -name "*_generated.ml"
        -not -name "*.cmly"
        -not -name "*.conflicts"
        -not -name "*.automaton"
        -not -name "*.dot"
        -not -name "*.cmi"
        -not -name "*.cmo"
        -not -name "*.cmt"
        -not -name "*.cmti"
        -not -name "*.cmx"
        -not -name "*.cma"
        -not -name "*.cmxa"
        -not -name "*.cmxs"
        -not -name "*.ml-gen"
        -not -name "*.all-deps"
        -not -name "*.d"
        -not -name "*.mock"
        -not -name "*.inferred"
        -not -name "Cmly.ml"

        # --- 9. Project Specific Exclusions ---
        -not -path "*/mini_ml/examples/*"
        -not -path "*/models/*"
        -not -path "*/install/*"
        -not -path "*/programs/*"
        -not -name "HELP.md"
        -not \( -name ".env*" -a -not -name ".env.example" \)
    )

    find . -type f "${EXCLUDES[@]}" \
        -exec grep -Iq . {} \; \
        -print0 | while IFS= read -r -d '' file; do
            echo "========================================="
            echo "File: $file"
            echo "========================================="
            cat "$file"
            echo -e "\n"
        done

} > "$OUTPUT"

echo "Success! All code combined into: $(pwd)/$OUTPUT"
```


=========================================
File: ./taquin.h
=========================================
#ifndef TAQUIN_H_
#define TAQUIN_H_

typedef struct _config *config;

config new_config(int n);

config new_config(int n);

config copy_config(config C);

void set_zero(config C);

config move(config C, char m);

void random_permutation(int *P, int k);

#endif // TAQUIN_H_


=========================================
File: ./taquin.c
=========================================
/*

CONSIGNES:

- Commencez par lire le sujet(.pdf) ! Compiler simplement avec make.

- C'est une épreuve individuelle. Toute communication avec autrui est
  interdite. Les IA et assistants de programmation sont interdits. Les
  connexions sortantes de UB et entrantes depuis l'extérieur vers votre compte
  sont interdites (elles sont enregistrées et seront vérifiées après l'épreuve).

- Page Moodle de récupération des sources et soumission du fichier taquin.c :

     https://moodle.u-bordeaux.fr/course/view.php?id=6930#section-1

- Ne changez pas l'ordre des fonctions de taquin.c. Ne modifiez pas misc.h.

- Lisez le type config de misc.h. Il désigne un pointeur vers une structure.

- Complétez/codez les fonctions incomplètes, à savoir :

  - config copy_config(config C)
  - void set_zero(config C)
  - config move(config C, char m)
  - void random_permutation(int *P, int k)
  - int fcmp_config(const void *X, const void *Y)
  - int h1(config X)
  - int h2(config X)
  - int h3(config X) [EN BONUS]
  - config solve(config S, heuristic h)

  Une description de chaque fonction est fournie avant son squelette (que vous
  devez compléter). Certaines fonctions sont fournies. Vous n'avez pas besoin de
  les lire, sauf éventuellement pour new_config() (qui est la seule fonction
  fournie dans ce fichier, les autres sont décrites dans misc.h).

- Vous pouvez modifier la fonction main() pour vos propres tests.

- Avant de soumettre sur la page Moodle, assurez-vous que :

  - Les instructions de débugage (printf par exemple) de vos fonctions ont été
    supprimées ou commentées.

  - Votre code compile, même s'il ne fonctionne pas normalement, sans erreur et
    avec le moins de warnings possible.

  CONSEILS:

  - Testez chaque fonction AU FUR ET À MESURE, progressivement, sans attendre la
    dernière minute pour compiler.

  - Afin de simplifier, on ne vous demande pas de libérer la mémoire allouée.
    Votre code pourra comporter des fuites mémoires (c'est le cas pour le code
    qui vous est proposé).

*/

#include "misc.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Crée une configuration n x n où toutes les cases sont à zéro. Tous les champs
// sont initialisés. On supposera que n > 0 (ce n'est donc pas à la fonction de
// gérer cette condition, mais à l'appelant de s'en assurer).
//
// [VOUS N'AVEZ PAS À LA CODER]
//
config new_config(int n) {
    config R = malloc(sizeof(*R));
    R->n     = n;
    R->G     = malloc(n * sizeof(*(R->G)));
    for (int i = 0; i < n; i++)
        R->G[i] = calloc(n, sizeof(int));
    R->i0 = R->j0 = 0;
    R->cost       = 0;
    R->score      = -1; // pour affichage intelligent avec print_config()
    R->parent     = NULL;
    return R;
}

// Crée une copie de la configuration C, supposée non NULL. Vous pouvez
// utiliser la fonction new_config ci-dessus. Copiez bien tous les
// champs.
//
// Attention : dans la copie C_copy, il n'est pas suffisant d'affecter C->G à
// C_copy->G car on veut *copier* les cases du tableau.
//
// [COMPLÉTEZ CETTE FONCTION]
//
config copy_config(config C) {
    ;
    ;
    ;
    return NULL;
}

// Trouve les coordonnées i,j de la case C->G[i][j] qui vaut 0,
// et affecte i à C->i0 et j à C->j0. On suppose C non NULL, et
// que C->G contient une unique valeur 0.
//
// [COMPLÉTEZ CETTE FONCTION]
//
void set_zero(config C) {
    ;
    ;
    ;
    return;
}

////////////////////////////////////////////////////////////////////////////////
// Dans la suite, on parle de "voisine" d'une configuration. //
//                                                                            //
// On travaille dans le graphe suivant (auquel on appliquera A* dans solve())://
// - Les sommets sont les configurations.                                     //
// - Il y a une arête C->C' si on peut aller de C en C' par un mouvement.     //
//   On dit dans ce cas que C' est une configuration voisine de C.            //
////////////////////////////////////////////////////////////////////////////////
//
//
//

//
//
//
// Renvoie la configuration voisine de C où le déplacement m a été effectué. Si
// le déplacement n'est pas possible, la fonction renvoie NULL. Dans tous les
// cas, C n'est pas modifiée (une nouvelle configuration est renvoyée).
//
// On supposera C non NULL et m un des 4 caractères dans "hbgd".
//
// On rappelle qu'un déplacement m signifie par convention qu'on déplace une
// case voisine de la case vide VERS la case vide. Par exemple 'h' signifie
// qu'on va monter une case d'une ligne vers le haut (si c'est possible), ce qui
// va avoir pour effet de descendre le point (i0,j0) d'une ligne vers le bas.
//
// Vous pouvez utiliser copy_config() et SWAP(). Vous devez mettre à jour
// correctement (i0,j0), en plus de modifier des cases de C->G.
//
// [COMPLÉTEZ CETTE FONCTION]
//
config move(config C, char m) {
    ;
    ;
    ;
    return NULL;
}

// Fonction qui génère rapidement une *permutation* aléatoire P de
// {0,1,...,k-1}. Cette fonction est utilisée par la fonction create_random()
// dejà écrite pour vous, qui génère une *configuration* aléatoire.
//
// La fonction random_permutation() à écrire suppose que P pointe vers k cases
// de type int, déjà allouées : P[0],...,P[k-1]. Elle consiste à :
//
// 1. Initialiser P avec la permutation identité (P[i] = i pour tout i de
// {0,1,...,k-1}).
//
// 2. Pour chaque position i de P, en partant de la dernière (k-1) et jusqu'à
//    i = 1 (il n'y a rien à faire pour i=0), il faut :
//
//    2.1 Choisir un indice j aléatoire dans {0,1,...,i};
//    2.2 Echanger P[j] avec P[i].
//
// Pour générer un entier aléatoire, utilisez la fonction random(). Vous devrez
// ensuite utiliser un modulo pour restreindre l'intervalle de valeurs cibles.
//
// [COMPLÉTEZ CETTE FONCTION]
//
void random_permutation(int *P, int k) {
    // Créez ici la permutation aléatoire P de k cases
    ;
    ;
    ;
}

// Fonction de comparaison de deux configurations supposées non NULL selon leur
// champ score (les valeurs des scores seront calculées plus tard dans A*).
//
// La fonction fcmp_config doit renvoyer :
//
// * -1 si le score de la configuration pointée par X est < à celui de la
//   configuration pointée par Y,
// * 1 si le score de la configuration pointée par X est > à celui de la
//   configuration pointée par Y,
// * 0 si les scores des deux configurations sont égales,
//
// [COMPLÉTEZ CETTE FONCTION]
//
int fcmp_config(const void *X, const void *Y) {
    ;
    ;
    return 0;
}

typedef int (*heuristic)(config);

// Heuristique donnant le nombre de cases mal placées sans compter la case vide.
// Bien sûr, ce nombre est nul si et seulement si X est la configuration
// gagnante. On peut montrer que cette heuristique est monotone.
//
// NB: Pour être à la bonne place dans la configuration gagnante, la case (i,j)
// devrait contenir la valeur v = j + i*n, où n est la taille d'un côté d'une
// configuration.
//
// [COMPLÉTEZ CETTE FONCTION]
//
int h1(config X) {
    ;
    ;
    ;
    return -1;
}

// Heuristique donnant la somme des distances des cases, pour toute case de X
// sauf la case vide, à leurs positions dans la configuration gagnante.
//
// Les distances doivent être calculées selon le 4-voisinage de la grille G[][]
// (où les diagonales sont interdites). C'est aussi la distance de Manhattan
// qui, on le rappelle vaut: d((i,j),(i',j')) = |i'-i| + |j'-j|. Bien sûr, cette
// somme de distances est nulle si et seulement si X est la configuration
// gagnante. On peut montrer que cette heuristique est monotone.
//
// NB: Une case contenant la valeur v doit se retrouver, dans la configuration
// gagnante, à la position (i,j) telle que i = v/n et j = v%n.
//
// [COMPLÉTEZ CETTE FONCTION]
//
int h2(config X) {
    ;
    ;
    ;
    return -1;
}

// Heuristique similaire à h2 sauf que la distance pour une case de
// valeur v est multipliée par v*v. L'idée est de forcer à trouver des
// solutions consistant à placer d'abord les petits numéros, ce qui
// revient à pénaliser ceux qui sont grands. On obtient des résultats
// encore plus rapides en remplaçant le facteur v par v^2. Cette
// heuristique n'est pas monotone.
//
// [COMPLÉTEZ CETTE FONCTION POUR UN BONUS]
//
int h3(config X) {
    ;
    ;
    ;
    return -1;
}

// Applique l'algorithme A* muni d'une heuristique h pour le calcul
// d'un chemin allant d'une configuration de départ S à la
// configuration gagnante.
//
// La fonction doit renvoyer la configuration C correspondant à la
// configuration gagnante, le chemin étant déterminé par la suite de
// configurations: C, C->parent, C->parent->parent, ..., S. Si le
// chemin n'existe pas la fonction devra renvoyer NULL.
//
// [COMPLÉTEZ CETTE FONCTION]
//
config solve(config S, heuristic h) {
    heap H = NULL;

    // Il est important d'éviter ce cas là sinon mémoire+temps
    // explosent
    if (!can_win(S))
        return NULL;

    // Crée un tas min pour fcmp_config() et ajouter la configuration
    // de départ. NB: L'implémentation du tas qui vous est donnée le
    // redimensionne dynamiquement si besoin est. Vous pouvez donc
    // l'initialiser avec une petite taille, comme 4 par exemple.
    ;
    ;

    if (H == NULL) {
        fprintf(stderr, "%s  Error: heap not allocated.\n", KO);
        exit(1);
    }

    // Boucle principale de A*
    while (!heap_empty(H)) {    // tant qu'il reste une configuration
        config C = heap_pop(H); // C = config de score min
        if (h1(C) == 0)
            return C; // on a fini
        if (is_marked(C))
            continue; // C déjà vue ? sinon, la fonction is_marked() marque C

        char m[] = "bdgh";            // les 4 déplacements potentiels
        for (int i = 0; i < 4; i++) { // pour chaque configuration
                                      // (potentiellement) voisine V de C
            // Tester ici si le déplacement est valide.
            // Uniquement s'il l'est :
            // - mettre à jour les différents champs du voisin,
            // - l'ajouter dans le tas.
            ;
            ;
            ;
            ;
            ;
        }
    }

    return NULL; // on a pas trouvé de chemin
}

//
//  USAGE: taquin [n]
//
int main(int argc, char *argv[]) {
    int n         = (argc >= 2) ? atoi(argv[1]) : 3;
    unsigned seed = time(NULL) % 1000;
    printf("seed: %u\n", seed); // pour rejouer la même chose au cas où
    srandom(seed);

    config C;

    // exemple du sujet
    int ex1[3][3] = {
        {3, 1, 2},
        {4, 7, 5},
        {6, 8, 0},
    };

    // solvable en 5 mouvements
    int ex2[2][2] = {
        {0, 2},
        {3, 1},
    };

    // solvable en 15 mouvements
    int ex3[3][3] = {
        {3, 1, 2},
        {8, 0, 6},
        {4, 5, 7},
    };

    // solvable en 29 mouvements
    int ex4[3][3] = {
        {5, 2, 6},
        {8, 1, 4},
        {7, 3, 0},
    };

    // solvable en 53 mouvements (utiliser impérativement h2)
    int ex5[4][4] = {
        {14, 4, 7, 9},
        {13, 0, 1, 12},
        {3, 11, 10, 2},
        {6, 8, 5, 15},
    };

    // Test lancé avec la configuration ex1.
    // Vous pouvez changer pour une autre.
    int (*ex)[3] = ex1;
    // int (*ex)[2] = ex2;
    // int (*ex)[3] = ex3;
    // int (*ex)[3] = ex4;
    // int (*ex)[4] = ex5;

    int n_ex     = sizeof(ex[0]) / sizeof(ex[0][0]); // taille d'une ligne
    C            = new_config(n_ex);                 // crée une nouvelle config
    for (int i = 0; i < n_ex; i++)
        C->G[i] = ex[i]; // copies les lignes
    set_zero(C);         // important !

    // test de move()
    printf("====== Test de move ======\n");
    print_config(C);
    print_config(move(C, 'd'));
    printf("\n");

    // test de walk() pour ex1
    printf("====== Test de walk ======\n");
    walk(C, "dbdb");
    printf("\n");

    // test grille n x n aléatoire
    printf("====== Test de create_random ======\n");
    C = create_random(n);
    printf("Starting config\n");
    print_config(C);
    printf("Can be solved? %s\n", can_win(C) ? "yes" : "no");
    printf("\n");

    // test heuristique
    heuristic h = h1;
    printf("====== Test d'une heuristique ======\n");
    printf("h: %d\n", h(C));
    printf("\n");

    // test solve()
    printf("====== Test de solve ======\n");
    C       = solve(C, h); // très long si n>3, utiliser h3

    // affiche le chemin de la config gagnante à la config initiale
    int cfg = 0; // pour compter le nombre de mouvements

    while (C) {
        print_config(C);
        printf("h: %d\n", h(C));
        C = C->parent;
        cfg++;
    }

    printf("\n");
    printf("#mouvements: %d\n", cfg);
    printf("#configs in htable: %u\n", HTN ? *HTN : 0);
    printf("\n");

    return 0;
}


=========================================
File: ./Makefile
=========================================
#CFLAGS = -O0 -Wall -g -Wno-unused-variable
CFLAGS = -O3 -Wall -g -Wno-unused-variable

tp_src := $(wildcard taquin.c misc.c)
tp_obj := $(patsubst %.c,%.o,$(tp_src))

taquin: $(tp_obj) misc.o

.PHONY: clean
clean:
	rm -f taquin  taquin.o taquin.cor.o
	rm -fr *.dSYM/





# Pour les enseignants
tp_src_cor := $(wildcard taquin.cor.c misc.c)
tp_obj_cor := $(patsubst %.c,%.o,$(tp_src_cor))

cor: taquin.cor

taquin.cor: $(tp_obj_cor)

archive:
	rm -f tp-note-TAP-2025.tgz
	pdflatex sujet && pdflatex sujet &&	pdflatex sujet_uk && pdflatex sujet_uk
	rm -f *.aux *.log *.out
	make clean
	mkdir -p tp-note-TAP-2025
	cp -p misc.c misc.h taquin.c taquin.h Makefile translation_taquin_dot_c sujet.pdf sujet_uk.pdf tp-note-TAP-2025
	scp -rp ./tp-note-TAP-2025 "trelawney:"
	rm -rf ./tp-note-TAP-2025
	ssh trelawney "(cd ./tp-note-TAP-2025 && gcc -O3 -Wall -g -Wno-unused-variable -c -o misc.o misc.c && rm -f misc.c)"
	ssh trelawney tar cfvz tp-note-TAP-2025.tgz tp-note-TAP-2025
	scp "trelawney:tp-note-TAP-2025.tgz" .
	ssh trelawney rm -rf tp-note-TAP-2025.tgz tp-note-TAP-2025


=========================================
File: ./translation_taquin_dot_c
=========================================
// Traduction des commentaires de taquin.c. Ne pas modifier.

// Translation of comments from taquin.c. Do not modify.

/*

INSTRUCTIONS:

- Start by reading the subject (.pdf)! Simply compile with make.

- This is an individual test. Any communication with others is
  prohibited. AI and programming assistants are forbidden.
  Outgoing connections from UB and incoming connections to your account
  from outside are prohibited (they are recorded and will be checked after the
test).

- Moodle page for retrieving sources and submitting the taquin.c file:

     https://moodle.u-bordeaux.fr/course/view.php?id=6930#section-1

- Do not change the order of functions in taquin.c. Do not modify misc.h.

- Read the config type in misc.h. It refers to a pointer to a structure.

- Complete/code the incomplete functions, namely:

  - config copy_config(config C)
  - void set_zero(config C)
  - config move(config C, char m)
  - void random_permutation(int *P, int k)
  - int fcmp_config(const void *X, const void *Y)
  - int h1(config X)
  - int h2(config X)
  - int h3(config X) [EN BONUS]
  - config solve(config S, heuristic h)

  A description of each function is provided before its skeleton (which you must
  complete). Some functions are provided. You don't need to read them, except
  possibly for new_config() (which is the only function provided in this file;
  the others are described in misc.h).

  - You can modify the main() function for your own tests.

  - Before submitting on the Moodle page, make sure that:

  - The debugging instructions (printf for example) in your functions have been
  removed or commented out.

  - Your code compiles, even if it doesn't work normally, without errors and
  with as few warnings as possible.

  TIPS:

  - Test each function STEP BY STEP, progressively, without waiting until the
  last minute to compile.

  - To simplify, you are not required to free the allocated memory.
  Your code may have memory leaks (this is the case for the code
  provided to you).

*/

#include "misc.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Creates an n x n configuration where all the cells are zero. All fields
// are initialized. It will be assumed that n > 0 (so it is not the function's
// responsibility to handle this condition, but for the caller to ensure it).
//
// [YOU DO NOT NEED TO CODE THIS FUNCTION]
//
config new_config(int n) {
    config R = malloc(sizeof(*R));
    R->n     = n;
    R->G     = malloc(n * sizeof(*(R->G)));
    for (int i = 0; i < n; i++)
        R->G[i] = calloc(n, sizeof(int));
    R->i0 = R->j0 = 0;
    R->cost       = 0;
    R->score      = -1; // pour affichage intelligent avec print_config()
    R->parent     = NULL;
    return R;
}

// Creates a copy of the configuration C, assumed to be non-NULL. You can
// use the new_config function above. Make sure to copy all the fields.
//
// Note: in the copy C_copy, it is not enough to assign C->G to
// C_copy->G because we want to copy the cells of the array.
//
// [COMPLETE THIS FUNCTION]
//
config copy_config(config C) {
    ;
    ;
    ;
    return NULL;
}

// Finds the coordinates i,j of the cell C->G[i][j] that equals 0,
// and assigns i to C->i0 and j to C->j0. It is assumed that C is non-NULL,
// and that C->G contains a single 0 value.
//
// [COMPLETE THIS FUNCTION]
//
void set_zero(config C) {
    ;
    ;
    ;
    return;
}

////////////////////////////////////////////////////////////////////////////
// In the following, we refer to the "neighbor" of a configuration.       //
//                                                                        //
// We work in the following graph (on which we will apply A* in solve()): //
// - The vertices are the configurations.                                 //
// - There is an edge C->C' if we can go from C to C' by a move.          //
// In this case, we say that C' is a neighboring configuration of C.      //
////////////////////////////////////////////////////////////////////////////
//
//
//

//
//
//
// Returns the neighboring configuration of C where the move m has been made.
// If the move is not possible, the function returns NULL. In all cases, C
// is not modified (a new configuration is returned).
//
// It is assumed that C is non-NULL and m is one of the 4 characters in "hbgd".
//
// Recall that a move m means, by convention, that we move a neighboring cell
// of the empty cell TOWARDS the empty cell. For example, 'h' means we move
// one cell up (if possible), which will have the effect of moving the point
// (i0,j0) one row down.
//
// You may use copy_config() and SWAP(). You must correctly update (i0,j0),
// in addition to modifying cells in C->G.
//
// [COMPLETE THIS FUNCTION]
//
config move(config C, char m) {
    ;
    ;
    ;
    return NULL;
}

// Function that quickly generates a random permutation P of
// {0,1,...,k-1}. This function is used by the create_random() function
// already written for you, which generates a random configuration.
//
// The random_permutation() function to write assumes that P points to k cells
// of type int, already allocated: P[0],...,P[k-1]. It consists of:
//
// 1. Initialize P with the identity permutation (P[i] = i for all i in
// {0,1,...,k-1}).
//
// 2. For each position i of P, starting from the last (k-1) down to
// i = 1 (there’s nothing to do for i=0), you must:
//
// 2.1 Choose a random index j in {0,1,...,i};
// 2.2 Swap P[j] with P[i].
//
// To generate a random integer, use the random() function. You will then
// need to use a modulo to restrict the target value range.
//
// [COMPLETE THIS FUNCTION]
//
void random_permutation(int *P, int k) {
    // Create here the random permutation of P on k cells
    ;
    ;
    ;
}

// Comparison function for two configurations assumed to be non-NULL based on
// their score field (the score values will be calculated later in A*).
//
// The fcmp_config function should return:
//
// * -1 if the score of the configuration pointed to by X is < than that of the
// configuration pointed to by Y,
// * 1 if the score of the configuration pointed to by X is > than that of the
// configuration pointed to by Y,
// * 0 if the scores of the two configurations are equal,
//
// [COMPLETE THIS FUNCTION]
//
int fcmp_config(const void *X, const void *Y) {
    ;
    ;
    return 0;
}

typedef int (*heuristic)(config);

// Heuristic giving the number of misplaced tiles, not counting the empty tile.
// Of course, this number is zero if and only if X is the winning configuration.
// It can be shown that this heuristic is monotonic.
//
// NB: To be in the correct position in the winning configuration, the tile
// (i,j) should contain the value v = j + i*n, where n is the size of one side
// of the configuration.
//
// [COMPLETE THIS FUNCTION]
//
int h1(config X) {
    ;
    ;
    ;
    return -1;
}

// Heuristic giving the sum of the distances of the tiles, for every tile in X
// except the empty tile, to their positions in the winning configuration.
//
// The distances must be calculated according to the 4-neighborhood of the grid
// G[][] (where diagonals are not allowed). It is also the Manhattan distance,
// which, as a reminder, is: d((i,j),(i',j')) = |i'-i| + |j'-j|. Of course, this
// sum of distances is zero if and only if X is the winning configuration.
// It can be shown that this heuristic is monotonic.
//
// NB: A tile containing the value v should be found, in the winning
// configuration, at the position (i,j) such that i = v/n and j = v%n.
//
// [COMPLETE THIS FUNCTION]
//
int h2(config X) {
    ;
    ;
    ;
    return -1;
}

// Heuristic similar to h2 except that the distance for a tile with
// value v is multiplied by v*v. The idea is to force the solution to
// place the smaller numbers first, which effectively penalizes the larger ones.
// Even faster results are obtained by replacing the factor v with v^2. This
// heuristic is not monotonic.
//
// [COMPLETE THIS FUNCTION FOR A BONUS]
//
int h3(config X) {
    ;
    ;
    ;
    return -1;
}

// Applies the A* algorithm with a heuristic h to calculate
// a path from a starting configuration S to the winning configuration.
//
// The function must return the configuration C corresponding to the
// winning configuration, with the path determined by the sequence of
// configurations: C, C->parent, C->parent->parent, ..., S. If the
// path does not exist, the function should return NULL.
//
// [COMPLETE THIS FUNCTION]
//
config solve(config S, heuristic h) {
    heap H = NULL;

    // It is important to avoid this case, otherwise memory+time
    // will explode.
    if (!can_win(S))
        return NULL;

    // Creates a min-heap for fcmp_config() and adds the
    // starting configuration. NB: The heap implementation given to you
    // dynamically resizes if necessary. Therefore, you can initialize it
    // with a small size, such as 4 for example.
    ;
    ;

    if (H == NULL) {
        fprintf(stderr, "%s  Error: heap not allocated.\n", KO);
        exit(1);
    }

    // Main loop of A*
    while (!heap_empty(H)) {    // as long as there remains a configuration
        config C = heap_pop(H); // C = config with minimal score
        if (h1(C) == 0)
            return C; // we are done
        if (is_marked(C))
            continue; // C already seen? otherwise, the function is_marked()
                      // marks C

        char m[] = "bdgh";            // the 4 possible moves
        for (int i = 0; i < 4; i++) { // for each (possible) neighboring of C
            // Test here if the move is valid.
            // Only if it is, do the following:
            // - update the various fields of the neighbor,
            // - add it to the heap.
            ;
            ;
            ;
            ;
            ;
        }
    }

    return NULL; // on a pas trouvé de chemin
}

//
//  USAGE: taquin [n]
//
int main(int argc, char *argv[]) {
    int n         = (argc >= 2) ? atoi(argv[1]) : 3;
    unsigned seed = time(NULL) % 1000;
    printf("seed: %u\n", seed); // pour rejouer la même chose au cas où
    srandom(seed);

    config C;

    // exemple du sujet
    int ex1[3][3] = {
        {3, 1, 2},
        {4, 7, 5},
        {6, 8, 0},
    };

    // solvable en 5 mouvements
    int ex2[2][2] = {
        {0, 2},
        {3, 1},
    };

    // solvable en 15 mouvements
    int ex3[3][3] = {
        {3, 1, 2},
        {8, 0, 6},
        {4, 5, 7},
    };

    // solvable en 29 mouvements
    int ex4[3][3] = {
        {5, 2, 6},
        {8, 1, 4},
        {7, 3, 0},
    };

    // solvable en 53 mouvements (utiliser impérativement h2)
    int ex5[4][4] = {
        {14, 4, 7, 9},
        {13, 0, 1, 12},
        {3, 11, 10, 2},
        {6, 8, 5, 15},
    };

    // Test lancé avec la configuration ex1.
    // Vous pouvez changer pour une autre.
    int (*ex)[3] = ex1;
    // int (*ex)[2] = ex2;
    // int (*ex)[3] = ex3;
    // int (*ex)[3] = ex4;
    // int (*ex)[4] = ex5;

    int n_ex     = sizeof(ex[0]) / sizeof(ex[0][0]); // taille d'une ligne
    C            = new_config(n_ex);                 // crée une nouvelle config
    for (int i = 0; i < n_ex; i++)
        C->G[i] = ex[i]; // copies les lignes
    set_zero(C);         // important !

    // test de move()
    printf("====== Test de move ======\n");
    print_config(C);
    print_config(move(C, 'd'));
    printf("\n");

    // test de walk() pour ex1
    printf("====== Test de walk ======\n");
    walk(C, "dbdb");
    printf("\n");

    // test grille n x n aléatoire
    printf("====== Test de create_random ======\n");
    C = create_random(n);
    printf("Starting config\n");
    print_config(C);
    printf("Can be solved? %s\n", can_win(C) ? "yes" : "no");
    printf("\n");

    // test heuristique
    heuristic h = h1;
    printf("====== Test d'une heuristique ======\n");
    printf("h: %d\n", h(C));
    printf("\n");

    // test solve()
    printf("====== Test de solve ======\n");
    C       = solve(C, h); // très long si n>3, utiliser h3

    // affiche le chemin de la config gagnante à la config initiale
    int cfg = 0; // pour compter le nombre de mouvements

    while (C) {
        print_config(C);
        printf("h: %d\n", h(C));
        C = C->parent;
        cfg++;
    }

    printf("\n");
    printf("#mouvements: %d\n", cfg);
    printf("#configs in htable: %u\n", HTN ? *HTN : 0);
    printf("\n");

    return 0;
}

// Translation of already coded functions (declared in misc.h).

// Performs a sequence of moves while displaying the resulting grids.
//
// This function can be used to test move(), see the main() function.
//
// It is a generalization of move(), returning the configuration obtained
// after a sequence of moves encoded by the string s (which, as usual in C,
// ends with the character '\0'). If a move is invalid, it is skipped. Normally,
// aside from the display, walk(C,"d") should have the same effect as
// move(C,'d') (and similarly for the other 3 moves).
//
config walk(config C, char *S);

// Function that determines if the configuration C, assumed to be non-NULL,
// can reach the winning configuration (in fact, only half of the configurations
// can reach it).
//
// Technical explanation (which you can ignore unless you have time):
//
// You can win if and only if the PARITIES of the following two numbers are
// equal:
//
// - 1st number: the Manhattan distance between the position of the empty cell
// in C and the final position. Since this distance is (i0 + j0), its parity is
// easily calculated: it's ((i0 + j0) % 2).
//
// - 2nd number: the number of inversions in the permutation defined by C.
// To calculate this number, we view the configuration as a permutation
// P: {0,1,...,k-1} -> {0,...,k-1}, where k = n*n, by reading C->G row by
// row, left to right.
//
// The number of inversions of such a permutation P: {0,...,k-1} ->
// {0,...,k-1} is the number of index pairs {i,j} such that
// i<j and P[i]>P[j]. Note that the number of inversions of P is
// independent of how P is represented (whether as a linear array, square, or
// other).
//
bool can_win(config C);


// Builds a random n x n configuration that can reach the winning configuration.
// To do this, random configurations must be generated until one is found that
// allows reaching the winning configuration, which can be tested with
// can_win(). It is assumed that n > 0.
//
config create_random(int n);


=========================================
File: ./misc.h
=========================================
#ifndef MISC_H
#define MISC_H

#include "taquin.h"

#include <stdbool.h>

/** @brief Symbole ❌. */
#define KO            "\xE2\x9D\x8C"

// échange les variables x et y, via z
#define SWAP(x, y, z) (z) = (x), (x) = (y), (y) = (z)

typedef struct _config {
    int n;           // largeur du jeu
    int **G;         // tableau n x n
    int i0, j0;      // position de la case vide (void), i0=ligne, j0=colonne
    int cost, score; // pour A*: coût et score
    struct _config *parent; // pour A*: pointeur vers le parent
} *config;

typedef struct {
    void **array;
    int n, nmax;
    int (*f)(const void *, const void *);
} *heap;

// Affiche la configuration C sous la forme d'une grille comme
// ci-dessous:
//
// ╔═══╦═══╦═══╗
// ║ • ║ 1 ║ 2 ║
// ╠═══╬═══╬═══╣
// ║ 3 ║ 4 ║ 5 ║
// ╠═══╬═══╬═══╣
// ║ 6 ║ 7 ║ 8 ║
// ╚═══╩═══╩═══╝
// void: (0,0)
// cost: 0
// score: 0
//
// À noter: cost et score ne sont pas affichés si score < 0. Si n > 10,
// alors la configuration n'est pas affichée (trop grande !). De même
// si C est NULL. Un warning est affiché si la case vide et (i0, j0) ne
// correspondent pas.
void print_config(config C);

// Crée un tas dynamique minimum selon une fonction de comparaison f()
// prédéfinie. Le paramètre k est la taille initiale.
heap heap_create(int k, int (*f)(const void *, const void *));

// Renvoie vrai si le tas h est vide, faux sinon. On supposera
// h!=NULL.
bool heap_empty(heap h);

// Ajoute un objet au tas h. On supposera h!=NULL. Renvoie vrai s'il
// n'y a pas assez de place, et faux sinon. La taille est doublé
// dynamiquement.
bool heap_add(heap h, void *object);

// Renvoie l'objet en haut du tas h, c'est-à-dire l'élément minimal
// selon f(), tout en le supprimant. On supposera h!=NULL. Renvoie
// NULL si le tas est vide. La taille du tas n'est pas diminué
// dynamiquement.
void *heap_pop(heap h);

// Pointeur vers le nombre d'éléments dans la table de hachage
// utilisée par is_marked().
extern unsigned *HTN;

// Indique si la configuration C a déjà été traitée. Si c'est le cas,
// la fonction renvoie true. Si elle n'a pas été traité, on la marque
// (via une table de hachage) avant de renvoyer false. On supposera C
// non NULL.
bool is_marked(config C);

//////////////////////////////
// FONCTIONS DÉJÀ FOURNIES, //
//////////////////////////////

// Effectue une suite de déplacements tout en affichant les grilles obtenues.
//
// Cette fonction peut être utilisée pour tester move(), cf. fonction main().
//
// C'est une généralisation de move(), renvoyant la configuration obtenue après
// une suite de déplacements codée par la chaîne de caractères s (qui, comme
// d'habitude en C, se termine par le caractère '\0'). Si un mouvement est
// invalide, il est sauté. Normalement, à part l'affichage, walk(C,"d") devrait
// avoir le même effet que move(C,'d') (de même pour les 3 autres déplacements).
//
config walk(config C, char *S);

// Fonction qui détermine si la configuration C, supposée non NULL,
// peut atteindre la configuration gagnante (en fait, seule la moitié
// des configurations le peuvent).
//
// Explication technique (que vous pouvez ignorer sauf si vous avez le temps) :
//
// On peut gagner si et seulement si les PARITÉS des deux nombres suivants sont
// égales:
//
// - 1er nombre : la distance de Manhattan entre la position de la case vide de
//   C et finale. Comme cette distance est (i0+j0), sa parité se calcule
//   facilement : c'est ((i0+j0) % 2).
//
// - 2ème nombre : le nombre d'inversions de la permutation définie par C.
//   Pour calculer ce nombre, on voit la configuration comme une permutation
//   P: {0,1,...,k-1} -> {0,...,k-1}, où k = n*n, en lisant C->G ligne par
//   ligne, de gauche à droite.
//
//   Le nombre d'inversions d'une telle permutation P: {0,...,k-1} ->
//   {0,...,k-1} est le nombre de paires d'indices {i,j} telles que
//   i<j et P[i]>P[j]. Notons que le nombre d'inversions de P est
//   indépendant de la représentation de P en tableau linéaire ou
//   carré ou autre.
//
bool can_win(config C);

// Construit une configuration aléatoire n x n pouvant atteindre la
// configuration gagnante. Pour cela, il faut générer des configurations
// aléatoires jusqu'à en obtenir une qui permette d'atteindre la configuration
// gagnante, ce qui est testable avec can_win(). On supposera n > 0.
//
// [VOUS N'AVEZ PAS À LA CODER]
//
config create_random(int n);

#endif


