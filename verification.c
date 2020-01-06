#include "verification.h"

/**
 * spec: Vérifie que le graph donné en entrée est désert ou non.
 * Avec g le graph et e l'ensemble de sommets représentant le sous-ensemble désert.
 * Pour chaque sommet dans l'ensemble, on vérifie si un autre sommet de cet ensemble est reliable par une arête.
 * Retourne 1 si vraie , 0 sinon.
 * auteur: Alexandre Tosi
 * verificateur: Thomas Rieffel
 * complexité: O(nlog(n)m)
 */
int isDesert(graphe_l g, ens_de_sommets *e)
{
  liste tmp = NULL, tmp2 = NULL;
  sommet s = 0;
  tmp = *e;

  /* Pour chaque sommet */
  while(tmp != NULL) {
      s = tmp->st;

      /* On vérifie tous les arcs du sommet */
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

/**
 * spec: Vérifie que le graph donné en entrée est un désert maximal ou non.
 * Avec g le graph et e l'ensemble de sommets représentant le sous-ensemble désert.
 * Si le graph est desert on vérifie pour chaque sommet dans le graph si en l'ajoutant le graph reste desert ou non.
 * Si oui, alors on retourne 0, 1 sinon.
 * auteur: Thomas Rieffel
 * verificateur: Romain Allemand
 * complexité: O(n^2log(n)m)
 */
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
