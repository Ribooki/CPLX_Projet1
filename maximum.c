#include "maximum.h";

int calcul_maximum_exact(graphe_l g, int * sommetsRetires, int *sommetsSelectionables,int k){
    if()
    if(sommetsRetires == NULL){
        sommetsRetires = malloc(sizeof(int)*g.e);
        for(int i=0; i<g.e; i++){
            sommetsRetires[i] = 0;
        }
    }
    if(sommetsSelectionables == NULL){
        sommetsSelectionables = malloc(sizeof(int)*g.e);
        for(int i=0; i<g.e; i++){
            sommetsSelectionables[i] = 1;
        }
    }

    //vériferi quand sommet est delectionnable ou non

    liste listeDesVoisins;
    for(int i=0; i<g.e; i++){
        sommetsRetires[i] = 1;
        sommetsSelectionables[i] = 0;
        free(listeDesVoisins);
        memcpy(listeDesVoisins, g.a[i], sizeof(g.a[i]));
        while(listeDesVoisins != NULL){
            if(sommetsSelectionables[i] == 1){
                sommetsRetires[listeDesVoisins->st] = 1;
            }
            listeDesVoisins = listeDesVoisins->suivant;
        }
        if(calcul_maximum_exact(g, sommetsRetires, sommetsSelectionables,k-1)){
            return 1;
        }
    }
}
