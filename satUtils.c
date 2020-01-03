#include "satUtils.h"

Sat createSat(){
    Sat s = malloc(sizeof(Sat));
    s.clausesCount = 0;
    s->clauses = malloc(s->clauses, 0);
    return s;
}

Clause createClause(){
    Clause c = malloc(sizeof(Clause));
    c.verticesCount = 0;
    s->vertices = malloc(s->vertices, 0);
    return c;
}

Vertex createVertex(int isNeg, edge edg){
    if(isNeg > 1 || isNeg < 0) return NULL;
    Vertex v = malloc(sizeof(Vertex));
    v.isNegative = isNeg;
    v.edge = edg;
}

int addClauseInSat(Sat s, Clause c){
    if(c == NULL || s = NULL) return 0;
    s.clausesCount = s.clausesCount + 1;
    s->clauses = realloc(s->clauses, sizeof(Clause) * s.clausesCount);
    s->clauses[s.clausesCount-1] = c;
    return 1;
}

void addVertexInClause(Clause c, Vertex v){
    if(c == NULL || v = NULL) return 0;
    c.verticesCount +1;
    c->vertices = realloc(c->vertices, sizeof(Vertex) * c.verticesCount);
    if(c.verticesCount > 3) return 0;
    c->vertices[c.verticesCount-1] = v;
    return 1;
}

