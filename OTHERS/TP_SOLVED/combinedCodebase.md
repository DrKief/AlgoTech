=========================================
Project Path: /home/lucas/Documents/S6/AlgoTech/OTHERS/TP_SOLVED
Project Directory Structure
=========================================
```
.:
combinedCodebase.md
playground_TP

./playground_TP:
a_star.c
heap
heap.c
heap.h
heap.tgz
htable.c
htable.h
Makefile
mygrid.txt
pppp
pppp.c
pppp.h
pppp.tgz
test_heap.c
tools.c
tools.h
tsp
tsp_brute_force.c
tsp_brute_force.h
tsp_heuristic.c
tsp_heuristic.h
tsp_main.c
tsp_mst.c
tsp_mst.h
tsp_prog_dyn.c
tsp_prog_dyn.h
tsp.tgz

./playground_TP/heap:

./playground_TP/pppp:

./playground_TP/tsp:
```


=========================================
System Information
=========================================
```bash


                    -`
                   .o+`
                  `ooo/
                 `+oooo:
                `+oooooo:
                -+oooooo+:
              `/:-:++oooo+:
             `/++++/+++++++:
            `/++++++++++++++:
           `/+++ooooooooooooo/`
          ./ooosssso++osssssso+`
         .oossssso-````/ossssss+`
        -osssssso.      :ssssssso.
       :osssssss/        osssso+++.
      /ossssssss/        +ssssooo/-
    `/ossssso+/:-        -:/+osssso+-
   `+sso+:-`                 `.-/+oso:
  `++:.                           `-/+/
  .`                                 `/[1G[20A[62COS  Arch Linux x86_64
[62CHost  Laptop 13 (AMD Ryzen 7040Series) (A5)
[62CKernel  Linux 6.19.12-zen1-1-zen
[62CUptime  23 hours, 14 mins
[62CProcesses  420
[62CPackages  1383 (pacman), 11 (flatpak)
[62CShell  fish 4.6.0
[62CDisplay  2880x1920 @ 2x in 13", 120 Hz [Built-in]
[62CLM  sddm 0.21.0 (Wayland)
[62CDE  KDE Plasma 6.6.4
[62CWM  KWin (Wayland)
[62CTerminal  ghostty 1.3.1-arch2
[62CCPU  AMD Ryzen 5 7640U (12) @ 3.50 GHz
[62CGPU  AMD Radeon 760M Graphics [Integrated]
[62CMemory  10.89 GiB / 27.21 GiB (40%)
[62CDisk (/)  562.00 GiB / 930.50 GiB (60%) - btrfs
[62CBattery  45% (2 hours, 24 mins remaining) [Discharging]
[62CLocal IP  10.32.6.208/24
[62CDNS  10.32.6.1
[62CDate & Time  2026-26-4 01:1:01
[62C
[62C● ● ● ● ● ● ● ●
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
    ls -R
    echo '```'
    echo -e "\n"

    echo "========================================="
    echo "System Information"
    echo "========================================="
    echo '```bash'
    fastfetch
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
File: ./playground_TP/a_star.c
=========================================
#include "tools.h"
#include "heap.h" // il faut aussi votre code pour heap.c


// Une fonction de type "heuristic" est une fonction h() qui renvoie
// une distance (double) entre une position de départ et une position
// de fin de la grille. La fonction pourrait aussi dépendre de la
// grille (comme par exemple du nombre de murs rencontrés par le
// segment départ-fin), mais on n'utilisera pas forcément ce dernier
// paramètre. Vous pouvez définir et tester votre propre heuristique.
typedef double (*heuristic)(position,position,grid*);


// Heuristique "nulle" pour Dijkstra.
double h0(position s, position t, grid *G){
  return 0.0;
}


// Heuristique "vol d'oiseau" pour A*.
double hvo(position s, position t, grid *G){
  return fmax(abs(t.x-s.x),abs(t.y-s.y));
}


// Heuristique "alpha x vol d'oiseau" pour A*.
static double alpha=0; // 0 = h0, 1 = hvo, 2 = approximation ...
double halpha(position s, position t, grid *G) {
  return alpha*hvo(s,t,G);
}


// Liste des heuristiques avec leurs descriptifs
// (pensez à inclure les votres)
static struct { heuristic h; char* s; } heuristic_list[] = {
  { h0,     "null (Dijkstra)" },
  { hvo,    "distance as the crow flies" },
  { halpha, "𝛼 times distance as the crow flies" },
};


// Structure "noeud" pour le tas min Q.
typedef struct _node {
  position pos;        // position (.x,.y) d'un noeud u
  double cost;         // coût[u]
  double score;        // score[u] = coût[u] + h(u,end)
  struct _node* parent;// parent[u] = pointeur vers le père, NULL pour start
} *node;


// Les arêtes, connectant les 8 cases voisines de la grille, sont
// valuées seulement par certaines valeurs correspondant aux
// différentes textures possibles des cases (il y en a 7). Le poids de
// l'arête u->v, noté ω(u,v) dans le cours, entre deux cases u et v
// voisines est déterminé par la texture de la case finale v. Plus
// précisément, si la case v de la grille est de texture t, le poids
// de u->v vaudra ω(u,v) = weight[t] dont les valeurs numériques
// exactes sont définies ci-après. Notez bien que t est un indice
// ('int'), alors que weight[t] est un coût ('double').
//
// La liste des textures possibles pour une case est disponibles dans
// l'enum de tools.h. Remarquez que weight[TX_WALL]<0 ce qui n'est pas
// a priori une valuation correcte.  En effet A* ne marche qu'avec des
// poids positifs ! Mais ce n'est pas un problème, puisque si
// G.texture[x][y] = TX_WALL, c'est que le sommet à la position (x,y)
// n'existe pas dans le graphe ! Et donc aucune arête ne peut donc
// être incidente à (x,y).

double weight[]={
    1.0,  // TX_FREE
    -99,  // TX_WALL
    3.0,  // TX_SAND
    9.0,  // TX_WATER
    2.3,  // TX_MUD
    1.5,  // TX_GRASS
    0.1,  // TX_TUNNEL
    2.0,  // TX_GRAVEL
    3.8,  // TX_ROCK
    6.0,  // TX_SNOW
    8.0,  // TX_ICE
    9.1,  // TX_LAKE
    9.2,  // TX_POOL
    1.4,  // TX_MEADOW
    1.6,  // TX_FOREST
    1.1,  // TX_TRACK
};

// Que doit faire la fonction A_star(G,h) ?
//------------------------------------------
//
// Votre fonction A_star(G,h) doit construire un chemin dans la grille
// G, entre la position G.start (s) et G.end (t), selon l'heuristique
// h(). Le chemin doit être calculé selon l'algorithme A* vu en cours
// (utilisez les notes de cours !). L'heuristique h() est une fonction
// à choisir lors de l'appel dans le main() parmi h0(), hvo(),
// halpha(). Vous pouvez aussi définir votre propre heuristique et la
// tester.
//
//
// Que doit renvoyer la fonction A_star(G,h) ?
//---------------------------------------------
//
// Si le chemin n'a pas été trouvé (par exemple si la destination est
// enfermée entre 4 murs ou si G.end est sur un mur), il faut renvoyer
// une valeur < 0.
//
// Sinon, il faut renvoyer le coût du chemin trouvé et remplir le
// champs .mark de G pour que le chemin trouvé puisse être visualisé
// par drawGrid(G) (plutard dans le main). Il faut, par convention,
// poser G.mark[x][y] = MK_PATH ssi la case (x,y) appartient au chemin
// trouvé. Pour que la visualisation soit complète, faite attention à
// ce que G.end et G.start soient bien marqués comme appartenant au
// chemin.
//
// Utilisez les touches a,z,+,-,p,c pour gérer la vitesse d'affichage
// et de progression de l'algorithme par exemple. Repportez-vous à
// "tools.h" pour avoir la liste des différentes touches et leurs
// actions, ainsi que les différents marquages possibles G.mark[x][y]
// pour une case (x,y).
//
//
// Comment gérer les ensembles P et Q ?
//--------------------------------------
//
// Pour gérer l'ensemble P, servez-vous du champs G.mark[x][y]. On
// aura G.mark[x][y] = MK_USED ssi le noeud en position (x,y) est dans
// P. Par défaut, ce champs est automatiquement initialisé partout à
// MK_NULL par toute fonction d'initialisation de la grille
// (initGridXXX()).
//
// Pour gérer l'ensemble Q, vous devez utiliser un tas min de noeuds
// (type node) avec une fonction de comparaison (à créer) qui dépend
// du champs .score des noeuds. Pour la fonction de comparaison
// inspirez vous de test_heap.c et faites attention au fait que
// l'expression '2.1 - 2.2' une fois castée en 'int' n'est pas
// négative, mais nulle !
//
// Vous devez utilisez la gestion paresseuse du tas (cf. le paragraphe
// du cours à ce sujet, dans la partie implémentation de Dijkstra ou
// de A*). Pensez qu'avec cette gestion paresseuse, la taille de Q est
// au plus la somme des degrés des sommets dans la grille. On peut
// être plus fin en remarquant que tout sommet, sauf s, aura toujours
// un voisin au moins déjà dans P (son parent). Pour visualiser un
// noeud de coordonnées (x,y) qui passe dans le tas Q vous pourrez
// mettre G.mark[x][y] = MK_FRONT au moment où vous l'ajoutez.
//
// Attention ! Même si cela est tentant, il ne faut pas utiliser la
// marque MK_FRONT pour savoir si un sommet (x,y) se trouve déjà dans
// Q. Cela ne sert pas à grand chose, car s'il est dans Q, vous ne
// pourrez pas déplacer le noeud correspondant pour le mettre au bon
// endroit dans Q en fonction de la mise à jour de son score.

int fcmp_node(const void *a, const void *b) {
    node n1 = (node)a;
    node n2 = (node)b;
    if (n1->score < n2->score) return -1;
    if (n1->score > n2->score) return 1;
    return 0;
}

double A_star(grid G, heuristic h) {
    if (G.texture[G.end.x][G.end.y] == TX_WALL) return -1;

    heap Q = heap_create(G.X * G.Y * 8, fcmp_node);
    
    node start_node = malloc(sizeof(struct _node));
    start_node->pos = G.start;
    start_node->cost = 0;
    start_node->score = h(G.start, G.end, &G);
    start_node->parent = NULL;
    heap_add(Q, start_node);

    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    while (!heap_empty(Q)) {
        node u = (node)heap_pop(Q);

        if (G.mark[u->pos.x][u->pos.y] == MK_USED) {
            free(u);
            continue;
        }

        G.mark[u->pos.x][u->pos.y] = MK_USED;
        drawGrid(G);

        if (u->pos.x == G.end.x && u->pos.y == G.end.y) {
            double final_cost = u->cost;
            node curr = u;
            while (curr != NULL) {
                G.mark[curr->pos.x][curr->pos.y] = MK_PATH;
                curr = curr->parent;
            }
            drawGrid(G);
            heap_destroy(Q);
            return final_cost;
        }

        for (int i = 0; i < 8; i++) {
            position v_pos = {u->pos.x + dx[i], u->pos.y + dy[i]};
            
            if (v_pos.x >= 0 && v_pos.x < G.X && v_pos.y >= 0 && v_pos.y < G.Y) {
                if (G.mark[v_pos.x][v_pos.y] == MK_USED) continue;
                
                int tex = G.texture[v_pos.x][v_pos.y];
                if (tex == TX_WALL) continue;
                
                double c = u->cost + weight[tex];
                
                node v = malloc(sizeof(struct _node));
                v->pos = v_pos;
                v->cost = c;
                v->score = c + h(v_pos, G.end, &G);
                v->parent = u;
                
                if (G.mark[v_pos.x][v_pos.y] == MK_NULL) {
                    G.mark[v_pos.x][v_pos.y] = MK_FRONT;
                }
                heap_add(Q, v);
            }
        }
    }
    heap_destroy(Q);
    return -1;
}


// Améliorations à faire seulement quand vous aurez bien avancé:
//
// (1) Lorsqu'il y a peu d'obstacles, l'ensemble des sommets visités
//     peut être relativement chaotique (on dirait qu'A* oublie de
//     visiter des sommets), ce qui peut être tout à fait normal.
//     Modifiez la fonction de comparaison pour qu'en cas d'égalité
//     des scores, elle tienne compte des coûts. Observez la
//     différence de comportement si vous privilégiez les coûts
//     croissant ou décroissant.
//
// (2) Le chemin a tendance à zigzaguer, c'est-à-dire à utiliser aussi
//     bien des arêtes horizontales que diagonales (qui peuvent avoir
//     le même coût), même pour des chemins en ligne droite. Essayez
//     de rectifier ce problème d'esthétique en modifiant le calcul de
//     score[v] de sorte qu'à coût[v] égale les arêtes (u,v)
//     horizontales ou verticales soient favorisées (un score plus
//     faible) ou de manière équivante que les diagonales soient
//     pénalisées (avec un score légèrement plus élevé). Il est aussi
//     possible d'intervenir au niveau de la fonction de comparaison
//     des noeuds pour tenir compte de la position du parent. Bien
//     sûr, votre modification ne doit en rien changer la distance (la
//     somme des coûts) entre .start et .end.
//
// (3) Modifier votre implémentation du tas dans heap.c de façon à
//     utiliser un tableau de taille variable, en utilisant realloc()
//     et une stratégie "doublante": lorsqu'il n'y a pas plus assez de
//     place dans le tableau, on double sa taille avec un realloc().
//     On peut imaginer que l'ancien paramètre 'k' dans heap_create()
//     devienne non pas le nombre maximal d'éléments total au cours de
//     l'algorihtme, mais le nombre maximal d'éléments au départ. On
//     pourra prendre k=4 par exemple.
//
// (4) Gérer plus efficacement la mémoire en libérant les noeuds
//     devenus inutiles. Pour cela on ajoute un champs .nchild à la
//     structure node, permettant de gérer le nombre de fils qu'un
//     node de P ou Q possède. C'est relativement léger et facile à
//     gérer puisqu'on augmente .nchild de u chaque fois qu'on fait
//     parent[v]=p, soit juste après "node v = createNode(p,...)".
//     Pensez à faire .nchild=0 dans createNode(). Notez bien qu'ici
//     on parle de "node", donc de copie de sommet.
//
//     L'observation utile est que tous les nodes de Q sont des
//     feuilles dans l'arbre des nodes de racine s. On va alors
//     pouvoir se débarrasser de tous les nodes ancêtres de ces
//     feuilles (qui ne sont plus dans Q car extraits avec heap_pop)
//     simplement en extrayant les nodes de Q dans n'importe quel
//     ordre, par exemple avec une boucle (*) sur heap_pop(Q). On
//     supprime alors chaque node, en mettant à jour le nombre de fils
//     de son père, puis en supprimant le père s'il devient feuille à
//     son tour (son .nchild passant à 0) et ainsi de suite
//     récursivement. On élimine ainsi totalement l'arbre par
//     l'élagage des branches qui se terminent dans Q.
//
//     (*) Si on veut être plus efficace que O(|Q|×log|Q|), on peut en
//         temps O(|Q|) vider le tableau .array[] directement sans
//         passer par heap_pop(). Mais pour être propre, c'est-à-dire
//         n'utiliser que des primitives de la structure de données et
//         pas son implémentation en accédant à h->array, il est bien
//         vu d'ajouter une primitive "void* heap_tail(heap h)" qui
//         permettrait d'extraire en temps constant le dernier élément
//         du tas (s'il existe). Cela a comme avantage de garder à
//         tout moment la structure de tas.
//
//     Ce processus peut ne pas éliminer tous les nodes car il peut
//     rester des branches de l'arbre qui se terminent par une feuille
//     qui est dans P (et donc qui n'ont pas de fils dans Q).
//     L'observation est que de tels nodes ne peuvent pas être sur le
//     chemin s->t. On peut donc les supprimer au fur et à mesure
//     directement dans la boucle principale quand on les détecte. On
//     voit qu'un tel node apparaît si après avoir parcouru tous les
//     voisins de u aucun node v n'est créé (et ajouté dans Q). Il
//     suffit donc de savoir si on est passé par heap_add() (ou encore
//     de comparer la taille de Q avant et après la boucle sur les
//     voisins). Si u est une feuille, on peut alors supprimer le node
//     u, mettre à jour .nchild de son père et remonter la branche
//     jusqu'à trouver un node qui n'est plus une feuille. C'est donc
//     la même procédure d'élagage que précédemment qu'on pourrait
//     capturer par une fonction freeNode(node p).


int main(int argc, char *argv[]){

  alpha = (argc>=2)? atof(argv[1]) : 0; // alpha = 0 => Dijkstra par défaut
  unsigned seed=time(NULL)%1000;
  printf("seed: %u\n",seed); // pour rejouer la même grille au cas où
  srandom(seed);

  // testez différentes grilles ...

  grid G = initGridPoints(80,45,TX_FREE,1); // petite grille vide, sans mur
  //grid G = initGridPoints(width,height,TX_FREE,1); // grande grille vide, sans mur
  //grid G = initGridPoints(40,22,TX_WALL,0.2); // petite grille avec quelques murs
  //grid G = initGridLaby(16,9,8); // petit labyrinthe aléatoire
  //grid G = initGridLaby(width/8,height/8,3); // grand labyrinthe aléatoire
  //grid G = initGridFile("mygrid.txt"); // grille à partir d'un fichier modifiable
  //grid G = initGrid3D(width/4,height/4); // grille avec texture réaliste pour 3D

  // ajoutez à G une ou plusieurs "régions" de texture donnée ...
  // (déconseillé pour initGridLaby, initGridFile et initGrid3D)

  //addRandomBlob(G, TX_WALL,   (G.X+G.Y)/10);
  //addRandomBlob(G, TX_SAND,   (G.X+G.Y)/15);
  //addRandomBlob(G, TX_WATER,  (G.X+G.Y)/6);
  //addRandomBlob(G, TX_MUD,    (G.X+G.Y)/3);
  //addRandomBlob(G, TX_GRASS,  (G.X+G.Y)/15);
  //addRandomBlob(G, TX_TUNNEL, (G.X+G.Y)/4);
  //addRandomArc(G, TX_WALL,    (G.X+G.Y)/25);

  // sélectionnez des positions s->t ...
  // (pas nécessaire pour initGridLaby, initGridFile et initGrid3D)

  G.start=(position){0.1*G.X,0.2*G.Y}, G.end=(position){0.8*G.X,0.9*G.Y};
  //G.start=randomPosition(G,TX_FREE); G.end=randomPosition(G,TX_FREE);

  // heuristique h à choisir parmi heuristic_list[]: 
  heuristic h = h0; // = h0, hvo, halpha, ...

  // affiche l'heuristique sélectionnée
  int i=0, n = CARD(heuristic_list);
  while (i<n && heuristic_list[i].h != h) i++; // cherche h dans la liste
  printf("heuristic: %s\n", (i==n)? "not founded" : heuristic_list[i].s);
  
  // constantes à initialiser avant init_SDL_OpenGL()
  scale = fmin((double)width/G.X,(double)height/G.Y); // zoom courant
  hover = false; // interdire les déplacements de points
  update = false; // accélère les dessins répétitifs

  init_SDL_OpenGL(); // à mettre avant le premier "draw"
  drawGrid(G); // dessin de la grille avant l'exécution de A*

  // exécution de A* avec l'heuristique h
  double d = A_star(G,h);

  // chemin trouvé ou pas ?
  if (d < 0){
    printf("path not found!");
    if(G.end.x<0 || G.end.y<0 || G.end.x>=G.X || G.end.y>=G.Y )
      printf(" destination out of the grid");
    if(G.texture[G.end.x][G.end.y] == TX_WALL)
      printf(" destination on a wall");
  }
  else printf("bingo!!! cost of the path: %g", d);

  // compte le nombre de sommets explorés pour comparer les
  // heuristiques
  n = 0;
  for (int i=0; i<G.X; i++)
    for (int j=0; j<G.Y; j++)
      n += (G.mark[i][j] != MK_NULL);
  printf("\n#nodes explored: %i\n", n);

  while (running) {     // affiche le résultat et attend
    update = true;      // force l'affichage de chaque dessin
    drawGrid(G);        // dessine la grille (/!\ passe update à false)
    handleEvent(false); // ne pas attendre d'évènement pour l'estompe
  }

  freeGrid(G);
  cleaning_SDL_OpenGL();
  return 0;
}


=========================================
File: ./playground_TP/mygrid.txt
=========================================
##############################
#
#      ++++++++       #  t
#                     #
#                       ##
#    ##############
#    #      #     #
#    #      #     #
#    #      #     #
#    #  #     #####
#    #  #  s      #
#    #  #         #
#    #            #
#   ##            #
#                 #
#    ##############
#     
#     ~~~~~~
############################


=========================================
File: ./playground_TP/tsp_brute_force.c
=========================================
#include "tools.h"

//
//  TSP - BRUTE-FORCE
//
// -> la structure "point" est définie dans "tools.h"
// -> tsp_main peut être testé dès les 3 premières fonctions codées
//

double dist(point A, point B) {
  ;
  ;
  ;
  return 0;
}

double value(point *V, int n, int *P) {
  ;
  ;
  ;
  return 0;
}

double tsp_brute_force(point *V, int n, int *Q) {
  ;
  ;
  ;
  return 0;
}

void MaxPermutation(int *P, int n, int k) {
  ;
  ;
  ;
  return;
}

double value_opt(point *V, int n, int *P, double w) {
  ;
  ;
  ;
  return 0;
}

double tsp_brute_force_opt(point *V, int n, int *Q) {
  ;
  ;
  ;
  return 0;
}


=========================================
File: ./playground_TP/tsp_brute_force.h
=========================================
#ifndef TSP_BRUTE_FORCE_H
#define TSP_BRUTE_FORCE_H

#include "tools.h"

double dist(point A, point B);
double value(point *V, int n, int *P);
double tsp_brute_force(point *V, int n, int *Q);
double value_opt(point *V, int n, int *P, double wmin);
void MaxPermutation(int *P, int n, int k);
double tsp_brute_force_opt(point *V, int n, int *Q);

#endif /* TSP_BRUTE_FORCE_H */


=========================================
File: ./playground_TP/tsp_heuristic.c
=========================================
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

=========================================
File: ./playground_TP/tsp_heuristic.h
=========================================
#ifndef TSP_HEURISTIC_H
#define TSP_HEURISTIC_H

#include "tools.h"

void reverse(int *T, int p, int q);
double first_flip(point *V, int n, int *P);
double tsp_flip(point *V, int n, int *P);
double tsp_greedy(point *V, int n, int *P);

#endif /* TSP_HEURISTIC_H */


=========================================
File: ./playground_TP/tsp_mst.c
=========================================
#include "tools.h"
#include "tsp_mst.h"
#include "tsp_brute_force.h"

//
//  TSP - MST
//
//  -> compléter uniquement tsp_mst() en fin de fichier
//  -> la structure "graph" est définie dans "tools.h"
//  -> la structure "edge" est définie dans "tsp_mst.h"
//

// Crée un graphe à n>0 sommets et sans arêtes. Les listes
// (potentielles de voisins) sont de tailles n, mais attention les
// degrés ne sont pas initialisés ! Il faudra le faire impérativement
// dans tsp_mst(). On code le fait que les degrés ne sont pas
// initialisés par G.deg[0]<0, ce qui permet de détecter la situation.
graph createGraph(int n) {
  graph G;
  G.n    = n;
  G.deg  = malloc(n * sizeof(*(G.deg)));
  G.list = malloc(n * sizeof(*(G.list)));
  for (int u = 0; u < n; u++)
    G.list[u] = malloc(n * sizeof(int)); // taille n par défaut
  G.deg[0] = -1; // par défaut, G ne sera pas dessiné par drawGraph()
  return G;
}

// Libère un graphe G et ses listes.
void freeGraph(graph G) {
  for (int u = 0; u < G.n; u++)
    free(G.list[u]);
  free(G.list);
  free(G.deg);
}

// Ajoute l'arête u-v au graphe G de manière symétrique. Les degrés de
// u et v doivent être à jour et les listes suffisamment grandes.
void addEdge(graph G, int u, int v) {
  G.list[u][G.deg[u]++] = v;
  G.list[v][G.deg[v]++] = u;
}

// Fonction de comparaison du poids de deux arêtes à utiliser avec
// qsort() pour un tri par ordre croissant. Ne pas hésiter à utiliser
// "man qsort" en ligne de commande pour l'aide sur cette fonction de
// la libraire standard du C.
int compEdge(const void *e1, const void *e2) {
  double const x = ((edge *)e1)->weight;
  double const y = ((edge *)e2)->weight;
  return (x > y) - (x < y); // -1,0,+1 suivant que x<y, x=y, ou x>y
}

// Fusionne les arbres de racines x et y selon l'heuristique du rang.
void Union(int x, int y, int *parent, int *rank) {
  if (rank[x] > rank[y])
    parent[y] = x;
  else {
    parent[x] = y;
    if (rank[x] == rank[y])
      rank[y]++;
  }
}

// Renvoie la racine de l'arbre contenant u (sa composante donc) selon
// l'heuristique de la compression de chemin.
int Find(int u, int *parent) {
  if (u != parent[u])
    parent[u] = Find(parent[u], parent);
  return parent[u];
}

// Calcule dans le tableau P l'ordre de première visite des sommets du
// graphe G selon un parcours en profondeur d'abord à partir du sommet
// u. Le paramètre p est le sommet parent de u. On doit avoir p<0 si u
// est l'origine du parcours (premier appel).
void dfs(graph G, int u, int *P, int p) {
  static int t; // t = temps ou indice (variable globale) du tableau P
  if (p < 0) {
    if (G.deg[0] < 0)
      return; // si G n'existe pas
    t = 0;
  }
  P[t++] = u;
  for (int i = 0; i < G.deg[u]; i++)
    if (G.list[u][i] != p)
      dfs(G, G.list[u][i], P, u);
}

double tsp_mst(point *V, int n, int *P, graph T) {
  // Cette fonction à compléter doit calculer trois choses (=les
  // sorties) à partir de V et n (=les entrées):
  //
  // 1. le graphe T, soit l'arbre couvrant V de poids minimum;
  // 2. la tournée P, soit l'ordre de visite selon le DFS de T;
  // 3. la valeur de la tournée P.
  //
  // NB: P et T doivent être créés et libérés par l'appelant. Il est
  // important de vider T, en remetant à zéro le degré de tous ses
  // sommets, avant de le remplir car tsp_mst() sera appelée plusieurs
  // fois.
  //
  // Algorithme:
  // 1. remplir puis trier le tableau d'arêtes avec qsort()
  // 2. répéter pour chaque arête u-v, mais pas plus de n-1 fois:
  //    si u-v ne forme pas un cycle de T (<=> u,v dans des composantes
  //    différentes) alors ajouter u-v au graphe T
  // 3. calculer dans P le DFS de T

  // E = tableau de toutes les arêtes définies à partir des n points de V
  int num_edges = n * (n - 1) / 2;
  edge *E = malloc(num_edges * sizeof(edge));

  int k = 0;
  for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
          E[k].u = i;
          E[k].v = j;
          E[k].weight = dist(V[i], V[j]);
          k++;
      }
  }
  qsort(E, num_edges, sizeof(edge), compEdge);

  // option pour le débugage: lorsque vous avez construit E[] afficher
  // ses arêtes (extrémités et poids), et lancer votre programme avec
  // disons n=4. Il devrait y avoir 6 arêtes triées.

  // initialisation pour Union-Find
  int *parent = malloc(n * sizeof(int)); // parent[u]=parent de u (=u si racine)
  int *rank   = malloc(n * sizeof(int)); // rank[u]=rang de l'arbre de racine u
  for (int u = 0; u < n; u++) {
    parent[u] = u; // chacun est racine de son propre arbre
    rank[u]   = 0; // rang nul
  }

  // construction de T
  // (pensez à (ré)initialiser les degrés des sommets de T)

  for (int u = 0; u < n; u++) {
      T.deg[u] = 0;
  }

  for (int i = 0; i < num_edges; i++) {
      int rootU = Find(E[i].u, parent);
      int rootV = Find(E[i].v, parent);
      
      if (rootU != rootV) {
          addEdge(T, E[i].u, E[i].v);
          Union(rootU, rootV, parent, rank);
      }
  }

  // option pour le débugage: lorsque vous ajoutez une arête à T vous
  // pouvez visualiser l'arbre courant avec drawGraph(V,n,NULL,T);
  // SDL_Delay(500); Ajouter un "&& running" dans votre boucle pour
  // quiter simplement.

  // libère les tableaux devenus inutiles
  free(parent);
  free(rank);
  free(E);

  if (T.deg[0] < 0)
    return 0; // si pas d'arbre, alors pas de tournée

  dfs(T, 0, P, -1);      // calcule P grâce au DFS à partir du sommet 0 de T
  return value(V, n, P); // renvoie la valeur de la tournée
}


