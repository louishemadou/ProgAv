#include "utility.h"
#include "town.h"
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

void repetition_nom(const vector<Town> & T){
	map<string, int> nb_occurence_noms;
	for(auto it = T.begin(); it!=T.end(); it++)
		nb_occurence_noms[it->name()]++;
	map<int, int> M;
	for(auto it = nb_occurence_noms.begin(); it != nb_occurence_noms.end(); it++)
		M[it->second]++;
	cout << "nb de noms de villes utilisés : par y villes exactement" << endl;
	for(auto it = M.begin(); it != M.end(); it++)
		cout << it->first<< " : " << it->second << endl; 
}

bool operator<(const Point2D & p1, const Point2D & p2){
	if(p1.x != p2.x)
		return p1.x<p2.x;
	else
		return p1.y<p2.y;
}


void repetition_coord(const vector<Town> & T){
	map<Point2D, int> nb_occurence_coord;
	for(vector<Town>::const_iterator it = T.begin(); it!=T.end(); it++)
		nb_occurence_coord[it->point()]++;
	map<int, int> M;
	for(auto it = nb_occurence_coord.begin(); it!=nb_occurence_coord.end(); it++)
		M[it->second]++;
	cout << "nb de coodonnées : partagées par y villes exactement" << endl;
	for(auto it = M.begin(); it != M.end(); it++)
		cout << it->first<< " : " << it->second << endl; 
}

bool operator<(const Town & town1, const Town & town2){
	if(town1.name() != town2.name())
		return town1.name() < town2.name();
	else
		return town1.point() < town2.point();
}

set<Town> N_inter_C(const vector<Town> & T){
	map<string, int> nb_occurence_noms;
	map<string, Town> nom_deja_traite;
	map<Point2D, int> nb_occurence_coord;
	map<Point2D, Town> coord_deja_traite;
	set<Town> N;
	set<Town> C;
	for(auto it = T.begin(); it!=T.end(); it++){
		nb_occurence_noms[it->name()]++;
		nb_occurence_coord[it->point()]++;

		if(nb_occurence_noms[it->name()] == 1)
			nom_deja_traite[it->name()] = *it;
		else if(nb_occurence_noms[it->name()] == 2){
			N.insert(*it);
			N.insert(nom_deja_traite[it->name()]);
		}
		else
			N.insert(*it);

		if(nb_occurence_coord[it->point()] == 1)
			coord_deja_traite[it->point()] = *it;
		else if(nb_occurence_coord[it->point()] == 2){
			C.insert(*it);
			C.insert(coord_deja_traite[it->point()]);
		}
		else
			C.insert(*it);
	}
	set<Town> N_inter_C;
	set_intersection(N.begin(), N.end(), C.begin(), C.end(), 
			inserter(N_inter_C, N_inter_C.begin()));
	return N_inter_C;
}

void intersection(const vector<Town> & T){
	set<Town> NC = N_inter_C(T);
	cout << "Il y a " << NC.size() << " élements dans l'intersection" << endl;
}


void villes_proches(const vector<Town> & T){
	// Complexité du programme en O(cardinal(N_inter_C)**2), bien plus efficace que
	// l'algorithme naïf
	set<Town> NC = N_inter_C(T);
	set<Town> sortie;
	for(set<Town>::const_iterator v1 = NC.begin(); v1 != NC.end(); v1++){
		for(set<Town>::const_iterator v4 = NC.begin(); v4 != NC.end(); v4++){
			if(v1->name() != v4->name() || v1->x() != v4->x() || v1->y() != v4->y()){

				vector<Town> NC_vector(NC.begin(), NC.end());

				vector<Town> 	n1 = towns_with_name(NC_vector, v1->name()),
						n4 = towns_with_name(NC_vector, v4->name()),
						c1 = towns_with_x_y(NC_vector, v1->x(), v1->y()),
						c4 = towns_with_x_y(NC_vector, v4->x(), v4->y());

				set<Town> 	N1(n1.begin(), n1.end()),
						N4(n4.begin(), n4.end()),
						C1(c1.begin(), c1.end()),
						C4(c4.begin(), c4.end());
				
				set<Town> N1C4; // v3 possiblement dans cet ensemble
				set_intersection(N1.begin(), N1.end(), C4.begin(), C4.end(),
					       	inserter(N1C4, N1C4.begin()));
				set<Town> N4C1; // v1 possiblemnt dans cet ensemble
				set_intersection(N4.begin(), N4.end(), C1.begin(), C1.end(),
					       	inserter(N4C1, N4C1.begin()));

				if(N1C4.size() != 0 && N4C1.size() != 0)
					sortie.insert(*v1);
			}
		}
	}
	cout << "On peut se tromper en entendant parler de " << sortie.size() << " villes." << endl;
}
