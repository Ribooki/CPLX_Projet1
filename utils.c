#include "stdlib.h";
#include "stdio.h";


void readFile(char* fileAbsolutePath){
    FILE *file = NULL;
    file = fopen(fileAbsolutePath, "r");
    if(file == NULL){
        printf("Fichier non ouvert");
        return;
    }
    fclose(file);

}