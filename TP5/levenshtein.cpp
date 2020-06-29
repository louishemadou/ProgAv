#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "levenshtein.h"

int min(int tableau[], int len){ // Retourne la valeur minimum d'une liste
	int min = tableau[0];
	for(int i=1; i<len; i++){
		if(tableau[i]<min)
			min = tableau[i];
	}
	return min;
}

int argmin(int tableau[], int len){ // Retourne l'indice de la valeur minimum d'une liste
	int mintab = min(tableau, len);
	int argmin;
	for(int i=0; i<len; i++){
		if(tableau[i] == mintab)
		argmin = i;	
	}
	return argmin;
}

int phi(string a, string b, int i, int j){ // Fonction de Bellman
	if(min(i,j) == 0)
		return max(i,j);
	else{
		int substitution = 1;
		if(a[i-1]==b[j-1])
			substitution = 0;
		int elements[3] = {phi(a,b,i-1,j)+1, phi(a,b,i,j-1)+1, phi(a,b,i-1,j-1) + substitution};
		return min(elements, 3);
	}
}

int levenshtein_sans_memo(string a, string b){
	return phi(a,b,a.length(),b.length());
}


int phi2(string a, string b, int i, int j, int* tableau){
	int m = b.length() + 1;
	if(tableau[i*m+j]!=-1) // On vérifie que le calcul n'a jamais été fait
		return tableau[i*m+j];
	if(min(i,j) == 0)
		return max(i,j);
	int substitution = 1;
	if(a[i-1] == b[j-1])
		substitution = 0;
	int elements[3] = {phi2(a,b,i-1,j,tableau)+1, phi2(a,b,i,j-1,tableau)+1, phi2(a,b,i-1,j-1,tableau)+substitution};
	tableau[i*m+j] = min(elements, 3);
	return tableau[i*m+j];
}

int levenshtein_avec_memo(string a, string b){
	int n = a.length() + 1;
	int m = b.length() + 1;
	int* tableau = new int[m*n];
	for(int k=0; k<m*n; k++){
		tableau[k] = -1;
	}
	int distance = phi2(a,b,n-1,m-1,tableau);
	delete [] tableau;
	return distance;
}

int levenshtein_iter(string a, string b){
	int n = a.length() + 1;
	int m = b.length() + 1;
	int* tableau = new int[n*m];
	for(int j=0; j<m; j++){ //         On construit les termes du tableau un à un, en se
		for(int i=0; i<n; i++){ // servant des termes déjà calculés.
			if(min(i,j) == 0)
				tableau[i*m+j] = max(i,j);
			else{	
				int substitution = 1;	
				if(a[i-1] == b[j-1])
					substitution = 0;
			int elements[3] = {tableau[(i-1)*m+j]+1, tableau[i*m+j-1]+1, tableau[(i-1)*m+j-1] + substitution};
			tableau[i*m+j] = min(elements, 3);
			}
		}
	}
	int distance = tableau[(m*n-1)];
	delete [] tableau;
	return distance;
}

void supprime_char(string &mot, int pos){ // Supprime le caractère de mot à la position pos
	mot.erase(pos, 1);
}

void ajoute_char(string &mot, int pos, char c){ // Ajoute le caractère c de mot à la position pos
	mot.insert(pos, 1, c);
}

void change_char(string &mot, int pos, char c){ // Change le caractère à la position pos
	mot[pos] = c;
}

void change_position(int action, int &i, int &j, string &a, string b){
	cout << i << " " << j << endl;
	cout << action << endl;
	if(action == 1){ // On a supprimé un caractère
		i++; // On met à jour la position des indices
		supprime_char(a,i);
	}
	if(action == 2){ // On a ajouté un caractère
		j++;
		ajoute_char(a,i,b[j]);
	}
	if(action == 3){ // On a changé un caractère
		i++;
		j++;
		change_char(a,i,b[j]);
	}
}

void levenshtein_iter_affiche(string a, string b){ // Fonction ne marchant pas
	int n = a.length() + 1;
	int m = b.length() + 1;
	int* tableau = new int[n*m];
	int* action = new int[(n-1)*(m-1)];
	// On créé récupère les actions effectuées sur le mot a pour calculer la distance
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			if(min(i,j) == 0)
				tableau[i*m+j] = max(i,j);
			else{	
				int substitution = 1;	
				if(a[i-1] == b[j-1])
					substitution = 0;
			int elements[3] = {tableau[(i-1)*m+j]+1, tableau[i*m+j-1]+1, tableau[(i-1)*m+j-1] + substitution};
			tableau[i*m+j] = min(elements, 3);
			action[(i-1)*(m-1)+(j-1)] = argmin(elements, 3) + 1;
			}
		}
	}
	int i=0;
	int j=0;
	string mot_a_afficher = a;
	while(i<=n-1 && j<=m-1){ // Tant que mot_a_afficher n'est pas le mot b
		cout << mot_a_afficher << endl;
		change_position(action[i*(m-1)+j], i, j, mot_a_afficher, b);
	}

}


int levenshtein_lin(string a, string b){
	int n = a.length() + 1;
	int m = b.length() + 1;
	int* lig1 = new int[m]; // On se sert d'uniquement deux lignes de la matrice
	int* lig2 = new int[m];
	for(int j=0;j<m;j++){ // Initialisation de la première ligne
		lig1[j] = j;
	}
	for(int i=1; i<n;i++){ // Calcul de la seconde ligne
		lig2[0] = i;
		for(int j=1; j<m; j++){
			int substitution = 1;
			if(a[i-1] == b[j-1])
				substitution = 0;
			int elements[3] = {lig1[j]+1, lig2[j-1]+1, lig1[j-1]+substitution};
			lig2[j] = min(elements, 3);
		}
		swap(lig1, lig2);
	}
	int distance = lig1[m-1];
	delete [] lig1;
	delete [] lig2;
	return distance;
}
