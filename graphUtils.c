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

void addVertex(ens_de_sommets *e, sommet y)
{
  ens_de_sommets p = malloc(sizeof(Couple));
  p->st = y;
  p->suivant = *e;
  e = &p;
}
