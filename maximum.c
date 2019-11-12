#include "maximum.h";

void calcul_maximum_exact(graphe_l g, int k){
    int *sommetsChoisis = malloc(sizeof(int)*g.e);
    int *sommetsSelectionnes = malloc(sizeof(int)*g.e);
    for(int i=0; i<g.e; i++){
        sommetsChoisis[i] = 0;
        sommetsSelectionnes[i] = 0;
    }
    /**
        free(listeDesVoisins);
        memcpy(listeDesVoisins, g.a[i], sizeof(g.a[i]));
        
    **/
    liste listeDesVoisins;
    for(int i=0; i<g.e; i++){
        sommetsSelectionnes[i] = 1;
        free(listeDesVoisins);
        memcpy(listeDesVoisins, g.a[i], sizeof(g.a[i]));
        while(listeDesVoisins != NULL){
            sommetsSelectionnes[listeDesVoisins->st] = 1;
            listeDesVoisins = listeDesVoisins->suivant;
        }
        
















        sommetsChoisis[i] = 0;
    }
}
