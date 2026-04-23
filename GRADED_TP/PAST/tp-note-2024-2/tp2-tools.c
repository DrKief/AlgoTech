#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> /* pour gettimeofday() */
#include <limits.h>   /* pour INT_MAX, LONG_MAX ... */
#include <math.h>     /* pour hypoth() ... */

// vrai ssi (i,j) est en dehors de la grille
#define OUT(i,j,n) ((i<0)||(j<0)||(i>=n)||(j>=n))


void print_resultat(grid G, int n, position P){
  int error=(n<3)||(G==NULL);
  printf("n=%i\n\t          \tj=%i\n",n,P.j);
  
  for(int i=P.i-1;i<=P.i+1;i++){
    if(i==P.i) printf("i=%i",i);
    printf("\t");
    for(int j=P.j-1;j<=P.j+1;j++){
      char *s=(i==P.i)||(j==P.j)?"\E[0;0m":"\E[0;0m";
      if(error||OUT(i,j,n)) printf("**********");
      else printf("%s" FORM,s,G[i][j]);
      printf("\t");
    }
    printf("\n");
  }

  if((P.i==0)||(P.j==0)){ printf("The maximum shouldn't be on the border.\n"); exit(1); }
  return;
}


grid grid_alloc(int n){
  if(n<1) return NULL;
  grid G=malloc(n*sizeof(*G));
  if(G==NULL) return NULL;
  for(int i=0;i<n;i++){
    G[i]=malloc(n*sizeof(*(G[i])));
    if(G[i]==NULL) return NULL;
  }
  return G;
}


grid grid_read(char *file, int *n){

  // ouvre le fichier
  FILE *f=fopen(file,"r");
  if(f==NULL){ printf("Cannot open file \"%s\"\n",file); exit(1); }

  // lit la dimension
  fscanf(f,"%i\n",n);

  // lit les n x n valeurs de la grille
  grid G=grid_alloc(*n);
  int fin=(G==NULL)||(*n<1);
  int i=0,j=0,c=0;
  
  while(!(feof(f)||fin)){
    fscanf(f,"%lf",&(G[i][j]));
    c++; // compte le nombre d'entrées lues
    j++; // changement de colonne
    if(j==*n){
      j=0;
      i++; // changement de ligne
      if(i==*n){
	fin=1;
      }
    }
  }
  fclose(f);

  if(c!=(*n)*(*n)){ printf("Incorrect number of values.\n"); exit(1); }
  return G;
}


// réel aléatoire dans [0,1[
#define RAND01  ((double)random()/(double)RAND_MAX)

// vrai ssi (i,j) correspond à un bord de la grille n x n
#define BORD(i,j,n) ((i==0)||(j==0)||(i==n-1)||(j==n-1))

grid grid_genrandom(int n){
  if((n<3)||(n>40000)) return NULL;
  grid G=grid_alloc(n);
  if(G==NULL) return G;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(BORD(i,j,n)){ G[i][j]=0.0; continue; }
      G[i][j]= RAND01; 
    }
  
  return G;
}

grid grid_gen1(int n){
  if((n<3)||(n>40000)) return NULL;
  grid G=grid_alloc(n);
  if(G==NULL) return G;

  // (x,y)=centre aléatoire en dehors des bords
  int x=1+(RAND01*(n-2));
  int y=1+(RAND01*(n-2));
  double v=RAND01/(double)n; // valeur pour (x,y)
  // calcule d = la longueur de la diagonale la plus grande
  int x0=n-1; if(x>n/2) x0=0;
  int y0=n-1; if(y>n/2) y0=0;
  double d=hypot(x0-x,y0-y);
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(BORD(i,j,n)){ G[i][j]=0.0; continue; }
      double a=hypot(i-x,j-y)/d; // a dans [0,1[
      double b=hypot(abs(i-x)+.5,abs(j-y)+.5)/d; // a+eps (eps< 1 pas)
      double c=a+RAND01*(b-a); // c aléatoire dans [a,b[
      if(c>1) c=1; // pas plus qu'1
      G[i][j]= 1 - v - c*(1-v); // G[i][j] dans [0,1-v]
    }
  
  return G;
}


grid grid_gen2(int n){
  if((n<3)||(n>40000)) return NULL;
  grid G=grid_alloc(n);
  if(G==NULL) return G;

  // met des 1.0 de partout
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      G[i][j]=0.0;

  // Creuse une fosse en spirale depuis le centre. Plus précisément,
  // on part du centre, puis on fait 2 fois vers la droite, puis 2
  // fois vers le haut, puis 4 fois vers le bas, puis 4 fois vers la
  // gauche, puis 6 fois ... Donc la direction tourne d'un quart à
  // chaque fois et on augmente la longueur du coté de 2 unités toutes
  // les deux fois. On peut vérifier que le nombre de positions qu'on
  // va parcourir (en incluant le point de départ) vaut, en fonction
  // de n: 1, 1, 2, 2, 17, 17, 18, 18, 49, 49, 50, 50, 97, 97, 98, 98,
  // ...  soit a((n+1)/4) + (((n+1)%4)>1), avec a(n)=8n(n-1)+1

  position D[]={{0,+1},{-1,0},{0,-1},{+1,0}}; // directions successives: > ^ < v
  int i,j,c,d;
  
  c=(n+1)/4;
  c=8*c*(c-1)+1+(((n+1)%4)>1);
  double v,dec=1.0/c; // dec = incrément

  i=j=n/2; // (i,j) = position courante = on part du centre
  c=2; // longueur des cotés:  2,2,4,4,6,6,8,8,...
  d=0; // indice de direction: 0,1,2,3,0,1,2,3,...
  
  for(;;){ // forever
    for(int k=0;k<c;k++){
      v=G[i][j]+dec; // nouvelle valeur = ancienne + incrément
      i += D[d].i; // déplacement suivant la direction D[d]
      j += D[d].j;
      if(BORD(i,j,n)) break; // on s'arrête si on touche un bord
      G[i][j]=v; // on creuse la fosse
    }
    if(BORD(i,j,n)) break; // on s'arrête si on touche un bord
    d=(d+1)%4; // changement de direction
    if(d%2==0) c+=2; // augmente la longueur du coté une fois sur 2
  }

  return G;
}


