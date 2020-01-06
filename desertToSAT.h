#include "utils.h"
#include "string.h"

/* Transforme un fichier graphe en fichier SAT */
Sat* toSAT(graphe_l g, int k);

void generateAllNotPossible(Sat* sat, int tab[], int k, int i);

void solveGrapheInSAT(graphe_l g, int k);

void tabToClauseInSAT(Sat* sat, int tab[]);

int getNbVertexInSol(char* out);

int isSatisfiable(char* out);
