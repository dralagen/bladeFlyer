#include <list>

std::list<std::list<int> > enumCli(int* demCli, int nbCli, int cap);

void enumCli_aux(std::list<std::list<int> > &l, int* demCli, int nbCli, int totalCap, int cli, int cap, std::list<int> lastList);

std::list<std::list<int>> permutdouble(std::list<std::list<int>> ec);
void permutbourrin(std::list<std::list<int>> &res, std::list<int> nouv, std::list<int> old);

int long(std::list<int> &l, int** mat);

void print_list(const std::list<int> &l);
void print_dlist(const std::list< std::list<int> > &l);

