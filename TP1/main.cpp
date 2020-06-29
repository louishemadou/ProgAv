#include <iostream>
using namespace std;
#include "matrice.h"

int main(){
	Matrice A(3,4);
	Matrice B(4,3);
	A.Alea();
	B.Alea();
	Matrice M(A*B);
	M.Affiche();
	Matrice C(M*A);
	C.Affiche();
	return 0;
}
