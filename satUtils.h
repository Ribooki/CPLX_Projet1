#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef int edge;

typedef struct{
    edge edg;
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

void miniSolve(char* cnf, char* out);

void deleteVertex(Vertex *v);   //supprime un vertex

void deleteClause(Clause *c);   //supprime une clause

void deleteSat(Sat *s);         //supprime sat
