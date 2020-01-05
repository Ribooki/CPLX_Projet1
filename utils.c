#include "utils.h"

graphe_l* readFile(char* fileAbsolutePath)
{
    graphe_l * graph = malloc(sizeof(graphe_l));
    int x = 0, y = 0;
    FILE *file = NULL;
    file = fopen(fileAbsolutePath, "r");

    if(file == NULL){
        fprintf(stderr, "Fichier non ouvert \n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", &graph->n, &graph->e);

    for(int s = 0 ; s < graph->n ; s++)
      graph->a[s] = NULL;
    while(fscanf(file, "%d %d", &x, &y) == 2){
        addVertex(&(graph->a[x]), y);
        addVertex(&(graph->a[y]), x);
    }

    fclose(file);
    return graph;
}

Sat* readSatFile(char* fileAbsolutePath)
{
  Sat * graph = malloc(sizeof(Sat));
  int x = 0, y = 0;
  FILE *file = NULL;
  file = fopen(fileAbsolutePath, "r");

  if(file == NULL){
      fprintf(stderr, "Fichier non ouvert \n");
      exit(EXIT_FAILURE);
  }

  Sat *s = createSat();
  int n, p;
  int vTemp;
  while(fscanf(file, "p cnf %d %d", &n, &p) != 2); //passe les commentaires et arrive a la premiere ligne
  Clause *c = createClause();
  Vertex v = NULL;
  while(fscanf(file, "%d", vTemp) == 1){
    if(vTemp == 0){
      addClauseInSat(&s, &c);
      c = createClause();
    }else{
      if(vTemp < 0){
        createVertex(1, vTemp);
      }else{
        createVertex(0, vTemp);
      }
    }
    addVertexInClause(&c, v);
  }
  fclose(file);
  return graph;
}

void freeTheG(graphe_l *g)
{
  for(int i = 0 ; i < g->n ; i++)
    deleteList(&g->a[i]);

  free(g);
}

void deleteList(liste *l)
{
  liste tmp = *l;
  liste next = NULL;

  while(tmp != NULL)
  {
    next = tmp->suivant;
    free(tmp);
    tmp = next;
  }

  l = NULL;
}
