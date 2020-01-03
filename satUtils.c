#include "satUtils.h"

Sat* createSat(){
    Sat *s = malloc(sizeof(Sat));
    s->clausesCount = 0;
    s->differentsVerticesCount = 0;
    s->clauses = malloc(sizeof(Clause));
    return s;
}

Clause* createClause(){
    Clause *c = malloc(sizeof(Clause));
    c->verticesCount = 0;
    c->vertices = malloc(sizeof(Vertex));
    return c;
}

Vertex* createVertex(int isNeg, edge edg){
    if(isNeg > 1 || isNeg < 0) return NULL;
    Vertex *v = malloc(sizeof(Vertex));
    v->isNegative = isNeg;
    v->edge = edg;
    return v;
}

int addClauseInSat(Sat *s, Clause *c){
    if(c == NULL || s == NULL || c->verticesCount > 3) return 0; //Pour 3 sat + verif de bases
    s->clausesCount = s->clausesCount + 1;
    s->clauses = realloc(s->clauses, sizeof(Clause) * s->clausesCount);
    s->clauses[s->clausesCount-1] = *c;
    return 1;
}

int addVertexInClause(Sat *s, Clause *c, Vertex *v){
    if(c == NULL || v == NULL) return 0;
    c->verticesCount += 1;
    if(c->verticesCount > 3) return 0; //Pour 3 sats
    c->vertices = realloc(c->vertices, sizeof(Vertex) * c->verticesCount);
    c->vertices[c->verticesCount-1] = *v;
    if(s->differentsVerticesCount < v->edge){
        s->differentsVerticesCount = v->edge;
    }
    return 1;
}

void displaySat(Sat s){
    int i = 0;
    int y = 0;
    for(i=0; i<s.clausesCount; i++){
        for(y=0; y<3; i++){
            printf(", %d", s.clauses[i].vertices[y].edge); //TODO: petit débat
        }
        printf("\n");
    }
}
