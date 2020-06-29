#pragma once
#include <string>
#include <vector>
using namespace std;

// Node of a tree containing an integer at each node
class IntTree {
    // Node information
    int data;
    // Sequence of sons (empty if none)
    vector<IntTree*> sons;
public:
    // Create a node with given information
    IntTree(int d);
    // Destruct a node and all its descendants
    ~IntTree();
    // Return information of this node
    int getData() const;
    // Set information of this node
    void setData(int d);
    // Return the number of sons of this node
    int nbSons() const;
    // Return the son at position pos, if pos is a valid position. Else, return an error
    IntTree* getSon(int pos) const;
    // Replace the exisiting son at position pos, if pos is a valid position. Else, return an error 
    void setSon(int pos, IntTree* newSon);
    // Add newSon as supplementary right-most son of this node
    void addAsLastSon(IntTree* newSon);
    // Remove right-most son of this node, if the node is not empty. Else, return an error
    void removeLastSon();
    // Display node and all its descendants
    void display(string prefix, string indent) const;
};
