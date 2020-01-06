#include "SATToDesert.h"
#include "graphUtils.h"
#include "utils.h"
#include "maximum.h"
#include "maximal.h"
#include "verification.h"

int main(int argc, char const *argv[]){

    if(argc != 2) {
        fprintf(stderr, "Usage: ./main fichier\n");
        exit(EXIT_FAILURE);
    }

    // graphe_l *g = readFile("files/1-FullIns_3");
    graphe_l *g = readFile(argv[1]);

    printf("Existe-t-il un sous-graphe désert de taille 3 avec la méthode exacte ? %s\n", existe_desert_maximum_exacte(*g, 3) ? "oui" : "non");
    printf("Existe-t-il un sous-graphe désert de taille 3 avec la méthode incomplète ? %s\n", existe_desert_maximum_incomplet(*g, 3) ? "oui" : "non");

    // solveGrapheInSAT(*g, 3);
    freeTheG(g);

    return 0;
}