=========================================
File: ./playground_TP/tsp_mst.h
=========================================
#ifndef TSP_MST_H
#define TSP_MST_H

#include "tools.h"

graph createGraph(int n);

// Libère un graphe G et ses listes.
void freeGraph(graph G);

// Ajoute l'arête u-v au graphe G de manière symétrique. Les degrés de
// u et v doivent être à jour et les listes suffisamment grandes.
void addEdge(graph G, int u, int v);

// Une arête u-v avec un poids.
typedef struct {
  int u, v;      // extrémités de l'arête u-v
  double weight; // poids de l'arête u-v
} edge;

int compEdge(const void *e1, const void *e2);
void Union(int x, int y, int *parent, int *rank);
int Find(int x, int *parent);
void dfs(graph G, int u, int *P, int p);
double tsp_mst(point *V, int n, int *P, graph T);

// variable globale pour une variante de tsp_mst()
extern bool msp;
// - si msp = true, alors version "minimal spanning path"
// - si msp = false, alors version "minimum spanning tree"

#endif /* TSP_MST */


=========================================
File: ./playground_TP/tsp_prog_dyn.c
=========================================
#include "tools.h"
#include "tsp_brute_force.h"
#include "tsp_prog_dyn.h"
#include <assert.h>

//
//  TSP - PROGRAMMATION DYNAMIQUE
//
//  -> compléter uniquement tsp_prog_dyn()
//  -> la structure "cell" est définie dans "tsp_prog_dyn.h"
//

// Renvoie l'ensemble S\{i}.
int DeleteSet(int S, int i) { return S & ~(1 << i); }

int ExtractPath(cell **D, int t, int S, int n, int *Q) {
  /*
    Construit dans Q le chemin entre les points V[n-1] et V[t] passant
    par tous les points de S, c'est-à-dire le chemin extrait depuis la
    case D[t][S]. La longueur du chemin Q ainsi extrait vaut en
    principe D[t][S].length. Renvoie le nombre de points du chemin
    Q. On supposera Q[] assez grand pour recevoir tous ses points.
  */
  if(D[0][1].length < 0) return 0; // si D n'a pas été remplie

  // phase 1: extrait Q = V[t] ... V[n-1] dans cet ordre

  Q[0] = t;                   // écrit le dernier point V[t] en premier
  int k = 1;                  // k = taille de Q = nombre de points écrits dans Q
  while (Q[k - 1] != n - 1) { // on s'arrête lorsque le point V[n-1] est atteint
    Q[k] = D[Q[k - 1]][S].pred;
    S = DeleteSet(S, Q[k - 1]);
    k++;
  }

  // phase 2: renverse Q pour avoir Q = V[n-1] ... V[t], au cas où la
  // fonction dist() ne soit pas symétrique

  int p=0, q=k-1;
  while(p<q){
    SWAP(Q[p], Q[q], t);
    p++; q--;
  }

  return k;
}

double tsp_prog_dyn(point *V, int n, int *Q) {
  /*
    Version programmation dynamique du TSP. La tournée optimale
    calculée doit être écrite dans la permutation Q, tableau qui doit
    être alloué par l'appelant. La fonction doit renvoyer aussi la
    valeur de la tournée Q ou 0 s'il y a eut un problème, comme la
    pression de 'q' pour sortir de l'affichage.
    
    La table D est un tableau 2D de "cell" indexé par t ("int"),
    l'indice d'un point V[t], et S ("int") représentant un ensemble
    d'indices de points.

    o D[t][S].length = longueur minimum d'un chemin allant de V[n-1] à
      V[t] qui visite tous les points d'indice dans S

    o D[t][S].pred = l'indice du point précédant V[t] dans le chemin
      ci-dessus de longueur D[t][S].length

    NB1: Ne pas lancer tsp_prog_dyn() avec n>31 car:
         o les entiers (int sur 32 bits) ne seront pas assez grands
           pour représenter tous les sous-ensembles;
         o pour n=32, il faudra environ n*2^n / 10^9 = 137 secondes
           sur un ordinateur à 1 GHz, ce qui est un peu long; et
         o l'espace mémoire, le malloc() pour la table D, risque
           d'être problématique: 32 * 2^32 * sizeof(cell) représente
           déjà 1536 Go de mémoire.

         En pratique on peut monter facilement jusqu'à n=24 pour une
         dizaine de secondes de calcul.
 
    NB2: La variable globale "running" indique si l'affichage
         graphique est actif, la pression de 'q' la faisant passer à
         faux. L'usage de "running" permet à l'utilisateur de sortir
         des boucles de calcul lorsqu'elles sont trop longues. Donc
         dans la phase de test, pensez à ajouter "&& running" dans vos
         conditions de boucle pour quitter en court de route si c'est
         trop long.
  */

  //-------------------------------------------------------------
  // Phase 1: Déclaration de la table.
  //
  // Elle comporte (n-1)*2^(n-1) "cell". NB: la colonne S=0
  // (l'ensemble vide) n'est pas utilisée.

  int const L = n-1;    // L = nombre de lignes = indice du dernier point
  int const C = 1 << L; // C = nombre de colonnes

  assert(L < 8*sizeof(L)-1); // un sous-ensemble de [0,n-1[ doit tenir
                             // strictement sur un int (sans le signe)

  cell **D = malloc(L*sizeof(cell*)); // L = n-1 lignes
  for (int t=0; t<L; t++) D[t] = malloc(C*sizeof(cell)); // C=2^{n-1} colonnes
  D[0][1].length=-1; // pour savoir si la table a été remplie


  //-------------------------------------------------------------
  // Phase 2: Remplissage de la table (par colonne).
  //
  // o Pour toutes les colonnes S faire ...
  //   o Pour chaque ligne t de D[][S] faire ...

  // Rappel de la formule pour remplir la table D:
  // si card(S)=1, alors D[t][S] = d(V[n-1], V[t]) avec S={t};
    for (int S = 1; S < C; S++) {
        for (int t = 0; t < L; t++) {
            if (!(S & (1 << t))) continue; 
            int T_set = DeleteSet(S, t);
            
            if (T_set == 0) { 
                D[t][S].length = dist(V[n - 1], V[t]);
                D[t][S].pred = n - 1;
            } else {
                double min_len = DBL_MAX;
                int best_pred = -1;
                for (int x = 0; x < L; x++) {
                    if (!(T_set & (1 << x))) continue;
                    double cand = D[x][T_set].length + dist(V[x], V[t]);
                    if (cand < min_len) {
                        min_len = cand;
                        best_pred = x;
                    }
                }
                D[t][S].length = min_len;
                D[t][S].pred = best_pred;
            }
        }
    }
  // Toujours dans la boucle, mais à la fin, lorsque le calcul de la
  // cellule D[t][S] est fait (c'est-à-dire les valeurs D[t][S].length
  // et D[t][S].pred correctement calcuées), vous pouvez afficher le
  // chemin Q correspondant à la case D[t][S] à l'aide d'ExtractPath()
  // puis de drawPath() comme ci-dessous:
  //
  // int k = ExtractPath(D, t, S, n, Q); // extrait Q depuis D[t][S]
  // drawPath(V, n, Q, k);               // dessine le chemin Q
  // if (!running) return 0;             // on arrête tout si 'q' est pressée
  //
  // Ici, c'est la fin des deux boucles. Le calcul de la table est
  // terminé.
  

  //-------------------------------------------------------------
  // Phase 3: Extraction de la tournée optimale.
  //
  // On notera w la longueur de la tournée optimale qui reste à
  // calculer. NB: si le calcul a été interrompu (pression de 'q'), il
  // faut renvoyer 0.

  double w = 0; // valeur par défaut

  if (running) {
        int best_last = -1;
        int full_set = C - 1;
        for (int t = 0; t < L; t++) {
            double cand = D[t][full_set].length + dist(V[t], V[n - 1]);
            if (cand < w || w == 0) {
                w = cand;
                best_last = t;
            }
        }
        if (best_last != -1) {
            ExtractPath(D, best_last, full_set, n, Q);
        }
  }


  //-------------------------------------------------------------
  for (int t = 0; t < L; t++) free(D[t]);
  free(D);

  return w;
}


=========================================
File: ./playground_TP/tsp_prog_dyn.h
=========================================
#ifndef TSP_PROG_DYN_H
#define TSP_PROG_DYN_H

#include "tools.h"

// Une cellule de la table.
typedef struct {
  double length; // longueur du chemin minimum D[t][S]
  int pred;      // point précédant t dans la solution D[t][S]
} cell;

int DeleteSet(int S, int i);
int ExtractPath(cell **D, int t, int S, int n, int *Q);
double tsp_prog_dyn(point *V, int n, int *Q);

#endif /* TSP_PROG_DYN_H */


=========================================
File: ./playground_TP/heap.c
=========================================
#include "heap.h"
#include <stdlib.h>

#define PARENT(i) ((i) / 2)
#define LEFT(i)   (2 * (i))
#define RIGHT(i)  (2 * (i) + 1)

heap heap_create(int k, int (*f)(const void *, const void *)) {
    heap h = malloc(sizeof(struct _heap)); // or sizeof(*h) depending on compiler strictness
    if (!h) return NULL;
    h->array = malloc((k + 1) * sizeof(void *)); // Index 0 is unused
    if (!h->array) { free(h); return NULL; }
    h->n = 0;
    h->nmax = k;
    h->f = f;
    return h;
}

void heap_destroy(heap h) {
    if (!h) return;
    free(h->array);
    free(h);
}

bool heap_empty(heap h) {
    return h->n == 0;
}

bool heap_add(heap h, void *object) {
    if (h->n >= h->nmax) return true; // Heap is full
    
    int i = ++(h->n);
    while (i > 1 && h->f(object, h->array[PARENT(i)]) < 0) {
        h->array[i] = h->array[PARENT(i)];
        i = PARENT(i);
    }
    h->array[i] = object;
    return false;
}

void *heap_top(heap h) {
    if (heap_empty(h)) return NULL;
    return h->array[1];
}

void *heap_pop(heap h) {
    if (heap_empty(h)) return NULL;
    
    void *root = h->array[1];
    void *last = h->array[(h->n)--];
    int i = 1;
    
    while (LEFT(i) <= h->n) {
        int min_child = LEFT(i);
        if (RIGHT(i) <= h->n && h->f(h->array[RIGHT(i)], h->array[LEFT(i)]) < 0) {
            min_child = RIGHT(i);
        }
        if (h->f(last, h->array[min_child]) <= 0) break;
        
        h->array[i] = h->array[min_child];
        i = min_child;
    }
    h->array[i] = last;
    return root;
}

=========================================
File: ./playground_TP/heap.h
=========================================
#ifndef HEAP_H
#define HEAP_H
#include <stdbool.h>

// Structure de tas binaire:
//
//  array = tableau de stockage des objets à partir de l'indice 1 (au lieu de 0)
//  n     = nombre d'objets (qui sont des void*) stockés dans le tas
//  nmax  = nombre maximum d'objets stockables dans le tas
//  f     = fonction de comparaison de deux objets (min, max, ..., cf. man qsort)
//
// Attention ! "heap" est défini comme un pointeur de structure pour
// optimiser les appels (empilement d'un mot (= 1 pointeur) au lieu de
// quatre sinon (= 1 mot pour chacun des 4 champs).

typedef struct{
  void* *array;
  int n, nmax;
  int (*f)(const void*, const void*);
} *heap;


// Crée un tas pouvant accueillir au plus k>0 objets avec une fonction
// de comparaison f() prédéfinie.
//
// NB: La taille d'un objet pointé par un pointeur h est sizeof(*h).
// Par exemple, si on déclare une variable T comme "char * T;" alors T
// est une variable de type "char*" (avec sizeof(T) = sizeof(1
// pointeur) = 8 octets) et *T est une variable de type "char" (avec
// sizeof(*T) = 1 octet).
heap heap_create(int k, int (*f)(const void *, const void *));


// Détruit le tas h. On supposera h!=NULL. Attention ! Il s'agit de
// libérer ce qui a été alloué par heap_create(). NB: Les objets
// stockés dans le tas n'ont pas à être libérés.
void heap_destroy(heap h);


// Renvoie vrai si le tas h est vide, faux sinon. On supposera
// h!=NULL.
bool heap_empty(heap h);


// Ajoute un objet au tas h. On supposera h!=NULL. Renvoie vrai s'il
// n'y a pas assez de place, et faux sinon.
bool heap_add(heap h, void *object);


// Renvoie l'objet en haut du tas h, c'est-à-dire l'élément minimal
// selon f(), sans le supprimer. On supposera h!=NULL. Renvoie NULL si
// le tas est vide.
void *heap_top(heap h);


// Comme heap_top() sauf que l'objet est en plus supprimé du tas.
// Renvoie NULL si le tas est vide.
void *heap_pop(heap h);

#endif

// Quelques pistes d'améliorations.
//
// 1. Usage de macros. C'est parfois une bonne pratique de définir
// remplacer des suites d'instructions qui se répètent souvent par une
// macro. Cela allège le code, et donc minimise les lieux d'erreurs.
// Mais, comme toutes les bonnes choses, il ne faut pas non plus en
// abuser si cela rend le code illisible et/ou incompréhensible. Par
// exemple, pensez déjà à utiliser la macro SWAP définie dans
// tools.h. Vous pourriez aussi définir FCMP(i,j) permettant de
// comparer les éléments d'indice i et j de votre tas tas. NB: Il est
// d'usage de mettre un #undef FCMP afin de supprimer la macro que
// vous auriez précédemment définie par un #define FCMP(i,j) ...
//
// 2. Pour le champs "array", il est possible d'allouer seulement k
// mots mémoires (au lieu de k+1), mais toujours sans utiliser
// l'indice 0, donc sans changer les fonctions heap_add() et
// heap_pop(). C'est possible en remarquant qu'après avoir fait
// l'allocation ...array = malloc(k * ...) on peut modifier le
// pointeur avec un ...array--. Ainsi, ...array[1] réfère alors à la
// première case du malloc(...). C'est normalement transparent, sauf
// pour heap_create() qu'il faut adapter.
//
// 3. Il est possible d'implémenter heap_add() et heap_pop() sans
// faire d'échanges (rendant l'usage de SWAP non nécessaire), en
// remarquant qu'on a besoin d'écrire l'objet qu'une seule fois à la
// bonne place.
//
// 4. Implémentez la Question 4 du TD sur le heap, c'est-à-dire un tas
// sans avoir à préciser la taille maximum. Allouer une taille par
// défaut, disons 16 mots, puis augmentez la taille lorsque nécessaire
// à l'aide d'un realloc(), cf. man realloc, qui fait la plus grosse
// partie du travail.
//
// 5. Une ruse spéciale peut être introduite pour heap_pop(),
// permettant de ne jamais tester le cas où l'élément courant, disons
// i, n'a qu'un seul fils. C'est lié au fait qu'au moment où l'on est
// améner à tester si i n'a qu'un fils, c'est que cet unique fils est
// précisément le dernier du tas, c'est-à-dire le dernier après
// l'opération de suppression. Mais bien évidemment, si c'est le cas
// l'élément, c'est que i avait 2 fils avant la suppression. Ainsi, on
// peut se restreindre aux cas i à 0 ou 2 fils. Il est clair que cette
// ruse est à implémenter lorsque la fonction heap_pop() est
// parfaitement fonctionnelle et maitrisé.


=========================================
File: ./playground_TP/test_heap.c
=========================================
/* 
   test_heap.c
   
   Permet de tester les fonctions de heap.c en remplissant un tas avec
   des éléments aléatoires d'un type donné, puis de les extraire en
   vérifiant qu'ils apparaissent dans l'ordre croissant. Plusieurs
   types et fonctions de comparaisons peuvent être testés.

   NB: La fonction de comparaison double2(), qui consiste à renvoyer
   "x-y" converti en "int", produit un comportement intéressant qui
   est doublement erroné. D'abord "0.5-0.3" (qui devrait être un test
   strictement positif), est interprété comme "0.5-0.3"<=0 car
   (int)(0.5-0.3) = (int)(0.2) = 0. Et donc le programme pourra penser
   que le tableau final est effectivement trié ("success!") par ordre
   croissant, alors que c'est visiblement pas le cas. Mais plus grave
   encore, le programme peut afficher un échec ("fail!") alors que
   l'implémentation du tas est tout à fait correcte. Pourtant,
   "success!" et "fail!" sont déterminés d'après la même fonction de
   comparaison: pour la gestion du tas et pour la vérification finale
   du tri. Cela vient du fait que la fonction double2() n'est pas
   transitive. On peut très bien avoir "x-y"=0 et "y-z"=0 mais avoir
   "x-z">0. Cela se produit par exemple avec x=1.2, y=0.7 et z=0.2.
   Donc, même avec une implémentation correcte, une fonction de
   comparaison non transitive peut faire échouer un tri par tas.
*/

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define NMAX 40  // taille max pour l'affichage avec print_heap()
#define BAR "-"  // un tiret
#define MAXSTR 7 // taille max d'une string
#define xstr(s) str(s) // permet l'expansion d'une macro
#define str(s) #s      // Ex: scanf("%"xstr(DMAX)"s",buffer);

// char UTF8
#define FAIL  "\xf0\x9f\x94\xa5 fail!"
#define NOWAY "\xf0\x9f\x9a\xab"
#define HEART "\xe2\x9d\xa4\xef\xb8\x8f"
#define OK    "\xf0\x9f\x91\x8c"


typedef int (*fcmp)(const void*,const void*); // type fonction de comparaison
typedef char* string;                         // type chaîne de caractères
typedef struct{ double x,y; } point;          // type point du plan

////////////////////////////////////////////////////

int fcmp_int(const void *x, const void *y) {
  return *(int*)x - *(int*)y;
}

int fcmp_char(const void *x, const void *y) {
  return *(char*)x - *(char*)y;
}

int fcmp_double(const void *x, const void *y) {
  const double a = *(double*)x;
  const double b = *(double*)y;
  return (a<b)? -1 : (a>b); // ou encore return (a>b) - (a<b);
}

int fcmp_double2(const void *x, const void *y) {
  return *(double*)x - *(double*)y; // incorecte !
}

int fcmp_string(const void *x, const void *y) {
  return strcmp( *(string*)x, *(string*)y );
}

int fcmp_pointx(const void *p, const void *q) {
  return fcmp_double( &(((point*)p)->x), &(((point*)q)->x) );
}

////////////////////////////////////////////////////

enum{ // les types possibles, pour les switch()
  INT=0,
  CHAR,
  DOUBLE,
  DOUBLE2,
  STRING,
  POINT,
};

int size[] = { // tableau des tailles des types
  sizeof(int),
  sizeof(char),
  sizeof(double),
  sizeof(double),
  sizeof(string),
  sizeof(point),
};

int psize[] = { // tableau des tailles d'affichage des types
  2,
  1,
  5,
  5,
  MAXSTR,
  9,
};

fcmp cmp[] = { // tableau des fonctions de comparaison
  fcmp_int,
  fcmp_char,
  fcmp_double,
  fcmp_double2,
  fcmp_string,
  fcmp_pointx,
};

char *type[] = { // tableau des types pour l'aide
  "int",     "integers in [0,100[ (default)",
  "char",    "capital letters in ['A','Z'[",
  "double",  "real numbers in ]-1.00,+1.00[",
  "double2", "same as 'double' but with 'x-y' like fcmp()",
  "string",  "strings of length at most "xstr(MAXSTR),
  "point",   "real points of [0,9.9]×[0,9.9] with 'x' like fcmp()",
};


////////////////////////////////////////////////////


// affiche T[i] avec le bon format suivant le type t
// en ajoutant un espace " " terminal
void print(int t, void *T, int i){
  switch(t){
  case INT:     printf("%02i ",    ((int*)    T)[i]); break;
  case CHAR:    printf("%c ",      ((char*)   T)[i]); break;
  case DOUBLE:
  case DOUBLE2: printf("%+1.2lf ", ((double*) T)[i]); break;
  case STRING:  printf("%s ",      ((string*) T)[i]); break;
  case POINT:   printf("(%.1lf,%.1lf) ",((point*)T)[i].x, ((point*)T)[i].y); break;
  }
}

// initialisation aléatoire de l'élément T[i]
void init(int t, void *T, int i){
  switch(t){

  case INT:
    { // entiers aléatoires dans [0,100[
      ((int*)T)[i] = random()%100;
    } break;

  case CHAR:
    { // lettres majuscules aléatoires
      ((char*)T)[i] = 'A' + (random()%('Z'-'A'+1));
    } break;

  case DOUBLE:
  case DOUBLE2:
    { // double aléatoires dans [-1,+1] avec 2 chiffres
      ((double*)T)[i] = ((random()%2000)-1000) / 1000.0;
    } break;

  case STRING:
    { // construit une chaîne aléatoire d'au plus MAXSTR char
      const int k = 1 + random()%MAXSTR; // k=1..MAXSTR
      string s = calloc(k+1,sizeof(char)); // remplit de '\0'
      for(int i=0; i<k; i++) s[i] = 'a' + (random()%('z'-'a'+1));
      ((string*)T)[i] = s;
    } break;
    
  case POINT:
    { // point aléatoire de [0,10[ x [0,10[ avec 1 chiffre
      ((point*)T)[i].x = random()%100 / 10.0;
      ((point*)T)[i].y = random()%100 / 10.0;
    } break;
  }
}


////////////////////////////////////////////////////


// affiche n fois la chaîne s
void rule(int n,string s){
  for(int i=0; i<n; i++) printf("%s",s);
}

// affiche le contenu du tas h d'éléments de type t sous la forme d'un
// arbre, sauf si le nombre d'éléments est est trop grand (>NMAX)
void print_heap(heap h, int t) {

  rule(psize[t],BAR);
  printf("\n");

  if (h == NULL) {
    printf("heap = NULL, the heap does not exist\n\n");
    return;
  }
  
  int j=h->n;
  if( j > NMAX ){
    printf(NOWAY" heap to large to be displayed!\n");
    return;
  }

  int haut=0; // hauteur du tas (=nombre de lignes)
  while(j>0) haut++, j>>=1;

  // On suppose que le pattern est de taille impaire 2s+1 avec s =
  // floor(psize[t]/2). Si taille est paire on fait pareil, ce qui
  // revient à ajouter virtuellement un espace terminal. On pourrait
  // faire une meilleure présentation dans le cas pair (= plus
  // compacte notamment sur la dernière ligne), mais cela complexifie.
  //
  // Ex: pattern PPP de taille psize[t] = 3 (s=1)
  //
  // y=3|              PPP
  // y=3|       ┌───────┴───────┐
  // y=2|      PPP             PPP
  // y=2|   ┌───┴───┐       ┌───┴───┐
  // y=1|  PPP     PPP     PPP     PPP
  // y=1| ┌─┴─┐   ┌─┴─┐   ┌─┴─┐   ┌─┴─┐
  // y=0|PPP PPP PPP PPP PPP PPP PPP PPP
  //
  // Variables (les positions en x démarrent à 0):
  //
  //  pm = position du milieu (┴)
  //  pp = position du début du pattern
  //  pb = position du début de branche (┌)
  //  lb = longueur de branche (entre ┌ et ┴)
  //  eb = espace entre deux branches (entre ┐ et ┌)
  //  ep = espace entre deux patterns
  //
  // Evolution des variables, à partir du bas (y=0,1,2,...):
  //
  //      y=0  y=1  y=2
  //
  //  pm = s   2s+1 4s+3 ... => pm(y) = 2*pm(y-1)+1 = (s+1)*2^y - 1
  //  lb = .   s    2s+1 ... => lb(y) = pm(y-1)
  //  pb = .   s    2s+1 ... => pb(y) = lb(y)
  //  pp = 0   s+1  3s+3 ... => pp(y) = pm(y)-s
  //  eb = .   2s+1 4s+3 ... => eb(y) = 2*eb(y-1)+1 = pm(y)
  //  ep = 1   ...  ...      => ep(y) = 2*lb(y+1)+1-2s = 2*pm(y)+1-2s

  int s1,s2;
  int s=psize[t]/2;  // nombre de caractères avant le milieu du pattern
  int B=1;           // B = nombre de patterns dans la ligne
  j=0;               // j = nombre d'éléments déjà affichés

  for(int y=haut-1; y>=0; y--, B<<=1){ // on part du haut

    int pm=(s+1)*(1<<y)-1;
    int lb=(s+1)*(1<<(y-1))-1;
    int ep=2*pm+1-2*s;

    // ligne avec les éléments
    rule(pm-s," ");
    for(int b=0; b<B && (j<h->n); b++){
      j++;
      if(psize[t]%2==0) printf(" "); // cas pair
      if(t==STRING){ // centrage si string
	s1=strlen(*(string*)h->array[j]);
	s2=(psize[t]-s1)/2;
	s1=psize[t]-s2-s1;
	rule(s1," "); // [s1 string s2]
      }
      print(t, h->array[j], 0);
      if(t==STRING) rule(s2," "); // centrage si string
      if(b<B-1) rule(ep-1," "); // -1 pour l'espace terminal
    }
    printf("\n");
    if(y==0) break; // fini si dernière ligne d'éléments

    // ligne avec les branchements
    rule(lb," ");
    for(int b=0; b<B; b++){
      printf("┌"); rule(lb,"─"); printf("┴"); rule(lb,"─"); printf("┐");
      if(b<B-1) rule(pm," ");
    }
    printf("\n");
    
  }
  
  rule(psize[t],BAR);
  printf("\n\n");
}


////////////////////////////////////////////////////


// NB: S'il y a des fflush(stdout) un peu partout, c'est qu'en cas
// d'erreur ("segmentation fault" par exemple) il arrive que le
// printf() précédant l'erreur n'a pas le temps d'être affiché (et
// donc ne s'affiche pas). Donc généralement les fflush() ne servent à
// rien, sauf si le programme est sujet à des erreurs.

