#include "Objet.h"

Objet::Objet(string nom) {
    name = nom;
}

Objet::~Objet()
{
    cout << name << " est perdu" << endl;
}

string Objet::getName()
{
    return name;
}

void Objet::setName(string n) {
    name = n;
}
