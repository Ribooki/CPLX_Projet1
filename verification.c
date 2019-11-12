#include "verification.h"

int isDesert(graphe_l g, ens_de_sommets *e)
{
  liste tmp = NULL;

  tmp = *e;
  while(tmp->suivant != NULL) {
    if(arc(g, tmp->st, tmp->suivant->st))
      return 0;
    // if(arc(g, tmp->suivant->st, tmp->st))
    //   return 0;
    tmp = tmp->suivant;
  }

  return 1;
}
