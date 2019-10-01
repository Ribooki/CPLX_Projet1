#define n_max

typedef int sommet;

typedef struct chainon {sommet st;
			struct chainon *suivant;
} Couple;

typedef Couple *liste;

typedef struct { liste a[n_max];
		 int n;
} graph_l;
