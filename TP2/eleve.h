#pragma once
#include <iostream>
using namespace std;

class Eleve{
private:
	string nom;
	int note;
public:
	Eleve();
	string get_nom();
	int get_note();
};


class CompareEleve{
public:
	int* ptr;
	CompareEleve(int & compteur){ptr = &compteur;}
	bool operator()(Eleve E1, Eleve E2){ ++*ptr; return E1.get_nom() < E2.get_nom(); };
};

class CompareNote{
public:
	int* ptr;
	CompareNote(int & compteur){ptr = &compteur;}
	bool operator()(Eleve E1, Eleve E2){ ++*ptr ;return E1.get_note() < E2.get_note(); };
};


