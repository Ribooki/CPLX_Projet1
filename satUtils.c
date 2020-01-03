#include "satUtils.h"

void addClauseInSat(Sat s, Clause s){
    s.clausesCount = s.clausesCount + 1;
    s.clauses = realloc(s.clauses, s.clausesCount);
    
}

void addVertexInClause(Clause c, Vertex v){
    
}

