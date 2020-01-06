#include "utils.h"
#include "string.h"

/* Transforme un fichier graphe en fichier SAT */
Sat* toSAT(graphe_l g, int k);

void solveGrapheInSAT(graphe_l g, int k);

int getNbVertexInSol(char* out);

int isSatisfiable(char* out);
