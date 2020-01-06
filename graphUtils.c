#include "graphUtils.h"

/**
 * spec: Vérifie si il existe un arc reliant les 2 sommets donnés.
 * Avec g le graph, x et y les 2 sommets à tester.
 * Si les 2 sommets sont bien dans le graph, on vérifie chaque arête du sommet x en vérifiant que son successeur soit y.
 * Si oui, on retourne 1 sinon on retourne 0 à la fin du parcourt.
 * auteur: Alexandre Tosi
 * verificateur: Thomas Rieffel 
 * complexité: O(m)
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
 * spec: Ajoute à l'ensemble de sommet donné les successeurs du sommet donné.
 * Avec g le graph, x le sommet et e l'ensemble de sommets
 * On parcourt les voisins du sommets et on les ajoutes 1 à 1 à l'ensemble.
 * auteur: ??
 * verificateur: Thomas Rieffel
 * complexité: O(m)
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
 * spec: Ajoute à l'ensemble de sommet donné les predecesseurs du sommet donné.
 * Avec g le graph, x le sommet et e l'ensemble de sommets
 * On parcourt les voisins du sommets et on les ajoutes 1 à 1 à l'ensemble.
 * auteur: ??
 * verificateur: Thomas Rieffel
 * complexité: O(m)
 */
void predecesseurs(graphe_l g, sommet x, ens_de_sommets *e)
{
  for(int i = 0 ; i < g.n ; i++) {
    if(arc(g, i, x))
      addVertex(e, i);
  }
}

/**
 * spec: Ajoute un sommet donné à l'ensemble de sommets donné.
 * Avec e l'ensemble de sommets et y le sommet.
 * auteur: ??
 * verificateur: Thomas Rieffel
 * complexité: O(1)
 */
void addVertex(ens_de_sommets *e, sommet y)
{
  ens_de_sommets p = malloc(sizeof(Couple));
  p->st = y;
  p->suivant = *e;
  *e = p;
}

/**
 * spec: Supprime le premier sommet de l'ensemble donné (Le 2 eme devient le 1er...)
 * Avec e l'ensemble de sommets.
 * auteur: ??
 * verificateur: Thomas Rieffel
 * complexité: O(1)
 */
void removeFirst(ens_de_sommets *e)
{
    liste tmp = *e;
    tmp = (*e)->suivant;
    *e = tmp;
}

/**
 * spec: Vérifie si l'ensemble donné contient le sommet donné.
 * Avec e l'ensemble et y le sommet à vérifier.
 * On parcourt donc l'ensemble en vérifiant si un sommet est égal à y.
 * Si oui on retourne 1, sinon, on retourne 0 a la fin du parcourt de l'ensemble.
 * auteur: Thomas Rieffel
 * verificateur: Alexandre Tosi
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
 * spec: Affiche le graph donné.
 * Avec g un graph.
 * parcourt le graph et affiche ses sommets et arêtes
 * auteur: ??
 * verificateur: ??
 * complexité: O(nm)
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
 * spec: Affiche l'ensemble de sommets donné.
 * Avec e un ensemble de sommets.
 * Parcourt l'ensemble de sommets et affiche ses sommets et arêtes
 * auteur: ??
 * verificateur: ??
 * complexité: O(nm)
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
