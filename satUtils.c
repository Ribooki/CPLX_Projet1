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
    if(c == NULL || s == NULL) return 0;
    // Passage en 3-SAT ?
    /*
    if(c->verticesCount > 3){
        Clause *c1 = createClause();
        addVertexInClause()
        Clause *c2 = createClause();
        for(int i=0 ; i< ; i++){
            
        }
    }*/
    s->clausesCount = s->clausesCount + 1;
    s->clauses = realloc(s->clauses, sizeof(Clause) * s->clausesCount);
    s->clauses[s->clausesCount-1] = *c;
    return 1;
}

int addVertexInClause(Sat *s, Clause *c, Vertex *v){
    if(c == NULL || v == NULL) return 0;
    c->verticesCount += 1;
    //if(c->verticesCount > 3) return 0; //Pour 3 sats
    c->vertices = realloc(c->vertices, sizeof(Vertex) * c->verticesCount);
    c->vertices[c->verticesCount-1] = *v;
    if(s->differentsVerticesCount < v->edge){
        s->differentsVerticesCount = v->edge+1;
    }
    return 1;
}

void displayVertex(Vertex *v, int isFirst){
    if(isFirst == 0)
        printf(" v ");
    if(v->isNegative == 0){
        printf("%d", v->edge);
    }
    else{
        printf("-%d", v->edge);
    }
}

void displaySat(Sat *s){
    printf("clausesCount : %d\n", s->clausesCount);
    printf("nbVertex : %d\n", s->differentsVerticesCount);
    for(int i=0; i<s->clausesCount; i++){
        displayVertex(&s->clauses[i].vertices[0], 1);
        for(int y=1; y<s->clauses[i].verticesCount; y++){
            displayVertex(&s->clauses[i].vertices[y], 0);
        }
        printf("\n");
    }
}