#define CHRONOMAX 5 /* nombre maximum de chronomètres */


char *TopChrono(int i){
/*
  Met à jour le chronomètre interne numéro i (i=0..CHRNONMAX-1) et
  renvoie sous forme de char* le temps écoulé depuis le dernier appel
  à la fonction pour le même chronomètre. La précision dépend du temps
  mesuré. Il varie entre la seconde et le 1/10000 de seconde. Plus
  précisément le format est le suivant:

  1d00h00'  si le temps est > 24h (précision: 1')
  1h00'00"  si le temps est > 60' (précision: 1s)
  1'00"0    si le temps est > 1'  (précision: 1/10s)
  1"00      si le temps est > 1"  (précision: 1/100s)
  0"0000    si le temps est < 1"  (précision: 1/10000s)

  Pour initialiser et mettre à jour tous les chronomètres (dont le
  nombre vaut CHRONOMAX), il suffit d'appeler une fois la fonction,
  par exemple avec TopChrono(0). Si i<0, alors les pointeurs alloués
  par l'initialisation sont désalloués. La durée maximale est limitée
  à 100 jours. Si une erreur se produit (durée supérieure ou erreur
  avec gettimeofday()), alors on renvoie la chaîne "--error--".
  
  On n'utilise pas clock() qui se limite à 72 minutes. Pour des durées
  en micro secondes mais plus beaucoup plus longues, il faut utiliser
  gettimeofday() comme ceci:

  gettimeofday(&t0,NULL);
  ...
  gettimeofday(&t1,NULL);
  long long t = (t1.tv_sec-t0.tv_sec)*1000000LL + t1.tv_usec-t0.tv_usec;
*/
  if(i>=CHRONOMAX) return "--error--";
  
  /* variables globales, locale à la fonction */
  static int first=1; /* =1 ssi c'est la 1ère fois qu'on exécute la fonction */
  static char *str[CHRONOMAX];
  static struct timeval last[CHRONOMAX],tv;
  int j;

  if(i<0){ /* libère les pointeurs */
    if(!first) /* on a déjà alloué les chronomètres */
      for(j=0;j<CHRONOMAX;j++)
	free(str[j]);
    first=1;
    return NULL;
  }

  /* tv=temps courant */
  int err=gettimeofday(&tv,NULL);

  if(first){ /* première fois, on alloue puis on renvoie TopChrono(i) */
    first=0;
    for(j=0;j<CHRONOMAX;j++){
      str[j]=malloc(10); // assez grand pour "--error--", "99d99h99'" ou "23h59'59""
      last[j]=tv;
    }
  }

  /* t=temps en 1/10000" écoulé depuis le dernier appel à TopChrono(i) */
  long t=(tv.tv_sec-last[i].tv_sec)*10000L + (tv.tv_usec-last[i].tv_usec)/10000L;
  last[i]=tv; /* met à jour le chrono interne i */
  if((t<0L)||(err)) t=LONG_MAX; /* temps erroné */
  
  /* écrit le résultat dans str[i] */
  for(;;){ /* pour faire un break */
    /* ici t est en millième de seconde */
    if(t<10000L){ /* t<1" */
      sprintf(str[i],"0\"%04li",t);
      break;
    }
    t /= 100L; /* t en centième de seconde */
    if(t<6000L){ /* t<60" */
      sprintf(str[i],"%li\"%02li",t/100L,t%100L);
      break;
    }
    t /= 10L; /* t en dixième de seconde */
    if(t<36000L){ /* t<1h */
      sprintf(str[i],"%li'%02li\"%li",t/360L,(t/10L)%60L,t%10L);
      break;
    }
    t /= 10L; /* t en seconde */
    if(t<86400L){ /* t<24h */
      sprintf(str[i],"%lih%02li'%02li\"",t/3600L,(t/60L)%60L,t%60L);
      break;
    }
    t /= 60L; /* t en minute */
    if(t<144000){ /* t<100 jours */
      sprintf(str[i],"%lid%02lih%02li'",t/1440L,(t/60L)%24L,t%60L);
      break;
    }
    /* error ... */
    sprintf(str[i],"--error--");
  }
  
  return str[i];
}