int main(int argc, char *argv[]) {

  int i, t, r;
  int ntype = sizeof(cmp)/sizeof(*cmp);     // nombre de types possibles
  int n = (argc>=2)? atoi(argv[1]) : -1;    // n = nombre d'éléments
  char *s = (argc>=3)? argv[2] : type[INT]; // t = type des éléments

  // double x=1.2, y=0.7, z=0.2;
  // printf("%g %g -> %d\n", x, y, fcmp_double2(&x,&y)); // 0
  // printf("%g %g -> %d\n", y, z, fcmp_double2(&y,&z)); // 0
  // printf("%g %g -> %d\n", x, z, fcmp_double2(&x,&z)); // 1
  // exit(1);

  for(t=0; t<ntype; t++) if(!strcmp(s,type[2*t])) break; // type trouvé !
  if( n<0 || t==ntype ){ // erreur
    printf("\n Usage: %s n [t]",argv[0]);
    printf("\n   Ex.: %s 10 int\n\n",argv[0]);
    printf("    n = number of random elements\n");
    printf("    t = type of elements & fcmp():\n\n");
    for(t=0; t<ntype; t++){
      printf("        '%s' ",type[2*t]);
      rule(12-strlen(type[2*t]),".");
      printf(" %s\n",type[2*t+1]);
    }
    printf("\n");
    exit(1);
  }

  unsigned seed = time(NULL) % 1000;
  srandom(seed);
  printf("\nseed: %u\n", seed); // pour rejouer la même chose au cas où

  void *T = malloc(n*size[t]); // tableau initial
  void *S = malloc(n*size[t]); // tableau final supposé trié

  printf("test heap with %i elements of type '%s'\n",n,type[2*t]);
  printf("(%s)\n",type[2*t+1]);

  // affichage et création de T[]
  printf("input array: ");
  for (i = 0; i<n; i++) {
    init(t, T, i);
    print(t, T, i);
  }
  printf("\n");

  // crée le tas avec la bonne fonction
  printf("heap creation... ");
  fflush(stdout);
  heap h = heap_create(n, cmp[t]);
  if ( h == NULL ){
    printf(FAIL" the returned heap is NULL\n\n");
    fflush(stdout);
    goto fin;
  }
  printf("ok\n");
  fflush(stdout);

  // teste que la fonction de comparaison soit correcte
  printf("heap comparison function? ");
  fflush(stdout);
  if (h->f != cmp[t]){
    printf(FAIL" wrong function\n\n");
    fflush(stdout);
    goto fin;
  }
  printf("correct\n");
  fflush(stdout);

  // teste que le tas soit bien vide au départ
  printf("heap empty at the start? ");
  fflush(stdout);
  if ( !heap_empty(h) ){
    printf(FAIL" the heap should be empty at the start\n\n");
    fflush(stdout);
    goto fin;
  }
  printf("yes\n");
  fflush(stdout);

  // teste que le nombre max d'éléments soit correct
  printf("heap size initialization? ");
  fflush(stdout);
  if (h->nmax != n){
    printf(FAIL" heap size is %d whereas it should be %d\n\n",
	   h->nmax, n);
    fflush(stdout);
    goto fin;
  }
  printf("correct\n");
  fflush(stdout);

  // pour les tests de lecture/écriture dans la zone allouée on fait
  // une petite pause pour permettre de voir où le 'segmentation
  // fault' se produit, s'il se produit. Malheureusement passer le
  // test ne signifie pas que les malloc() dans heap_create() étaient
  // corrects. Ces tests pourraient peut-être affinés avec l'usage de
  // mmap() ou mprotect().

  // test lecture
  printf("reading test in the heap array[1..%d]... ",n);
  printf("\E[?25l"); // echo off
  fflush(stdout);
  for(i=1; i<=n; i++){
    int k = printf("%d",i);
    printf("\E[%dD",k); // retour de k colonnes à gauche
    fflush(stdout);
    usleep(1000000/n); // pause d'une seconde au total
    void *w = h->array[i]; // lecture
    (void)w; // pour éviter le warning 'w not used'
  }
  printf("\E[?25h"); // echo on
  printf("ok\E[K\n");
  fflush(stdout);

  // test écriture
  printf("writing test in the heap array[1..%d]... ",n);
  printf("\E[?25l"); // echo off
  fflush(stdout);
  for(i=1; i<=n; i++){
    int k = printf("%d",i);
    printf("\E[%dD",k); // retour de k colonnes à gauche
    fflush(stdout); // écriture
    usleep(1000000/n); // pause d'une seconde au total
    h->array[i] = (void*)main;
  }
  printf("\E[?25h"); // echo on
  printf("ok\E[K\n");
  fflush(stdout);

  // déplace les éléments de T[] vers h avec des add()
  printf("\ntesting insertions:\n\n");
  fflush(stdout);
  for (i = 0; i<n; i++) {
    printf("insert ");
    print(t, T, i);
    printf("\n");
    if (heap_add(h, T+i*size[t])) { // T+i*size[t] = &(T[i])
      printf(FAIL" insert aborted after %d items (instead of %d)\n",
	     i, n);
      fflush(stdout);
      break;
    }
    if (heap_empty(h)) {
      printf(FAIL" the heap cannot be empty after insertion");
      fflush(stdout);
    }
    print_heap(h, t);
  }
  
  // déplace les i éléments insérés de h vers S[] avec des pop()
  // et vérification que top() retourne bien le même élément
  printf("testing suppressions:\n\n");
  fflush(stdout);
  for (int j=0; j<i; j++) {
    void *x = heap_top(h);
    if ( x == NULL ){
      printf(FAIL" the heap looks empty after poping %d item(s)\n", j+1);
      fflush(stdout);
      break;
    }
    void *y = heap_pop(h);
    memcpy(S+j*size[t],y,size[t]); // S[j] = heap_pop(h)
    printf("pop ");
    print(t, S, j);
    printf("\n");
    if ( y != x ) {
      printf(FAIL" heap_top() and heap_pop() differ at the %d-th item\n", j+1);
      fflush(stdout);
    }
    print_heap(h, t);
  }

  // teste que le tas soit bien vide
  printf("heap empty? ");
  fflush(stdout);
  printf(heap_empty(h)? "yes it is\n" : FAIL" it should be empty\n");
  fflush(stdout);

  // teste qu'on ne peut pas faire heap_top() sur un tas vide
  printf("reading top element from empty heap? ");
  fflush(stdout);
  printf((heap_top(h)==NULL)? "NULL => correct!\n" : FAIL" a top element founded in an empty heap!\n");
  fflush(stdout);

  // teste qu'on ne peut ni faire heap_pop() sur un tas vide
  printf("poping element from empty heap? ");
  fflush(stdout);
  printf((heap_pop(h)==NULL)? "NULL => correct!\n" : FAIL" a top element removed from an empty heap!\n");
  fflush(stdout);

  // libère le tas
  printf("heap destruction... ");
  fflush(stdout);
  heap_destroy(h);
  printf("ok\n");
  fflush(stdout);

  // affichage du résultat S[] et vérifie qu'il est trié
  // affiche "... x [>] y ..." si x>y (pas le bon ordre)
  // NB: le test peut échouer si cmp = double2
  printf("output array: ");
  for (i=0, r=1; i<n; i++){
    if(i>0){ // seulement à partir du 2e élément
      int c = cmp[t](S+(i-1)*size[t], S+i*size[t]); // S[i-1] <= S[i] ?
      if( c>0 ){ r=0; printf("[>] "); } // y'a un problème
    }
    print(t, S, i); // affiche S[i]
  }
  printf("\n%s the above array is %ssorted\n",
	 r? "success!"OK : FAIL, r?"":"not ");
  fflush(stdout);

  // teste que S[] et T[] on bien les mêmes éléments
  // pour cela, on trie S et T avec qsort(), puis on teste l'égalité
  // des éléments avec cmp[t](x,y) == 0
  // NB: le test peut échouer si cmp = double2
  printf("final test: is output array a permutation of the input? ");
  qsort(S, n, size[t], cmp[t]);
  qsort(T, n, size[t], cmp[t]);
  for (i=r=0; i<n; i++) // r = compte les valeurs égales
    r += (cmp[t](S+i*size[t], T+i*size[t]) == 0); // S[i] == T[i] ?
  printf((r==n)? "\nthis is a total success! "HEART"\n\n" : "\n"FAIL" output differ from input!\n\n");
  fflush(stdout);
  
 fin:;
  // libération de la mémoire
  if(t==STRING) // cas d'un tableau de string
    for(i=0; i<n; i++)
      free(((string*)T)[i]); // inutile pour S car mêmes éléments que T
  free(T);
  free(S);

  return 0;
}


=========================================
File: ./playground_TP/htable.c
=========================================
#include "htable.h"
#include <stdlib.h>
#include <strings.h>


// Fonction permettant de calculer la position du bit de poids fort
// d'une valeur, les positions commençant à 1. Renvoie 0 si la valeur
// est nulle. C'est littéralement la même fonction que fls(), fonction
// hardware en temps constant qui existe sous Mac OS, mais pas
// forcément sous Linux. La déclaration en 'weak' permet d'utiliser la
// fonction d'origine si elle est disponible.
int __attribute__((weak)) fls(int value){
  if (value == 0) return 0;
  int p = 1;
  unsigned x = value;
  while( x != 1 ) x >>= 1, p++;
  return p;
}


inline void ht_reset(htable T){
    bzero(T->state,(T->mask+1)*sizeof(*T->state)); // reset complet
    T->n = 0; // plus aucune entrée
}


htable ht_create(void){
  htable T = malloc(sizeof(*T));
  T->key   = malloc(HT_INIT_SIZE*sizeof(*T->key));
  T->value = malloc(HT_INIT_SIZE*sizeof(*T->value));
  T->state = malloc(HT_INIT_SIZE*sizeof(*T->state));
  T->mask = HT_INIT_SIZE-1; // pour un modulo rapide
  T->shift = 8*sizeof(HT_MAGIC) - (fls(HT_INIT_SIZE)-1); // pour le hash
  ht_reset(T); // vide la table
  return T;
}


void ht_free(htable T){
  free(T->key);
  free(T->value);
  free(T->state);
  free(T);
}


enum{
  ST_FREE = 0, // l'entrée est libre, doit être = 0 pour bzero()
  ST_SET,      // l'entrée est occupé
  //ST_DEL,      // l'entrée a été supprimée
};


// Code d'opérations pour ht_lookup()
typedef enum{
  OP_READ,   // une lecture
  OP_WRITE,  // une écriture
  //OP_DELETE, // une suppression
} ht_opcode;


// Effectue une opération de lecture ou d'écriture dans la table T.
// L'opération est spécifiée par le paramètre op. Si op = OP_READ,
// alors la valeur associée à key est renvoyée (renvoie NULL si aucune
// entrée (key,value) n'a été écrite précédemment dans T). Si op =
// OP_WRITE, alors l'entrée (key,value) est écrite dans la table
// T. Pour l'écriture, l'ancienne valeur est retournée (renvoie NULL
// si l'entrée était libre).
void* ht_lookup(htable T, int key, void *value, ht_opcode op){

  void* v;

  // détermine l'index h de T où mettre l'entrée (key,value)
  unsigned h = (key * HT_MAGIC) >> T->shift; // multiplication uint64_t

  // CAS 1: l'entrée est libre
  // Il y a de bonne chance que cela se produise

  if(T->state[h] == ST_FREE)
    switch(op){
      
    case OP_READ: // lecture
      return NULL;
      
    case OP_WRITE: // écriture
      T->key[h] = key;
      T->value[h] = value;
      T->state[h] = ST_SET;
      T->n++; // une nouvelle entrée (key,value)
      return NULL; // ancienne valeur
      
    //case OP_DELETE: // suppression
    //  T->state[h] = ST_DEL; // NB: T->n ne change pas
    //  return NULL;

    }
  
  // CAS 2: l'entrée n'est pas libre
  // Il y a beaucoup de chance que cela soit la bonne clé

  if( key == T->key[h] )
    switch(op){
      
    case OP_READ: // lecture
      return T->value[h];
      
    case OP_WRITE:; // écriture (mise à jour)
      v = T->value[h]; // ancienne valeur à renvoyer
      T->value[h] = value; // NB: ici n et T->state sont corrects
      return v;

    //case OP_DELETE: // suppression, NB: T->n>0
    //  T->state[h] = ST_DEL;
    //  T->n--; // un élément de moins
    //  return T->value[h];
      
    }
  
  // CAS 3: il y a collision

  // Il faut donc chercher la clé dans la table grâce au sondage
  // (linéaire). On s'arrête à la 1ère entrée libre. Pour l'écriture,
  // il faut faire attention que la table ne soit pas pleine sinon la
  // recherche ne déminera pas.
  
  if( 2*T->n > T->mask ){ // si remplissage de la table est >= 50%
    const unsigned m = T->mask + 1; // taille de la table actuelle
    const unsigned m2 = m<<1;       // nouvelle taille (x2)

    // sauvegarde les données (entrées + états)
    int   *K = T->key;
    void* *V = T->value;
    char  *S = T->state;
    
    // nouvelle table 2 fois plus grande
    T->key   = malloc(m2*sizeof(*T->key));
    T->value = malloc(m2*sizeof(*T->value));
    T->state = malloc(m2*sizeof(*T->state));
    T->mask = m2-1; // nouveau mask
    ht_reset(T);    // reset complet de T->state et de T->n
    T->shift--;     // nouveau décalage pour le hash
    // ici T est la nouvelle table, 2 fois plus grande et vidée

    // re-hachage: réécrit l'ancienne table dans la nouvelle
    for(int i=0; i<m; i++) // parcoure les (key,value) de l'ancienne table
      if( S[i] == ST_SET ) ht_lookup(T,K[i],V[i],OP_WRITE);

    // libère les données de l'ancienne table
    free(K); free(V); free(S);

    // on recommence l'opération, nécessairement une écriture, pour
    // (key,value) car le hash courant h pour key n'est pas bon pour
    // la nouvelle table
    return ht_lookup(T,key,value,op);
  }

  // sondage linéaire pour trouver l'indice h d'une entrée libre, qui
  // exite forcément car ici la table n'est pas pleine (taux <= 50%)

  for(;;){ // boucle infinie qui va s'arrêter 

    h = (h+1)&T->mask; // entrée suivante (modulo la taille)
    switch(T->state[h]){ // dépend de l'état de h
      
    case ST_FREE: // entrée libre
      switch(op){
      case OP_READ: return NULL; // key n'est pas dans la table
      case OP_WRITE:
	v = T->value[h]; // ancienne valeur à renvoyer
	T->key[h] = key;
	T->value[h] = value;
	T->state[h] = ST_SET;
	T->n++; // une nouvelle entrée (key,value)
	return v;
      }
      
    case ST_SET: // entrée occupée
      if( key != T->key[h]) continue; // on a pas trouvé la clé
      // on a trouvé la clé
      switch(op){
      case OP_READ: return T->value[h];
      case OP_WRITE:
	v = T->value[h]; // ancienne valeur à renvoyer
	T->value[h] = value; // NB: key et state sont corrects
	T->n++; // une nouvelle entrée (key,value)
	return v;
      }
      
    }
  }
}


inline void* ht_read(htable T, int key){
  return ht_lookup(T, key, NULL, OP_READ);
}


inline void* ht_write(htable T, int key, void* value){
  return ht_lookup(T, key, value, OP_WRITE);
}


//inline void* ht_delete(htable T, int key){
//  return ht_lookup(T, key, NULL, OP_DELETE);
//}


=========================================
File: ./playground_TP/htable.h
=========================================
#ifndef __HTABLE_H__
#define __HTABLE_H__

//////////////////////////////////////////////////////////////////////
//
// Table de hachage dynamique pour des entrées (key,value) de type
// (int,void*). Les opérations autorisées sont:
//
// - ht_create/ht_free: créer ou détruire une table de hachage
// - ht_write: T[key] = value, ajouter (key,value) à la table T 
// - ht_read: return T[key], lire dans T la value correspondant à key
// - ht_reset: supprime toutes les entrées de T, sans détruire T
//
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
//
// Aspects techniques.
//
// La taille de la table est de la forme 2^k, avec k entier > 0. Pour
// distribuer key sur une entrée de la table, disons h, on utilise le
// hash de Fibonacci, les k bits de poids forts d'une grande
// multiplication: h = (key * HT_MAGIC) >> (64-k) où HT_MAGIC est un
// entier sur 64 bits lié au nombre d'or (voir plus loin). La gestion
// des collisions se fait par un adressage ouvert, via un sondage
// linéaire: on prend la première entrée libre suivante (modulo 2^k).
// La table est dynamique et croît par doublement dès que son taux de
// remplissage dépasse 50% lors d'une collision. Il faut alors
// re-hacher l'ancienne table dans la nouvelle. On pourrait passer ce
// taux à 100%, pour consommer moins d'espace, mais cela augmenterait
// significativement le taux de collisions.
//
// Lectures et écritures peuvent prendre, dans le pire des cas, un
// temps linéaire en la taille de la table (2^k) à cause: (1) du
// sondage lors des collisions (mais c'est constant avec un hachage
// uniforme des clés -- en fait, pour un taux de remplissage t<1,
// c'est 1/(1-t) pour un échec et (1/t)*ln(1/(1-t)) pour un succès);
// (2) de la recopie possible et de l'initialisation de la table lors
// du doublement (mais c'est constant en moyenne car amorti sur le
// nombre d'insertions).
//
//////////////////////////////////////////////////////////////////////


typedef struct{
  int *key;       // liste des clés de la table
  void* *value;   // liste de valeurs de la table
  char *state;    // liste des états de chaque entrée (key,value)
  unsigned n;     // nombre d'entrées (key,value) présentes dans la table
  unsigned mask;  // mot binaire de la forme 2^k-1 pour un modulo rapide
  unsigned shift; // décalage pour le calcul rapide du hash
} *htable;


// Constante multiplicative pour le calcul du hash (soit l'indice h de
// key dans la table). Il s'agit du hash de Fibonacci. Cette constante
// correspond au nombre impair le plus proche de 2^64 / φ, où φ =
// (1+√5)/2 est le nombre d'or. Elle est sur 64 bits, de type
// "unsigned long long" (ou uint64_t), d'où le suffixe "llu".
#define HT_MAGIC 11400714819323198485llu


// Taille d'initialisation de la table. Elle doit impérativement être
// une puissance de 2. Elle influence directement le temps de
// ht_create() et ht_reset().
#define HT_INIT_SIZE 4


// Crée une table de hachage. Cette création nécessite une
// initialisation en temps O(HT_INIT_SIZE) = O(1).
htable ht_create(void);


// Supprime la table de hachage créer par ht_create(). Les objets
// insérés dans la table (value) ne sont pas désalloués.
void ht_free(htable T);


// Ajoute de (key,value) dans la table T en écrasant l'ancienne valeur
// (si elle existait). Renvoie la valeur écrasée ou bien NULL si key
// n'était pas dans la table.
void* ht_write(htable T, int key, void* value);


// Lit la valeur correspondant à key dans T. Renvoie NULL si key n'est
// pas dans la table.
void* ht_read(htable T, int key);


// Supprime toutes les entrées de la table sans modifier la taille de
// la table. Cela permet de réutiliser la même table en évitant la
// réallocation dynamique et le re-hachage. Prend un temps
// proportionnel à la taille de la table, pas au nombre d'entrées
// quelle contient.
void ht_reset(htable T);


#endif



=========================================
File: ./playground_TP/pppp.c
=========================================
#include "pppp.h"

//
//  PPPP - Paire de Points les Plus Proches
//
//    Chacun des trois algorithmes doit renvoyer le couple {i,j} d' **
//    indices ** des deux points les plus proches. Voir pppp.h pour
//    une description plus fine. Pour pppp_divide(), c'est la partie
//    récursive pppp_rec() que vous devez programmer.
//
//    -> la structure "point" est définie dans "tools.h"
//    -> la structure "couple" est définie dans "pppp.h"
//
//
// Extensions/optimisations à tester (une fois que vous avez bien
// avancé):
//
// Pour pppp_rec():
//
// . Pour la recherche du min dans Sy, au lieu de mettre "j <= i+7",
//   utilisez "Sy[j].y - Sy[i].y < delta", ce qui va générer moins de
//   tests. Optimisez encore le test avec "Sy[j].y < d" en posant d =
//   delta + Sy[i].y.
//
// . Evitez la construction des tableaux Ax et Bx en réutilisant Vx
//   qui est déjà trié selon les x.
//
// . L'algorithme du cours suppose qu'il n'y a qu'un seul point
//   d'abscisse x*, l'abscisse du médian. Contournez ce problème pour
//   qu'il fonctionne sans cette hypothèse. Pour cela, il faut (1)
//   utiliser le même test de comparaison en x pour le tri de Vx[] et
//   le remplissage de Ay[] afin de garantir |Ax| = |Ay|; et (2) que
//   ce test de comparaison en x soit un ordre total, c'est-à-dire ne
//   donne 0 que si (x,y) = (x',y'), et pas seulement si x = x'.
//   Testez des points sur une grille avec generateGrid() où le nombre
//   de colonnes est de la forme 2^k - 1 (= 1, 3, 7, 15, ...).
//
// . Améliorez l'algorithme pour qu'il fonctionne même s'il y a des
//   points superposés (des points avec même x et même y) en testant
//   les points consécutifs de Vx directement dans pppp_divide().
//   Testez cette situation avec une affectation comme V[n/2] = V[n-1]
//   mise après la génération de points.
//
// Pour pppp_random():
//
// . Il est possible de maintenir l'indice du dernier échec, disons tf
//   (initialisée à -1), de sorte que les instructions 3b et 3c
//   doivent être exécutée seulement si t>tf. Faire attention, lors
//   d'un échec, de bien chercher le point q le plus proche dans le
//   voisinage, sinon il y aura des échecs plusieurs fois au même
//   indice.
//
// . Optimisez le nombre de cellules voisines en passant de 25 à 21
//   cellules à explorez. Comparez.
//
// NB. Pour comparer plusieurs versions, ajouter une autre fonction à
//     pppp.c, disons pppp_random_v2(), et mettez à jour pppp.h et
//     tsp_main.c en ajoutant une ligne.


couple pppp_naive(point* V,int n){
  couple result = {-1,-1};
  ;
  ;
  ;
  return result;
}


// Fonction de comparaison des ordonnées pour qsort():
// renvoie -1 si y(A)<y(B), +1 si y(A)>y(B) et 0 sinon.
int fcmp_y(const void *A, const void *B) {
    double diff = ((point*)A)->y - ((point*)B)->y;
    return (diff > 0) - (diff < 0);
}


// Fonction de comparaison pour des abscisses qsort():
// renvoie -1 si x(A)<x(B), +1 si x(A)>x(B) et 0 sinon.
int fcmp_x(const void *A, const void *B) {
    double diff = ((point*)A)->x - ((point*)B)->x;
    return (diff > 0) - (diff < 0);
}


// paire de points pour pppp_rec()
typedef struct{
  point P1,P2;
} ppoints;


// Cette fonction doit, comme dans l'algorithme du cours, renvoyer la
// paire de points les plus proche pris dans l'ensemble Vx[] (type
// "ppoints"), et non pas les indices des points les plus proches
// (type "couple"). La récurrence est plus simple ainsi. C'est
// pppp_divide() déjà programmée qui se chargera de retrouver les
// indices dans V[] des deux points en question.
//
// Point de vigilance. Le choix du médian, celui de rang m =
// ceil(n/2), est important pour que la séparation en A et B donne
// deux ensembles d'au moins deux points, c'est-à-dire tels |A|=m >= 1
// et |B|=n-m >= 1. Les points ayant des indices commençant à 0, il
// faut donc prendre le point d'indice m-1. Il se trouve aussi que
// ceil(n/2) = floor((n+1)/2) = (int)(n+1)/2.
//
ppoints pppp_rec(point* Vx,point* Vy,int n){
  ppoints Q = {Vx[0],Vx[0]};
  ;
  ;
  ;
  return Q;
}


couple pppp_divide(point* V,int n){

  couple result = {-1,-1};
  ppoints Q;

  // Vx[] = V[] trié selon x
  point *Vx = malloc(n*sizeof(*Vx));
  memcpy(Vx,V,n*sizeof(*V));
  qsort(Vx,n,sizeof(point),fcmp_x);

  // Vy[] = V[] trié selon y
  point *Vy = malloc(n*sizeof(*Vy));
  memcpy(Vy,V,n*sizeof(*V));
  qsort(Vy,n,sizeof(point),fcmp_y);

  // Q = {P1,P2} = paire de points les plus proches
  Q = pppp_rec(Vx,Vy,n);
  free(Vx);
  free(Vy);

  // cherche dans V[] les indices des deux points de Q
  for(int k=0; k<n; k++){
    if( result.i < 0 && Q.P1.x == V[k].x && Q.P1.y == V[k].y ) result.i = k;
    if( result.j < 0 && Q.P2.x == V[k].x && Q.P2.y == V[k].y ) result.j = k;
  }
  
  return result;
}


// map: N^2 -> N définit pour tout couple d'entiers (i,j) un entier
// unique. Il faut i,j >= 0. Il correspond aux nombre de sommets
// contenus dans les diagonales montantes de la forme (t,0) -> (0,t),
// partant de (0,0), et jusqu'à atteindre le point (i,j) sans le
// compter. Cf. le TD.
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
int map(int i, int j) {
    return j + ((i + j) * (i + j + 1)) / 2;
}


// Point de vigilance. Attention à ce que les cellules voisines
// tombent dans le premier quadrant (i,j >= 0), sinon map(i,j) ne
// marchera pas.
couple pppp_random(point* V,int n){
  couple result = {-1,-1};
  ;
  ;
  ;
  return result;
}


=========================================
File: ./playground_TP/pppp.h
=========================================
#ifndef PPPP_H
#define PPPP_H

#include "tools.h"           // pour la structure de point
#include "tsp_brute_force.h" // pour utiliser dist()
#include "htable.h"          // pour la table de hachage


// Un couple d'indices.
typedef struct{
  int i,j;
} couple;


// Algorithme selon la méthode naïve en O(n^2).
// Il s'agit d'examiner toutes les paires de points possibles.
// Suppose qu'il y a au moins n >= 2 points dans V.
couple pppp_naive(point* V, int n);


// Algorithme selon la méthode diviser-pour-régner en O(nlog(n)).
// Il s'agit de l'algorithme vu en cours, cf. section 5.2.3.
// Suppose qu'il y a au moins n >= 2 points dans V.
couple pppp_divide(point* V, int n);


// Algorithme probabiliste en O(n) en moyenne.
// Il s'agit de l'algorithme vu en TD, cf. aussi section 5.2.6 du cours.
// Suppose qu'il y a au moins n >= 2 points dans V.
couple pppp_random(point* V, int n);


#endif


=========================================
File: ./playground_TP/Makefile
=========================================
CC = gcc
#CC = gcc-13
CFLAGS = -O3 -Wall -g -Wno-unused-function -Wno-deprecated-declarations -Wno-uninitialized -Wno-unused-result -Wno-implicit-function-declaration -Wno-unknown-pragmas
LDLIBS = -lm

ifeq ($(shell uname -s), Darwin)
   LDLIBS += -framework OpenGL -framework GLUT
   CPPFLAGS += -I/opt/homebrew/include
else
   LDLIBS += -lglut -lGLU -lGL
   # parfois -lglut n'est pas nécessaire et peut-être supprimé
endif

LDLIBS += $(shell sdl2-config --libs)
LDFLAGS += $(shell sdl2-config --cflags)

tsp_src := $(wildcard tsp_*.c pppp*.c htable*.c)
tsp_obj := $(patsubst %.c,%.o,$(tsp_src))

tsp_main:  tools.o $(tsp_obj)
test_heap: test_heap.o heap.o
a_star:    tools.o a_star.o heap.o


.PHONY: clean
clean:
	rm -f *.o
	rm -f tsp_main
	rm -f test_heap
	rm -f a_star
	rm -f pppp
	rm -fr *.dSYM/


=========================================
File: ./playground_TP/tools.c
=========================================
#include "tools.h"

#define MATH_3D_IMPLEMENTATION
/**

Math 3D v1.0 - 2016-02-15
By Stephan Soller <stephan.soller@helionweb.de> and Tobias Malmsheimer
Licensed under the MIT license

Math 3D is a compact C99 library meant to be used with OpenGL. It provides basic
3D vector and 4x4 matrix operations as well as functions to create transformation
and projection matrices. The OpenGL binary layout is used so you can just upload
vectors and matrices into shaders and work with them without any conversions.

It's an stb style single header file library. Define MATH_3D_IMPLEMENTATION
before you include this file in *one* C file to create the implementation.


QUICK NOTES

- If not explicitly stated by a parameter name all angles are in radians.
- The matrices use column-major indices. This is the same as in OpenGL and GLSL.
  The matrix documentation below for details.
- Matrices are passed by value. This is probably a bit inefficient but
  simplifies code quite a bit. Most operations will be inlined by the compiler
  anyway so the difference shouldn't matter that much. A matrix fits into 4 of
  the 16 SSE2 registers anyway. If profiling shows significant slowdowns the
  matrix type might change but ease of use is more important than every last
  percent of performance.
- When combining matrices with multiplication the effects apply right to left.
  This is the convention used in mathematics and OpenGL. Source:
  https://en.wikipedia.org/wiki/Transformation_matrix#Composing_and_inverting_transformations
  Direct3D does it differently.
- The `m4_mul_pos()` and `m4_mul_dir()` functions do a correct perspective
  divide (division by w) when necessary. This is a bit slower but ensures that
  the functions will properly work with projection matrices. If profiling shows
  this is a bottleneck special functions without perspective division can be
  added. But the normal multiplications should avoid any surprises.
- The library consistently uses a right-handed coordinate system. The old
  `glOrtho()` broke that rule and `m4_ortho()` has be slightly modified so you
  can always think of right-handed cubes that are projected into OpenGLs
  normalized device coordinates.
- Special care has been taken to document all complex operations and important
  sources. Most code is covered by test cases that have been manually calculated
  and checked on the whiteboard. Since indices and math code is prone to be
  confusing we used pair programming to avoid mistakes.

**/

#ifndef MATH_3D_HEADER
#define MATH_3D_HEADER

// Define PI directly because we would need to define the _BSD_SOURCE or
// _XOPEN_SOURCE feature test macros to get it from math.h. That would be a
// rather harsh dependency. So we define it directly if necessary.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


//
// 3D vectors
// 
// Use the `vec3()` function to create vectors. All other vector functions start
// with the `v3_` prefix.
// 
// The binary layout is the same as in GLSL and everything else (just 3 floats).
// So you can just upload the vectors into shaders as they are.
//

typedef struct { unsigned int x, y; } uvec2_t;
typedef struct { float x, y; }        vec2_t;
typedef struct { float x, y, z; }     vec3_t;

static inline vec3_t vec3(float x, float y, float z) { return (vec3_t){ x, y, z }; }

