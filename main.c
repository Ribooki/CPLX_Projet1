#include "verification.h"

int main()
{
  // graphe_l *g = readFile("files/1-FullIns_3");
  graphe_l *g = readFile("test.txt");

  ens_de_sommets head = NULL;
  addVertex(&head, 0);
  addVertex(&head, 1);
  addVertex(&head, 2);

  printf("ens_de_sommets désert ? %s\n", (isDesert(*g, &head) ? "oui" : "nop"));
  printf("maximal ? %s\n", (isMaximal(*g, &head) ? "oui" : "nop"));
  free(head->suivant);
  free(head);
  freeTheG(g);
  return 0;
}
