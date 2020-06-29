#include <iostream>
using namespace std;
#include "IntTree.h"

int main(){
	IntTree* root = new IntTree(12);
	root->addAsLastSon(new IntTree(8));
	root->getSon(0)->addAsLastSon(new IntTree(4));
	root->getSon(0)->addAsLastSon(new IntTree(9));
	root->addAsLastSon(new IntTree(23));
	root->getSon(1)->addAsLastSon(new IntTree(17));
	root->getSon(1)->getSon(0)->addAsLastSon(new IntTree(15));
	root->display("* ", "   ");
	
	cout << "Which error dou want to see ? 1- getSon 2- setSon 3- removeLastSon" << endl;
	int c;
	cin >> c;
	if(c == 1){
		IntTree* node = root->getSon(2);
	}
	if(c == 2){
		root->setSon(3, new IntTree(4));
	}
	if(c == 3){
		root->getSon(0)->getSon(0)->removeLastSon();
	}
	return 0;
}