static inline vec3_t v3_add   (vec3_t a, vec3_t b) { return (vec3_t){ a.x + b.x, a.y + b.y, a.z + b.z }; }
static inline vec3_t v3_adds  (vec3_t a, float s)  { return (vec3_t){ a.x + s,   a.y + s,   a.z + s   }; }
static inline vec3_t v3_sub   (vec3_t a, vec3_t b) { return (vec3_t){ a.x - b.x, a.y - b.y, a.z - b.z }; }
static inline vec3_t v3_subs  (vec3_t a, float s)  { return (vec3_t){ a.x - s,   a.y - s,   a.z - s   }; }
static inline vec3_t v3_mul   (vec3_t a, vec3_t b) { return (vec3_t){ a.x * b.x, a.y * b.y, a.z * b.z }; }
static inline vec3_t v3_muls  (vec3_t a, float s)  { return (vec3_t){ a.x * s,   a.y * s,   a.z * s   }; }
static inline vec3_t v3_div   (vec3_t a, vec3_t b) { return (vec3_t){ a.x / b.x, a.y / b.y, a.z / b.z }; }
static inline vec3_t v3_divs  (vec3_t a, float s)  { return (vec3_t){ a.x / s,   a.y / s,   a.z / s   }; }
static inline float  v3_length(vec3_t v)           { return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z); }
static inline vec3_t v3_norm  (vec3_t v);
static inline float  v3_dot   (vec3_t a, vec3_t b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
static inline vec3_t v3_proj  (vec3_t v, vec3_t onto);
static inline vec3_t v3_cross (vec3_t a, vec3_t b);
static inline float  v3_angle_between(vec3_t a, vec3_t b);

static inline vec2_t v2_add   (vec2_t a, vec2_t b) { return (vec2_t){ a.x + b.x, a.y + b.y}; }
static inline vec2_t v2_mul   (vec2_t a, vec2_t b) { return (vec2_t){ a.x * b.x, a.y * b.y}; }
static inline vec2_t v2_div   (vec2_t a, vec2_t b) { return (vec2_t){ a.x / b.x, a.y / b.y}; }

//
// 4×4 matrices
//
// Use the `mat4()` function to create a matrix. You can write the matrix
// members in the same way as you would write them on paper or on a whiteboard:
// 
// mat4_t m = mat4(
//     1,  0,  0,  7,
//     0,  1,  0,  5,
//     0,  0,  1,  3,
//     0,  0,  0,  1
// )
// 
// This creates a matrix that translates points by vec3(7, 5, 3). All other
// matrix functions start with the `m4_` prefix. Among them functions to create
// identity, translation, rotation, scaling and projection matrices.
// 
// The matrix is stored in column-major order, just as OpenGL expects. Members
// can be accessed by indices or member names. When you write a matrix on paper
// or on the whiteboard the indices and named members correspond to these
// positions:
// 
// | m[0][0]  m[1][0]  m[2][0]  m[3][0] |
// | m[0][1]  m[1][1]  m[2][1]  m[3][1] |
// | m[0][2]  m[1][2]  m[2][2]  m[3][2] |
// | m[0][3]  m[1][3]  m[2][3]  m[3][3] |
// 
// | m00  m10  m20  m30 |
// | m01  m11  m21  m31 |
// | m02  m12  m22  m32 |
// | m03  m13  m23  m33 |
// 
// The first index or number in a name denotes the column, the second the row.
// So m[i][j] denotes the member in the ith column and the jth row. This is the
// same as in GLSL (source: GLSL v1.3 specification, 5.6 Matrix Components).
//

typedef union {
  // The first index is the column index, the second the row index. The memory
  // layout of nested arrays in C matches the memory layout expected by OpenGL.
  float m[4][4];
  // OpenGL expects the first 4 floats to be the first column of the matrix.
  // So we need to define the named members column by column for the names to
  // match the memory locations of the array elements.
  struct {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
  };
} mat4_t;

static inline mat4_t mat4(
  float m00, float m10, float m20, float m30,
  float m01, float m11, float m21, float m31,
  float m02, float m12, float m22, float m32,
  float m03, float m13, float m23, float m33
);

static inline mat4_t m4_identity     ();
static inline mat4_t m4_translation  (vec3_t offset);
static inline mat4_t m4_scaling      (vec3_t scale);
static inline mat4_t m4_rotation_x   (float angle_in_rad);
static inline mat4_t m4_rotation_y   (float angle_in_rad);
static inline mat4_t m4_rotation_z   (float angle_in_rad);
              mat4_t m4_rotation     (float angle_in_rad, vec3_t axis);

              mat4_t m4_ortho        (float left, float right, float bottom, float top, float back, float front);
              mat4_t m4_perspective  (float vertical_field_of_view_in_deg, float aspect_ratio, float near_view_distance, float far_view_distance);
              mat4_t m4_look_at      (vec3_t from, vec3_t to, vec3_t up);

static inline mat4_t m4_transpose    (mat4_t matrix);
static inline mat4_t m4_mul          (mat4_t a, mat4_t b);
              mat4_t m4_invert_affine(mat4_t matrix);
              vec3_t m4_mul_pos      (mat4_t matrix, vec3_t position);
              vec3_t m4_mul_dir      (mat4_t matrix, vec3_t direction);

              void   m4_print        (mat4_t matrix);
              void   m4_printp       (mat4_t matrix, int width, int precision);
              void   m4_fprint       (FILE* stream, mat4_t matrix);
              void   m4_fprintp      (FILE* stream, mat4_t matrix, int width, int precision);


//
// 3D vector functions header implementation
//

static inline vec3_t v3_norm(vec3_t v) {
  float len = v3_length(v);
  if (len > 0)
    return (vec3_t){ v.x / len, v.y / len, v.z / len };
  else
    return (vec3_t){ 0, 0, 0};
}

static inline vec3_t v3_proj(vec3_t v, vec3_t onto) {
  return v3_muls(onto, v3_dot(v, onto) / v3_dot(onto, onto));
}

static inline vec3_t v3_cross(vec3_t a, vec3_t b) {
  return (vec3_t){
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
  };
}

static inline float v3_angle_between(vec3_t a, vec3_t b) {
  return acosf( v3_dot(a, b) / (v3_length(a) * v3_length(b)) );
}


//
// Matrix functions header implementation
//

static inline mat4_t mat4(
  float m00, float m10, float m20, float m30,
  float m01, float m11, float m21, float m31,
  float m02, float m12, float m22, float m32,
  float m03, float m13, float m23, float m33
) {
  return (mat4_t){
    .m[0][0] = m00, .m[1][0] = m10, .m[2][0] = m20, .m[3][0] = m30,
    .m[0][1] = m01, .m[1][1] = m11, .m[2][1] = m21, .m[3][1] = m31,
    .m[0][2] = m02, .m[1][2] = m12, .m[2][2] = m22, .m[3][2] = m32,
    .m[0][3] = m03, .m[1][3] = m13, .m[2][3] = m23, .m[3][3] = m33
  };
}

static inline mat4_t m4_identity() {
  return mat4(
     1,  0,  0,  0,
     0,  1,  0,  0,
     0,  0,  1,  0,
     0,  0,  0,  1
  );
}

static inline mat4_t m4_translation(vec3_t offset) {
  return mat4(
     1,  0,  0,  offset.x,
     0,  1,  0,  offset.y,
     0,  0,  1,  offset.z,
     0,  0,  0,  1
  );
}

static inline mat4_t m4_scaling(vec3_t scale) {
  float x = scale.x, y = scale.y, z = scale.z;
  return mat4(
     x,  0,  0,  0,
     0,  y,  0,  0,
     0,  0,  z,  0,
     0,  0,  0,  1
  );
}

static inline mat4_t m4_rotation_x(float angle_in_rad) {
  float s = sinf(angle_in_rad), c = cosf(angle_in_rad);
  return mat4(
    1,  0,  0,  0,
    0,  c, -s,  0,
    0,  s,  c,  0,
    0,  0,  0,  1
  );
}

static inline mat4_t m4_rotation_y(float angle_in_rad) {
  float s = sinf(angle_in_rad), c = cosf(angle_in_rad);
  return mat4(
     c,  0,  s,  0,
     0,  1,  0,  0,
    -s,  0,  c,  0,
     0,  0,  0,  1
  );
}

static inline mat4_t m4_rotation_z(float angle_in_rad) {
  float s = sinf(angle_in_rad), c = cosf(angle_in_rad);
  return mat4(
     c, -s,  0,  0,
     s,  c,  0,  0,
     0,  0,  1,  0,
     0,  0,  0,  1
  );
}

static inline mat4_t m4_transpose(mat4_t matrix) {
  return mat4(
    matrix.m00, matrix.m01, matrix.m02, matrix.m03,
    matrix.m10, matrix.m11, matrix.m12, matrix.m13,
    matrix.m20, matrix.m21, matrix.m22, matrix.m23,
    matrix.m30, matrix.m31, matrix.m32, matrix.m33
  );
}

/**
 * Multiplication of two 4x4 matrices.
 * 
 * Implemented by following the row times column rule and illustrating it on a
 * whiteboard with the proper indices in mind.
 * 
 * Further reading: https://en.wikipedia.org/wiki/Matrix_multiplication
 * But note that the article use the first index for rows and the second for
 * columns.
 */
static inline mat4_t m4_mul(mat4_t a, mat4_t b) {
  mat4_t result;
  
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      float sum = 0;
      for(int k = 0; k < 4; k++) {
        sum += a.m[k][j] * b.m[i][k];
      }
      result.m[i][j] = sum;
    }
  }
  
  return result;
}

#endif // MATH_3D_HEADER


#ifdef MATH_3D_IMPLEMENTATION

/**
 * Creates a matrix to rotate around an axis by a given angle. The axis doesn't
 * need to be normalized.
 * 
 * Sources:
 * 
 * https://en.wikipedia.org/wiki/Rotation_matrix#Rotation_matrix_from_axis_and_angle
 */
mat4_t m4_rotation(float angle_in_rad, vec3_t axis) {
  vec3_t normalized_axis = v3_norm(axis);
  float x = normalized_axis.x, y = normalized_axis.y, z = normalized_axis.z;
  float c = cosf(angle_in_rad), s = sinf(angle_in_rad);
  
  return mat4(
    c + x*x*(1-c),            x*y*(1-c) - z*s,      x*z*(1-c) + y*s,  0,
        y*x*(1-c) + z*s,  c + y*y*(1-c),            y*z*(1-c) - x*s,  0,
        z*x*(1-c) - y*s,      z*y*(1-c) + x*s,  c + z*z*(1-c),        0,
        0,                        0,                    0,            1
  );
}


/**
 * Creates an orthographic projection matrix. It maps the right handed cube
 * defined by left, right, bottom, top, back and front onto the screen and
 * z-buffer. You can think of it as a cube you move through world or camera
 * space and everything inside is visible.
 * 
 * This is slightly different from the traditional glOrtho() and from the linked
 * sources. These functions require the user to negate the last two arguments
 * (creating a left-handed coordinate system). We avoid that here so you can
 * think of this function as moving a right-handed cube through world space.
 * 
 * The arguments are ordered in a way that for each axis you specify the minimum
 * followed by the maximum. Thats why it's bottom to top and back to front.
 * 
 * Implementation details:
 * 
 * To be more exact the right-handed cube is mapped into normalized device
 * coordinates, a left-handed cube where (-1 -1) is the lower left corner,
 * (1, 1) the upper right corner and a z-value of -1 is the nearest point and
 * 1 the furthest point. OpenGL takes it from there and puts it on the screen
 * and into the z-buffer.
 * 
 * Sources:
 * 
 * https://msdn.microsoft.com/en-us/library/windows/desktop/dd373965(v=vs.85).aspx
 * https://unspecified.wordpress.com/2012/06/21/calculating-the-gluperspective-matrix-and-other-opengl-matrix-maths/
 */
mat4_t m4_ortho(float left, float right, float bottom, float top, float back, float front) {
  float l = left, r = right, b = bottom, t = top, n = front, f = back;
  float tx = -(r + l) / (r - l);
  float ty = -(t + b) / (t - b);
  float tz = -(f + n) / (f - n);
  return mat4(
     2 / (r - l),  0,            0,            tx,
     0,            2 / (t - b),  0,            ty,
     0,            0,            2 / (f - n),  tz,
     0,            0,            0,            1
  );
}

/**
 * Creates a perspective projection matrix for a camera.
 * 
 * The camera is at the origin and looks in the direction of the negative Z axis.
 * `near_view_distance` and `far_view_distance` have to be positive and > 0.
 * They are distances from the camera eye, not values on an axis.
 * 
 * `near_view_distance` can be small but not 0. 0 breaks the projection and
 * everything ends up at the max value (far end) of the z-buffer. Making the
 * z-buffer useless.
 * 
 * The matrix is the same as `gluPerspective()` builds. The view distance is
 * mapped to the z-buffer with a reciprocal function (1/x). Therefore the z-buffer
 * resolution for near objects is very good while resolution for far objects is
 * limited.
 * 
 * Sources:
 * 
 * https://unspecified.wordpress.com/2012/06/21/calculating-the-gluperspective-matrix-and-other-opengl-matrix-maths/
 */
mat4_t m4_perspective(float vertical_field_of_view_in_deg, float aspect_ratio, float near_view_distance, float far_view_distance) {
  float fovy_in_rad = vertical_field_of_view_in_deg / 180 * M_PI;
  float f = 1.0f / tanf(fovy_in_rad / 2.0f);
  float ar = aspect_ratio;
  float nd = near_view_distance, fd = far_view_distance;
  
  return mat4(
     f / ar,           0,                0,                0,
     0,                f,                0,                0,
     0,                0,               (fd+nd)/(nd-fd),  (2*fd*nd)/(nd-fd),
     0,                0,               -1,                0
  );
}

/**
 * Builds a transformation matrix for a camera that looks from `from` towards
 * `to`. `up` defines the direction that's upwards for the camera. All three
 * vectors are given in world space and `up` doesn't need to be normalized.
 * 
 * Sources: Derived on whiteboard.
 * 
 * Implementation details:
 * 
 * x, y and z are the right-handed base vectors of the cameras subspace.
 * x has to be normalized because the cross product only produces a normalized
 *   output vector if both input vectors are orthogonal to each other. And up
 *   probably isn't orthogonal to z.
 * 
 * These vectors are then used to build a 3x3 rotation matrix. This matrix
 * rotates a vector by the same amount the camera is rotated. But instead we
 * need to rotate all incoming vertices backwards by that amount. That's what a
 * camera matrix is for: To move the world so that the camera is in the origin.
 * So we take the inverse of that rotation matrix and in case of an rotation
 * matrix this is just the transposed matrix. That's why the 3x3 part of the
 * matrix are the x, y and z vectors but written horizontally instead of
 * vertically.
 * 
 * The translation is derived by creating a translation matrix to move the world
 * into the origin (thats translate by minus `from`). The complete lookat matrix
 * is then this translation followed by the rotation. Written as matrix
 * multiplication:
 * 
 *   lookat = rotation * translation
 * 
 * Since we're right-handed this equals to first doing the translation and after
 * that doing the rotation. During that multiplication the rotation 3x3 part
 * doesn't change but the translation vector is multiplied with each rotation
 * axis. The dot product is just a more compact way to write the actual
 * multiplications.
 */
mat4_t m4_look_at(vec3_t from, vec3_t to, vec3_t up) {
  vec3_t z = v3_muls(v3_norm(v3_sub(to, from)), -1);
  vec3_t x = v3_norm(v3_cross(up, z));
  vec3_t y = v3_cross(z, x);
  
  return mat4(
    x.x, x.y, x.z, -v3_dot(from, x),
    y.x, y.y, y.z, -v3_dot(from, y),
    z.x, z.y, z.z, -v3_dot(from, z),
    0,   0,   0,    1
  );
}


/**
 * Inverts an affine transformation matrix. That are translation, scaling,
 * mirroring, reflection, rotation and shearing matrices or any combination of
 * them.
 * 
 * Implementation details:
 * 
 * - Invert the 3x3 part of the 4x4 matrix to handle rotation, scaling, etc.
 *   correctly (see source).
 * - Invert the translation part of the 4x4 matrix by multiplying it with the
 *   inverted rotation matrix and negating it.
 * 
 * When a 3D point is multiplied with a transformation matrix it is first
 * rotated and then translated. The inverted transformation matrix is the
 * inverse translation followed by the inverse rotation. Written as a matrix
 * multiplication (remember, the effect applies right to left):
 * 
 *   inv(matrix) = inv(rotation) * inv(translation)
 * 
 * The inverse translation is a translation into the opposite direction, just
 * the negative translation. The rotation part isn't changed by that
 * multiplication but the translation part is multiplied by the inverse rotation
 * matrix. It's the same situation as with `m4_look_at()`. But since we don't
 * store the rotation matrix as 3D vectors we can't use the dot product and have
 * to write the matrix multiplication operations by hand.
 * 
 * Sources for 3x3 matrix inversion:
 * 
 * https://www.khanacademy.org/math/precalculus/precalc-matrices/determinants-and-inverses-of-large-matrices/v/inverting-3x3-part-2-determinant-and-adjugate-of-a-matrix
 */
mat4_t m4_invert_affine(mat4_t matrix) {
  // Create shorthands to access matrix members
  float m00 = matrix.m00,  m10 = matrix.m10,  m20 = matrix.m20,  m30 = matrix.m30;
  float m01 = matrix.m01,  m11 = matrix.m11,  m21 = matrix.m21,  m31 = matrix.m31;
  float m02 = matrix.m02,  m12 = matrix.m12,  m22 = matrix.m22,  m32 = matrix.m32;
  
  // Invert 3x3 part of the 4x4 matrix that contains the rotation, etc.
  // That part is called R from here on.
    
    // Calculate cofactor matrix of R
    float c00 =   m11*m22 - m12*m21,   c10 = -(m01*m22 - m02*m21),  c20 =   m01*m12 - m02*m11;
    float c01 = -(m10*m22 - m12*m20),  c11 =   m00*m22 - m02*m20,   c21 = -(m00*m12 - m02*m10);
    float c02 =   m10*m21 - m11*m20,   c12 = -(m00*m21 - m01*m20),  c22 =   m00*m11 - m01*m10;
    
    // Caclculate the determinant by using the already calculated determinants
    // in the cofactor matrix.
    // Second sign is already minus from the cofactor matrix.
    float det = m00*c00 + m10*c10 + m20 * c20;
    if (fabsf(det) < 0.00001)
      return m4_identity();
    
    // Calcuate inverse of R by dividing the transposed cofactor matrix by the
    // determinant.
    float i00 = c00 / det,  i10 = c01 / det,  i20 = c02 / det;
    float i01 = c10 / det,  i11 = c11 / det,  i21 = c12 / det;
    float i02 = c20 / det,  i12 = c21 / det,  i22 = c22 / det;
  
  // Combine the inverted R with the inverted translation
  return mat4(
    i00, i10, i20,  -(i00*m30 + i10*m31 + i20*m32),
    i01, i11, i21,  -(i01*m30 + i11*m31 + i21*m32),
    i02, i12, i22,  -(i02*m30 + i12*m31 + i22*m32),
    0,   0,   0,      1
  );
}

/**
 * Multiplies a 4x4 matrix with a 3D vector representing a point in 3D space.
 * 
 * Before the matrix multiplication the vector is first expanded to a 4D vector
 * (x, y, z, 1). After the multiplication the vector is reduced to 3D again by
 * dividing through the 4th component (if it's not 0 or 1).
 */
vec3_t m4_mul_pos(mat4_t matrix, vec3_t position) {
  vec3_t result = vec3(
    matrix.m00 * position.x + matrix.m10 * position.y + matrix.m20 * position.z + matrix.m30,
    matrix.m01 * position.x + matrix.m11 * position.y + matrix.m21 * position.z + matrix.m31,
    matrix.m02 * position.x + matrix.m12 * position.y + matrix.m22 * position.z + matrix.m32
  );
  
  float w = matrix.m03 * position.x + matrix.m13 * position.y + matrix.m23 * position.z + matrix.m33;
  if (w != 0 && w != 1)
    return vec3(result.x / w, result.y / w, result.z / w);
  
  return result;
}

/**
 * Multiplies a 4x4 matrix with a 3D vector representing a direction in 3D space.
 * 
 * Before the matrix multiplication the vector is first expanded to a 4D vector
 * (x, y, z, 0). For directions the 4th component is set to 0 because directions
 * are only rotated, not translated. After the multiplication the vector is
 * reduced to 3D again by dividing through the 4th component (if it's not 0 or
 * 1). This is necessary because the matrix might contains something other than
 * (0, 0, 0, 1) in the bottom row which might set w to something other than 0
 * or 1.
 */
vec3_t m4_mul_dir(mat4_t matrix, vec3_t direction) {
  vec3_t result = vec3(
    matrix.m00 * direction.x + matrix.m10 * direction.y + matrix.m20 * direction.z,
    matrix.m01 * direction.x + matrix.m11 * direction.y + matrix.m21 * direction.z,
    matrix.m02 * direction.x + matrix.m12 * direction.y + matrix.m22 * direction.z
  );
  
  float w = matrix.m03 * direction.x + matrix.m13 * direction.y + matrix.m23 * direction.z;
  if (w != 0 && w != 1)
    return vec3(result.x / w, result.y / w, result.z / w);
  
  return result;
}

void m4_print(mat4_t matrix) {
  m4_fprintp(stdout, matrix, 6, 2);
}

void m4_printp(mat4_t matrix, int width, int precision) {
  m4_fprintp(stdout, matrix, width, precision);
}

void m4_fprint(FILE* stream, mat4_t matrix) {
  m4_fprintp(stream, matrix, 6, 2);
}

void m4_fprintp(FILE* stream, mat4_t matrix, int width, int precision) {
  mat4_t m = matrix;
  int w = width, p = precision;
  for(int r = 0; r < 4; r++) {
    fprintf(stream, "| %*.*f %*.*f %*.*f %*.*f |\n",
      w, p, m.m[0][r], w, p, m.m[1][r], w, p, m.m[2][r], w, p, m.m[3][r]
    );
  }
}

#endif // MATH_3D_IMPLEMENTATION


//
// Les constantes char* xxx_glsl ci-dessous sont les programmes GLSL
// (OpenGL Shading Language), les shaders, envoyés à la carte
// graphique (GPU) permettant de visualiser les éléments graphiques de
// la scène.
//
// Les shaders "vertex" sont chargés de convertir les positions 3D en
// pixels 2D. La sortie est donc la position des pixels (out vec2:
// x,y) sur l'écran. Les shaders "fragment" s'occupent du rendu de
// chaque pixel (in vec2), c'est-à-dire de leur couleur (out vec4:
// R,G,B,𝛼). Ici R,G,B,𝛼 sont dans [0,1].
//
// Les variables précédées de "in/out" décrivent les entrées sorties
// du GPU, alors que les "uniform" décrivent des variables de
// communications avec le CPU.
//
// Ressources:
//
// • Shadertoy: https://www.shadertoy.com/
// • Inigo Quilez website: https://iquilezles.org/articles/
// • 2D signed distance functions: https://iquilezles.org/articles/distf...
// • Color palette article: https://iquilezles.org/articles/palet...
// • Color palette webapp: http://dev.thi.ng/gradients/
// • Graphtoy: https://graphtoy.com/
// • GLSL Reference & Swizzling: https://www.khronos.org/opengl/wiki/D...
// • The Book of Shaders: https://thebookofshaders.com/
// • Shadertoy Unofficial: https://shadertoyunofficial.wordpress...

const char* texture_frag_glsl = "\n					\
#version 410\n								\
\n									\
in  vec2 coord;\n							\
out vec4 color;\n							\
\n									\
// (.x,.y): translation, .z: scale\n					\
uniform vec3 translation_scale;\n					\
uniform vec2 screensize;\n						\
uniform sampler2D tex;\n						\
\n									\
void main(){\n								\
   vec2 center = vec2(0.5,0.5);\n					\
   vec2 texsize  = textureSize(tex, 0);\n				\
   vec2 texscale = screensize/texsize;\n				\
   texscale = texscale/min(texscale.x, texscale.y);\n			\
   vec2 p = translation_scale.xy + (coord-center)/translation_scale.z;\n \
   color = vec4(texture(tex, p*texscale).xyz, 1);\n     		\
}\n									\
";

const char* texture_vert_glsl = "\n                             \
#version 410\n							\
\n								\
out vec2 coord;\n						\
\n								\
// (.x,.y): translation, .z: scale\n				\
uniform vec3 translation_scale;\n				\
\n								\
vec2 positions[6] = vec2[6](\n					\
   vec2(-1, -1),\n						\
   vec2(+1, -1),\n						\
   vec2(+1, +1),\n						\
   vec2(-1, -1),\n						\
   vec2(+1, +1),\n						\
   vec2(-1, +1)\n						\
);\n								\
\n								\
void main(){\n							\
   coord = (positions[gl_VertexID] + vec2(1))/2.0;\n		\
   gl_Position = vec4(positions[gl_VertexID], 0.0, 1.0);\n	\
}\n								\
"; 

const char* geom_vert_glsl = "\n                                        \
#version 410\n								\
\n									\
layout(location = 0) in vec3 pos;\n					\
layout(location = 1) in vec3 color;\n					\
\n									\
out vec3 fpos;\n							\
out vec3 fcolor;\n							\
\n									\
// (.x,.y): translation, .z: scale\n					\
uniform vec3 translation_scale;\n					\
\n									\
void main(){\n								\
   vec2 center = vec2(0.5,0.5);\n					\
   fpos = pos;\n							\
   fpos.xy = center + (pos.xy-translation_scale.xy)*translation_scale.z;\n \
   fcolor = color;\n							\
   vec2 glpos = (fpos.xy-center)*2.0;\n					\
   gl_Position = vec4(glpos, pos.z, 1);\n				\
}\n									\
";

const char* geom_frag_glsl = "\n \
#version 410\n			 \
\n				 \
in vec3 fpos;\n			 \
in vec3 fcolor;\n		 \
out vec4 pcolor;\n		 \
\n				 \
void main(){\n			 \
   pcolor = vec4(fcolor, 1);\n	 \
}\n				 \
";

const char* mapshader_vert_glsl = "\n   \
#version 410\n				\
\n					\
layout(location = 0) in vec3 pos;\n	\
out vec3 fpos;\n			\
\n					\
uniform mat4 MVP;\n			\
uniform vec3 bbox;\n			\
\n					\
void main(){\n				\
   fpos = pos;\n			\
   gl_Position = MVP*vec4(pos, 1.0);\n	\
}\n					\
";

// Shader pour l'affichage des triangles de la grille.
//
// La lumière dépend de la hauteur max (bbox.y) via le coefficient
// hcoeff compris dans [0,1] (et via les variables externes lux et
// contrast). La 2e ligne avec hcoeff permet de définir l'ombre où la
// source de l'éclairage est la caméra (cam_pos).
//
// mix() et clamp() sont des fonctions GLSL prédéfinies:
// - mix(a,b,x) = (1-x)*a + x*b -> interpolation de x entre a et b
// - clamp(x, a, b) = min(max(x, a), b) -> met x dans [a,b]
//
const char* mapshader_frag_glsl = "\n                                   \
#version 410\n								\
\n									\
in vec3 fpos;\n								\
out vec4 color;\n							\
\n									\
uniform float contrast;\n						\
uniform float lux;\n							\
uniform vec3 bbox;\n							\
uniform vec3 cam_pos;\n							\
uniform sampler2D maptex;\n						\
\n									\
void main(){\n								\
    vec2 coord = (fpos/bbox).xz + vec2(0.5);\n				\
    float r = fpos.y/bbox.y;\n						\
    float hcoeff = (bbox.y < 0.01)? 1.0 : clamp(mix(lux, sqrt(r)*1.5, contrast), 0.0, 1.0);\n \
    hcoeff *= max(0.5, dot(normalize(cross(dFdx(fpos)*1000.0, dFdy(fpos)*1000.0)), normalize(cam_pos)));\n \
    float dcam = distance(fpos, cam_pos);\n				\
    float lightcam = min(0.6/(dcam*dcam), 1.0);\n			\
    color = vec4(texture(maptex, coord).xyz*(hcoeff+lightcam), 1.0);\n	\
}\n									\
";

#define MAX_GLBUFFERS_VAO 5

typedef unsigned int uint;

typedef struct {
  uint vertex;
  uint fragment;
  uint program;
} GLShader;

typedef struct {
  uint id;
  uint size; // taille de data[]
  vec3_t* data;
} GLBuffer;

typedef struct {
  vec3_t data[MAX_VERTICES];
  uint size;
} StaticVector;

typedef struct {
  uint id;
  uint size; // taille de data[]
  uint* data;
} GLElementBuffer;

typedef struct {
  uint id;
  GLBuffer* attached[MAX_GLBUFFERS_VAO+1];
  GLElementBuffer* indices;
} VAO;

//
// Structure contenant tous les sommets et les triangles décrivant la
// grille G. Chaque cellule (x,y) de la grille a 4 coins (corners),
// soit (G->X+1)*(G->Y+1) sommets, et un centre, soit G->X*G->Y autres
// sommets. Les centres sont stockés dans GLBuffer après tous les
// corners, c'est-à-dire à partir de l'indice (G->X+1)*(G->Y+1).
//
typedef struct {
  grid* G; // la grille
  GLBuffer* vertices; // les sommets
  GLElementBuffer* indices; // les triangles (indices de sommets)
  vec2_t size; // bounding boxes de la grille (2D)
} GridBuffer;

enum camViewMode { ROTATING=0, MANUAL };


///////////////////////////////////////////////////////////////////////////
//
// Variables et fonctions internes (static) qui ne doivent pas être
// visibles à l'extérieur de ce fichier. À ne pas mettre dans le .h.
//
///////////////////////////////////////////////////////////////////////////

