#include "eleve.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void affiche_prom(vector<Eleve> prom){
	int len = prom.size();
	for(int i=0;i<len;i++){
		cout << prom[i].get_nom() << ", " << prom[i].get_note() << endl;
	}
}

const int N = 20; // Nombre d'élèves
int main(){
	srand(time(NULL)); // Initialisation des nombres pseudo-aléatoires
	vector<Eleve> prom;
	for(int i=0;i<N;i++){ // Création de la "promotion"
		Eleve E;
		prom.push_back(E);
	}
	cout << "Eleves generes:" << endl;
	affiche_prom(prom);

	int compteur1 = 0;
	sort(prom.begin(),prom.end(),CompareEleve(compteur1));
	cout << "Eleves tries par nom croissant" << endl;
	affiche_prom(prom);
	cout << "Nombre de comparaisons effectuees: " << compteur1 << endl;

	int compteur2 = 0;
	sort(prom.begin(),prom.end(),CompareNote(compteur2));
	cout << "Eleves tries par note croissante" << endl;
	affiche_prom(prom);
	cout << "Nombre de comparaisons effectuees: " << compteur2 << endl;
	return 0;
}
