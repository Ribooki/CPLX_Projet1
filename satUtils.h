#include <stdio.h>
#include <stdlib.h>

typedef int sommet;

typedef struct {
    struct Clause *clauses;
    int clausesCount;
} Sat;

typedef struct {
    struct Vertex *vertices;
} Clause;

typedef struct{
    int sommet *sommets;
    int isNegative;
} Vertex;

void addClauseInSat();

void addVertexInClause();