// pour l'affichage de l'aide
static char HELP[] = "\n\
┌──\n\
│ Commandes pour l'interface graphique\n\
│\n\
│  [h] ... affiche l'aide\n\
│  [q] ... passe running à false\n\
│  [p] ... pause de 0\"5, maintenir pour pause plus longue\n\
│  [souris] ... déplacement d'un ou de tous les points, zoom\n\
│\n\
│ Spécifique pour TSP:\n\
│\n\
│  [s] ... change la taille des points\n\
│  [o] ... indique l'orientation de la tournée\n\
│  [r] ... indique le point de départ (racine du MST) de la tournée\n\
│  [t] ... dessine ou pas la tournée et/ou l'arbre MST\n\
│  [g] ... dessine ou pas une grille pour le positionnement des points\n\
│  [u] ... recentrage (modification) du nuage de points dans la fenêtre\n\
│  [w] ... écrit les coordonnées des points dans un fichier\n\
│\n\
│ Spécifique pour A*:\n\
│\n\
│  [c] ..... maintient ou supprime les sommets visités à la fin de A*\n\
│  [-/+] ... ralentit/accélère drawGrid() et l'exécution d'A*\n\
│  [z/a] ... idem que [-/+]\n\
│  [d] ..... bascule la vue en 3D ou 2D\n\
│  [l/m] ... en vue 3D, ralentit/accélère la vitesse de la caméra\n\
│  [k] ..... en vue 3D, stoppe la caméra\n\
│  [1/2] ... en vue 3D, diminue/augmente la lumineusité\n\
│  [3/4] ... en vue 3D, diminue/augmente le constrast\n\
└──\n\
";

// nombres d'appels au dessin de la grille attendus par seconde
static unsigned long call_speed = 1 << 7;

static float mouse_dx = 0; // distance parcourue par la souris en x depuis le dernier calcul de MVP
static float mouse_dy = 0; // distance parcourue par la souris en y depuis le dernier calcul de MVP
static bool mouse_ldown = false; // bouton souris gauche, vrai si enfoncé
static bool mouse_rdown = false; // boutons souris droit, vrai si enfoncé
static bool oriented = false;    // pour afficher l'orientation de la tournée
static bool root = false;        // pour afficher le point de départ de la tournée
static int selectedVertex = -1;  // indice du point sélectionné avec la souris
static point *POINT = NULL;      // tableau de points (interne)
static int nPOINT = 0;           // nombre de points (de POINTS)
static int mst = 3;              // pour drawGraph():
                                 // bit-0: dessin de l'arbre (1=oui/0=non)
                                 // bit-1: dessin de la tournée (1=oui/0=non)
static int quadrillage = 0;      // quadrillage pour drawX(): 0 (=off), 1, 2, 3, 0
static SDL_Window *window;       // la fenêtre d'affichage
static SDL_GLContext glcontext;
static GLvoid *gridImage;        // image de pixels calculée à partir d'une 'grid' G
static int view3D = 0;           // par défaut, vue en 2D (= 1 si 3D)

static GLuint maptexture;

// les shaders
static GLShader mapshader;
static GLShader texshader;
static GLShader geomshader;

// variables permettant de communiquer entre GPU et CPU
static uint MVP_location = 0;
static uint lux_location = 0;
static uint contrast_location = 0;
static uint bbox_location = 0;
static uint cam_pos_location = 0;
static uint transcale_location = 0;
static uint screensize_location = 0;
static uint geom_transcale_location = 0;

static vec3_t transcale = {0.5, 0.5, 1.0}; // (.x,.y): translation, .z: scale
static vec3_t cpuvertices[MAX_VERTICES];
static vec3_t cpucolors[MAX_VERTICES];
static uint cpu_triangles_amount = 0;

static VAO* vao3d   = NULL;
static VAO* vaotex  = NULL;
static VAO* vaogeom = NULL;
static GridBuffer* glgrid  = NULL;
static GLBuffer* gvertices = NULL;
static GLBuffer* gcolors   = NULL;

static vec3_t cam_pos = {0,0,-2};
static vec3_t cam_dir = {0,0,1};
static vec3_t up_head = {0,1,0};
static vec3_t cam_target = {0,0,-1};
static float cam_speed = 0.2f;
static float cam_old_speed = 0.2f;
static float cam_manual_speed = 0.012f;
static float cam_sensi = -0.006f;
static float cam_angle = 0.0f;
static float cam_arrows_speed = 0.1f;
static float cam_tour_radius = 4.0f;
static enum camViewMode cam_view_mode = ROTATING;

static vec3_t bbox; // bounding boxes de la scène
static mat4_t proj;
static mat4_t view;
static mat4_t MVP;

static float  contrast = 0.5; // contrast dans [0,1] 
static float  lux      = 1.2; // lumière dans [0,+∞[ (pas d'effet si constrast=1)

//////////////////////////////////////////////////////////////////////
// Functions principales OpenGL
//////////////////////////////////////////////////////////////////////
static GridBuffer* createGridBuffer(grid*);
static void freeGridBuffer(GridBuffer*);
static void compute_MVP();
static void error(const char*);
static VAO* createVAO(void);
static void bindVAO(const VAO*);
static void unbindVAO(void);
static void freeVAO(VAO*);
static GLBuffer* createEmptyGLBuffer(void);
static GLBuffer* createGLBuffer(vec3_t*, uint);
static GLElementBuffer* createEmptyGLElementBuffer(void);
static GLElementBuffer* createGLElementBuffer(uint*, uint);
static void bindGLBuffer(GLBuffer*);
static void bindGLElementBuffer(GLElementBuffer*);
static void recreateGLBufferDataGPU(GLBuffer*);
static void recreateGLElementBufferGPU(GLElementBuffer*);
static void replaceGLBufferData(GLBuffer*, vec3_t*, uint, uint);
static void freeGLBuffer(GLBuffer*);
static void freeGLElementBuffer(GLElementBuffer*);
static void attachBuffertoVAO(VAO*, GLBuffer*, uint);
static void attachElementBufferVAO(VAO*, GLElementBuffer*);
static void drawVAO(GLShader*, VAO*);
static void draw_stored_triangles();
static void prepareDrawLineGrad(const point, const point, const vec3_t, const vec3_t, float);
static void prepareDrawLine(const point, const point, const vec3_t, double);
static void prepareDrawPoint(const point, const vec3_t, double);
static vec3_t point_to_glcoord(const point);
static void prepareDrawArrow(const point, const point, const vec3_t, double);
static void prepareDrawTriangleGradGLcoord(const vec3_t, const vec3_t, const vec3_t, const vec3_t, const vec3_t, const vec3_t);
//////////////////////////////////////////////////////////////////////

static vec3_t right_dir(void) { return v3_norm(v3_cross(cam_dir, (vec3_t){0,1,0})); }
static vec3_t up_dir(void) { return v3_cross((vec3_t){0,1,0}, v3_norm(v3_cross(cam_dir, (vec3_t){0,1,0}))); }

static void openglerr(void) {
  GLenum err;
  while ((err = glGetError()) != GL_NO_ERROR)
    printf("OpenGL error: %d\n", err);
}

// Donne la hauteur du corner (x,y). Les hauteurs sont décalées de
// G->hmin pour que le point le plus bas soit en y = 0, sinon
// l'ensemble est trop sombre. Renvoie 0 si (x,y) est sur le bord de
// G.
static float get_corner_height(grid *G, uint x, uint y) {
  if(mounts <= 0) return 0;
  if(x >= G->X || y >= G->Y || x <= 0 || y <= 0) return 0;
  return G->height[x][y] - G->hmin;
}

// Interpole (=barycentre) la hauteur du centre à partir des 4 corners
// de la cellule (x,y).
static float get_center_height(grid *G, uint x, uint y) {
  return (get_corner_height(G, x+0, y+0)+
	  get_corner_height(G, x+1, y+0)+
	  get_corner_height(G, x+1, y+1)+
	  get_corner_height(G, x+0, y+1))/4;
}

// Construit dans un GridBuffer, à partir de la grille G, tous les
// sommets et les triangles. Chaque cellule (x,y) de la grille est est
// un carré unité qui est découpée en 4 triangles partageant le centre
// du carré.
//
// 1 cellule   4 corners + 1 center
//   o---o          o---o
//   |   |          |\ /|
//   |   |          | o |
//   |   |          |/ \|
//   o---o          o---o
//
static GridBuffer* createGridBuffer(grid *G) {

  GridBuffer* B = malloc(sizeof(*B));

  B->G = G;
  B->vertices = createEmptyGLBuffer(); // les sommets
  B->indices  = createEmptyGLElementBuffer(); // les triangles

  // raccourcis
  GLBuffer* V = B->vertices;
  GLElementBuffer* I = B->indices;

  // allocation des sommets
  V->size = (G->X+1)*(G->Y+1)+(G->X)*(G->Y); // nb de vertices dans buffer
  V->size += 5; // pour le drapeau (4 sommets)
  V->data = malloc(sizeof(*V->data)*V->size); // 1 vertex = 1 vec3_t

  // allocation des triangles (1 triangle = 3 indices consécutifs)
  I->size = (G->X)*(G->Y)*4*3; // nb d'indices dans buffer
  I->size += 3*3; // pour le drapeau (2 triangles)
  I->data = malloc(sizeof(*I->data)*I->size); // 1 triangle = 3 uint

  // Fixe les coordonnées des corners. NB: Les x et y sont décalés
  // pour que le centre de la grille soit en (0,0,h).

  uint idata = 0; // indices pour V->data[]

  for(uint x=0; x<=G->X; x++)
    for(uint y=0; y<=G->Y; y++){
      float fx = (float)x - (float)G->X / 2.0f; // centrage en x
      float fy = (float)y - (float)G->Y / 2.0f; // centrage en y
      float h = get_corner_height(B->G, x, y); // hauteur de (x,y)
      V->data[idata++] = (vec3_t){ fx, h, fy };
    }

  // indice à partir duquel sont stockés les centers
  uint icenters = idata;

  // Fixe les coordonnées des centres. NB: Les x et y sont décalés
  // pour que le centre de la grille soit en (0,0,h).

  for(uint x=0; x<G->X; x++) // pour chaque cellule (x,y) de G
    for(uint y=0; y<G->Y; y++){
      
      float fx = (float)x - (float)G->X / 2.0f + 0.5f; // centrage en x
      float fy = (float)y - (float)G->Y / 2.0f + 0.5f; // centrage en y
      float h = get_center_height(B->G, x, y); // hauteur de (x,y)
      V->data[idata++] = (vec3_t){ fx, h, fy };
    }

  // Fixe les triangles, 4 triangles par cellule de G, chacun étant un
  // triplet d'indices à mettre dans I->data.

  uint itriangle = 0; // indices pour I->data[] 

  for(uint x=0; x<G->X; x++) // pour chaque cellule (x,y) de G
    for(uint y=0; y<G->Y; y++){
      
      uint corners[4] = { // indices des 4 corners de (x,y)
	(G->Y+1)*(x+0) + (y+0),
	(G->Y+1)*(x+0) + (y+1),
	(G->Y+1)*(x+1) + (y+1),
	(G->Y+1)*(x+1) + (y+0),
      };
      uint center = icenters + G->Y*x + y; // indice du centre de (x,y)

      for(uint i=0; i<4; i++){ // les 4 triangles pour (x,y)
        I->data[itriangle++] = corners[i]; 
        I->data[itriangle++] = corners[(i+1)%4]; 
        I->data[itriangle++] = center;
      }
    }

  // Ajout du drapeau sur la cellule G.end: 5 sommets et 3 triangles
  //
  // D----     A = centre de la cellule
  // |\   \    A-B-D à la verticale
  // B-C---E   B-C-E à l'horizontale
  // | /
  // |/
  // A

  uint iflag = idata; // indice des sommets du drapeau

  float fx = (float)G->end.x - (float)G->X / 2.0f + 0.5f; // Centre de G->end
  float fz = (float)G->end.y - (float)G->Y / 2.0f + 0.5f;
  float fy = get_center_height(G, G->end.x, G->end.y);
  float H = (G->hmax-G->hmin)/15.0f; // hauteur total du drapeau
  
  // Sommets du drapeau (après ceux de la grille)
  V->data[idata++] = (vec3_t){ fx,      fy,        fz };      // A
  V->data[idata++] = (vec3_t){ fx,      fy+0.7f*H, fz };      // B
  V->data[idata++] = (vec3_t){ fx+0.3f, fy+0.7f*H, fz+0.3f }; // C
  V->data[idata++] = (vec3_t){ fx,      fy+H,      fz };      // D
  V->data[idata++] = (vec3_t){ fx+1.5f, fy+0.7f*H, fz+1.5f }; // E

  // Triangles du drapeau (après ceux de la grille)

  // Triangle 1 : A-B-C
  I->data[itriangle++] = iflag + 0;
  I->data[itriangle++] = iflag + 1;
  I->data[itriangle++] = iflag + 2;
  
  // Triangle 2 : B-C-D
  I->data[itriangle++] = iflag + 1;
  I->data[itriangle++] = iflag + 2;
  I->data[itriangle++] = iflag + 3;

  // Triangle 3 : C-D-E
  I->data[itriangle++] = iflag + 2;
  I->data[itriangle++] = iflag + 3;
  I->data[itriangle++] = iflag + 4;

  // Mise à jour du GPU.
  recreateGLBufferDataGPU(V);
  recreateGLElementBufferGPU(I);

  // bounding boxes
  //
  // en x: largeur en x des corners
  // en z: largeur en y des corners
  // en y: différence d'altitude
  bbox = (vec3_t){
    V->data[icenters-1].x - V->data[0].x,
    G->hmax - G->hmin + H,
    V->data[icenters-1].z - V->data[0].z
  };

  B->size = (vec2_t){bbox.x, bbox.z};

  return B;
}

static void attachGridBufferVAO(GridBuffer* g, VAO* svao) {
  attachBuffertoVAO(svao, g->vertices, 0);
  attachElementBufferVAO(svao, g->indices);
}

static void freeGridBuffer(GridBuffer* g) {
  free(g->vertices->data);
  free(g->indices->data);

  freeGLBuffer(g->vertices);
  freeGLElementBuffer(g->indices);
  free(g);
}

static void compute_MVP() {

  if (cam_view_mode == ROTATING) {
    float R = cam_tour_radius*(0.9f+cos(cam_angle)*0.1f);
    cam_pos = (vec3_t){cam_target.x+cos(cam_angle)*R,
                       cam_target.y*(4.0f + (1.0f+cos(cam_angle*3.0f))*1.4f),
                       cam_target.z+sin(cam_angle)*R};
    cam_dir = v3_sub(cam_target, cam_pos);
  }
  
  if (cam_view_mode == MANUAL && mouse_rdown) {
    mat4_t rot = m4_rotation(mouse_dx*cam_sensi, up_head);
    cam_dir = m4_mul_dir(rot, cam_dir);
    vec3_t rightv = v3_norm(v3_cross(cam_dir, up_head));
    rot = m4_rotation(mouse_dy*cam_sensi, rightv);
    cam_dir = m4_mul_dir(rot, cam_dir);
    
    mouse_dx = 0;
    mouse_dy = 0;
  }
  
  view = m4_look_at(cam_pos, v3_add(cam_pos, cam_dir), up_head);
  MVP  = m4_mul(proj, view);
}

static void error(const char* msg) {
  fprintf(stderr, "ERROR: %s\n", msg);
  exit(EXIT_FAILURE);
}

static VAO* createVAO() {
  VAO* ret = malloc(sizeof(VAO));
  glGenVertexArrays(1, &(ret->id));
  for(uint i=0; i<MAX_GLBUFFERS_VAO+1; i++) ret->attached[i] = NULL;
  ret->indices = NULL;
  return ret;
}

static void bindVAO(const VAO* svao) {
  glBindVertexArray(svao->id);
}

static void unbindVAO() {
  glBindVertexArray(0);
}

static void freeVAO(VAO* svao) {
  glDeleteVertexArrays(1, &(svao->id));
  free(svao);
}

static GLBuffer* createEmptyGLBuffer() {
  GLBuffer* B = malloc(sizeof(*B));
  glGenBuffers(1, &(B->id));
  B->size = 0;
  B->data = NULL;
  return B;
}

static GLElementBuffer* createEmptyGLElementBuffer() {
  GLElementBuffer* B = malloc(sizeof(*B));
  glGenBuffers(1, &(B->id));
  B->size = 0;
  B->data = NULL;
  return B;
}

static void bindGLBuffer(GLBuffer* buffer) {
  glBindBuffer(GL_ARRAY_BUFFER, buffer->id);
}

static void bindGLElementBuffer(GLElementBuffer* buffer) {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->id);
}

static void recreateGLBufferDataGPU(GLBuffer* buffer) {
  bindGLBuffer(buffer);
  glBufferData(GL_ARRAY_BUFFER,
	       sizeof(buffer->data[0])*buffer->size,
	       buffer->data, GL_DYNAMIC_DRAW);
}

static void replaceGLBufferData(GLBuffer* buffer, vec3_t* data,
				uint buffer_first, uint size) {
  bindGLBuffer(buffer);
  glBufferSubData(GL_ARRAY_BUFFER,
		  sizeof(buffer->data[0])*buffer_first,
		  sizeof(buffer->data[0])*size, data);
}

static void replaceRecreateGLBufferData(GLBuffer* buffer, vec3_t* data,
					uint buffer_first, uint size) {
  bindGLBuffer(buffer);
  glBufferData(GL_ARRAY_BUFFER,
	       sizeof(buffer->data[0])*size,
	       data, GL_DYNAMIC_DRAW);
}

static void recreateGLElementBufferGPU(GLElementBuffer* buffer) {
  bindGLElementBuffer(buffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
	       sizeof(uint)*(buffer->size),
	       buffer->data, GL_DYNAMIC_DRAW);
}

static GLBuffer* createGLBuffer(vec3_t* data, uint size) {
  GLBuffer* B = createEmptyGLBuffer();
  B->data = data;
  B->size = size;
  recreateGLBufferDataGPU(B);
  return B;
}

static GLElementBuffer* createGLElementBuffer(uint* data, uint size) {
  GLElementBuffer* B = createEmptyGLElementBuffer();
  B->data = data;
  B->size = size;
  recreateGLElementBufferGPU(B);
  return B;
}

static void freeGLBuffer(GLBuffer* buffer) {
  glDeleteBuffers(1, &(buffer->id)); 
  free(buffer);
}

static void freeGLElementBuffer(GLElementBuffer* buffer) {
  glDeleteBuffers(1, &(buffer->id)); 
  free(buffer);
}

static void attachBuffertoVAO(VAO* svao, GLBuffer* buffer, uint location) {
  if(location >= MAX_GLBUFFERS_VAO)
    error("attachBuffertoVAO(): location out of bounds");

  svao->attached[location] = buffer;

  bindVAO(svao);
  bindGLBuffer(buffer);
  glEnableVertexAttribArray(location);
  glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

static void attachElementBufferVAO(VAO* svao, GLElementBuffer* buffer) {
  svao->indices = buffer;

  bindVAO(svao);
  bindGLElementBuffer(buffer);
}

static void drawVAO(GLShader* shad, VAO* svao) {
  if(svao->attached[0] == NULL)
    error("drawVAO(): svao has no attached buffers");

  glUseProgram(shad->program);

  // Update MVP uniform
  compute_MVP();
  glUniformMatrix4fv(MVP_location, 1, GL_FALSE, (GLfloat*)&MVP);
  glUniform3fv(bbox_location, 1, (GLfloat*)&bbox);
  glUniform3fv(cam_pos_location, 1, (GLfloat*)&cam_pos);
  glUniform1fv(contrast_location, 1, &contrast);
  glUniform1fv(lux_location, 1, &lux);

  // Draw parameters
  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);

  // Bind and drawcall
  bindVAO(svao);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, maptexture);
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, glgrid->G->X, glgrid->G->Y,
               GL_RGB, GL_UNSIGNED_BYTE, gridImage);

  if(svao->indices) glDrawElements(GL_TRIANGLES, svao->indices->size, GL_UNSIGNED_INT, 0);
  else glDrawArrays(GL_TRIANGLES, 0, svao->attached[0]->size);

  openglerr();
}

// Convertit les coordonnées pixels en coordonnées OpenGL entre 0 et 1
// dans le dessin, cf.
// https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluUnProject.xml
static void pixelToCoord(int pixel_x, int pixel_y, double *x, double *y) {

  float cx = +(((float)pixel_x)/((float)width)  - 0.5f)/ transcale.z;
  float cy = -(((float)pixel_y)/((float)height) - 0.5f)/ transcale.z;

  *x = cx + transcale.x;
  *y = cy + transcale.y;
}

// Convertit les coordonnées pixels en coordonnées dans le dessin.
static point transformPoint(const point p) {

  point r = (point){transcale.x*width, (1.0-transcale.y)*height};
  r.x += (p.x - (((double)(width ))/2.0))/transcale.z;
  r.y += (p.y - (((double)(height))/2.0))/transcale.z;

  return r;
}

// Récupère les coordonnées du centre de la fenêtre.
static void getCenterCoord(double *x, double *y) {

  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);
  pixelToCoord((viewport[0] + viewport[2]) / 2,
               (viewport[1] + viewport[3]) / 2,
               x, y);
}

// Renvoie l'indice imin du point le plus proche de (x,y).
static int getClosestVertex(double x, double y) {
  int imin = 0;
  double dmin = DBL_MAX;
  
  for (int i = 0; i < nPOINT; i++) {
    double d = (x - POINT[i].x) * (x - POINT[i].x) +
      (y - POINT[i].y) * (y - POINT[i].y);
    if (d < dmin) dmin = d, imin = i;
  }
  
  return imin;
}

// Calcule le titre de la fenêtre. Ce titre est mis dans un buffer
// static pour éviter des malloc() sans free().
static char *getTitle(void) {
  static char buffer[MAX_FILE_NAME];
  sprintf(buffer,"Techniques Algorithmiques et Programmation - %d x %d (%.2lf)",
          width,height,scale);
  return buffer;
}

// Zoom d'un facteur s centré en (x,y).
static void zoomAt(double s, double x, double y) {
  transcale = (vec3_t){ x, y, transcale.z * s};
}

// Zoom d'un facteur s centré sur la position de la souris, modifie
// la variable globale scale du même facteur.
static void zoomMouse(double s) {

  int mx, my;
  double x, y;
  SDL_GetMouseState(&mx, &my);
  pixelToCoord(mx, my, &x, &y);
  // Merci Timothé pour la formule de ses morts
  zoomAt(s, transcale.x/s + (1.0f - 1.0f/s)*x, transcale.y/s + (1.0f - 1.0f/s)*y);
  scale *= s;
}

// Vrai ssi (i,j) est sur le bord de la grille G.
static inline int onBorder(grid *G, int i, int j) {
  return (i == 0) || (j == 0) || (i == G->X - 1) || (j == G->Y - 1);
}

// Vrai ssi p est une position de la grille. Attention ! cela ne veut
// pas dire que p est un sommet du graphe, car la case peut contenir
// TX_WALL. Si (inGrid(&G,p) && !onBorder(&G,p)) alors p est à
// l'intérieur de la grille.
static inline int inGrid(grid *G, position p) {
  return (0 <= p.x) && (p.x < G->X) && (0 <= p.y) && (p.y < G->Y);
}

// Vrai ssi deux positions sont égales.
static inline int equalPosition(position p, position q) {
  return (p.x == q.x) && (p.y == q.y);
}

// Distance L2 entre deux positions.
static inline double distL2(position s, position t) {
  return hypot(t.x - s.x, t.y - s.y);
}

typedef struct {
  // l'ordre de la déclaration est important
  GLubyte R;
  GLubyte G;
  GLubyte B;
} RGB;

static RGB color[] = {

  // l'ordre de la déclaration est important, il doit vérifier l'ordre
  // de l'enum dans tools.h. Pour visualiser les couleurs, disons
  // {0xF0,0xFA,0xFF}: https://imagecolorpicker.com/color-code/F0FAFF

  {0xE0, 0xE0, 0xE0}, // TX_FREE
  {0x10, 0x10, 0x30}, // TX_WALL
  {0xF0, 0xD8, 0xA8}, // TX_SAND
  {0x00, 0x6D, 0xBA}, // TX_WATER
  {0x7C, 0x70, 0x56}, // TX_MUD
  {0x23, 0xBA, 0x28}, // TX_GRASS
  {0x70, 0xE0, 0xD0}, // TX_TUNNEL
  {0x8F, 0x82, 0x77}, // TX_GRAVEL
  {0x4F, 0x4A, 0x45}, // TX_ROCK
  {0xF9, 0xFD, 0xFF}, // TX_SNOW
  {0xD4, 0xEF, 0xFC}, // TX_ICE
  {0x00, 0x42, 0xBA}, // TX_LAKE
  {0x0D, 0x04, 0xA2}, // TX_POOL
  {0x00, 0xA0, 0x60}, // TX_MEADOW
  {0x03, 0x69, 0x22}, // TX_FOREST
  {0x9E, 0x9E, 0x8A}, // TX_TRACK

  {0x80, 0x80, 0x80}, // MK_NULL
  {0x12, 0x66, 0x66}, // MK_USED
  {0x08, 0xF0, 0xF0}, // MK_FRONT
  {0x90, 0x68, 0xF8}, // MK_PATH

  {0xFF, 0x00, 0x00}, // C_START
  {0xFF, 0x88, 0x28}, // C_END
  {0x99, 0xAA, 0xCC}, // C_FINAL
  {0xFF, 0xFF, 0x80}, // C_END_WALL

  {0x66, 0x12, 0x66}, // MK_USED2
  {0xC0, 0x4F, 0x16}, // C_FINAL2
  {0xFF, 0xFF, 0x00}, // C_PATH2
};

//
// Construit l'image de pixels (variable globale gridImage) à partir
// de la grille G, en vue de l'afficher. Elle est appellée
// régulièrement par drawGrid(). Permet des effets de couleurs en
// fonction du temps (fading). Le point (0,0) de G correspond au coin
// en haut à gauche.
//
// +--x
// |
// y
//
static void makeImage(grid *G) {

  // Attention! modifie update si fin=true

  static int cpt; // compteur d'étape lorsqu'on reconstruit le chemin

  RGB *I = gridImage, c;
  int k = 0, v, m, f;

  // fin = true ssi le chemin a fini d'être construit, .start et .end
  //       ont été marqués MK_PATH tous les deux
  bool const fin =
    (G->mark[G->start.x][G->start.y] == MK_PATH) &&
    (G->mark[G->end.x][G->end.y] == MK_PATH);

  // debut = vrai ssi le chemin commence à être construit
  bool debut = false;
  for (int j = 0; j < G->Y && !debut; j++)
    for (int i = 0; i < G->X && !debut; i++)
      if(G->mark[i][j]==MK_PATH) debut = true;

  if (fin) update = false;
  if (!debut) cpt = 0;
  if (debut) cpt++;
  if (debut && cpt == 1){
    call_speed = sqrt(call_speed/4);
    if(call_speed < 0) call_speed = 1;
  }

  double t1,t2,dmax = distL2(G->start, G->end);
  if (dmax == 0) dmax = 1E-10; // pour éviter la division par 0

  for (int j = 0; j < G->Y; j++)
    for (int i = 0; i < G->X; i++) {
      m = G->mark[i][j];
      if ((m < 0) || (m >= CARD(color))) m = MK_NULL;
      v = G->texture[i][j];
      if ((v < 0) || (v >= CARD(color))) v = TX_FREE;
      do { // do...while(0) pour permettre des break
        if (m == MK_PATH) {
          c = color[m];
          if ( fin && !erase ) c = color[C_PATH2];
          break;
        }
        if (fin && erase) {
          c = color[v];
          break;
        } // affiche la grille d'origine à la fin
        if (m == MK_NULL) {
          c = color[v];
          break;
        } // si pas de marquage
        if (m == MK_USED || m == MK_USED2) {
          // interpolation de couleur entre les couleurs MK_USED(2) et
          // C_FINAL(2) ou bien MK_USED(2) et v si on est en train de
          // reconstruire le chemin
          position p = {.x = i, .y = j};
          t1 = (m == MK_USED) ? distL2(G->start, p) / dmax : distL2(G->end, p) / dmax;
          t1 = fmax(t1, 0.0), t1 = fmin(t1, 1.0);
          t2 = (debut && erase)? 0.5 * cpt / dmax : 0;
          t2 = fmin(t2, 1.0);
          f = (m == MK_USED) ? C_FINAL : C_FINAL2;
          c.R = t2*color[v].R + (1-t2) * (t1 * color[f].R + (1-t1)*color[m].R);
          c.G = t2*color[v].G + (1-t2) * (t1 * color[f].G + (1-t1)*color[m].G);
          c.B = t2*color[v].B + (1-t2) * (t1 * color[f].B + (1-t1)*color[m].B);
          break;
        }
        c = (m == MK_NULL) ? color[v] : color[m];
        break;
      } while (0);
      I[k++] = c;
    }

  if (inGrid(G, G->start)) {
    k = G->start.y * G->X + G->start.x;
    I[k] = color[C_START];
  }

  if (inGrid(G, G->end)) {
    v = (G->texture[G->end.x][G->end.y] == TX_WALL) ? C_END_WALL : C_END;
    k = G->end.y * G->X + G->end.x;
    I[k] = color[v];
  }
}


