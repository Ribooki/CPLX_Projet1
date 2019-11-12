#include "maximal.h";

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
          else                  //sinon e n'est pas maximal
            return 0;
      }
  }
  return 1;
}