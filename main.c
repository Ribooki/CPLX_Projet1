/*
#include "maximum.h"

int main()
{
  //graphe_l *g = readFile("files/1-FullIns_3");
  graphe_l *g = readFile("test.txt");
  //display_graphe(*g);

  printf("Existe-t-il un sous-graphe désert de taille 10 avec la méthode exacte ? %d\n", existe_desert_maximum_exacte(*g, 2));
  // printf("Existe-t-il un sous-graphe désert de taille 10 avec la méthode incomplète ? %d\n", existe_desert_maximum_incomplet(*g, 3));

  freeTheG(g);
  return 0;
}*/
//#include "desertToSAT.h"
#include "utils.h"
#include "SATToDesert.h"


int main(){

    graphe_l *g = readFile("test.txt");
    display_graphe(*g);
    Sat* sat = toSAT(*g);

    //Sat *sat = readSatFile("SAT/dubois20.cnf");

    displaySat(sat);

    satToFile(sat, "testPrintSat.cnf");

    return 0;
}
