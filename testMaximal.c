#include "utils.h"
#include "verification.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: ./testV fichier\n");
        exit(EXIT_FAILURE);
    }

    testMaximal(argv[1]);
    return 0;
}

int testMaximal(const char* fileAbsolutePath){
    graphe_l *g = readFile(fileAbsolutePath);
    int randG = rand()%10+5;
    int nbDeSommetsAPrendre = g->n/randG; //Nb de sommets a prendre (ici entre 5 et 15)
    int nbSommetsPris = 0;
    ens_de_sommets e = NULL;
    //Creation ensemble de sommets aleatoirement
    while(nbSommetsPris<nbDeSommetsAPrendre){
        randG = rand()%g->n;
        if(!contains(e, randG)){
            addVertex(&e, randG);
            nbSommetsPris ++;
        }
    }

    display_ens_de_sommets(e);
    if(isMaximal){
        printf("L'ensemble est maximal");
    }else{
        printf("L'ensemble n'est pas maximal");
    }
        deleteList(&e);
    freeTheG(g);
}