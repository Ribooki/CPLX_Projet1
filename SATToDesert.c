#include "SATToDesert.h"

/**
 * spec: Transorme un Probleme SAT vers un graph.
 * Avec fileAbsolutePath, le chamin du fichier a lire.
 * La transformation se fait en lisant le fichier, chaque ligne représentant une clause, on transforme chaque littéral en sommet et on met en voisins
 * les autres littéraux  de la clause.
 * Renvoi le pointeur du graph généré.
 * auteur: Alexandre Tosi
 * verificateur: Romain Allemand
 * complexité: O(n)
 */
graphe_l* satToGraph(char* fileAbsolutePath)
{
    graphe_l *graph = NULL;
    int s1 = 0, s2 = 0, s3 = 0;
    char buffer[1024];
    char tmp = 0;
    FILE *file = NULL;
    file = fopen(fileAbsolutePath, "r");

    if(file == NULL) {
        fprintf(stderr, "Fichier non ouvert.\n");
        exit(EXIT_FAILURE);
    }

    graph = malloc(sizeof(graphe_l));

    //Passe les commentaires
    while(fgetc(file) == 'c')
        fgets(buffer, 1024, file);

    //On enregistre les nombres de sommet et d'arête
    fscanf(file, " cnf %d %d", &graph->n, &graph->e);
    graph->n = 2*graph->n;
    for(sommet s = 0 ; s < graph->n ; s++)
        graph->a[s] = NULL;

    //TODO : On reste en 3-SAT
    // Création du graphe
    while(fscanf(file, "%d %d %d %c", &s1, &s2, &s3, &tmp) == 4) {
        // printf("s1 : %d ; s2 : %d ; s3 : %d\n", s1, s2, s3);
        addVertex(&graph->a[s1], s2);
        addVertex(&graph->a[s2], s1);

        addVertex(&graph->a[s2], s3);
        addVertex(&graph->a[s3], s2);

        addVertex(&graph->a[s3], s1);
        addVertex(&graph->a[s1], s3);
    }

    // for(sommet s = 0 ; s < g->n ; s++) {
    //
    // }

    fclose(file);
    return graph;
}
