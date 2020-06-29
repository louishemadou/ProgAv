#include <string>
using namespace std;
#pragma once

int min(int tableau[], int len);

int levenshtein_sans_memo(string a, string b);

int levenshtein_avec_memo(string a, string b);

int levenshtein_iter(string a, string b);

void levenshtein_iter_affiche(string a, string b);

int levenshtein_lin(string a, string b);
