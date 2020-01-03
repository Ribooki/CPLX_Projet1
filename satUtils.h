#include <stdio.h>
#include <stdlib.h>

typedef int sommet;

typedef struct {
    struct clause *clauses;
    int clausesCount;
} sat;

typedef struct {
    struct vertex *vertices;
} clause;

typedef struct{
    int sommet *sommets;
    int isNegative;
} vertex;
