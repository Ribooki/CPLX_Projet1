#include "desertToSAT.h"

/**
 * spec: Transforme des données d'un problème de graphe désert en données de problème SAT
 * g est le graphe, k le nombre minimum de sommets du sous-graphe désert souhaité
 * auteur: Romain Allemand
 * verificateur: Alexandre Tosi
 * complexité: O(2^n + m)
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
 * spec: Génère toutes les combinaisons possibles où le nombre de littéraux positifs est inférieur à k.
 * sat est le programme SAT généré à partir du problème de sous-graphe désert, tab[] est un tableau de booléens qui décrit si oui ou non un littéral est positif, k est le k du problème de sous-graphe désert, i est l'indice auquel en est la génération de la combinaison
 * auteur: Romain ALLEMAND
 * verificateur: Thomas Reiffel
 * complexité: O(2^n)
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
 * spec: Ajoute une clause dans le problème SAT à partir d'un tableau
 * sat est le problème sat en cours de génération, tab est un tableau de booléens décrivant si oui ou non un littéral est positif dans la clause
 * auteur: Romain ALLEMAND
 * verificateur: Alexandre Tosi
 * complexité: O(n)
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
 * spec: Résout un problème de graphe en le transformant en problème SAT
 * g le graphe et k la taille minimale du sous-graphe désert voulu
 * auteur: Romain Allemand
 * verificateur: Thomas Reiffel
 */
void solveGrapheInSAT(graphe_l g, int k){
    Sat* sat = toSAT(g, k);
    Vertex *vt = NULL;
    Clause *newCl = NULL;
    displaySat(sat);
    satToFile(sat, "tmpSAT.cnf");
    miniSolve("tmpSAT.cnf", "tmpOUT.txt");
    
    while(isSatisfiable("tmpOUT.txt") == 1 && getNbVertexInSol("tmpOUT.txt") < k){
       FILE* file = fopen("tmpOUT.txt", "r");
       char buff[255];
       int tmp=0;
       newCl = createClause();
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
 * spec: Retourne le nombre de littéraux positifs dans une solution proposée par miniSAT
 * out est le path du fichier solution généré par miniSAT
 * auteur: Romain Allemand
 * verificateur: Alexandre Tosi
 * complexité: O(n)
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
 * spec: Retourne si oui ou non la solution proposée par miniSAT est une solution SATISFIABLE
 * out est le path du fichier solution généré par miniSAT
 * auteur: Romain Allemand
 * verificateur: Thomas Reiffel
 * complexité: O(1)
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
