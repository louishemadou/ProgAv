#include <iostream>
using namespace std;
#include "levenshtein.h"
#include "damerau.h"

int main(){
	clock_t t0;
	clock_t t1;
	string mot1 ("tintin");
	string mot2 ("milou");
	cout << "mot1 = " << mot1 << endl;
	cout << "mot2 = " << mot2 << endl;
	cout << "Distances de Levenshtein : \n" << endl;
	t0 = clock();
	cout << "distance sans mémoïsation = " << levenshtein_sans_memo(mot1, mot2);
	t1 = clock();
	cout << " calculée en " << float((t1-t0)/float(CLOCKS_PER_SEC)) << " secondes" <<endl;
	t0 = clock();
	cout << "distance avec mémoïsation = " << levenshtein_avec_memo(mot1, mot2);
	t1 = clock();
	cout << " calculée en " << float((t1-t0)/float(CLOCKS_PER_SEC)) << " secondes" <<endl;
	t0 = clock();
	cout << "distance avec calcul itératif = " << levenshtein_iter(mot1, mot2);
	t1 = clock();
	cout << " calculée en " << float((t1-t0)/float(CLOCKS_PER_SEC)) << " secondes" <<endl;
	t0 = clock();
	cout << "distance avec algorithme linéaire en espace = " << levenshtein_lin(mot1, mot2);
	t1 = clock();
	cout << " calculée en " << float((t1-t0)/float(CLOCKS_PER_SEC)) << " secondes \n" <<endl;
	/*	
	cout << "Affichage des transformations" << endl;
	levenshtein_iter_affiche(mot1, mot2);	
	cout << "Fin de la transformation" << endl;
	*/
	cout << "Distances de Damerau-Levenshtein : \n" << endl;
	t0 = clock();
	cout << "distance sans mémoïsation = " << damerau_sans_memo(mot1, mot2);
	t1 = clock();
	cout << " calculée en " << float((t1-t0)/float(CLOCKS_PER_SEC)) << " secondes" <<endl;
	t0 = clock();
	cout << "distance avec mémoïsation = " << damerau_avec_memo(mot1, mot2);
	t1 = clock();
	cout << " calculée en " << float((t1-t0)/float(CLOCKS_PER_SEC)) << " secondes" <<endl;
	t0 = clock();
	cout << "distance avec calcul itératif = " << damerau_iter(mot1, mot2);
	t1 = clock();
	cout << " calculée en " << float((t1-t0)/float(CLOCKS_PER_SEC)) << " secondes" <<endl;

	return 0;
}
