#ifndef __UTILS__
#define __UTILS__

#include "graphUtils.h"
#include "satUtils.h"

/* Crée un graphe suivant le fichier donné en paramètre */
graphe_l* readFile(const char* fileAbsolutePath);

/* Crée un graphe suivant le fichier donné en paramètre */
Sat* readSatFile(char* fileAbsolutePath);

/* Supprime le graphe */
void freeTheG(graphe_l *g);

/* Supprime une liste du graphe */
void deleteList(liste *l);

#endif /* __UTILS__ */
