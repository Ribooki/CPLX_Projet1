#include "graphUtils.h"

/* Crée un graphe suivant le fichier donné en paramètre */
graphe_l* readFile(char* fileAbsolutePath);

/* Supprime le graphe */
void freeTheG(graphe_l *g);

/* Supprime une liste du graphe */
void deleteList(liste *l);
