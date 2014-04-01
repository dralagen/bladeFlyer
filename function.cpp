#include "function.hpp"
#include <iostream>
#include <glpk.h>

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

list<regroupement> permutdouble(list<list<int>> ec, const int** mat){
	static list<regroupement> res;
	for (list<list<int>>::iterator it = ec.begin(); it != ec.end(); it++){
		regroupement tmp;
		tmp.perm = *it;
		tmp.lon = CalLong(*it, mat);
		list<int> rien;
		permutbourrin(tmp, rien, *it, mat);
		res.push_back(tmp);
	}
	return res;
}

void permutbourrin(regroupement &res, list<int> nouv, list<int> old, const int** mat){
	if (old.size() == 0){
		int tmp = CalLong(nouv, mat);
		if (tmp < res.lon) {
			res.lon = tmp;
			res.perm = nouv;
		}
	}
	else{
		list<int>::iterator it = old.begin();
		while ( it != old.end()){
			list<int> tmp1 (nouv);
			tmp1.push_back(*it);
			list<int> tmp2;
			list<int> tmp3;
			tmp2.assign(old.begin(), it);
			tmp3.assign(++it, old.end());
			tmp2.splice(tmp2.end(), tmp3);
			permutbourrin(res, tmp1, tmp2, mat);
		}
	}
}

int CalLong(const list<int> &l, const int** mat){
	list<int>::const_iterator it = l.begin();
	int res = mat[0][*it];
	for (it = ++it; it != l.end(); ++it){
		res += mat[*--it][*++it];
	}
	res += mat[*--it][0];
	return res;
}

void resolution(const list<regroupement> &reg, const donnees &d) {
	glp_prob *prob;
	double z;

	int *ia,*ja;
	double *ar;
	ia = new int[reg.size()*d.nblieux];
	ja = new int[reg.size()*d.nblieux];
	ar = new double[reg.size()*d.nblieux];

	cout << "/*" << endl;
	prob = glp_create_prob();
	glp_set_prob_name(prob, "Choix des regroupement");
	glp_set_obj_dir(prob, GLP_MIN);

	glp_add_rows(prob, d.nblieux-1);

	for (int i = 1; i < d.nblieux; ++i) { //bornes des contraintes (Visite 1 fois chaque client
		glp_set_row_name(prob,i,"visite du client "+i);
		glp_set_row_bnds(prob,i, GLP_FX, 1.0,1.0);
	}

	glp_add_cols(prob, reg.size());
	for (int i = 1; i <= reg.size(); ++i) {
		glp_set_col_kind(prob,i,GLP_BV); //type des varaibles binary
	}

	{
		int id = 1;
		for (list<regroupement>::const_iterator it = reg.begin(); it != reg.end(); ++it) {
			glp_set_obj_coef(prob, id, it->lon);
			++id;
		}
	}

	int nbCreux = 0; int numReg = 1;
	for (list<regroupement>::const_iterator it = reg.begin(); it != reg.end(); ++it) {
		for (list<int>::const_iterator itCli = it->perm.begin(); itCli != it->perm.end(); ++itCli) {
			++nbCreux;
			// ia [nbCreux] = num contrainte (num client)
			// ja [nbCreux] = num regroupement
			ia[nbCreux] = *itCli; ja[nbCreux] = numReg; ar[nbCreux] = 1.0;
		}
		++numReg;
	}
	glp_load_matrix(prob,nbCreux,ia,ja,ar);

	/* definision des contraintes */

	glp_simplex(prob,NULL); glp_intopt(prob,NULL); // resolution

	cout << "*/" <<endl<<endl;

	z = glp_mip_obj_val(prob);

	list<regroupement>::const_iterator it = reg.begin();
	for (int i = 0; i < reg.size(); ++i) {
		if (glp_mip_col_val(prob,i+1)) {
			cout << "x"<<i+1<<"=1 : ";
			print_list(it->perm);
			cout << endl;
		}
		++it;
	}

	glp_delete_prob(prob);

	cout << "z = " << (int)z << endl;

	delete[] ia;
	delete[] ja;
	delete[] ar;
}

void print_list(const list<int> &l) {
	cout << "{ ";
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
		cout << *it << " ";
	}
	cout << "} ";
}

void print_list(const list<regroupement> &l) {
	for (std::list<regroupement>::const_iterator it=l.begin(); it != l.end(); ++it) {
		cout << it->lon << " : ";
		print_list(it->perm);
		cout << endl;
	}
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

