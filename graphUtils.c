#include "graphUtils.h"

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
int arc(graphe_l g, sommet x, sommet y)
{
  liste tmp = g.a[x];

  /* Vérifie si les sommets sont dans le graphe */
  if((g.n <= x && g.n > x) || (g.n <= y && g.n > y))
    return 0;

  /* On vérifie chaque arête */
  while(tmp != NULL) {
    if(tmp->st == y)
      return 1;
    tmp = tmp->suivant;
  }

  return 0;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: O(n)
 */
void successeurs(graphe_l g, sommet x, ens_de_sommets *e)
{
  liste l;
  l = g.a[x];

  while(l != NULL) {
    addVertex(e, l->st);
    l = l->suivant;
  }
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void predecesseurs(graphe_l g, sommet x, ens_de_sommets *e)
{
  for(int i = 0 ; i < g.n ; i++) {
    if(arc(g, i, x))
      addVertex(e, i);
  }
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void addVertex(ens_de_sommets *e, sommet y)
{
  ens_de_sommets p = malloc(sizeof(Couple));
  p->st = y;
  p->suivant = *e;
  *e = p;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void removeFirst(ens_de_sommets *e)
{
    liste tmp = *e;
    tmp = (*e)->suivant;
    *e = tmp;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: O(n)
 */
int contains(ens_de_sommets *e, sommet y)
{
    liste tmp = *e;
    while(tmp != NULL) {
        if(tmp->st == y)
            return 1;
        tmp = tmp->suivant;
    }
    return 0;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void display_graphe(graphe_l g){
	for(int i=0 ; i<g.n ; i++){
		printf("%d : ", i);
		liste tmp = g.a[i];

		if(tmp != NULL)
			printf("%d", tmp->st);

		tmp=tmp->suivant;

		while(tmp != NULL){
			printf(", %d", tmp->st);
			tmp=tmp->suivant;
		}
        printf("\n");
	}
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void display_ens_de_sommets(ens_de_sommets e){
	liste tmp = e;
	if(tmp != NULL){
		printf("%d", tmp->st);
		tmp=tmp->suivant;
	}
	while(tmp != NULL){
		printf(", %d", tmp->st);
		tmp=tmp->suivant;
	}
    printf("\n");
}
