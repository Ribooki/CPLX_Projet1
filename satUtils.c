#include "satUtils.h"

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
Sat* createSat(){
    Sat *s = malloc(sizeof(Sat));
    s->clausesCount = 0;
    s->differentsVerticesCount = 0;
    s->clauses = malloc(sizeof(Clause));
    return s;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
Clause* createClause(){
    Clause *c = malloc(sizeof(Clause));
    c->verticesCount = 0;
    c->vertices = malloc(sizeof(Vertex));
    return c;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
Vertex* createVertex(int isNeg, edge edg){
    if(isNeg > 1 || isNeg < 0) return NULL;
    Vertex *v = malloc(sizeof(Vertex));
    v->isNegative = isNeg;
    v->edg = edg;
    return v;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
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
    deleteClause(c);
    return 1;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
int addVertexInClause(Sat *s, Clause *c, Vertex *v){
    if(c == NULL || v == NULL) return 0;

    c->verticesCount += 1;
    //if(c->verticesCount > 3) return 0; //Pour 3 sats
    c->vertices = realloc(c->vertices, sizeof(Vertex) * c->verticesCount);
    c->vertices[c->verticesCount-1] = *v;
    if(s->differentsVerticesCount < v->edg){
        s->differentsVerticesCount = v->edg;
    }
    deleteVertex(v);
    return 1;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void displayVertex(Vertex *v, int isFirst){
    if(isFirst == 0)
        printf(" v ");
    if(v->isNegative == 0){
        printf("%d", v->edg);
    }
    else{
        printf("-%d", v->edg);
    }
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void displaySat(Sat* s){
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

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void satToFile(Sat* s, char* path){
   FILE *file = fopen(path, "w+");

   fprintf(file, "p cnf %d %d\n", s->differentsVerticesCount, s->clausesCount);

   for(int i=0 ; i<s->clausesCount ; i++){
       for(int j=0 ; j<s->clauses[i].verticesCount ; j++){
           if(s->clauses[i].vertices[j].isNegative == 1)
               fprintf(file, "-%d ", s->clauses[i].vertices[j].edg);
           else
               fprintf(file, "%d ", s->clauses[i].vertices[j].edg);
       }
       fprintf(file, "0\n");
   }

   fclose(file);

   printf("SAT printed in %s\n", path);
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void miniSolve(char* cnf, char* out){
    pid_t pid;
    pid = fork();
    if (pid == 0){
        execlp("minisat", "minisat", cnf, out, NULL);
    }
    else{
        wait(0);
    }

    printf("%s résolu et solution écrite dans %s\n", cnf, out);
}

void deleteVertex(Vertex *v)
{
    free(v);
}

void deleteClause(Clause *c)
{
    deleteVertex(c->vertices);
    free(c);
}

void deleteSat(Sat *s)
{
    deleteClause(s->clauses);
    free(s);
}
