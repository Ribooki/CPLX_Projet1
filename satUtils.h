#include <stdio.h>
#include <stdlib.h>

typedef int edge;

typedef struct {
    struct Clause *clauses;
    int clausesCount;
    int differentsVerticesCount;
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

Vertex createVertex(int isNeg, edge edg);

int addClauseInSat(Sat *s, Clause *c);//retourne 1 si réussis, 0 sinon

int addVertexInClause(Sat *s, Clause *c, Vertex *v);//retourne 1 si réussis, 0 sinon

void displaySat(Sat s);