//
// Fixe les hauteurs de la grille G pour la surface 3D, en remplissant
// le champs G->height[][] (y compris le bord) avec un ensemble de
// pics (montagnes ou creux) positionnés aléatoirement sur la grille
// et de hauteurs aléatoires <= z (en fait de différence d'altitutes
// entre pics et creux = z). Le nombre de pics, leur raideur, la
// disparité des hauteurs et la fraction des creux par rapport aux
// montagnes sont respectivement contrôlées par les constantes
// globales: 'mounts', 'steepness', 'disparity' et 'holeness'.
//
// Le tableau G->height[][] n'est pas modifié si mounts = 0. En
// sorties, G->hmax et G->hmin contiennent la hauteur maximum et la
// hauteur minimum.
// 
static void generateHeights(grid* G, float z) {

  if( mounts == 0 || z <= 0){
    G->hmin = G->hmax = 0; // rien à faire les hauteurs sont déjà à 0
    return;
  }

  position M[mounts]; // liste des pics, NB: on peut avoir plusieurs pics
                      // sur la même case
  
  // choisit les pics placés aléatoirement dans [0,G->X[×[0,G->Y[
  for(int i=0; i < mounts; i++)
    M[i] = (position){ random()%G->X, random()%G->Y }; 
  
  // Ajuste la hauteur des pics relativement à la positions des autres
  // pics sur la grille, et calcule les hauteurs min et max
  // rencontrées. Après cette étape, les hauteurs sont dans [-1,1].

  float hmin = FLT_MAX; // hauteur min
  float hmax = 0;       // hauteur max
  float dmax = fmin(G->X,G->Y);
  float const fmounts = mounts; // pour éviter un cast
  long const A = 7877, B = 37; // deux nombres premiers
  
  for(int x = 0; x < G->X; x++)
    for(int y = 0; y < G->Y; y++){

      // Modifie la hauteur des pics en tenant compte de celle des
      // autres afin d'avoir des massifs de montagnes plutôt que des
      // pics isolés, en fonction de 'steepness', 'disparity' et
      // 'holeness'.
      //
      // La variable R produit une séquence pseudo-aléatoire qui sert
      // à mettre des creux selon la fréquence 'holeness'. Cette
      // séquence doit être identique pour chaque (x,y).

      position XY = {x,y};
      float h = 0;
      uint R = B; // premier nombre de la séquence pseudo-aléatoire

      for(int i=0; i<mounts; i++) { // tient compte de tous les pics
	float d = distL2(XY,M[i])/dmax; // distance entre (x,y) et le pic i
	d = 1/(1 + steepness*fmounts*d*d); // modifiée selon la raideur
	d *= (1-disparity) + i*disparity/fmounts; // modulée selon la disparité
	R = (uint)(A*R + B); if(R<0) R = -R; // pour avoir R >= 0
	if ( R%mounts < holeness*fmounts ) d = -d; // négatif de temps de temps 
	h += d;
      }
      
      G->height[x][y] = h;
      hmin = fmin(hmin, G->height[x][y]);
      hmax = fmax(hmax, G->height[x][y]);
    }

  // Modifie les hauteurs de sorte que hmax - hmin = z. NB: Ici z>0.
  double c = (hmin == hmax)? z : z / (hmax-hmin);
  for(int x = 0; x < G->X; x++)
    for(int y = 0; y < G->Y; y++)
      G->height[x][y] *= c;

  // NB: Les tests comme (G->height[x][y] == hmax) ou (G->height[x][y]
  // == hmin) vont bien vraies pour une certaine position (x,y), car
  // la formule (... x c) est la même pour G->height et G->hmax,
  // G->hmin.

  G->hmin = c * hmin;
  G->hmax = c * hmax;
}

//
// Alloue et initialise une grille G aux dimensions x,y ainsi que son
// image (tableau de pixels pour visualisation). On force x,y >= 3
// pour avoir au moins un point qui n'est pas sur le bord. La texture
// est initialisée à TX_FREE et les bords à TX_WALL. Les marques
// .mark[][] sont initialisées à MK_NULL. Les hauteurs .height[][]
// sont remplies en fonction des paramètres 3D, en particulier la
// différence de hauteurs max et min des pics/creux est fixées à
// min(x,y)/flatness. Les paramètres 'mounts', 'flatness',
// 'steepness', 'holeness' et 'disparity' sont vérifiés. Attention!
// .start et .end ne sont pas définis pour être dans la grille.
//
static grid allocGrid(int x, int y) {

  grid G;
  position p = {-1, -1};
  G.start = G.end = p;

  if (x < 3) x = 3;
  if (y < 3) y = 3;
  G.X = x;
  G.Y = y;

  mounts    = (int)fmax(mounts,0);       // au moins 0
  flatness  = fmax(flatness,0.1);        // au moins 0.1
  steepness = fmax(steepness,0);         // au moins 0
  disparity = fmin(fmax(disparity,0),1); // dans [0,1]
  holeness  = fmin(fmax(holeness,0),1);  // dans [0,1]
  G.hmin = G.hmax = 0;
 
  G.texture = malloc(x * sizeof(*(G.texture)));
  G.mark    = malloc(x * sizeof(*(G.mark)));
  G.height  = malloc(x * sizeof(*(G.height)));

  for(int i=0; i<x; i++){
    G.texture[i] = malloc(y * sizeof(*(G.texture[i])));
    G.mark[i]    = malloc(y * sizeof(*(G.mark[i])));
    G.height[i]  = malloc(y * sizeof(*(G.height[i])));
    for (int j=0; j<y; j++){
      G.mark[i][j] = MK_NULL; // marques par défaut
      G.height[i][j] = 0;     // hauteurs par défaut
    }
  }

  // met les bords à TX_WALL et remplit l'intérieur à TX_FREE
  for (int i=0; i<x; i++)
    for (int j=0; j<y; j++)
      G.texture[i][j] = onBorder(&G,i,j) ? TX_WALL : TX_FREE;

  // initialise les hauteurs, G->hmax et G->hmin
  generateHeights(&G, fmin(x,y)/flatness);

  // initialise le tableau de pixels
  gridImage = malloc(3 * x*y * sizeof(GLubyte));
  return G;
}

///////////////////////////////////////////////////////////////////////////
//
// Variables et fonctions utilisées depuis l'extérieur (non static).
// À mettre dans le .h.
//
///////////////////////////////////////////////////////////////////////////

// valeurs par défaut
int    width    = 1280; // NB: 1280/720 = 16 x 9ème
int    height   = 720;
bool   update   = true;
bool   running  = true;
bool   hover    = true;
bool   erase    = true;
double scale    = 1;
GLfloat size_pt = 5.0;

int   mounts    = 50;
float flatness  = 2.0;
float steepness = 5.0;
float holeness  = 0.2;
float disparity = 0.7;

bool NextPermutation(int *P, int n) {
  /*
    Génère la prochaine permutation P de taille n dans l'ordre
    lexicographique. On renvoie true si la prochaine permutation a pu
    être déterminée et false si P était la dernière permutation (et
    alors P n'est pas modifiée). Il n'est pas nécessaire que les
    valeurs de P soit dans [0,n[.

    On se base sur l'algorithme classique qui est:

    1. Trouver le plus grand index i tel que P[i] < P[i+1].
       S'il n'existe pas, la dernière permutation est atteinte.
    2. Trouver le plus grand indice j tel que P[i] < P[j].
    3. Echanger P[i] avec P[j].
    4. Renverser la suite de P[i+1] jusqu'au dernier élément.

  */
  int i=-1, j, m=n-1, t;

  /* étape 1: cherche i le plus grand tq P[i]<P[i+1] */
  for (j = 0; j < m; j++)
    if (P[j] < P[j + 1]) i = j; /* on a trouvé un i tq P[i]<P[i+1] */
  if (i < 0) return false; /* le plus grand i tq P[i]<[i+1] n'existe pas */

  /* étape 2: cherche j le plus grand tq P[i]<P[j] */
  for (j = i+1; (j<n) && (P[i]<P[j]) ; j++);
  j--;

  /* étape 3: échange P[i] et P[j] */
  SWAP(P[i], P[j], t);

  /* étape 4: renverse P[i+1]...P[n-1] */
  for (++i; i < m; i++, m--)
    SWAP(P[i], P[m], t);

  return true;
}

char *TopChrono(int const i) {
#define CHRONOMAX 10
  /*
    Met à jour le chronomètre interne numéro i (i=0..CHRNONMAX-1) et
    renvoie sous forme de char* le temps écoulé depuis le dernier
    appel à la fonction pour le même chronomètre. La précision dépend
    du temps mesuré. Elle varie entre la minute et le 1/1000e de
    seconde. Plus précisément le format est le suivant:

    1d00h00'  si le temps est > 24h (précision: 1')
    1h00'00"  si le temps est > 60' (précision: 1s)
    1'00"0    si le temps est > 1'  (précision: 1/10s)
    1"00      si le temps est > 1"  (précision: 1/100s)
    0"000     si le temps est < 1"  (précision: 1/1000s)

    Pour initialiser et mettre à jour tous les chronomètres (dont le
    nombre vaut CHRONOMAX), il suffit d'appeler une fois la fonction,
    par exemple avec TopChrono(0). Si i<0, alors les pointeurs alloués
    par l'initialisation sont désalloués. La durée maximale est
    limitée à 100 jours. Si une erreur se produit (durée supérieure ou
    erreur avec gettimeofday()), alors on renvoie la chaîne
    "--error--".
  */
  if (i >= CHRONOMAX) return "--error--";

  /* variables globales, locale à la fonction */
  static int first = 1; /* =1 ssi c'est la 1ère fois qu'on exécute la fonction */
  static char *str[CHRONOMAX];
  static struct timeval last[CHRONOMAX], tv;
  int j;

  if (i < 0) {  /* libère les pointeurs */
    if (!first) /* on a déjà alloué les chronomètres */
      for (j = 0; j < CHRONOMAX; j++) free(str[j]);
    first = 1;
    return NULL;
  }

  /* tv=temps courant */
  int err = gettimeofday(&tv, NULL);

  if (first) { /* première fois, on alloue puis on renvoie TopChrono(i) */
    first = 0;
    for (j = 0; j < CHRONOMAX; j++) {
      str[j] = malloc(
                      10); // assez grand pour "--error--", "99d99h99'" ou "23h59'59""
      last[j] = tv;
    }
  }

  /* t=temps en 1/1000" écoulé depuis le dernier appel à TopChrono(i) */
  long t = (tv.tv_sec - last[i].tv_sec) * 1000L +
    (tv.tv_usec - last[i].tv_usec) / 1000L;
  last[i] = tv; /* met à jour le chrono interne i */
  if ((t < 0L) || (err))
    t = LONG_MAX; /* temps erroné */

  /* écrit le résultat dans str[i] */
  for (;;) { /* pour faire un break */
    /* ici t est en millième de seconde */
    if (t < 1000L) { /* t<1" */
      sprintf(str[i], "0\"%03li", t);
      break;
    }
    t /= 10L;        /* t en centième de seconde */
    if (t < 6000L) { /* t<60" */
      sprintf(str[i], "%li\"%02li", t / 100L, t % 100L);
      break;
    }
    t /= 10L;         /* t en dixième de seconde */
    if (t < 36000L) { /* t<1h */
      sprintf(str[i], "%li'%02li\"%li", t / 360L, (t / 10L) % 60L, t % 10L);
      break;
    }
    t /= 10L;         /* t en seconde */
    if (t < 86400L) { /* t<24h */
      sprintf(str[i], "%lih%02li'%02li\"", t / 3600L, (t / 60L) % 60L, t % 60L);
      break;
    }
    t /= 60L;         /* t en minute */
    if (t < 144000) { /* t<100 jours */
      sprintf(str[i], "%lid%02lih%02li'", t / 1440L, (t / 60L) % 24L, t % 60L);
      break;
    }
    /* error ... */
    sprintf(str[i], "--error--");
  }

  return str[i];
#undef CHRONOMAX
}

//
// Renvoie une position aléatoire de la grille qui est uniforme parmi
// toutes les cases de la grille du type t (hors les bords de la
// grille). Si aucune case de type t n'est trouvée, la position
// est initialisée aléatoirement à l'intérieure de la grille.
//
position randomPosition(grid G, int t) {
  int i, j, c;
  int n;                      // n=nombre de cases de type t hors le bord
  int r = -1;                 // r=numéro aléatoire dans [0,n[
  position p = {-1, -1};      // position par défaut
  int const stop = G.X * G.Y; // pour sortir des 2 boucles for
  int const X2 = G.X - 2;
  int const Y2 = G.Y - 2;

  // On fait deux parcours: un 1er pour compter le nombre n de cases
  // de type t, et un 2e pour tirer au hasard la position parmi les n
  // possibles. À la fin du premier parcours on connaît le nombre n de
  // cases de type t. (Si ici n=0, alors on s'arrête en renvoyant une
  // position aléatoirement à l'intérieur de la grille.) On tire alors
  // au hasard un numéro r dans [0,n[.  Puis on recommence le comptage
  // (n=0) de cases de type t et on s'arrête dès qu'on arrive à la
  // case numéro r.

  c = 0;
  do {
    n = 0;
    for (i = 1; i <= X2; i++)
      for (j = 1; j <= Y2; j++)
        if (G.texture[i][j] == t) {
          if (n == r){ // toujours faux au 1er parcours (n=0, r<0)
            p = (position){ i, j };
            i = j = stop;
          }
          n++;
        }
    c = 1 - c;
    if (c){
      if(n == 0) return (position){ 1 + random()%X2, 1 + random()%Y2 }; // si texture non trouvée
      r = random()%n; // aléatoire uniforme dans [0,n[
    }
  } while (c); // vrai la 1ère fois, faux la 2e

  return p;
}


//
// Libère les pointeurs alloués par allocGrid().
//
void freeGrid(grid G) {
  for (int i = 0; i < G.X; i++) {
    free(G.texture[i]);
    free(G.mark[i]);
    free(G.height[i]);
  }
  free(G.texture);
  free(G.mark);
  free(G.height);
  free(gridImage);
}

//
// Renvoie une grille de dimensions x,y rempli de points aléatoires de
// type et de densité donnés. Le départ et la destination sont
// initialisées aléatoirement dans une case TX_FREE (si possible).
//
grid initGridPoints(int x, int y, int type, double density) {

  grid G = allocGrid(x, y); // alloue la grille et son image

  // vérifie que le type est correct, MK_NULL par défaut
  if ((type < 0) || (type >= CARD(color))) type = MK_NULL;

  // remplit l'intérieur aléatoirement
  for (int i = 1; i < x-1; i++)
    for (int j = 1; j < y-1; j++)
      if(RAND01 <= density) G.texture[i][j] = type;

  // position start/end aléatoires
  G.start = randomPosition(G, TX_FREE);
  G.end = randomPosition(G, TX_FREE);

  return G;
}

//
// Renvoie une grille aléatoire de dimensions x,y (au moins 3)
// correspondant à un labyrinthe basé sur un arbre couvrant aléatoire
// uniforme. On fixe les points 'start' et 'end' au milieu de la
// cellule en bas à droite et en haut à gauche respectivement. La
// largeur des couloirs est donnée par w>0.
//
// Il s'agit de l'algorithme de Wilson par "marches aléatoires avec
// effacement de boucle" (cf. https://bl.ocks.org/mbostock/11357811)
// qui génère un arbre couvrant uniforme -- un échantillon non biaisé
// de tous les arbres couvrants possibles. La plupart des autres
// algorithmes de génération de labyrinthes, comme ceux de Prim, de
// parcours aléatoire ou de parcours en profondeur aléatoire, ne
// possèdent pas cette propriété remarquable.
//
// L’algorithme initialise le labyrinthe avec une cellule de départ
// arbitraire. Ensuite, une nouvelle cellule est ajoutée au
// labyrinthe, déclenchant une marche aléatoire. Cette marche
// aléatoire se poursuit jusqu’à ce qu’elle se reconnecte au
// labyrinthe existant. Cependant, si la marche aléatoire
// s’auto-intersecte, la boucle résultante est effacée avant que la
// marche aléatoire ne se poursuive.
//
// Au début, l’algorithme peut sembler désespérément lent à observer,
// car les premières marches aléatoires ont peu de chances de se
// reconnecter au petit labyrinthe existant. Cependant, à mesure que
// le labyrinthe grandit, les marches aléatoires ont de plus en plus
// de chances d’entrer en collision avec le labyrinthe, et
// l’algorithme s’accélère de manière spectaculaire.
//
grid initGridLaby(int x, int y, int w) {

  // vérifie les paramètres
  if (x < 3) x = 3;
  if (y < 3) y = 3;
  if (w <= 0) w = 1;

  // initialise la grille et son image
  int const w1 = w+1;
  grid G = allocGrid(x*w1 + 1, y*w1 + 1);
  int const x1 = G.X-1;
  int const y1 = G.Y-1;

  // position par défaut (au mileu du couloir)
  G.start = (position){ .x = x1 - w1/2, .y = y1 - w1/2 };
  G.end   = (position){ .x = w1/2, .y = w1/2 };

  int i,j;
  
  // au début des murs sur les bords de chaque cellules de G, ce qui
  // forme une maillage, les bords de G étant déjà à TX_WALL
  for (i=1; i < x1; i++)
    for (j=1; j < y1; j++)
      if((i%w1 == 0)||(j%w1 == 0)) G.texture[i][j] = TX_WALL;

  // tableau pour la génération du labyrinthe
  int *maze = malloc(x*y*sizeof(*maze));
  memset(maze, -1, x*y*sizeof(*maze)); // vide le tableau (avec des -1)

  int count = 1;
  maze[0] = 0;

  while (count < x*y) {
    // cherche un point i0 non vide
    int i0 = 0;
    while (i0 < x*y && maze[i0] != -1) i0++;
    maze[i0] = i0 + 1;
    while (i0 < x*y) {
      int x0 = i0/y, y0 = i0%y;
      // déplace (x0,y0) selon une direction aléatoire
      // qui doit rester dans le cadre [0,x[ × [0,y[
      while (true) {
        switch (random()&3) { // =0,1,2 ou 3
        case 0: if (x0 <= 0)   continue; x0--; break;
        case 1: if (y0 <= 0)   continue; y0--; break;
        case 2: if (x0 >= x-1) continue; x0++; break;
        case 3: if (y0 >= y-1) continue; y0++; break;
        }
        break;
      }
      if (maze[x0*y + y0] == -1) {
        maze[x0*y + y0] = i0 + 1;
        i0 = x0*y + y0;
      } else {
        if (maze[x0*y + y0] > 0) {
          while (i0 != x0*y + y0 && i0 > 0) {
            int i1 = maze[i0] - 1;
            maze[i0] = -1;
            i0 = i1;
          }
        } else { // trace le couloir en effaçant les murs
          int i1 = i0;
          i0 = x0*y + y0;
          do {
            int const x0 = i0/y, y0 = i0%y;
            int const x1 = i1/y, y1 = i1%y;
	    if( x1 != x0) {
	      int const m = (x0>x1)? x0 : x1;
	      for (i=0; i<w; ++i) G.texture[m*w1][y0*w1 + i+1] = TX_FREE;
	    }
	    if( y1 != y0) {
	      int const m = (y0>y1)? y0 : y1;
              for (i=0; i<w; ++i) G.texture[x1*w1 + i+1][m*w1] = TX_FREE;
	    }
            i0 = i1;
            i1 = maze[i0] - 1;
            maze[i0] = 0;
            count++;
          } while (maze[i1] != 0);
          break;
        }
      }
    }
  }

  free(maze);

  return G;
}

//
// Initialise une grille à partir d'un fichier. Chaque caractère
// correspond à une texture particulière: ' ' -> TX_FREE, '#' ->
// TX_WALL, '~' -> TX_WATER, ... (voir le switch dans le code
// ci-dessous). Tous les types de texture ne sont pas codés.
//
grid initGridFile(char *file) {
  FILE *f = fopen(file, "r");
  if (f == NULL) {
    printf("Cannot open file \"%s\"\n", file);
    exit(1);
  }

  char *L = NULL; // L=buffer pour la ligne de texte à lire
  size_t b = 0;   // b=taille du buffer L utilisé (nulle au départ)
  ssize_t n;      // n=nombre de caractères lus dans L, sans le '\0'

  // Étape 1: on évalue la taille de la grille. On s'arrête si c'est
  // la fin du fichier ou si le 1ère caractère n'est pas un '#'

  int x = 0; // x=nombre de caractères sur une ligne
  int y = 0; // y=nombre de lignes

  while ((n = getline(&L, &b, f)) > 0) {
    if (L[0] != '#') break;
    if (L[n - 1] == '\n')
      n--; // se termine par '\n' sauf si fin de fichier
    if (n > x) x = n;
    y++;
  }

  rewind(f);

  // initialise la grille et son image
  grid G = allocGrid(x, y);

  // Étape 2: on relie le fichier et on remplit la grille

  int v,i,j;
  for (j=0; j<y; j++) {
    n = getline(&L, &b, f);
    if (L[n-1] == '\n') n--; // enlève le '\n' éventuelle
    for (i=0; i<n; i++) { // ici n<=x
      switch (L[i]) {
      case ' ': v = TX_FREE;   break;
      case '#': v = TX_WALL;   break;
      case ';': v = TX_SAND;   break;
      case '~': v = TX_WATER;  break;
      case ',': v = TX_MUD;    break;
      case '.': v = TX_GRASS;  break;
      case '+': v = TX_TUNNEL; break;
      case 's': v = TX_FREE; G.start = (position){ .x=i, .y=j }; break;
      case 't': v = TX_FREE; G.end   = (position){ .x=i, .y=j }; break;
      default:  v = TX_FREE;
      }
      G.texture[i][j] = v;
    }
  }

  free(L);
  fclose(f);
  return G;
}

//
// Initialise une grille 3D de taille x*y dont la texture dépend de
// l'altitude, le champs .height[][]. Positionne .end sur le plus haut
// pic et .start le un point d'altitude >= 0 le plus loin possible de
// .end mais pas à 10% d'un bord.
//
grid initGrid3D(int x, int y) {

  contrast = 0.5; lux = 1; // valeurs qui vont bien

  // Hiéarchie des textures en fonction de l'altitude.

  // du plus bas au plus profond
  int const EAU[]={ // si altitude < 0
    TX_WATER,
    TX_LAKE,
    TX_POOL,
  };

  // du plus bas au plus haut
  int const MONT[]={ // si altitude >= 0
    TX_SAND,
    TX_GRASS,
    TX_MEADOW,
    TX_FOREST,
    TX_GRAVEL,
    TX_ROCK,
    TX_ICE,
    TX_SNOW,
  };

  // initialise la grille et son image
  grid G = allocGrid(x, y); // G->height est rempli

  int i,j,t;

  // Remplissage des creux selon EAU[] et des montagnes selon MONT[],
  // sans toucher aux bords. On ne le fait que si G.hmax et G.hmin
  // sont non nuls (division par 0 sinon).

  if(G.hmax > 0 && G.hmin < 0)
    for(i=1; i<x-1; i++)
      for(j=1; j<y-1; j++){
	float h = G.height[i][j];
	if(h>0){
	  t = (CARD(MONT)*h)/G.hmax;
	  if(t == CARD(MONT)) t--;
	  G.texture[i][j] = MONT[t];
	}else{
	  t = (CARD(EAU)*h)/G.hmin;
	  if(t == CARD(EAU)) t--;
	  G.texture[i][j] = EAU[t];
	}
      }


  // Place la destination au sommet du plus haut pic. S'il n'est pas
  // trouvé, alors il est placé aléatoirement.

  for(i=1; i<x-1; i++)
    for(j=1; j<y-1; j++)
      if(G.height[i][j] == G.hmax) goto break_ij;

 break_ij:
  G.end = (i==x && j==y)? randomPosition(G,TX_FREE) : (position){i,j};
  
  // Place la source comme un point d'altitude >= 0 et le plus loin
  // possible de la destination, mais pas à plus de 10% d'un bord.

  G.start = G.end; // par défaut
  double dmin = 0; // distance entre G.end et G.start

  for(i=1+0.1*x; i<0.9*x-1; i++)
    for(j=1+0.1*y; j<0.9*y-1; j++){
      if(G.height[i][j] < 0) continue;
      double d = distL2(G.end, (position){i,j}); // distance entre G.end et (i,j)
      d -= G.height[i][j]*G.height[i][j]; // pénalité fonction de la hauteur
      if (d>dmin) G.start = (position){i,j}, dmin = d; // on a trouvé plus loin
    }
  
  return G;
}

//
// Ajoute à la grille n régions aux contours aléatoires (blobs) de
// type t donnés, sans toucher aux bords ni à start et end.
//
void addRandomBlob(grid G, int type, int n) {

  int const V[8][2] = {{ 0, -1}, { 1, 0}, {0,  1}, {-1, 0},
		       {-1, -1}, {-1, 1}, {1, -1}, { 1, 1}};

  int const X2 = G.X-2;
  int const Y2 = G.Y-2;

  for (int i = 0; i < n; i++) // met n graines
    G.texture[1 + random()%X2][1 + random()%Y2] = type;

  int m = (G.X+G.Y)/2; // demi-périmètre
  for (int t = 0; t < m; t++) // répète m fois
    for (int i = 1; i <= X2; i++)
      for (int j = 1; j <= Y2; j++) {
        int c = 0; // c = nombre de voisins de (i,j) de texture "type"
        for (int k = 0; k < 8; k++)
          if (G.texture[i + V[k][0]][j + V[k][1]] == type) c++;
        if (c && (random() % ((8 - c) * 20 + 1) == 0)) G.texture[i][j] = type;
      }
}

static inline double angle(double const x, double const y)
/*
  Renvoie l'angle de [0,2𝜋[ en radian du point de coordonnées
  cartésiennes (x,y) par rapport à l'axe des abscisses (1,0). NB:
  atan(y/x) donne un angle [-𝜋/2,+𝜋/2] ce qui n'est pas ce que l'on
  veut. On renvoie 0 si (x,y)=(0,0).

  Pour avoir ces constantes, faire sous xmaple par exemple:
  > evalf(3𝜋/2,39);
*/
{
#define M_2PI   6.28318530717958647692528676655900576839 /* = 2𝜋 */
#define M_3PI_2 4.71238898038468985769396507491925432630 /* = 3𝜋/2 */

  if(x==0){
    if(y>0) return M_2PI;   // =  𝜋/2
    if(y<0) return M_3PI_2; // = 3𝜋/2
    return 0;
  }

  // atan(y/x) renvoie un angle entre -𝜋/2 et +𝜋/2
  // l'angle est correct si x>0 et y>0
  // si x,y de signe contraire alors atan(y/x)=-atan(y/x)

  double const a=atan(y/x);
  if(x>0) return (y>0)? a : a+M_2PI; // = a ou a+2𝜋
  return a+M_PI;                     // = a+𝜋
}

//
// Ajoute à la grille G un ensemble de n segments (arcs) de texture de
// type t entre G.start et G.end, sans toucher aux bords, ni à G.start
// et G.end, sauf si ces derniers sont < 0. Dans ce cas ils sont fixés
// aléatoirement dans une partie libre de G (TX_FREE), si possible.
// 
void addRandomArc(grid G, int type, int n) {
  
  // Algorithme: n fois on crée un arc de cercle entre +𝜋/4 et -𝜋/4
  // (en fait 𝜋/(2c) où c=0.6 autour de l'axe s-t (on tire au hasard
  // si l'arc est depuis s ou depuis t). L'arc est continue selon de
  // 4-voisinage.

  if( !inGrid(&G,G.start) || !inGrid(&G,G.end) ){
    G.start = randomPosition(G, TX_FREE);
    G.end = randomPosition(G, TX_FREE);
  }
  // ici .star et .end sont dans la grille
  if(equalPosition(G.start,G.end)) return; // rien à faire 

  double d,a1,a2,t,a,da;
  position p,q,u,v;
  double const c=0.6;

  for(int i=0;i<n; i++){ // on répète n fois

    a1 = RAND01 * M_PI*c-M_PI*c/2; // angle1 par rapport au segment s-t
    a2 = RAND01 * M_PI*c-M_PI*c/2; // angle2 par rapport au segment s-t

    if(a1<a2) SWAP(a1,a2,t); // ici a1>a2
    if(a1-a2>M_PI/3) a2=(a1+a2)/2; // si arc trop grand

    // choisit au hasard le point de départ: s ou t
    p=G.start, q=G.end;
    if(random()&1) SWAP(p,q,u);

    d=RAND01*distL2(p,q); // d=distance p-q
    t=angle(q.x-p.x,q.y-p.y); // angle entre p->q
    a=a1; // angle courant
    da=(a1-a2)/(1.5*d); // variation d'angle

    for(int j=0;j<(int)(1.5*d); j++){

      // u=position courante à dessiner
      u=(position){ p.x+d*cos(t+a), p.y+d*sin(t+a) };
      if(!inGrid(&G,u) || onBorder(&G,u.x,u.y)) continue;
      G.texture[u.x][u.y]=type; // position sur la grille
      a-=da; // pour la prochaine position

      // teste si la prochaine position v de u va être en diagonale
      // pour la 4-connexité
      v=(position){ p.x+d*cos(t+a), p.y+d*sin(t+a) };
      if(abs(u.x-v.x)>0 && abs(u.y-v.y)>0){ // v en diagonale ?
        if(random()&1) u.x=v.x; else u.y=v.y; // corrige x ou y au hasard
        if(!inGrid(&G,u) || onBorder(&G,u.x,u.y)) continue;
        G.texture[u.x][u.y]=type; // position sur la grille
      }
    }
  }

}

