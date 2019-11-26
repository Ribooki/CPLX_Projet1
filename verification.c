#include "verification.h"

int isDesert(graphe_l g, ens_de_sommets *e)
{
  liste tmp = NULL, tmp2 = NULL;
  sommet s = 0;
  tmp = *e;

  while(tmp != NULL) {
      s = tmp->st;

      /* On check tous les arcs du sommet */
      tmp2 = tmp;
      while(tmp2 != NULL) {
          /* S'il y a un arc, le graphe n'est pas désert */
          if(arc(g, s, tmp2->st))
              return 0;
          tmp2 = tmp2->suivant;
      }

      /* On passe au sommet suivant */
      tmp = tmp->suivant;
  }

  /* Si on ne trouve aucun arc, alors le graphe est désert */
  return 1;
}

int isMaximal(graphe_l g, ens_de_sommets *e)
{
    graphe_l tmp = g;
    if(!isDesert(tmp, e))
        return 0;

    for(int i = 0 ; i < tmp.n ; i++) {
    /* Si i n'est pas déjà un sommet, on l'ajoute puis on teste si le graphe
    ** est désert */
        if(!contains(e, i)) {
            addVertex(e, i);
            if(!isDesert(tmp, e))   //si pas désert on continue
                removeFirst(e);
            else {                  //sinon e n'est pas maximal
                removeFirst(e);
                return 0;
            }
        }
    }
    return 1;
}
