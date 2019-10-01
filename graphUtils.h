#define n_max 1000

typedef int sommet;

typedef struct chainon {
	sommet st;
	struct chainon *suivant;
} Couple;

typedef Couple *liste;

typedef struct {
	liste a[n_max];
	int n;
} graphe_l;
