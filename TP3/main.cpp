#include <iostream>
#include <cmath>
using namespace std;
#include "fonction.h"

int main(){
	int deg = 3;
	float coeff[deg+1];
	coeff[0] = 1;
	coeff[1] = 2;
	coeff[2] = 3;
	coeff[3] = 4;
	cout << "Polynome initial" << endl;
	Polynome P(deg, coeff);
	P.print();
	Polynome Q =*P.derivee();
	cout << "Polynome derive" << endl;
	Q.print();
	cout << "Polynome affine" << endl;
	Affine A(2,1);
	A.print();
	int deg2 = 3;
	float coeff2[deg2+1];
	coeff2[0] = 0;
	coeff2[1] = 0;
	coeff2[2] = 0;
	coeff2[3] = 1;
	Polynome R(deg2, coeff2);
	cout << "Polynome X^3" << endl;
	R.print();
	cout << "racine cubique de 27 = " << R.inverse(27) << endl;
	Trigo* tan = new Trigo("tan");
	cout << "4*atan(1) = " <<4*tan->inverse(1) << endl;
	cout <<  "tan'(1) = " << (*tan->derivee())(M_PI/4) << endl;
	cout << "tan''(1) = '"<< (*tan->derivee()->derivee())(M_PI/4) << endl;
	return 0;
}