static void init_opengl_drawing() {
  vao3d  = createVAO();
  vaotex = createVAO();

  MVP   = m4_identity(); 
  proj  = m4_perspective(45, (float)width/(float)height, 1, 10000);
  view  = m4_identity();
}

static GLShader build_shader(const char* vertex, const char* fragment) {

  GLShader shad;
  const char* vstring = vertex;
  const char* fstring = fragment;

  shad.vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(shad.vertex, 1, &vstring, NULL);
  glCompileShader(shad.vertex);

  shad.fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(shad.fragment, 1, &fstring, NULL);
  glCompileShader(shad.fragment);

  int  success;
  char infoLog[512];

  glGetShaderiv(shad.vertex, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(shad.vertex, 512, NULL, infoLog);
    printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED:\n%s", infoLog);
    exit(EXIT_FAILURE);
  }

  glGetShaderiv(shad.fragment, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(shad.fragment, 512, NULL, infoLog);
    printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED:\n%s", infoLog);
    exit(EXIT_FAILURE);
  }

  shad.program = glCreateProgram();
  glAttachShader(shad.program, shad.vertex);
  glAttachShader(shad.program, shad.fragment);
  glLinkProgram(shad.program);

  glGetProgramiv(shad.program, GL_LINK_STATUS, &success);
  if(!success) {
    glGetProgramInfoLog(shad.program, 512, NULL, infoLog);
    printf("ERROR::SHADER::LINKING::COMPILATION_FAILED:\n%s", infoLog);
    exit(EXIT_FAILURE);
  }

  return shad;
}

static void free_shader(GLShader shad) {
  glDeleteShader(shad.vertex);
  glDeleteShader(shad.fragment); 
}

