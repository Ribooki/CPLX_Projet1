#include "graphUtils.h"

int arc(graphe_l g, sommet x, sommet y)
{
  liste tmp = g.a[x];

  if(g.n <= x || g.n <= y)
    return 0;

  while(tmp != NULL) {
    if(g.a[x]->suivant->st == y)
      return 1;
    tmp = tmp->suivant;
  }

  return 0;
}

void successeurs(graphe_l g, sommet x, ens_de_sommets *e)
{
  liste l;
  l = g.a[x];
  e = NULL;

  while(l != NULL) {
    addVertex(e, l->st);
    l = l->suivant;
  }
}

void predecesseurs(graphe_l g, sommet x, ens_de_sommets *e)
{
  for(int i = 0 ; i < g.n ; i++) {
    if(arc(g, i, x))
      addVertex(e, i);
  }
}

void addVertex(ens_de_sommets *e, sommet y)
{
  ens_de_sommets p = malloc(sizeof(Couple));
  p->st = y;
  p->suivant = *e;
  *e = p;
}

int isDesert(graphe_l g, ens_de_sommets *e)
{
  liste tmp = NULL;
  if(e == NULL)
    return 0;

  tmp = *e;
  while(tmp->suivant != NULL)
    if(arc(g, tmp->st, tmp->suivant->st))
      return 0;

  return 1;
}
