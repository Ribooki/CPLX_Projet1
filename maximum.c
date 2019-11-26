#include "maximum.h"

// int calcul_maximum_exact(graphe_l g, int * sommetsRetires, int *sommetsSelectionables,int k) {
//     if()
//     if(sommetsRetires == NULL){
//         sommetsRetires = malloc(sizeof(int)*g.e);
//         for(int i=0; i<g.e; i++){
//             sommetsRetires[i] = 0;
//         }
//     }
//     if(sommetsSelectionables == NULL){
//         sommetsSelectionables = malloc(sizeof(int)*g.e);
//         for(int i=0; i<g.e; i++){
//             sommetsSelectionables[i] = 1;
//         }
//     }
//
//     //vérifie quand sommet est delectionnable ou non
//
//     liste listeDesVoisins;
//     for(int i=0; i<g.e; i++){
//         sommetsRetires[i] = 1;
//         sommetsSelectionables[i] = 0;
//         free(listeDesVoisins);
//         memcpy(listeDesVoisins, g.a[i], sizeof(g.a[i]));
//         while(listeDesVoisins != NULL){
//             if(sommetsSelectionables[i] == 1){
//                 sommetsRetires[listeDesVoisins->st] = 1;
//             }
//             listeDesVoisins = listeDesVoisins->suivant;
//         }
//         if(calcul_maximum_exact(g, sommetsRetires, sommetsSelectionables,k-1)){
//             return 1;
//         }
//     }
// }

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
            deleteList(&e);
            return 1;
        }
        deleteList(&e);
    }
    deleteList(&e);
    return 0;
}
