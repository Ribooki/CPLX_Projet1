#include "verification.h"

int isDesert(graphe_l g, ens_de_sommets *e)
{
  liste tmp = NULL;

  tmp = *e;
  while(tmp->suivant != NULL) {
    if(arc(g, tmp->st, tmp->suivant->st))
      return 0;
    if(arc(g, tmp->suivant->st, tmp->st))
      return 0;
    tmp = tmp->suivant;
  }

  return 1;
}


int isMaximal(graphe_l g, ens_de_sommets *e)
{
  if(!isDesert(g, e))
    return 0;

  /*
  tant qu'on arrive pas à la fin alors
    parcours tous les sommets
      on ajoute un sommet qui n'est pas déjà dans e et on vérifie que le graphe est tjr désert
      si non alors
        on retire le sommet
      sinon
        c'en est un et wlh c pa macksymmâlleux
  */
}
