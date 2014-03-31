#include <list>

std::list<std::list<int> > enumCli(int* demCli, int nbCli, int cap);

void enumCli_aux(std::list<std::list<int> > &l, int* demCli, int nbCli, int totalCap, int cli, int cap, std::list<int> lastList);

std::list<std::list<int>> permutdouble(std::list<std::list<int>> ec);
void permutbourrin(std::list<std::list<int>> res, std::list<int> new, std::list<std::list<int>> old);

void print_list(const std::list<int> &l);
void print_dlist(const std::list< std::list<int> > &l);

