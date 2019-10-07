#include <stdio.h>
#include <stdlib.h>

#define n_max 1000

typedef int sommet;

typedef struct chainon {
	sommet st;
	struct chainon *suivant;
} Couple;

typedef Couple *liste;
typedef liste ens_de_sommets;

/* Graphe sous forme de liste d'adjacence */
typedef struct {
	liste a[n_max];
	int n;	//nombre de sommets
	int e;	//nombre d'arêtes
} graphe_l;

/* Renvoie 1 s'il existe un arc entre le sommet x et y, et 0 sinon */
int arc(graphe_l g, sommet x, sommet y);

/* Ajoute les successeurs du sommet x dans ens_de_sommets e */
void successeurs(graphe_l g, sommet x, ens_de_sommets *e);

/* Ajoute le sommet y dans l'ens_de_sommets e */
void addVertex(ens_de_sommets *e, sommet y);

/* Renvoie 1 si le graphe en paramètre est désert, et 0 sinon */
int isDesert(graphe_l g, ens_de_sommets *e);
