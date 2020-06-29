#include <vector>
#include <iostream>
#include <string>
using namespace std;
#include "IntTree.h"

IntTree::IntTree(int d){
	data = d;
}

IntTree::~IntTree(){
	if(nbSons() == 0){
		delete this;
	}
	else{
		for(int i=0; i<nbSons()-1; i++){
			sons[i]->~IntTree(); // On détruit tous les fils
		}
	}
}


int IntTree::getData() const{
	return data;
}

void IntTree::setData(int d){
	data = d;
}

int IntTree::nbSons() const{
	return sons.size();
}

IntTree* IntTree::getSon(int pos) const{
	try{
		if(pos <0 || pos>=nbSons()){
			throw "Trying to access a non-existent son";
		}
		return sons[pos];
	}
	catch(char const* message){
		cerr << message << endl;
		exit(1);
	}
}

void IntTree::setSon(int pos, IntTree* newSon){
	try{
		if(pos <0 || pos>=nbSons()){
			throw "Trying to change a non-existent son";
		}
		sons[pos] = newSon;
	}
	catch(char const* message){
		cerr << message << endl;
		exit(2);
	}
}

void IntTree::addAsLastSon(IntTree* newSon){
	sons.push_back(newSon);
}

void IntTree::removeLastSon(){
	try{
		if (nbSons() == 0){
			throw "Trying to remove a non-existent son";
		}
		sons.pop_back();
	}
	catch(char const* message){
		cerr << message << endl;
		exit(3);
	}
}

void IntTree::display(string prefix = "", string indent = "    ") const{
	if(nbSons() == 0){ // Si c'est le bout d'une branche
		cout << prefix << data << endl;
	}
	else{
		int index = 0;
		cout << prefix << data << endl;
		prefix += indent;
		while(index < nbSons()){ // On parcourt tous les fils du noeud
			sons[index]->display(prefix, indent);
			index++;
		}
	}
}
