#include "testVerification.h"

ens_de_sommets randomEns(graphe_l *g)
{
    srand(time(NULL));
    ens_de_sommets e = NULL;

    for(int i = 0 ; i < 3 ; i++) {  //3 sommets aléatoires
        int random = rand() % g->n;
        if(!contains(&e, random))
            addVertex(&e, random);
    }

    return e;
}

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: ./testV fichier\n");
        exit(EXIT_FAILURE);
    }

    graphe_l *g = readFile(argv[1]);
    ens_de_sommets e = randomEns(g);
    display_ens_de_sommets(e);
    printf("e est-il un sous-graphe désert de g ? %s\n", isDesert(*g, &e) ? "oui" : "non");

    deleteList(&e);
    freeTheG(g);

    return 0;
}
