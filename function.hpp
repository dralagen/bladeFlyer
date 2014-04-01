#include <list>

typedef struct{
  std::list<int> perm;
  int lon;
} regroupement;

std::list<std::list<int> > enumCli(int* demCli, int nbCli, int cap);

void enumCli_aux(std::list<std::list<int> > &l, int* demCli, int nbCli, int totalCap, int cli, int cap, std::list<int> lastList);

regroupement permutdouble(std::list<std::list<int>> ec, int** mat);
void permutbourrin(regroupement &res, std::list<int> nouv, std::list<int> old, int** mat);

int CalLong(std::list<int> &l, int** mat);

void print_list(const std::list<int> &l);
void print_dlist(const std::list< std::list<int> > &l);

