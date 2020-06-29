#include <iostream>
using namespace std;
#include "Tree.h"

int main(){
	Tree<int>* root = new Tree<int>(12);
	root->addAsLastSon(new Tree<int>(8));
	root->getSon(0)->addAsLastSon(new Tree<int>(4));
	root->getSon(0)->addAsLastSon(new Tree<int>(9));
	root->addAsLastSon(new Tree<int>(23));
	root->getSon(1)->addAsLastSon(new Tree<int>(17));
	root->getSon(1)->getSon(0)->addAsLastSon(new Tree<int>(15));
	cout << "Basic tree" << endl;
	root->display("* ", "   ");
	root->insertSon(1, new Tree<int>(2));
	root->getSon(1)->insertSon(0, new Tree<int>(3));
	cout << "adding a branch" << endl;
	root->display("* ", "   ");
	root->removeSon(1);
	cout << "removing branch" << endl;
	root->display("* ", "   ");
	return 0;
}
