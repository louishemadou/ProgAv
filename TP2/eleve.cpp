#include "eleve.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int alea(int a, int b){ // Nombre aléatoire entre a et b, inclus
	return rand()%(b+1-a)+a;
}

char random_char(){ // Renvoie une lettre minuscule aléatoire
	char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int index = alea(0,25);
	return alpha[index];
}

Eleve::Eleve(){
	int taille_nom = alea(2,11);
	for(int i=0;i<taille_nom;i++){
		char c = random_char();
		if(i==0){
			nom += toupper(c); // Première lettre est une majuscule
		}
		else{
			nom += c;
		}
	}
	note = alea(0,20);
		
}

string Eleve::get_nom(){
	return nom;
}

int Eleve::get_note(){
	return note;
}
