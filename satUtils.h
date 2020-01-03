#include <stdio.h>
#include <stdlib.h>

typedef int edge;

typedef struct {
    struct Clause *clauses;
    int clausesCount;
} Sat;

typedef struct {
    struct Vertex *vertices;
    int verticesCount;
} Clause;

typedef struct{
    edge edge;
    int isNegative;
} Vertex;

Sat createSat();

Clause createClause();

Vertex createVertex();

int addClauseInSat();//retourne 1 si réussis, 0 sinon

int addVertexInClause();//retourne 1 si réussis, 0 sinon