#include "utils.h"

int main()
{
  graphe_l *g = readFile("files/1-FullIns_3");

  ens_de_sommets head = NULL;
  ens_de_sommets second = NULL;

  head = malloc(sizeof(Couple));
  second = malloc(sizeof(Couple));

  head->st = 1;
  head->suivant = second;
  second->st = 2;
  second->suivant = NULL;

  printf("ens_de_sommets désert ? %d\n", isDesert(*g, &head));
  free(head);
  free(second);
  freeTheG(g);
  return 0;
}
