#include "maximal.h"

int main()
{
  graphe_l *g = readFile("files/1-FullIns_3");
  // graphe_l *g = readFile("test.txt");

  ens_de_sommets head = NULL;
  addVertex(&head, 0);
  addVertex(&head, 1);
  addVertex(&head, 2);

  display_graphe(*g);
  // calcul_graphe_maximal(g, 0);

  free(head->suivant);
  free(head);
  freeTheG(g);
  return 0;
}