// Initialisation de SDL
void init_SDL_OpenGL(void) {

  SDL_Init(SDL_INIT_VIDEO);

  // Set OpenGL version (2.1 Core Profile in this case)
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  
  // Set OpenGL profile to Core
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  // Multi-sampling (for antialiasing)
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

  window = SDL_CreateWindow(getTitle(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, width, height,
                            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if (window == NULL) { // échec lors de la création de la fenêtre
    printf("Could not create window: %s\n", SDL_GetError());
    SDL_Quit();
    exit(1);
  }

  // SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
  SDL_GetWindowSize(window, &width, &height);

  // Contexte OpenGL
  glcontext = SDL_GL_CreateContext(window);

  // Some GL options
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_MULTISAMPLE);

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &maptexture);
  glBindTexture(GL_TEXTURE_2D, maptexture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

  // Initialisation des shaders et des variables
  mapshader = build_shader(mapshader_vert_glsl, mapshader_frag_glsl);
  MVP_location         = glGetUniformLocation(mapshader.program, "MVP");
  bbox_location        = glGetUniformLocation(mapshader.program, "bbox");
  cam_pos_location     = glGetUniformLocation(mapshader.program, "cam_pos");
  lux_location         = glGetUniformLocation(mapshader.program, "lux");
  contrast_location    = glGetUniformLocation(mapshader.program, "contrast");
  
  texshader = build_shader(texture_vert_glsl, texture_frag_glsl);
  transcale_location = glGetUniformLocation(texshader.program, "translation_scale");
  screensize_location = glGetUniformLocation(texshader.program, "screensize");

  geomshader = build_shader(geom_vert_glsl, geom_frag_glsl);
  geom_transcale_location = glGetUniformLocation(geomshader.program, "translation_scale");

  init_opengl_drawing();
}

// Fermeture de SDL
void cleaning_SDL_OpenGL() {
  freeVAO(vao3d);
  freeVAO(vaotex);
  if(vaogeom) freeVAO(vaogeom);
  if(glgrid) freeGridBuffer(glgrid);
  if(gvertices) freeGLBuffer(gvertices);
  if(gcolors) freeGLBuffer(gcolors);
  free_shader(mapshader); 
  SDL_GL_DeleteContext(glcontext);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

// Permet de recentrer les points de POINT[] pour qu'ils apparaissent
// au centre de la fenêtre [0,width] × [0,height] en laissant un bord
// vide tout autour (margin). Ici margin est une fraction de width et
// height. Prendre par exemple margin=0.05 pour laisser un bord de 5%
// vide tout autour. Les valeurs de POINT[] sont modifiées.
void centering(double margin){
  point Pmin = POINT[0];
  point Pmax = Pmin;

  for(int i=1; i<nPOINT; i++){ // bounding box
    Pmin.x = fmin(Pmin.x,POINT[i].x);
    Pmin.y = fmin(Pmin.y,POINT[i].y);
    Pmax.x = fmax(Pmax.x,POINT[i].x);
    Pmax.y = fmax(Pmax.y,POINT[i].y);
  }

  double const m = fmin(width,height);
  double s = fmax(Pmax.x-Pmin.x,Pmax.y-Pmin.y);
  if(s==0) s=m; // si tous les points sont confondus

  point const c = { width / 2.0, height / 2.0}; // centre fenêtre
  point const M = { (Pmin.x+Pmax.x)/2, (Pmin.y+Pmax.y)/2 }; // centre points
  double const K = m/s/(1+margin);

  // recentrage (avec décalage) et une marge au bord
  for(int i=0; i<nPOINT; i++){
    POINT[i].x = (POINT[i].x - M.x)*K + c.x;
    POINT[i].y = (POINT[i].y - M.y)*K + c.y;
  }

}

// Compare deux angles entre l'axe des abscisses et les point P et Q.
int fcmp_angle(const void *P, const void *Q){
  double const p = angle(((point*)P)->x,((point*)P)->y);
  double const q = angle(((point*)Q)->x,((point*)Q)->y);
  return (p>q) - (p<q);
}

// Génère n points aléatoires du rectangle [0,width] × [0,height] et
// renvoie le tableau des n points (type double) ainsi générés. Met à
// jour les variables globales POINT[] et nPOINT. Une bande de taille
// 2*size_pt est laissée libre autour du rectangle afin d'éviter
// d'avoir des points trop proche du bord.
point *generatePoints(int n) {

  POINT = malloc(n * sizeof(point));
  double const d = 2*size_pt;
  double const rx = (double)(width-2*d);
  double const ry = (double)(height-2*d);
  for (int i = 0; i < n; i++) {
    POINT[i].x = d + rx * RAND01;
    POINT[i].y = d + ry * RAND01;
  }
  nPOINT = n;
  return POINT;
}

// Génère n points du rectangle [0,width] × [0,height] répartis
// aléatoirement sur k cercles concentriques de rayon r_j =
// j*min{height,width}/(2.2*k) pour j=1..k. Met à jour les variables
// globales POINT[] et nPOINT.
point *generateCircles(int n, int k) {

  POINT = malloc(n * sizeof(point));
  point c = { width / 2.0, height / 2.0 }; // centre
  double const r0 = fmin(width,height)/(2.2*k);

  for (int i = 0; i < n; i++) { // on place les n points
    int j = random()%k; // j=numéro du cercle
    double r = (j+1)*r0;
    double a = 2.0 * M_PI * RAND01; // angle aléatoire
    POINT[i].x = c.x + r * cos(a);
    POINT[i].y = c.y + r * sin(a);
  }

  nPOINT = n;
  return POINT;
}

// Génère n points sur un disque centrée dans le rectangle [0,width] ×
// [0,height] de rayon 98% du min(width,height)/2 avec comme distance
// au centre u^p avec u aléaoire uniforme dans [0,1]. Prendre p=0.5
// pour une distribution uniforme dans le disque, p>0.5 pour une
// concentration des valeurs vers le centre et p<0.5 pour un
// écartement du centre. Les valeurs <0 de p donne des écartements au
// delà du rayon du disque. Met à jour les variables globales POINT[]
// et nPOINT.
point *generatePower(int n, double p){

  POINT = malloc(n * sizeof(point));
  point c = { width / 2.0, height / 2.0 }; // centre
  double const r0 = 0.49*fmin(width,height);

  for (int i = 0; i < n; i++) { // on place les n points
    double a = 2.0 * M_PI * RAND01; // angle aléatoire
    double r = r0 * pow(RAND01,p); // loi puissance
    POINT[i].x = c.x + r * cos(a);
    POINT[i].y = c.y + r * sin(a);
  }

  nPOINT = n;
  return POINT;
}

// Génère n points en position convexe dans le rectangle [0,width] ×
// [0,height]. Le principe de l'algorithme, de complexité O(nlog(n)),
// est le suivant:
//
// On part de points aléatoires dans [0,1[², puis on calcule (pour les
// points finaux) la différence entre deux points consécutifs. La
// somme des n différences est nulle. On trie alors les points obtenus
// selon l'angle, puis on dessine de proche en proche les points de
// l'enveloppe convexe (avec chaque fois d'un angle croissant donc).
//
// Le dessin est ensuite recalibré pour tenir dans la fenêtre. Met à
// jour les variables globales POINT[] et nPOINT.
point *generateConvex(int n){

  POINT = malloc(n * sizeof(point));

  for(int i=0; i<n; i++)
    POINT[i] = (point){ RAND01, RAND01 };

  point p0 =  POINT[0];      // sauvegarde le 1er point
  for(int i=0; i<n-1; i++){ // différences
    POINT[i].x -= POINT[i+1].x;
    POINT[i].y -= POINT[i+1].y;
  }
  POINT[n-1].x -= p0.x;
  POINT[n-1].y -= p0.y;

  qsort(POINT,n,sizeof(point),fcmp_angle); // trie les angles

  for(int i=1; i<n; i++){ // dessin
    POINT[i].x += POINT[i-1].x;
    POINT[i].y += POINT[i-1].y;
  }

  nPOINT = n;
  centering(0.2); // centrage avec 20% de marge
  return POINT;
}

// Génère pq points sur une grille pxq régulière et centrée sur le
// rectangle [0,width] × [0,height]. On suppose p,q>0 et n!=NULL. Le
// point d'indice 0 est en haut à gauche, les autres suivent lignes
// par lignes, les segments horizontaux et verticaux étant le même
// longueur. Ecrit dans n le nombre de points, soit pq. Met à jour les
// variables globales POINT[] et nPOINT.
point *generateGrid(int *n, int p, int q) {

  POINT = malloc(p*q * sizeof(point));

  for (int y = *n = 0; y < p; y++)
    for (int x = 0; x < q; x++, (*n)++ )
      POINT[*n] = (point){ x, y };

  nPOINT = *n;
  centering(0.2); // centrage avec 20% de marge
  return POINT;
}

// Lecture des points à partir d'un fichier. Renvoie NULL et n=0 en
// cas d'erreur. Met à jour les variables globales POINT[] et nPOINT.
point *generateLoad(int* n, char *file){

  // ouvre le fichier
  FILE *f=fopen(file,"r");
  if(f==NULL){
    printf("Cannot open file \"%s\"\n",file);
    nPOINT = *n = 0;
    POINT = NULL;
    return NULL;
  }

// lit les commentaires éventuels, ils doivent commencer par '#' mais
// comprendre au moins un autre caractère
#define READ_COMMENT(f)				\
  do{						\
    char tmp[1024];				\
    while(!feof(f)&&fscanf(f,"#%[^\n] ",tmp));	\
  }while(0)

  // lit le nombre de points
  READ_COMMENT(f);
  fscanf(f,"%i\n",n);
  bool center = (*n<0); // si n<0, alors centrage à la fin
  *n = abs(*n);

  // lit les options
  double factor = 1.0;
  point shift = {0,0};
  READ_COMMENT(f);
  fscanf(f,"factor = %lf\n",&factor);
  READ_COMMENT(f);
  fscanf(f,"shift = %lf %lf\n",&(shift.x),&(shift.y));

  // lit les points
  POINT = malloc((*n)*sizeof(point));

  int i=0;
  for(;;){
    READ_COMMENT(f);
    if(feof(f)) break;
    fscanf(f,"%lf %lf\n",&(POINT[i].x),&(POINT[i].y));
    POINT[i].x = POINT[i].x * factor + shift.x;
    POINT[i].y = POINT[i].y * factor + shift.y;
    i++; // compte le nombre de points lus
  }
  fclose(f);

#undef READ_COMMENT

  if( (i!=(*n)) || ((*n)<1) || (POINT==NULL) ){
    printf("Incorrect number of points.\n");
    *n = 0;
    POINT = NULL;
  }

  nPOINT = *n;
  if(center) centering(0.1); // centrage avec 10% de marge
  return POINT;
}


// couleurs pour drawX(), valeurs RGB dans [0,1]

GLfloat COLOR_GROUND[] = { 0.0, 0.0, 0.0 }; // fond
GLfloat COLOR_POINT[]  = { 1.0, 0.0, 0.0 }; // point
GLfloat COLOR_LINE[]   = { 1.0, 1.0, 1.0 }; // ligne de la tournée
GLfloat COLOR_PATH[]   = { 0.0, 0.0, 1.0 }; // chemin
GLfloat COLOR_ROOT[]   = { 0.9, 0.8, 0.3 }; // racine, point de départ
GLfloat COLOR_TREE[]   = { 0.0, 0.4, 0.0 }; // arête de l'arbre

#define CLR_GROUND  COLOR_GROUND[0], COLOR_GROUND[1], COLOR_GROUND[2]
#define CLR_POINT   COLOR_POINT[0],  COLOR_POINT[1],  COLOR_POINT[2]
#define CLR_LINE    COLOR_LINE[0],   COLOR_LINE[1],   COLOR_LINE[2]
#define CLR_PATH    COLOR_PATH[0],   COLOR_PATH[1],   COLOR_PATH[2]
#define CLR_ROOT    COLOR_ROOT[0],   COLOR_ROOT[1],   COLOR_ROOT[2]
#define CLR_TREE    COLOR_TREE[0],   COLOR_TREE[1],   COLOR_TREE[2]

vec3_t* CLR_GROUND_V3 = (vec3_t*)COLOR_GROUND;
vec3_t* CLR_POINT_V3  = (vec3_t*)COLOR_POINT;
vec3_t* CLR_LINE_V3   = (vec3_t*)COLOR_LINE;
vec3_t* CLR_PATH_V3   = (vec3_t*)COLOR_PATH;
vec3_t* CLR_ROOT_V3   = (vec3_t*)COLOR_ROOT;
vec3_t* CLR_TREE_V3   = (vec3_t*)COLOR_TREE;

// dessine les k premiers sommets d'une tournée; ou dessine une
// tournée complète (si k=n+1); ou dessine un graphe (si G<>NULL) et
// sa tournée complète.

void drawX(point *V, int n, int *P, int k, graph *G) {
  static uint last_tick = 0;
 
  cpu_triangles_amount  = 0;

  if(vaogeom == NULL) {
    vaogeom = createVAO();
    bindVAO(vaogeom);

    gvertices = createGLBuffer(cpuvertices, MAX_VERTICES);
    gcolors   = createGLBuffer(cpucolors  , MAX_VERTICES);

    bindGLBuffer(gvertices);
    attachBuffertoVAO(vaogeom, gvertices, 0);
    
    bindGLBuffer(gcolors);
    attachBuffertoVAO(vaogeom, gcolors  , 1);
   
    unbindVAO();
  }

  // saute le dessin si le précédent a été fait il y a moins de 20ms
  // ou si update est faux
  if ((!update) && (last_tick + 20 > SDL_GetTicks())) return;
  last_tick = SDL_GetTicks();

  // gestion de la file d'event
  handleEvent(false);

  // dessine un quadrillage, si besoin
  if (quadrillage){
    GLfloat C[3]; // couleur du quadrillage = couleur du fond +/- 0.35
    for(int i=0;i<3;i++) C[i]=COLOR_GROUND[i] + 0.35*((COLOR_GROUND[i]<0.5)? +1.0:-1.0);
    double m = 1.2*fmax(width,height); // quadrillage 20% plus large que la fenêtre
    int k = (1<<(quadrillage+1))+1; // nombre de croix qui doit être impair
    double e = m/(k-1); // écart entre les croix
    point z = (point){ (width - e*(k-1))/2, (height-e*(k-1))/2 }; // point zéro
    // on place les k croix sur la diagonale allant de z+(0,0) à z+(m,m)
    for (int i=0; i<k; i++ ){ // k croix, dont une au centre
      prepareDrawLine( (point){ z.x+0,   z.y+i*e }, (point){ z.x+m,   z.y+i*e }, *(vec3_t*)C, 1);
      prepareDrawLine( (point){ z.x+i*e, z.y+0   }, (point){ z.x+i*e, z.y+m   }, *(vec3_t*)C, 1);
    }
  }

  // dessine G, s'il existe
  if (G && V && G->list && (G->deg[0]>=0) && (mst&1))
    for (int i = 0; i < n; i++)
      for (int j = 0; j < G->deg[i]; j++)
        if (i < G->list[i][j])
          prepareDrawLine(V[i], V[G->list[i][j]], *CLR_TREE_V3, 6.0f);

  // dessine le cycle en blanc si k=n+1; ou
  if (V && P && (P[0]>=0) && ((G && (mst&2)) || (!G && (mst&1)))) {
    vec3_t col;
    if(k>n){
      col = *CLR_LINE_V3;
      k=n+1; // k = pas plus que n+1
    }
    else col = *CLR_PATH_V3;
    for (int i=0; i<k-1; i++){
      if(oriented) prepareDrawArrow(V[P[i]], V[P[(i + 1) % n]], col, 1.5f);
      else prepareDrawLine(V[P[i]], V[P[(i + 1) % n]], col, 1.5f);
    }
    if (root) {
      if(oriented && n>0) prepareDrawArrow(V[P[0]], V[P[1%n]], col, 1.5f);
      else prepareDrawLine(V[P[0]], V[P[1%n]], col, 1.5f);
    }
  }
  
  // dessine les points
  if (V) {
    for (int i = 0; i < n; i++)
      prepareDrawPoint(V[i], *CLR_POINT_V3, size_pt);
    if (root && P && (P[0]>=0) ) prepareDrawPoint(V[P[0]], *CLR_ROOT_V3, size_pt);
  }

  glUseProgram(geomshader.program);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
  
  glUniform3fv(geom_transcale_location, 1, (GLfloat*)&transcale);

  // efface la fenêtre
  glClearColor(CLR_GROUND, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

  bindVAO(vaogeom);
  draw_stored_triangles();

  // affiche le dessin
  SDL_GL_SwapWindow(window);
}

static void prepareDrawArrow(const point p, const point q, const vec3_t color, double arrowwidth) {
  float arrowsize = ((float)(width))/100.0f;
  float arrowwidth_coeff = 0.5f;
  
  vec3_t p1 = {p.x, p.y, 0};
  vec3_t p2 = {q.x, q.y, 0};
  vec3_t dir    = v3_norm(v3_sub(p2, p1));
  vec3_t normal = {-dir.y, dir.x, dir.z};
  dir    = v3_muls(dir   , arrowsize);
  normal = v3_muls(normal, arrowsize*arrowwidth_coeff);

  vec3_t interm = v3_sub(p2, dir);

  vec3_t corner1 = v3_add(interm, normal);
  vec3_t corner2 = v3_sub(interm, normal);

  point corner1p = {corner1.x, corner1.y};
  point corner2p = {corner2.x, corner2.y};

  prepareDrawLine(p, q, color, arrowwidth);
  prepareDrawLine(q, corner1p, color, arrowwidth);
  prepareDrawLine(q, corner2p, color, arrowwidth);
}

static vec3_t point_to_glcoord(const point p) {
  return (vec3_t){p.x/((float)(width)),(1.0f-p.y/((float)(height))),0};
}

static vec3_t to_glcoord(const vec3_t p) {
  return (vec3_t){p.x/((float)(width)),(1.0f-p.y/((float)(height))),0};
}

static vec3_t unproj_point(const point p) {
  return (vec3_t){p.x, p.y,0};
}

static void prepareDrawPoint(const point p, const vec3_t color, double width) {
  int precision = 6;
  float w = width/2.0f;

  vec3_t center = point_to_glcoord(p);

  for(uint i=0; i<precision; i++){
    int j = (i+1)%precision;

    float angle1 = (float)(i)/(float)(precision) * M_PI * 2.0f;
    float angle2 = (float)(j)/(float)(precision) * M_PI * 2.0f;

    prepareDrawTriangleGradGLcoord(
      center,
      point_to_glcoord((point){p.x + w*cos(angle1), p.y + w*sin(angle1)}),
      point_to_glcoord((point){p.x + w*cos(angle2), p.y + w*sin(angle2)}),
      color,
      color,
      color
    );
  }
}

/*
  t1-----------------t2
  |                   |
  |   u1         u2   |
  |                   |
  b1-----------------b2
*/

static void prepareDrawLineGrad(const point p1, const point p2,
				const vec3_t color1, const vec3_t color2,
				float width) {

  float w = width/2.0f;
  vec3_t u1 = unproj_point(p1); 
  vec3_t u2 = unproj_point(p2);

  vec3_t dirN    = v3_norm(v3_sub(u2,u1));
  vec3_t normalN = {-dirN.y, dirN.x, 0};

  vec3_t b1 = v3_sub(v3_sub(u1, v3_muls(dirN, w)), v3_muls(normalN, w));
  vec3_t t1 = v3_add(v3_sub(u1, v3_muls(dirN, w)), v3_muls(normalN, w));
  vec3_t b2 = v3_sub(v3_add(u2, v3_muls(dirN, w)), v3_muls(normalN, w));
  vec3_t t2 = v3_add(v3_add(u2, v3_muls(dirN, w)), v3_muls(normalN, w));

  vec3_t b1gl = to_glcoord(b1);
  vec3_t t1gl = to_glcoord(t1);
  vec3_t b2gl = to_glcoord(b2);
  vec3_t t2gl = to_glcoord(t2);

  prepareDrawTriangleGradGLcoord(
    b1gl,
    b2gl,
    t2gl,
    color1,
    color2,
    color2
  );
  prepareDrawTriangleGradGLcoord(
    b1gl,
    t2gl,
    t1gl,
    color1,
    color2,
    color1
  );
}

static void prepareDrawTriangleGradGLcoord(const vec3_t p1, const vec3_t p2, const vec3_t p3,
					   const vec3_t color1, const vec3_t color2, const vec3_t color3) {

  if((cpu_triangles_amount+1)*3 >= MAX_VERTICES) {
    fprintf(stderr, "Too many lines to be drawn (%d), change the macro MAX_VERTICES\n", cpu_triangles_amount);
    exit(EXIT_FAILURE);
  }

  cpuvertices[cpu_triangles_amount*3+0] = p1;
  cpuvertices[cpu_triangles_amount*3+1] = p2;
  cpuvertices[cpu_triangles_amount*3+2] = p3;

  cpucolors[cpu_triangles_amount*3+0] = color1;
  cpucolors[cpu_triangles_amount*3+1] = color2;
  cpucolors[cpu_triangles_amount*3+2] = color3;

  cpu_triangles_amount++;
}

static void prepareDrawLine(const point p, const point q,
			    const vec3_t color, double width) {
  prepareDrawLineGrad(p, q, color, color, width);
}

// si vaogeom est borné
static void draw_stored_triangles(void) {

  if(cpu_triangles_amount > 0) {
    if(cpu_triangles_amount*3 >= MAX_VERTICES) {
      fprintf(stderr, "Too many lines to be drawn (%d), change the macro MAX_VERTICES (%d)\n", cpu_triangles_amount, MAX_VERTICES);
      exit(EXIT_FAILURE);
    }

    replaceGLBufferData(gvertices, cpuvertices, 0, cpu_triangles_amount*3);
    replaceGLBufferData(gcolors  , cpucolors, 0, cpu_triangles_amount*3);

    glDrawArrays(GL_TRIANGLES, 0 , cpu_triangles_amount*3);
    
    cpu_triangles_amount = 0;
  }
}

void drawTour(point *V, int n, int *P) { drawX(V,n,P,n+1,NULL); }
void drawPath(point *V, int n, int *P, int k) { drawX(V,n,P,k,NULL); }
void drawGraph(point *V, int n, int *P, graph G) { drawX(V,n,P,n+1,&G); }

static void drawGridImage3D(grid G) {

  // initialise glgrid et la caméra
  if(glgrid == NULL) { // une seule fois au départ
    glgrid = createGridBuffer(&G);
    attachGridBufferVAO(glgrid, vao3d);
    cam_arrows_speed = (G.X+G.Y)*0.01f;
    cam_tour_radius  = (G.X+G.Y)*0.5f;
    cam_target.y = (G.hmax-G.hmin)/2.0f;
  } else glgrid->G = &G;

  // Met à jour l'angle de la caméra: ajoute à cam_angle la vitesse
  // cam_speed (en radian/seconde) × la différence de temps entre
  // deux appels (en seconde).

  static struct timeval oldtime = {0,0}; // 0 seconde et 0 microseconde
  double dt; // différence de temps en seconde

  if(oldtime.tv_sec == 0 && oldtime.tv_usec == 0){ // une seule fois au départ
    gettimeofday(&oldtime, NULL);
    dt = 0;
  }
  else{
    struct timeval newtime;
    gettimeofday(&newtime, NULL); // temps courant
    dt = (newtime.tv_sec - oldtime.tv_sec); // différence de secondes
    dt += (newtime.tv_usec - oldtime.tv_usec)/1000000.0; // +différence de μs
    oldtime = newtime;
  }

  cam_angle += dt * cam_speed;
  drawVAO(&mapshader, vao3d);
}

static void drawGridImage2D(grid G) {

  glUseProgram(texshader.program);

  bindVAO(vaotex);

  // Draw parameters
  glEnable(GL_CULL_FACE);
  glDisable(GL_DEPTH_TEST);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, maptexture);

  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, G.X, G.Y,
		  GL_RGB, GL_UNSIGNED_BYTE, gridImage);  

  glUniform3fv(transcale_location, 1, (GLfloat*)&transcale );

  vec2_t screensize = (vec2_t){width, height};  
  glUniform2fv(screensize_location, 1, (GLfloat*)&screensize);  

  glDrawArrays(GL_TRIANGLES, 0, 6);
}

static void update_maptexture(grid G) {

  static bool created = false;

  if(!created) {
    glBindTexture(GL_TEXTURE_2D, maptexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, G.X, G.Y, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, gridImage);
    created = true;
  }
}

static void drawGridImage(grid G) {

  // Efface la fenêtre
  glClearColor(CLR_GROUND, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  update_maptexture(G);
  if(view3D) drawGridImage3D(G);
  else drawGridImage2D(G);

  openglerr();
}

#undef CLR_GROUND
#undef CLR_POINT
#undef CLR_LINE
#undef CLR_PATH
#undef CLR_ROOT
#undef CLR_TREE

void waitGridDelay(grid G, uint delay, uint frame_delay) {
  uint const last_tick = SDL_GetTicks();
  uint current_tick = SDL_GetTicks();

  while(running && current_tick - last_tick < delay) {
    handleEvent(false);
    drawGridImage(G);
    SDL_GL_SwapWindow(window);

    if (delay - (current_tick - last_tick) > frame_delay)
      SDL_Delay(frame_delay);
    else
      SDL_Delay(delay - (current_tick - last_tick));
    current_tick = SDL_GetTicks();
  }
}

// affichage de la grille
void drawGrid(grid G) {

  static uint last_tick = 0;
  static uint last_drawn_call = 0;
  static uint call_count = 0;
  
  uint const current_tick = SDL_GetTicks();

  uint const frame_rate = 50; // 50 fps
  uint const frame_delay = 1000 / frame_rate; // durée en millisecondes

  call_count++;
  uint next_drawn_call = call_count;

  if(!update)
    next_drawn_call = last_drawn_call + call_speed / frame_rate;

  if (next_drawn_call > call_count)
    return;

  uint delay = 0;
  uint elasped_tick = current_tick - last_tick;
  uint elasped_call = call_count - last_drawn_call;

  if (elasped_call*1000 > elasped_tick * call_speed)
    delay = elasped_call*1000 / call_speed - elasped_tick;

  // ceci intervient quand call_speed diminue
  // le choix suivant est raisonnable au vu de la vitesse des entrées
  // utilisateur: on dessine la grille sans attendre
  if (elasped_call > call_speed) delay = 0;

  if (!update) waitGridDelay(G, delay, frame_delay);

  makeImage(&G);
  handleEvent(false);

  drawGridImage(G);

  // affiche le résultat puis attend un certain délai
  SDL_GL_SwapWindow(window);
  last_tick = current_tick;
  last_drawn_call = call_count;
}

bool handleEvent(bool wait_event) {

  bool POINT_has_changed = false;
  SDL_Event e;

  if (wait_event) SDL_WaitEvent(&e); // attendre un événement
  else if (!SDL_PollEvent(&e)) return false;

  do {
    switch (e.type) {

    case SDL_QUIT:
      goto quit;

    case SDL_KEYDOWN:
      if (e.key.keysym.sym == SDLK_q) {
	quit:
        running = false;
        update = false;
	call_speed = ULONG_MAX; // vitesse d'affichage max pour drawGrid()
        break;
      }
      if (e.key.keysym.sym == SDLK_p) { // pause
        SDL_Delay(500);
        SDL_WaitEvent(&e);
        break;
      }
      if (e.key.keysym.sym == SDLK_c) { // affichage des sommets visités pour A*
        erase = !erase;
        break;
      }
      if (e.key.keysym.sym == SDLK_o) { // affichage de l'orientation
        oriented = !oriented;
        break;
      }
      if (e.key.keysym.sym == SDLK_r) { // affichage de la racine de l'arbre
        root = !root;
        break;
      }
      if (e.key.keysym.sym == SDLK_t) { // switch points -> arbre -> tournée -> arbre+tournée
        mst = (mst+1)&3; // +1 modulo 4
        break;
      }
      if (e.key.keysym.sym == SDLK_g) { // affichage un quadrillage
        quadrillage = (quadrillage+1)%5; // +1 modulo 5
        break;
      }
      if (e.key.keysym.sym == SDLK_d) { // switch 3D
        view3D = 1-view3D;
        break;
      }
      if (e.key.keysym.sym == SDLK_s) { // taille des points
        size_pt *= 1.75; // NB: 1.75^5 = 16.41
        if(size_pt > 17) size_pt = 1; // redémarre à 1
        break;
      }
      if (e.key.keysym.sym == SDLK_RIGHT && view3D) {
        cam_target = v3_add(cam_target, v3_muls(right_dir(), cam_arrows_speed));
        cam_pos = v3_add(cam_pos, v3_muls(right_dir(), cam_arrows_speed));
        break;
      }
      if (e.key.keysym.sym == SDLK_LEFT && view3D) {
        cam_target = v3_sub(cam_target, v3_muls(right_dir(), cam_arrows_speed));
        cam_pos = v3_sub(cam_pos, v3_muls(right_dir(), cam_arrows_speed));
        break;
      }
      if (e.key.keysym.sym == SDLK_UP && view3D) {
        cam_target = v3_add(cam_target, v3_muls(up_dir(), cam_arrows_speed));
        cam_pos = v3_add(cam_pos, v3_muls(up_dir(), cam_arrows_speed));
        break;
      }
      if (e.key.keysym.sym == SDLK_DOWN && view3D) {
        cam_target = v3_sub(cam_target, v3_muls(up_dir(), cam_arrows_speed));
        cam_pos = v3_sub(cam_pos, v3_muls(up_dir(), cam_arrows_speed));
        break;
      }
      if (e.key.keysym.sym == SDLK_k && view3D) {
	// stoppe ou redémarre la caméra
	if(cam_speed > 0) {
	  cam_old_speed = cam_speed;
	  cam_speed = 0;
	} else cam_speed = cam_old_speed;
        break;
      }
      if (e.key.keysym.sym == SDLK_m && view3D) {
        if(cam_speed < 10) cam_speed *= 1.5f; // +50%
	if(cam_speed == 0) cam_speed = 0.05f; // redémarrage après arrêt
        break;
      }
      if (e.key.keysym.sym == SDLK_l && view3D) {
        cam_speed /= 1.5f; // -50%
        if(cam_speed < 0.05) cam_speed = 0; // arrêt
        break;
      }
      if (e.key.keysym.sym == SDLK_z || e.key.keysym.sym == SDLK_KP_MINUS) {
	// divise par deux la vitesse d'affichage pour drawGrid()
	// jusqu'à 1
	call_speed >>= 1;
	if (call_speed == 0) call_speed = 1;
        break;
      }
      if (e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_KP_PLUS) {
	// augmente (x2) la vitesse d'affichage pour drawGrid()
	// jusqu'à ULONG_MAX (sans le dépasser)
	if (call_speed == 0) call_speed = 1;
	if (call_speed >= (ULONG_MAX>>1)) call_speed = ULONG_MAX;
	call_speed <<= 1;
        break;
      }
      if (e.key.keysym.sym == SDLK_1 && view3D) {
	lux -= 0.1;
	if (lux < 0) lux = 0;
        break;
      }
      if (e.key.keysym.sym == SDLK_2 && view3D) {
	lux += 0.1;
	if (lux > 10) lux = 10;
        break;
      }
      if (e.key.keysym.sym == SDLK_3 && view3D) {
	contrast -= 0.1;
	if (contrast < 0) contrast = 0;
        break;
      }
      if (e.key.keysym.sym == SDLK_4 && view3D) {
	contrast += 0.1;
	if (contrast > 1) contrast = 1;
        break;
      }
      if (e.key.keysym.sym == SDLK_u) {
	if( (nPOINT<=0) || (POINT==NULL) ) break; // rien à faire
	centering(0.1); // centrage avec 10% de marge
        POINT_has_changed = true;
	break;
      }
      if (e.key.keysym.sym == SDLK_w) { // sauvegarde des points
	if( (nPOINT<=0) || (POINT==NULL) ) break; // rien à faire
	char file[MAX_FILE_NAME];
	printf("\nWrite points into a file.\n");
	printf("Enter file name ('q' to quit): ");
	scanf("%s",file);
	if(strcmp(file,"q")==0){
	  printf("waiting for a key ...");
	  break;
	}
	FILE *f=fopen(file,"w");
	if(f==NULL){
	  printf("Cannot open file \"%s\"\n",file);
	  break;
	}
	fprintf(f,"%i\n",nPOINT);
	for(int i=0; i<nPOINT; i++)
	  fprintf(f,"%g %g\n",POINT[i].x,POINT[i].y);
	fclose(f);
	printf("%i points saved in \"%s\".\n",nPOINT,file);
	printf("waiting for a key ...");
	break;
      }
      if (e.key.keysym.sym == SDLK_h) {
	printf("%s",HELP);
	fflush(stdout);
	break;
      }
      break;

    case SDL_WINDOWEVENT:
      if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
        double x, y;
        getCenterCoord(&x, &y);
        glViewport(0, 0, e.window.data1, e.window.data2);
        zoomAt(scale, x, y);
        SDL_GetWindowSize(window, &width, &height);
        SDL_SetWindowTitle(window, getTitle());
      }
      break;

    case SDL_MOUSEWHEEL:
      if (e.wheel.y > 0 && !view3D) zoomMouse(2.0);
      if (e.wheel.y < 0 && !view3D) zoomMouse(0.5);
      if (e.wheel.y > 0 && view3D) {
        if(cam_view_mode == ROTATING) {
          cam_tour_radius /= 1.06f;
        }
        if(cam_view_mode == MANUAL) {
          cam_pos = v3_add(cam_pos, v3_muls(cam_dir, cam_manual_speed));
        }
      }
      if (e.wheel.y < 0 && view3D) {
        if(cam_view_mode == ROTATING) {
          cam_tour_radius *= 1.06f;
        }
        if(cam_view_mode == MANUAL) {
          cam_pos = v3_sub(cam_pos, v3_muls(cam_dir, cam_manual_speed));
        }
      }
      SDL_GetWindowSize(window, &width, &height);
      SDL_SetWindowTitle(window, getTitle());
      break;

    case SDL_MOUSEBUTTONDOWN:
      if (e.button.button == SDL_BUTTON_LEFT && !view3D) {
        mouse_ldown = true;
        point transformed = transformPoint((point){e.motion.x, e.motion.y});
        double x = transformed.x;
        double y = transformed.y;
        if (hover) {
          int v = getClosestVertex(x, y);
          if ((x - POINT[v].x)*(x - POINT[v].x) +
              (y - POINT[v].y)*(y - POINT[v].y) < (size_pt*size_pt/transcale.z/transcale.z)+2 )
            selectedVertex = v;
        }
      }
      if (e.button.button == SDL_BUTTON_LEFT && view3D) {
        mouse_ldown = true;
	cam_view_mode = ROTATING;
	cam_speed = cam_old_speed;
      }
      if (e.button.button == SDL_BUTTON_RIGHT && view3D) {
        mouse_rdown = true;
	cam_view_mode = MANUAL;
	if(cam_speed > 0) cam_old_speed = cam_speed;
	cam_speed = 0.0f;
      }
      break;

    case SDL_MOUSEBUTTONUP:
      if (e.button.button == SDL_BUTTON_LEFT) {
        mouse_ldown = false;
        selectedVertex = -1;
      }
      if (e.button.button == SDL_BUTTON_RIGHT)
        mouse_rdown = false;
      break;

    case SDL_MOUSEMOTION:
      mouse_dx = (abs(e.motion.xrel) > 0) ? e.motion.xrel : mouse_dx;
      mouse_dy = (abs(e.motion.yrel) > 0) ? e.motion.yrel : mouse_dy;
      if (hover && !mouse_rdown && mouse_ldown && selectedVertex >= 0) {
        POINT[selectedVertex] = transformPoint((point){e.motion.x, e.motion.y});
        POINT_has_changed = true;
      }
      if (mouse_rdown) { 
        transcale.x -= ((float)e.motion.xrel) / ((float)width ) / transcale.z;
        transcale.y += ((float)e.motion.yrel) / ((float)height) / transcale.z;
      }
      break;

    }
  } while (SDL_PollEvent(&e));

  return POINT_has_changed;
}

/* ==================================================================
   KOSARAJU'S STRONGLY CONNECTED COMPONENTS
   ================================================================== */
void kosaraju_dfs1(graph G, int u, int *visited, int *stack, int *top) {
    visited[u] = 1;
    for (int i = 0; i < G.deg[u]; i++) {
        if (!visited[G.list[u][i]]) kosaraju_dfs1(G, G.list[u][i], visited, stack, top);
    }
    stack[(*top)++] = u; // Push POST-order
}

void kosaraju_dfs2(graph G_rev, int u, int *visited, int *curr_size) {
    visited[u] = 1;
    (*curr_size)++;
    for (int i = 0; i < G_rev.deg[u]; i++) {
        if (!visited[G_rev.list[u][i]]) kosaraju_dfs2(G_rev, G_rev.list[u][i], visited, curr_size);
    }
}

int largest_scc(graph G, graph G_rev) {
    int *visited = calloc(G.n, sizeof(int));
    int *stack = malloc(G.n * sizeof(int));
    int top = 0;

    for (int i = 0; i < G.n; i++) 
        if (!visited[i]) kosaraju_dfs1(G, i, visited, stack, &top);

    memset(visited, 0, G.n * sizeof(int));
    int max_scc_size = 0;

    while (top > 0) {
        int u = stack[--top];
        if (!visited[u]) {
            int curr_size = 0;
            kosaraju_dfs2(G_rev, u, visited, &curr_size);
            if (curr_size > max_scc_size) max_scc_size = curr_size;
        }
    }
    free(visited); free(stack);
    return max_scc_size; 
}

/* ==================================================================
   DIVIDE & CONQUER: Maximum Subarray
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
   DYNAMIC PROGRAMMING: Ribbon Cutting
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
    int res = dp[n];
    free(dp);
    return res; 
}

/* ==================================================================
   GREEDY: Set Cover
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
        
        if (best_set == -1) break; // Impossible to cover all
        
        used_sets[best_set] = 1;
        sets_picked++;
        for (int j = 0; j < sizes[best_set]; j++) {
            if (uncovered[sets[best_set][j]] == 1) {
                uncovered[sets[best_set][j]] = 0;
                elements_left--;
            }
        }
    }
    free(uncovered); free(used_sets);
    return elements_left == 0 ? sets_picked : -1;
}


=========================================
File: ./playground_TP/tools.h
=========================================
#ifndef __TOOLS_H__
#define __TOOLS_H__


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>


// alt: -Wno-deprecated-declarations 
#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


// échange les variables x et y, via z
#define SWAP(x, y, z)  (z) = (x), (x) = (y), (y) = (z)

// réel aléatoire dans [0,1]
#define RAND01  ((double)random()/RAND_MAX)

// taille maximum du nom d'un fichier
#define MAX_FILE_NAME  256

// nombre maximum de points affichable à l'écran (avant erreur)
#define MAX_VERTICES 1000000

// nombre d'éléments d'un tableau statique
#define CARD(T) ((int)(sizeof(T)/sizeof(*T)))


////////////////////////
//
// SPÉCIFIQUE POUR TSP
//
////////////////////////

// Un point (x,y).
typedef struct {
  double x, y;
} point;


// Construit la prochaine permutation de P de taille n dans l'ordre
// lexicographique. Le résultat est écrit dans P. La fonction renvoie
// true sauf si à l'appel P était la dernière permutation. Dans ce cas
// false est renvoyé et P n'est pas modifiée. Il n'est pas nécessaire
// que les valeurs de P soit dans [0,n[.
bool NextPermutation(int *P, int n);

// Primitives de génération des points.
point *generatePoints(int n); // n points au hasard dans [0,width] × [0,height]
point *generateCircles(int n, int k); // n points au hasard sur k cercles concentriques
point *generatePower(int n, double p); // points selon loi puissance sur un disque
point *generateConvex(int n); // n points au hasard en position convexe
point *generateGrid(int *n, int p, int q); // points sur une grille régulière p × q
point *generateLoad(int *n, char *file); // points lus depuis un fichier

// Format d'un fichier de points: si n<0, alors les points seront
// recentrés dans la fenêtre. Les paramètres "factor" et "shift", qui
// sont optionnels, permettent de transformer chaque point (x_i,y_i)
// en (x_i*f + dx, y_i*f + dy). Les lignes vides ou commençant par
// '##' sont ignorées.
//
// ## ceci est un commentaires
// n
// factor = f
// shift = dx dy
//
// x_1 y_2
// ... ...
// x_n y_n

// Primitives de dessin.
void drawTour(point *V, int n, int *P); // affichage de la tournée P
void drawPath(point *V, int n, int *P, int k); // desine les k premiers points de P

// Un graphe G (pour MST).
typedef struct {
  int n;         // n=nombre de sommets
  int *deg;      // deg[u]=nombre de voisins du sommet u
  int **list;    // list[u][i]=i-ème voisin de u, i=0..deg[u]-1
} graph;

void drawGraph(point *V, int n, int *P, graph G); // affiche graphe, arbre et tournée


////////////////////////
//
// SPÉCIFIQUE POUR A*
//
////////////////////////


// Une position d'une case dans la grille.
typedef struct {
  int x, y;
} position; 

// Une grille.
typedef struct {
  int X, Y;       // dimensions: X et Y
  int **texture;  // texture des cases:  texture[x][y], 0<= x < X, 0 <= y < Y
  int **mark;     // marquage des cases: mark[x][y],    0<= x < X, 0 <= y < Y
  position start; // position de la source
  position end;   // position de la destination
  //
  // spécifique surface 3D
  //
  float** height; // hauteur des cases: height[x][y], 0<= x < X, 0 <= y < Y
  float hmin,hmax; // hauteur min/max: hmin <= height[x][y] <= hmax 
} grid;

// Codes possibles des cases d'une grille pour les champs .texture et
// .mark. L'ordre est important! Il doit être cohérent avec les
// tableaux color[] (de tools.c) et weight[] (de a_star.c).
enum {

  // pour .texture
  TX_FREE = 0, // case vide
  TX_WALL,     // Mur
  TX_SAND,     // Sable
  TX_WATER,    // Eau
  TX_MUD,      // Boue
  TX_GRASS,    // Herbe
  TX_TUNNEL,   // Tunnel
  TX_GRAVEL,   // Gravière
  TX_ROCK,     // Rocher
  TX_SNOW,     // Neige
  TX_ICE,      // Glace
  TX_LAKE,     // Lac
  TX_POOL,     // Fosse
  TX_MEADOW,   // Prairie
  TX_FOREST,   // Forêt
  TX_TRACK,    // Sentier

  // pour .mark
  MK_NULL,     // sommet non marqué
  MK_USED,     // sommet marqué dans P
  MK_FRONT,    // sommet marqué dans Q
  MK_PATH,     // sommet dans le chemin

  // divers
  C_START,    // couleur de la position de départ
  C_END,      // idem pour la destination
  C_FINAL,    // couleur de fin du dégradé pour MK_USED
  C_END_WALL, // couleur de destination si sur TX_WALL

  // extra
  MK_USED2,    // sommet marqué dans P_t
  C_FINAL2,   // couleur de fin du dégradé pour MK_USED2
  C_PATH2,    // couleur du chemin si 'c'
};

// Routines de dessin et de construction de grille. Le point (0,0) de
// la grille est le coin en haut à gauche. Pour plus de détails sur
// les fonctions, se reporter à tools.c.

void drawGrid(grid); // affiche une grille
grid initGridLaby(int,int,int w); // labyrithne x,y, w = largeur des couloirs
grid initGridPoints(int,int,int t,double p); // pts de texture t avec proba p
grid initGridFile(char*); // construit une grille à partir d'un fichier
grid initGrid3D(int,int); // construit une grille en fonction de l'altitude
void addRandomBlob(grid,int t,int n); // ajoute n blobs de texture t
void addRandomArc(grid,int t,int n); // ajoute n arcs de texture t
position randomPosition(grid,int t); // position aléatoire sur texture de type t
void freeGrid(grid); // libère la mémoire alouée par les fonctions initGridXXX()


////////////////////////
//
// SPÉCIFIQUE POUR SDL
//
////////////////////////


// Quelques variables globales.
//
// NB: Certains compilateurs râlent si on n'ajoute pas "extern" devant
//     les variables initialisées ailleurs (dans tools.c). Suivant la
//     même logique on pourrait ajouter des "extern" devant toutes les
//     fonctions des .h, mais cela semble inutile même sous les
//     compilateurs râleurs.

extern int width, height;  // taille de la fenêtre, mise à jour si redimensionnée
extern bool update;        // si vrai, force le dessin dans les fonctions drawXXX()
extern bool running;       // devient faux si 'q' est pressé
extern bool hover;         // si vrai, permet de déplacer un sommet
extern bool erase;         // pour A*: efface les couleurs à la fin ou pas
extern double scale;       // zoom courrant, 1 par défaut
extern GLfloat size_pt;    // taille des points

// pour la 3D
extern int mounts;         // nombre de montagnes ou de creux
extern float flatness;     // applatissement fixant la hauteur max à min(X,Y)/flatness
extern float steepness;    // raideur des pics: 0=plat, 10=raide, 50=très raide
extern float holeness;     // pourcentage de creux [0,1]
extern float disparity;    // pourcentage de disparité des hauteurs [0,1]

// couleurs pour drawX(), valeurs RGB dans [0,1]
extern GLfloat COLOR_GROUND[]; // fond
extern GLfloat COLOR_POINT[];  // point
extern GLfloat COLOR_LINE[];   // ligne de la tournée
extern GLfloat COLOR_PATH[];   // chemin
extern GLfloat COLOR_ROOT[];   // racine, point de départ
extern GLfloat COLOR_TREE[];   // arête de l'arbre

// Initialisation de SDL et OpenGL.
void init_SDL_OpenGL(void);

// Libération de la mémoire.
void cleaning_SDL_OpenGL(void);

// Gestion des évènements (souris, touche clavier, redimensionnement
// de la fenêtre, etc.). Renvoie true ssi la position d'un point a
// changé. Si wait_event = true, alors on attend qu'un évènement se
// produise (et on le gère). Sinon, on n'attend pas et on gère
// l'évènement courant. La touche 'h' affiche une aide dans la
// console, soit la chaîne HELP[] définie dans tools.c.
bool handleEvent(bool wait_event);

// Définit le nombre d'appels à DrawGrid par seconde (minimum 1),
// utile notamment quand vous trouvez un chemin et pour ralentir
// l'affichage à ce moment.
void speedSet(unsigned long speed);

// Fonction de chronométrage. Renvoie une durée (écrite sous forme de
// texte) depuis le dernier apppel à la fonction TopChrono(i) où i est
// le numéro de chronomètre souhaité. La précision varie entre la
// minute et le 1/1000e de seconde.
char *TopChrono(const int i);

#endif // __TOOLS_H__


=========================================
File: ./playground_TP/tsp_main.c
=========================================
#include "tools.h"

#include "tsp_brute_force.h"
// #include "tsp_prog_dyn.h"
// #include "tsp_heuristic.h"
// #include "tsp_mst.h"
// #include "pppp.h"

int main(int argc, char *argv[]) {
  int n         = (argc >= 2) ? atoi(argv[1]) : 10;
  unsigned seed = time(NULL) % 1000;
  printf("seed: %u\n", seed); // pour rejouer la même chose au cas où
  srandom(seed);

  TopChrono(0);                 // initialise tous les chronos

  point *V = NULL;              // tableau de points
  V = generatePoints(n);        //  n pts au hasard
  // V = generateCircles(n,8);  //  n pts sur 8 cercles
  // V = generateConvex(n);     //  n pts aléatoires en position convexe
  // V = generatePower(n,1.4);  //  n pts sur un disque avec loi exponentielle
  // V = generateGrid(&n,3,6);  // 18 pts sur une grille 3x6
  // V = generateGrid(&n,5,10); // 50 pts qui peuvent faire boucler first_flip()
  // V = generateLoad(&n,"points.txt"); // pts depuis un fichier

  if (n <= 0) {
    printf("Error: n=%d, it must be at least one.\n", n);
    exit(1);
  } // ici n>=1

  int *P = malloc(n * sizeof(*P)); // P = la tournée
  P[0] = -1;   // permutation qui ne sera pas dessinée par drawTour()

  init_SDL_OpenGL();    // initialisation avant de dessiner
  drawTour(V, n, NULL); // dessine seulement les points

#define MESSAGE                                 \
  printf("running time: %s\n", TopChrono(1));   \
  printf("waiting for a key ... [h] for help"); \
  fflush(stdout);

#ifdef TSP_BRUTE_FORCE_H
  printf("*** brute-force ***\n");
  running = true;      // force l'exécution
  TopChrono(1);        // départ du chrono 1
  printf("value: %g\n", tsp_brute_force(V, n, P));
  MESSAGE;
  update = true;       // force l'affichage
  while (running) {    // affiche le résultat et attend (q pour sortir)
    drawTour(V, n, P); // dessine la tournée
    handleEvent(true); // attend un évènement (=true) ou pas
  }
  printf("\n");

  printf("*** brute-force optimisé ***\n");
  running = true;      // force l'exécution
  TopChrono(1);        // départ du chrono 1
  printf("value: %g\n", tsp_brute_force_opt(V, n, P));
  MESSAGE;
  update = true;       // force l'affichage
  while (running) {    // affiche le résultat et attend (q pour sortir)
    drawTour(V, n, P); // dessine la tournée
    handleEvent(true); // attend un évènement (=true) ou pas
  }
  printf("\n");

  /* pour rendre dynamique le calcule */
  /*
     printf("*** brute-force optimisé (affichage dynamique) ***\n");
     running = true; // force l'exécution
     bool redraw = true; // si les points ont changés
     while (running) {   // affiche le résultat et attend (q pour sortir)
     if (redraw){      // recalcule si nécessaire
      TopChrono(1);   // départ du chrono 1
      printf("value: %g\n", tsp_brute_force_opt(V, n, P));
      MESSAGE;
     }
     drawTour(V, n, P); // dessine la tournée
     redraw = handleEvent(true); // attend un évènement (=true) ou pas
     }
   */
#endif

#ifdef TSP_PROG_DYN_H
  printf("*** programmation dynamique ***\n");
  running = true;          // force l'exécution
  TopChrono(1);            // départ du chrono 1
  printf("value: %g\n", tsp_prog_dyn(V, n, P));
  MESSAGE;
  update = true;           // force l'affichage
  while (running) {        // affiche le résultat et attend (q pour sortir)
    drawTour(V, n, P);     // dessine la tournée
    handleEvent(true);     // attend un évènement (=true) ou pas
  }
  printf("\n");
#endif

#ifdef TSP_HEURISTIC_H
  printf("*** flip ***\n");
  running = true;          // force l'exécution
  TopChrono(1);            // départ du chrono 1
  printf("value: %g\n", tsp_flip(V, n, P));
  MESSAGE;
  while (running) {        // affiche le résultat et attend (q pour sortir)
    update = (first_flip(V, n, P) ==
              0.0);        // force l'affichage si pas de flip possible
    drawTour(V, n, P);     // dessine la tournée
    handleEvent(update);   // attend un évènement (si affichage) ou pas
  }
  printf("\n");

  printf("*** greedy ***\n");
  running = true;          // force l'exécution
  TopChrono(1);            // départ du chrono 1
  printf("value: %g\n", tsp_greedy(V, n, P));
  MESSAGE;
  bool new_redraw1 = true;
  update = true;           // force l'affichage
  while (running) {        // affiche le résultat et attend (q pour sortir)
    if (new_redraw1)
      tsp_greedy(V, n, P);
    drawTour(V, n, P);     // dessine la tournée
    new_redraw1 =
      handleEvent(update); // attend un évènement (si affichage) ou pas
    // décommentez la ligne suivante pour avoir greedy+flip
    // update = (first_flip(V, n, P) == 0.0); // force l'affichage si pas de
    // flip
  }
  printf("\n");
#endif

#ifdef TSP_MST_H
  printf("*** mst ***\n");
  running = true;           // force l'exécution
  TopChrono(1);             // départ du chrono 1
  graph T = createGraph(n); // graphe vide
  printf("value: %g\n", tsp_mst(V, n, P, T));
  MESSAGE;
  bool new_redraw2 = true;
  update = true;            // force l'affichage
  while (running) {
    if (new_redraw2)
      tsp_mst(V, n, P, T);
    drawGraph(V, n, P, T);
    new_redraw2 =
      handleEvent(update);  // attend un évènement (si affichage) ou pas
    // décommentez la ligne suivante pour avoir mst+flip
    // update = (first_flip(V, n, P) == 0.0); // force l'affichage si pas de
    // flip
  }
  printf("\n");
  freeGraph(T);
#endif

#ifdef PPPP_H
  printf("*** closest pair of points ***\n");
  if (n < 2) {
    printf("Error: n=%d, it must be at least two.\n", n);
    exit(1);
  }                                   // ici n>=2
#define FAIL "\xf0\x9f\x94\xa5 fail!" // char utf8
#define PPPP(algo)                                                \
  {                                                               \
    TopChrono(1);                                                 \
    couple C = pppp_ ## algo(V, n);                               \
    printf("pppp_" # algo "():\tdist(V[%i],V[%i]) = ", C.i, C.j); \
    if (C.i < 0 || C.i >= n || C.j < 0 || C.j >= n || C.i == C.j) \
    printf(FAIL);                                                 \
    else {                                                        \
      printf("%.04lf", dist(V[C.i], V[C.j]));                     \
      M.list[C.i][M.deg[C.i]++] = C.j;                            \
      M.list[C.j][M.deg[C.j]++] = C.i;                            \
    }                                                             \
    printf("  (time=%s)\n", TopChrono(1));                        \
  }

  // V[n/2] = V[n-1]; // test point confondus

  running = true;                         // force l'exécution
  bool new_redraw3 = true;                // si les points ont changés
  graph M          = createGraph(n);      // graphe vide (ensemble d'arête)
  update = true;                          // force l'affichage
  while (running) {                       // affiche le résultat et attend (q
                                          // pour sortir)
    if (new_redraw3) {                    // recalcule si nécessaire
      bzero(M.deg, M.n * sizeof(*M.deg)); // vide le graphe
      PPPP(naive);
      PPPP(divide);
      PPPP(random);
      printf("\n");
    }
    drawGraph(V, n, NULL, M);             // dessine les arêtes du graphe
    new_redraw3 = handleEvent(update);    // attend un évènement (=true) ou pas
  }
  printf("\n");
  freeGraph(M);
#endif

  // Libération de la mémoire
  TopChrono(-1);
  free(V);
  free(P);

  cleaning_SDL_OpenGL();
  return 0;
}


