#include "maximum.h"

int main()
{
  graphe_l *g = readFile("files/1-FullIns_3");
  // graphe_l *g = readFile("test.txt");

  // ens_de_sommets head = NULL;
  printf("Existe-t-il un sous-graphe désert de taille 5 ? %d\n", existe_desert_maximum(*g, 15));
  // head = calcul_graphe_maximal(*g, 0);
  // printf("maximal ? %s\n",isMaximal(*g, &head) ? "Oui" : "Non");
  // display_ens_de_sommets(head);
  // deleteList(&head);
  //
  // head = calcul_graphe_maximal(*g, 1);
  // printf("maximal ? %s\n",isMaximal(*g, &head) ? "Oui" : "Non");
  // display_ens_de_sommets(head);
  //
  // deleteList(&head);
  // freeTheG(g);
  return 0;
}
