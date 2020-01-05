#include "desertToSAT.h"

Sat* toSAT(graphe_l g){
    Sat* tmpSAT = createSat();
    
    for(int i=0 ; i<g.n ; i++){
      liste tmp = g.a[i];
      Clause* cl = createClause();
      Vertex* vt = createVertex(0, i+1);
      addVertexInClause(tmpSAT, cl, vt);
      while(tmp != NULL){
          vt = createVertex(1, tmp->st+1);
          addVertexInClause(tmpSAT, cl, vt);
          tmp = tmp->suivant;
      }
      addClauseInSat(tmpSAT, cl);
    }

    return tmpSAT;
}
