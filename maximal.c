#include "maximal.h"

/**
 * spec: Génère le graph désert maximal pour un sommet donné
 * Avec un graph g et un sommet x
 * On parcourt tous les sommets du graph en vérifiant qu'ils ne soient pas dans la liste d'adjacence qui se met a jour en incluant les voisins du nouveau sommet
 * ajouté dans l'ensemble du graph desert
 * Retourne l'ensemble de donné généré
 * auteur: Alexandre Tosi
 * verificateur: Thomas Rieffel
 * complexité: O(n^2)
 */
ens_de_sommets calcul_graphe_maximal(graphe_l g, sommet x)
{
    ens_de_sommets e = NULL;
    ens_de_sommets checkVertex = NULL;
    addVertex(&e, x);   //on ajoute le premier sommet
    successeurs(g, x, &checkVertex);

    /* Pour chaque sommet, s'il ne se trouve pas parmi les successeurs des
    ** sommets, on l'ajoute dans le sous-graphe, et on met à jour la liste de
    ** tous les successeurs */
    for(int i = 0 ; i < g.n ; i++) {
        if(!contains(&checkVertex, i) && i != x) {
            addVertex(&e, i);
            successeurs(g, i, &checkVertex);
        }
    }

    deleteList(&checkVertex);
    return e;
}
