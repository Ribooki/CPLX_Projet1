#include "maximal.h"

ens_de_sommets calcul_graphe_maximal(graphe_l g, sommet x)
{
    ens_de_sommets e = NULL;
    ens_de_sommets checkVertex = NULL;
    addVertex(&e, x);   //on ajoute le premier sommet
    successeurs(g, x, &checkVertex);

    /* Pour chaque sommet, s'il ne se trouve pas parmi les successeurs des
    ** sommets, on l'ajoute dans le sous-graphe, et on met à jour la liste de  
    ** tous les successeurs */
    for(int i = 0 ; i < g.n ; i++) {
        if(!contains(&checkVertex, i) && i != x) {
            addVertex(&e, i);
            successeurs(g, i, &checkVertex);
        }
    }

    deleteList(&checkVertex);
    return e;
}
