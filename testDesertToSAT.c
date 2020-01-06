#include "desertToSAT.h"

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: ./testDesertToSAT fichier\n");
        exit(EXIT_FAILURE);
    }

    graphe_l *g = readFile(argv[1]);
    
    solveGrapheInSAT(*g, 3);
    
    freeTheG(g);

    return 0;
}
