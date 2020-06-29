#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "levenshtein.h"
#include "damerau.h"

int psi(string a, string b, int i, int j){
	if(min(i,j) == 0)
		return max(i,j);
	int substitution = 1;
	if(a[i-1]==b[j-1])
		substitution = 0;
	if(min(i,j)>1 && a[i-1]==b[j-2] && a[i-2]==b[j-1]){
		int elements[4] = {psi(a,b,i-1,j)+1, psi(a,b,i,j-1)+1, psi(a,b,i-1,j-1) + substitution, psi(a,b,i-2,j-2)+1};
		return min(elements, 4);
	}
	int elements[3] = {psi(a,b,i-1,j)+1, psi(a,b,i,j-1)+1, psi(a,b,i-1,j-1) + substitution};
	return min(elements, 3);
}


int damerau_sans_memo(string a, string b){
	return psi(a,b,a.length(),b.length());
}


int psi2(string a, string b, int i, int j, int* tableau){
	int m = b.length() + 1;
	if(tableau[i*m+j]!=-1)
		return tableau[i*m+j];
	if(min(i,j) == 0)
		return max(i,j);
	int substitution = 1;
	if(a[i-1] == b[j-1])
		substitution = 0;
	if(min(i,j)>1 && a[i-1]==b[j-2] && a[i-2]==b[j-1]){
		int elements[4] = {psi2(a,b,i-1,j,tableau)+1, psi2(a,b,i,j-1,tableau)+1, psi2(a,b,i-1,j-1,tableau)+substitution, psi2(a,b,i-2,j-2,tableau)+1};
		tableau[i*m+j] = min(elements, 4);
		return tableau[i*m+j];
	}
	else{
	int elements[3] = {psi2(a,b,i-1,j,tableau)+1, psi2(a,b,i,j-1,tableau)+1, psi2(a,b,i-1,j-1,tableau)+substitution};
	tableau[i*m+j] = min(elements, 3);
	return tableau[i*m+j];
	}
}

int damerau_avec_memo(string a, string b){
	int n = a.length() + 1;
	int m = b.length() + 1;
	int* tableau = new int[m*n];
	for(int k=0; k<m*n; k++){
		tableau[k] = -1; // Non calculé
	}
	int distance = psi2(a,b,n-1,m-1,tableau);
	delete [] tableau;
	return distance;
}

int damerau_iter(string a, string b){
	int n = a.length() + 1;
	int m = b.length() + 1;
	int* tableau = new int[n*m];
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			if(min(i,j) == 0)
				tableau[i*m+j] = max(i,j);
			else{	
				int substitution = 1;	
				if(a[i-1] == b[j-1])
					substitution = 0;
				if(min(i,j)>1 && a[i-1]==b[j-2] && a[i-2]==b[j-1]){
					int elements[4] = {tableau[(i-1)*m+j]+1, tableau[i*m+j-1]+1, tableau[(i-1)*m+j-1]+substitution, tableau[(i-2)*m+j-2]+1};
					tableau[i*m+j] = min(elements, 4);
				}
				else{
					int elements[3] = {tableau[(i-1)*m+j]+1, tableau[i*m+j-1]+1, tableau[(i-1)*m+j-1] + substitution};
				tableau[i*m+j] = min(elements, 3);
				}
			}
		}
	}
	int distance = tableau[(m*n-1)];
	delete [] tableau;
	return distance;
}
