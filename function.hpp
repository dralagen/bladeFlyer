#include <list>

typedef struct{
  std::list<int> perm;
  int lon;
} regroupement;

/* Structure contenant les données du problème */

typedef struct {
	int nblieux; /* Nombre de lieux (incluant le dépôt) */
	int capacite; /* Capacité du véhicule de livraison */
	int *demande; /* Demande de chaque lieu (la case 0 est inutilisée car le dépôt n'a aucune demande à voir satisfaire) */
	int **C; /* distancier (les lignes et colonnes 0 correspondent au dépôt) */
} donnees;


std::list<std::list<int> > enumCli(int* demCli, int nbCli, int cap);

void enumCli_aux(std::list<std::list<int> > &l, int* demCli, int nbCli, int totalCap, int cli, int cap, std::list<int> lastList);

std::list<regroupement> permutdouble(std::list<std::list<int>> ec, const int** mat);
void permutbourrin(regroupement &res, std::list<int> nouv, std::list<int> old, const int** mat);

int CalLong(const std::list<int> &l, const int** mat);

void resolution(const std::list<regroupement> &reg, const donnees &d);

void print_list(const std::list<int> &l);
void print_list(const std::list<regroupement> &l);
void print_dlist(const std::list< std::list<int> > &l);

