#include "Personnage.h"

Personnage::Personnage() :viePhysique(100), attack(10), name("NoName") {}

Personnage::Personnage(int h, int a, string n) : viePhysique(h), attack(a), name(n) {}

int Personnage::getHealth()const {
	return viePhysique;
}

int Personnage::getAttack()const {
	return attack;
}

string Personnage::getName()const {
	return name;
}

void Personnage::setAttack(int a) {
	attack = a;
}

void Personnage::setHealth(int h) {
	viePhysique = h;
}

void Personnage::setName(string n) {
	name = n;
}

void Personnage::attackEnemy(Personnage& cible) {
	cout << getName() << " attaque " << cible.getName() << " pour " << getAttack() << " degats : " << endl;
	cible.setHealth(cible.getHealth() - getAttack());
	cout << cible;
}


ostream& operator<<(ostream& os, Personnage const& p) {
	os << "----" << p.getName() << "----" << endl;
	os << "Health = " << p.getHealth() << endl;
	os << "Attack = " << p.getAttack() << endl << endl;
	return os;
}
