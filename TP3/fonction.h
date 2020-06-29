#include <string>
using namespace std;
#pragma once

class Fonction{
public:
	virtual float operator()(float x)=0;
	virtual Fonction* derivee() const =0;
	virtual ~Fonction(){};
	virtual Fonction* clone() const = 0;
	float inverse(float y);
	
};

class Polynome: public Fonction{
protected:
	int deg;
	float* coeff;
public:
	Fonction* clone() const;
	Polynome(int deg, float coeff[]);
	Polynome(){};
	void print(void);
	~Polynome();
	float operator()(float x);
	Polynome* derivee() const;
};

class Affine: public Polynome{
public:
	Affine(float a, float b);
	~Affine();
};

class Derivee: public Fonction{
private:
	Fonction* integrale;
public:
	Derivee(Fonction* f);
	Fonction* clone() const;
	float operator()(float x);
	Derivee* derivee() const;
};

class Trigo: public Fonction{
private:
	string type;
public:
	Trigo(string type_fonction);
	float operator()(float x);
	Fonction* clone() const;
	Derivee* derivee() const;	
};
