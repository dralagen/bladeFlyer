#include "function.hpp"
#include <iostream>

using namespace std;

list<list<int>> enumCli(int* demCli, int nbCli, int cap) {
	static list<list<int> > l;
	list<int> listVide;
	for (int i = 1; i < nbCli; ++i) {
		enumCli_aux(l, demCli, nbCli, cap, i, 0, listVide);
 	}
	return l;
}

void enumCli_aux(list<list<int> > &l, int* demCli, int nbCli, int totalCap, int cli, int cap, list<int> lastList) {
 	if ( cli < nbCli) {
		if (demCli[cli]+cap <= totalCap) { //ajout cli list
			lastList.push_back(cli);
			l.push_back(lastList);
			for (int j = cli+1; j <= nbCli; ++j) {
				enumCli_aux(l, demCli, nbCli, totalCap, j, cap+demCli[cli], lastList);
			}
		}
	}
}

list<list<int>> permutdouble(list<list<int>> ec){
	list<list<int>> res;
	for (iterator it = ec.begin(); it != ec.end(); it++){
		permutbourrin(res, list<int> rien,*it)
	}
}

void permutbourrin(list<list<int>> res, list<int> new, list<int> old){
	if old.size() == 0;
		res.push_back(new);
	else for (iterator it = old.begin(); it != old.end(); it++){
		new.push_back(*it);
		list<int> tmp.assign(old.begin(), old.end());
		tmp.erase(it);
		permutbourrin(res, new, tmp);
	}
}

void print_list(const list<int> &l) {
 cout << "{ ";
 for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
	 cout << *it << " ";
 }
 cout << "} ";
}

void print_dlist(const std::list< std::list<int> > &l) {
 cout << "{ "<< endl;
 for (list< list< int > >::const_iterator it = l.begin(); it != l.end() ; ++it) {
	 cout << "{ ";
	 for (list<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2) {
			cout << *it2 << ' ' ;
		}
		cout << "} "<< endl;
	}

 cout << "} " << endl << endl;
}
