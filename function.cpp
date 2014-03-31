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
	for (list<list<int>>::iterator it = ec.begin(); it != ec.end(); it++){
		list<int> rien;
		permutbourrin(res, rien, *it);
	}
	return res;
}

void permutbourrin(list<list<int>> res, list<int> nouv, list<int> old){
	if (old.size() == 0){
		print_list(nouv);
		res.push_back(nouv);
	}
	else{
		for (list<int>::iterator it = old.begin(); it != old.end(); it++){
			nouv.push_back(*it);
			list<int> tmp;
			tmp.assign(old.begin(), old.end());
			cout << tmp.size() << ' ';
			tmp.erase(it);
			cout << tmp.size() << endl;
			permutbourrin(res, nouv, tmp);
		}
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
