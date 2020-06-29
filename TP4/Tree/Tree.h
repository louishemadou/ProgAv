#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Node of a tree containing an integer at each node
template <typename T> class Tree {
    // Node information
    T data;
    // Sequence of sons (empty if none)
    vector<Tree<T>*> sons;
public:
    // Create a node with given information
    Tree(T d){data = d;};
    // Destruct a node and all its descendants
    ~Tree();
    // Return information of this node
    T getData() const{return data;};
    // Set information of this node
    void setData(T d){data = d;};
    // Return the number of sons of this node
    int nbSons() const{return sons.size();};
    // Return the son at position pos, if pos is a valid position. Else, return an error
    Tree<T>* getSon(int pos) const;
    // Replace the exisiting son at position pos if pos is a valid position. Else, return an error
    void setSon(int pos, Tree<T>* newSon);
    // Add newSon as supplementary right-most son of this node
    void addAsLastSon(Tree<T>* newSon){sons.push_back(newSon);};
    // Add son at position pos
    void insertSon(int pos, Tree<T>* son);
    // Remove son at position pos and reduce nbSons
    void removeSon(int pos);
    // Remove right-most son of this node
    void removeLastSon();
    void display(string prexif, string indent) const;
};


template <typename T> Tree<T>::~Tree(){
	if(nbSons() == 0){
		delete this;
	}
	else{
		for(int i=0; i<nbSons()-1; i++){ // On détruit tous les fils
			sons[i]->~Tree();
		}
	}

}

template <typename T> Tree<T>* Tree<T>::getSon(int pos) const{
	try{
		if(pos < 0 || pos >= nbSons()){
			throw "Trying to access a non-existent son";
		}
		return sons[pos];
	}
	catch(char const* message){
		cerr << message << endl;
		exit(1);
	}
}

template <typename T> void Tree<T>::setSon(int pos, Tree* newSon){
	try{
		if(pos < 0 || pos >= nbSons()){
			throw "Trying to change a non-existent son";
		}
		sons[pos] = newSon;
	}
	catch(char const* message){
		cerr << message << endl;
		exit(2);
	}
}

template <typename T> void Tree<T>::removeLastSon(){
	try{
		if(nbSons() == 0){
			throw "Trying to remove a non-existent son";
		}
		sons.pop_back();
	}
	catch(char const* message){
		cerr << message << endl;
		exit(3);
	}
}

template <typename T> void Tree<T>::display(string prefix, string indent) const{
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

template <typename T> void Tree<T>::insertSon(int pos, Tree<T>* son){
	try{
		if(pos < 0 || pos > nbSons()){
		throw "Trying to insert an element to a non-existent position";
		}
	    	sons.insert(sons.begin() + pos, son);
	}
	catch(char const* message){
		cerr << message << endl;
		exit(4);
	}
}

template <typename T> void Tree<T>::removeSon(int pos){
	try{
	    if(pos < 0 || pos >= nbSons()){
		    throw "Trying to remove a non-existent son";
	    }
	    sons.erase(sons.begin() + pos);
	}
	catch(char const* message){
		cerr << message << endl;
		exit(5);
	}
	
}
