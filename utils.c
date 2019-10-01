#include <stdlib.h>;
#include <stdio.h>;
#include "graphUtils.h";


graphe_l* readFile(char* fileAbsolutePath){
    graphe_l *graph = malloc(sizeof(graphe_l));
    FILE *file = NULL;
    file = fopen(fileAbsolutePath, "r");
    if(file == NULL){
        printf("Fichier non ouvert");
        return;
    }

    fscanf("%i %i", &(graph->n), &(graph->e));
    printf("e: %i, n: %i", graph->e, graph->n);
    int x;
    int y;
    while(fscanf("%i %i", &x, &y)!=EOF){
        addVertex(graph->a[x], y);
        printf("x: %i, y: %i", x, graph->a[x]->st);
    }
    
    fclose(file);
    return graph;
}