#include "satUtils.h"

/**
 * spec: créé et initialise la structure Sat.
 * renvoie le pointeur de la structure.
 * auteur: Thomas Rieffel
 * verificateur: ??
 * complexité: O(1)
 */
Sat* createSat(){
    Sat *s = malloc(sizeof(Sat));
    s->clausesCount = 0;
    s->differentsVerticesCount = 0;
    s->clauses = malloc(sizeof(Clause));
    return s;
}

/**
 * spec: créé et initialise une clause.
 * Renvoie le pointeur de la clause.
 * auteur: Thomas Rieffel
 * verificateur: ??
 * complexité: O(1)
 */
Clause* createClause(){
    Clause *c = malloc(sizeof(Clause));
    c->verticesCount = 0;
    c->vertices = malloc(sizeof(Vertex));
    return c;
}

/**
 * spec: créé et initialise un vertex.
 * Renvoie le pointeur du vertex.
 * auteur: Thomas Rieffel
 * verificateur: ??
 * complexité: O(1)
 */
Vertex* createVertex(int isNeg, edge edg){
    if(isNeg > 1 || isNeg < 0) return NULL;
    Vertex *v = malloc(sizeof(Vertex));
    v->isNegative = isNeg;
    v->edg = edg;
    return v;
}

/**
 * spec: Ajoute une clause dans une structure sat.
 * Avec s un pointeur Sat et c une Clause
 * auteur: Thomas Rieffel 
 * verificateur: ??
 * complexité: O(1)
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
 * spec: Ajoute un sommet dans une clause sat.
 * Avec s un pointeur Sat, c une Clause et v un sommet.
 * auteur: Thomas Rieffel
 * verificateur: ??
 * complexité: O(1)
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
 * spec: Affiche le sommet donné.
 * Avec v un sommet et isFirst qui est à 1 si le sommet est le premier de la clause, 0 sinon.
 * auteur: ??
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
 * spec: Affiche le probleme Sat dans son ensemble.
 * Avec s un Sat.
 * parcourt chaque clause et les affiches
 * auteur: Thomas Rieffel
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
 * spec: transfère une structure Sat vers un fichier cnf.
 * parcourt le Sat et pour chaque clause créé une ligne et y met les littérraux
 * auteur: ??
 * verificateur: 
 * complexité: O(n)
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
 * spec: Appel le solveur mini-sat.
 * auteur: Alexandre Tosi
 * verificateur: Thomas Rieffel
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

//supprime la structure d'un vertex
void deleteVertex(Vertex *v)
{
    free(v);
}

//supprime la structure d'une clause et tous ses litérraux
void deleteClause(Clause *c)
{
    deleteVertex(c->vertices);
    free(c);
}

//supprime la structure sat et toutes ses clauses 
void deleteSat(Sat *s)
{
    deleteClause(s->clauses);
    free(s);
}
