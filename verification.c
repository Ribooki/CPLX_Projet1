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

int isMaximal(graphe_l g, ens_de_sommets *e)
{
  if(!isDesert(g, e))
      return 0;

  for(int i = 0 ; i < g.n ; i++) {
      /* Si i n'est pas déjà un sommet, on l'ajoute puis on teste si le graphe
      ** est désert */
      if(!contains(e, i)) {
          addVertex(e, i);
          if(!isDesert(g, e))   //si pas désert on continue
            removeFirst(e);
          else                  //sinon e n'est pas maximal
            return 0;
      }
  }
  return 1;
}
