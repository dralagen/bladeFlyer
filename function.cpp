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

list<list<int>> permutbourrin(int** mat, list<int> l) { // Cette méthode ci nous renvoi toutes les permutations
	// Une amélioration pourrait ne pas renvoyer les "reflets", soit diviser par deux le nb de permutations
	static list<list<int>> res; //La liste de toutes les permutations
	list<int> listVide;
	int fin = l.size(); //Pour ne pas le calculer à chaque fois
	for (int i = 1; i < fin; ++i) {
		permutbourrin_aux(i, ) //Fct aux, c'est la que je galère
		// Une permutation de ( x , ... ) c'est une permut de ( ... ) avec x devant etc.
		// http://www.developpez.net/forums/d504828/autres-langages/algorithmes/mathematiques/algorithme-permutation/
		// Réponse #5
	}
	
	for (list<int>::iterator it = res.begin(); it != res.end()){
		// Pour rajouter les 0 (l'entrepôt) de chaque côté des permutations
		*it.push_front(0);
		*it.push_back(0);
	}
	return res;
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
