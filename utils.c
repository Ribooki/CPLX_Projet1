#include "graphUtils.h"

graphe_l* readFile(char* fileAbsolutePath)
{
    graphe_l *graph = malloc(sizeof(graphe_l));
    int x, y;
    FILE *file = NULL;
    file = fopen(fileAbsolutePath, "r");
    if(file == NULL){
        fprintf(stderr, "Fichier non ouvert");
        return NULL;
    }

    fscanf(file, "%d %d", &graph->n, &graph->e);
    // printf("n: %d, e: %d\n", graph->n, graph->e);
    while(fscanf(file, "%d %d", &x, &y) == 2){
        addVertex(&graph->a[x], y);
        // printf("x: %d, y: %d\n", x, graph->a[x]->st);
    }

    fclose(file);
    return graph;
}

void freeTheG(graphe_l *g)
{

}
