#include "Heros.h"


Heros::Heros (int hP,int attack,string name, int hM,  vector<Objet> * inventory):Personnage(hP,attack,name){
	vieMental = hM;
	inventaire = *inventory;
}

Heros::~Heros(){}

void Heros::setVieMental(int vieM){
	vieMental = vieM;
}
int Heros::getVieMental(){
	return vieMental;
}

void Heros::addInInventory(Objet newObjet){
	inventaire.push_back(newObjet);
}

bool Heros::getInInventory(string objetName){
	for(int i = 0; i<inventaire.size(); i++){
		if (objetName == inventaire[i].getName()){
			return true;
		}
	}
	return false;
}

void Heros::getInventory(){
	for (int i = 0; i < inventaire.size(); i++){
		cout << inventaire[i].getName() << endl;
	}
	cout << endl;
}
