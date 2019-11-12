#include "maximal.h"

ens_de_sommets calcul_graphe_maximal(graphe_l g, sommet x)
{
    ens_de_sommets e = NULL;
    ens_de_sommets checkVertex = NULL;
    addVertex(&e, x);   //on ajoute le premier sommet
    successeurs(g, x, &checkVertex);
    predecesseurs(g, x, &checkVertex);

    for(int i = 0 ; i < g.n ; i++) {
        if(!contains(&checkVertex, i))
            addVertex(&e, i);
    }

    return e;
}
