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
    int x;
    int y;
    while(fscanf("%i %i", &x, &y)!=EOF){
        addVertex(graph->a[x], y);
    }
    
    fclose(file);
    return graph;
}