#include "maximum.h"

/**
 * spec: Compte le nombre de sommets dans l'ensemble donné
 * Avec e l'ensemble de sommets
 * Retourne le nombre de sommets
 * auteur:
 * verificateur:
 * complexité: O(n)
 */
int count_vertex(ens_de_sommets e)
{
    int count = 0;
    liste tmp = e;
    while(tmp != NULL) {
        count++;
        tmp = tmp->suivant;
    }
    return count;
}

/**
 * spec: Vérifie si il existe un desert maximum pour un k donné
 * Avec g un graph et k le nombre de sommets minimum devant composer le désert
 * Parcourt le graph en essayant pour chaque sommet son graph maximal jusqu'à arriver à un desert dont le nombre de sommets > k sinon s'arrete à la fin du parcourt
 * Retourne 1 si il existe, 0 sinon
 * auteur: Alexandre Tosi
 * verificateur: Romain Allemand
 * complexité: O(n^3)
 */
int existe_desert_maximum_exacte(graphe_l g, int k)
{
    ens_de_sommets e = NULL;
    for(sommet x = 0 ; x < g.n ; x++) {
        e = calcul_graphe_maximal(g, x);
        if(count_vertex(e) >= k)
        {
            // display_ens_de_sommets(e);
            deleteList(&e);
            return 1;
        }
        deleteList(&e);
    }
    deleteList(&e);
    return 0;
}

/**
 * spec: Vérifie si il existe un desert maximum pour un k donné
 * Avec g un graph et k le nombre de sommets minimum devant composer le désert
 * Parcourt le graph en essayant pour 1 sommet sur 2 son graph maximal jusqu'à arriver à un desert dont le nombre de sommets > k sinon s'arrete à la fin du parcourt
 * Retourne 1 si il existe, 0 sinon
 * auteur: Alexandre Tosi
 * verificateur: Romain Allemand
 * complexité: O(n/2*(n^2))
 */
int existe_desert_maximum_incomplet(graphe_l g, int k)
{
    ens_de_sommets e = NULL;
    for(sommet x = 0 ; x < g.n ; x += 2) {
        e = calcul_graphe_maximal(g, x);
        if(count_vertex(e) >= k)
        {
            //display_ens_de_sommets(e);
            deleteList(&e);
            return 1;
        }
        deleteList(&e);
    }
    deleteList(&e);
    return 0;
}
