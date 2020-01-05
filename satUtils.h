#include "maximum.h"

typedef int edge;

typedef struct{
    edge edge;
    int isNegative;
} Vertex;

typedef struct {
    Vertex* vertices;
    int verticesCount;
} Clause;

typedef struct {
    Clause* clauses;
    int clausesCount;
    int differentsVerticesCount;
} Sat;

Sat* createSat();

Clause* createClause();

Vertex* createVertex(int isNeg, edge edg);

int addClauseInSat(Sat *s, Clause *c);//retourne 1 si réussis, 0 sinon

int addVertexInClause(Sat *s, Clause *c, Vertex *v);//retourne 1 si réussis, 0 sinon

void displayVertex(Vertex *v, int isFirst);

void displaySat(Sat* s);

void satToFile(Sat* s, char* path);
 
void execSat(char* path);
