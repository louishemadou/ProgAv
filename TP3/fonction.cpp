#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
#include "fonction.h"


float Fonction::inverse(float y){
	int i=0;
	Fonction* der = (*this).derivee();
	float x1 = 1.;
	float x2 = x1 + (y - (*this)(x1))/(*der)(x1);
	float eps = pow(10, -5);
	while(i < 100 && abs(x2-x1) > eps){
		x1 = x2;
		x2 = x1 + (y - (*this)(x1))/(*der)(x1);
	}
	return x1;
}

// Partie Polynome

Polynome::Polynome(int d, float c[]){
	deg = d;
	coeff = new float[deg];
	for(int i=0; i<deg+1; i++){
		coeff[i] = c[i];
	}
}

Polynome::~Polynome(){
	delete[] coeff;
}

Fonction* Polynome::clone() const{
	return new Polynome(*this);
}

float Polynome::operator()(float x){
	float tmp = 0;
	for(int i=0; i<deg+1; i++){
		tmp += coeff[i]*pow(x,i);
	}
	return tmp;	
}


Polynome* Polynome::derivee() const{
	float coeff_der[max(1,deg-1)];
	int deg_der;
	if(deg == 0){
		deg_der = 0;
		coeff_der[0] = 0;
	}
	else{
		for(int i=0; i<deg; i++){
			coeff_der[i] = coeff[i+1]*(i+1);
		}
		deg_der = deg-1;
	}
	return new Polynome(deg_der, coeff_der);
}

void Polynome::print(void){
	for(int i=0; i<deg+1; i++){
		if(i==0){
			cout << coeff[0];
		}
		else{
			cout << " + " << coeff[i] << "X^" << i;
		}
	}
	endl(cout);
}

Affine::Affine(float a, float b){
	deg = 1;
	coeff = new float[deg];
	coeff[0] = a;
	coeff[1] = b;
}

Affine::~Affine(){
	delete[] coeff;
}

// Partie fonctions trigonométriques

Trigo::Trigo(string type_fonction){
	assert(type_fonction == "sin" || type_fonction == "cos" || type_fonction == "tan");
	type = type_fonction;
}

float Trigo::operator()(float x){
	if(type == "sin"){
		return sin(x);
	}
	if(type == "cos"){
		return cos(x);
	}
	if(type == "tan"){
		return tan(x);
	}
	else{
		cout << "Mauvaise definition de la fonction" << endl;
		return 0;
	}
}

Fonction* Trigo::clone() const{
	return new Trigo(*this);
}

Derivee* Trigo::derivee() const{
	return new Derivee(clone());
}

// Partie dérivée

Derivee::Derivee(Fonction* f){
	integrale = f;	
}

Fonction* Derivee::clone() const{
	return new Derivee(*this);
}

float Derivee::operator()(float x){
	float eps = 0.01;
	return ((*integrale)(x+eps)-(*integrale)(x-eps))/(eps*2);
}

Derivee* Derivee::derivee() const{
	return new Derivee(clone());
}
