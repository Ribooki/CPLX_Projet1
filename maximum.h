#include "maximal.h"
#include <string.h>

void calcul_maximum_exact(graphe_l g, int k);

/* Retourne le nombre de sommets de l'ens_de_sommets e */
int count_vertex(ens_de_sommets e);

/* Renvoie 1 s'il existe un sous-graphe désert de taille minimum k, et 0 sinon */
int existe_desert_maximum_exacte(graphe_l g, int k);

/* Renvoie 1 s'il existe un sous-graphe désert de taille minimum k, et 0 sinon.
** Cette fonction ne teste que 50% des cas */
int existe_desert_maximum_incomplet(graphe_l g, int k);
