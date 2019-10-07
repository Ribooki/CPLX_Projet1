#include "graphUtils.h"

graphe_l* readFile(char* fileAbsolutePath)
{
    graphe_l *graph = malloc(sizeof(graphe_l));
    FILE *file = NULL;
    file = fopen(fileAbsolutePath, "r");
    if(file == NULL){
        fprintf(stderr, "Fichier non ouvert");
        return NULL;
    }

    fscanf(file, "%d %d", &graph->n, &graph->e);
    printf("e: %d, n: %d", graph->e, graph->n);
    int x;
    int y;
    while(fscanf(file, "%d %d", &x, &y)!=EOF){
        addVertex(&graph->a[x], y);
        printf("x: %d, y: %d", x, graph->a[x]->st);
    }

    fclose(file);
    return graph;
}
