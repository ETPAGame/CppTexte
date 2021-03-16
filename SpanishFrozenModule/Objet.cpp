#include "Objet.h"

Objet::Objet(string name){
    name = name;
}

Objet::~Objet()
{
    cout<<name<<" est perdu"<<endl;
}

string Objet::getName()
{
  return name;
}

void Objet::setName(string n){
  name = n;
}
