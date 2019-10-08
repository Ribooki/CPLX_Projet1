#include "utils.h"

int main()
{
  graphe_l *g = readFile("files/1-FullIns_3");

  ens_de_sommets head = NULL;
  ens_de_sommets second = NULL;
  ens_de_sommets third = NULL;

  head = malloc(sizeof(Couple));
  second = malloc(sizeof(Couple));
  third = malloc(sizeof(Couple));

  head->st = 0;
  head->suivant = second;
  second->st = 16;
  second->suivant = third;
  third->st = 2;
  third->suivant = NULL;

  printf("ens_de_sommets désert ? %s\n", (isDesert(*g, &head) ? "oui" : "nop"));
  free(head);
  free(second);
  freeTheG(g);
  return 0;
}
