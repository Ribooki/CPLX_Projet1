#include "maximum.h"

int count_vertex(ens_de_sommets e)
{
    int count = 0;
    liste tmp = e;
    while(tmp != NULL) {
        count++;
        tmp = tmp->suivant;
    }
    return count;
}

int existe_desert_maximum_exacte(graphe_l g, int k)
{
    ens_de_sommets e = NULL;
    for(sommet x = 0 ; x < g.n ; x++) {
        e = calcul_graphe_maximal(g, x);
        if(count_vertex(e) >= k)
        {
            display_ens_de_sommets(e);
            deleteList(&e);
            return 1;
        }
        deleteList(&e);
    }
    deleteList(&e);
    return 0;
}

int existe_desert_maximum_incomplet(graphe_l g, int k)
{
    ens_de_sommets e = NULL;
    for(sommet x = 0 ; x < g.n ; x += 2) {
        e = calcul_graphe_maximal(g, x);
        if(count_vertex(e) >= k)
        {
            //display_ens_de_sommets(e);
            deleteList(&e);
            return 1;
        }
        deleteList(&e);
    }
    deleteList(&e);
    return 0;
}
