#include <list>

std::list<std::list<int> > enumCli(int* demCli, int nbCli, int cap);

void enumCli_aux(std::list<std::list<int> > &l, int* demCli, int nbCli, int totalCap, int cli, int cap, std::list<int> lastList);

list<list<int>> permutdouble(list<list<int>> ec);
void permutbourrin(list<list<int>> res, list<int> new, list<list<int>> old);

void print_list(const std::list<int> &l);
void print_dlist(const std::list< std::list<int> > &l);

