#include "desertToSAT.h"

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
Sat* toSAT(graphe_l g, int k){
    Sat* tmpSAT = createSat();
    liste tmp = NULL;
    Clause *cl = NULL;
    Vertex *vt1 = NULL;
    Vertex *vt2 = NULL;

    for(int i=0 ; i<g.n ; i++){
      tmp = g.a[i];
      while(tmp != NULL){
          cl = createClause();
          vt1 = createVertex(1, i+1);
          vt2 = createVertex(1, tmp->st+1);
          addVertexInClause(tmpSAT, cl, vt1);
          addVertexInClause(tmpSAT, cl, vt2);
          addClauseInSat(tmpSAT, cl);
          tmp = tmp->suivant;
      }
    }
    printf("g.n = %d\n", g.n);
    int tab[g.n];
    for(int i=0 ; i<g.n ; i++)
        tab[i]=0;
    generateAllNotPossible(tmpSAT, tab, k, 0);

    return tmpSAT;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void generateAllNotPossible(Sat* sat, int tab[], int k, int i){
    int nbPos = 0;
    for(int j=0 ; j<sat->differentsVerticesCount ; j++){
        if(tab[j] == 1)
            nbPos+=1;
    }

    if(i == sat->differentsVerticesCount){
        if(nbPos < k){
            tabToClauseInSAT(sat, tab);
            /*for(int j=0 ; j<sat->differentsVerticesCount ; j++)
                printf("%d ", tab[j]);
            printf("\n");*/
        }
        return;
    }
    tab[i]=0;
    generateAllNotPossible(sat, tab, k, i+1);

    tab[i]=1;
    generateAllNotPossible(sat, tab, k, i+1);
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void tabToClauseInSAT(Sat* sat, int tab[]){
    Clause* cl = createClause();
    Vertex *vt = NULL;
    for(int j=0 ; j<sat->differentsVerticesCount ; j++){
        if(tab[j] == 1){
            vt = createVertex(1, j+1);
            addVertexInClause(sat, cl, vt);
        }
        else{
            vt = createVertex(0, j+1);
            addVertexInClause(sat, cl, vt);
        }
    }
    addClauseInSat(sat, cl);
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
void solveGrapheInSAT(graphe_l g, int k){
    Sat* sat = toSAT(g, k);
    Vertex *vt = NULL;
    displaySat(sat);
    satToFile(sat, "tmpSAT.cnf");
    miniSolve("tmpSAT.cnf", "tmpOUT.txt");
    while(isSatisfiable("tmpOUT.txt") == 1 && getNbVertexInSol("tmpOUT.txt") < k){
       FILE* file = fopen("tmpOUT.txt", "r");
       char buff[255];
       int tmp=0;
       Clause* newCl = createClause();
       fscanf(file, "%s", buff);
       while(fscanf(file, "%d", &tmp) == 1){
           if(tmp > 0){
               vt = createVertex(1, tmp);
               addVertexInClause(sat, newCl, vt);
           }
           else if(tmp < 0){
               vt = createVertex(0, -tmp);
               addVertexInClause(sat, newCl, vt);
           }
       }
       fclose(file);
       addClauseInSat(sat, newCl);
       //displaySat(sat);
       satToFile(sat, "tmpSAT.cnf");
       miniSolve("tmpSAT.cnf", "tmpOUT.txt");
    }

    if(isSatisfiable("tmpOUT.txt") == 1 && getNbVertexInSol("tmpOUT.txt") >= k)
        printf("Il existe une solution pour ce problème.\n");
    else
        printf("Il n'existe pas de solution pour ce problème.\n");
    //remove("tmpSAT.cnf");
    //remove("tmpOUT.txt");
    deleteSat(sat);
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
int getNbVertexInSol(char* out){
    FILE* file = fopen(out, "r");
    int nbInSol = 0;
    char buff[255];
    int tmp=0;
    fscanf(file, "%s", buff);
    while(fscanf(file, "%d", &tmp) == 1){
        if(tmp > 0)
            nbInSol+=1;
    }
    fclose(file);
    printf("%d vertex positifs dans la solution.\n", nbInSol);
    return nbInSol;
}

/**
 * spec: 
 * auteur: 
 * verificateur: 
 * complexité: 
 */
int isSatisfiable(char* out){
    FILE* file = fopen(out, "r");
    char buff[255];

    fscanf(file, "%s", buff);
    if(strcmp(buff, "SAT") == 0){
        fclose(file);
        return 1;
    }
    else{
        fclose(file);
        return 0;
    }
}
