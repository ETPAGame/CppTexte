#include "Heros.h"


Heros::Heros(int hP, int attack, string name, int hM, vector<Objet>* inventory) :Personnage(hP, attack, name) {
	vieMental = hM;
	inventaire = *inventory;
}

Heros::~Heros() {}

void Heros::setVieMental(int vieM) {
	vieMental = vieM;
}
int Heros::getVieMental() {
	return vieMental;
}

void Heros::addInInventory(Objet* newObjet) {
	inventaire.push_back(* newObjet);
}

bool Heros::getInInventory(string objetName) {
	for (int i = 0; i < inventaire.size(); i++) {
		if (objetName == inventaire[i].getName()) {
			return true;
		}
	}
	return false;
}

void Heros::getInventory() {
	for (int i = 0; i < inventaire.size(); i++) {
		cout << inventaire[i].getName() << endl;
	}
	cout << endl;
}

void Heros::attaque(Personnage& cible) {
	int choixCoup;
	string choixZone;
	cout << "Faut faire quoi ?" << endl;
	cout << "1 : Uppercut" << endl;
	cout << "2 : Droite" << endl;
	cout << "3 : Coup de boule" << endl;
	cout << "4 : Balayette" << endl;
	cin >> choixCoup;
	switch (choixCoup) {
	case 1:
		cout << "Uppercut, mais ou ?" << endl;
		cout << "Tete" << endl;
		cout << "Corps" << endl;
		cin >> choixZone;
		uppercut(cible, choixZone);
		break;
	case 2:
		cout << "Droite, mais ou ?";
		cout << "Tete" << endl;
		cout << "Corps" << endl;
		cout << "Jambes" << endl;
		cin >> choixZone;
		droite(cible, choixZone);
		break;
	case 3:
		cout << "Coup de boule, mais ou ?";
		cout << "Tete" << endl;
		cout << "Corps" << endl;
		cin >> choixZone;
		coupDeBoule(cible, choixZone);
		break;
	case 4:
		cout << "Balayette, mais ou ?";
		cout << "Corps" << endl;
		cout << "Jambes" << endl;
		cin >> choixZone;
		balayette(cible, choixZone);
		break;
	default:
		cin >> choixCoup;
	}

}

void Heros::uppercut(Personnage& cible, string zone) {
	float coef;
	if (zone != "Tete" || zone != "Corps") {
		cout << "La zone visée n'est pas bonne" << endl;
		cin >> zone;
	}
	if (zone == "Tete") {
		coef = 0.75;
	}
	if (zone == "Corps") {
		coef = 0.5;
	}
}
void Heros::droite(Personnage& cible, string zone) {
	float coef;
	if (zone == "Tete") {
		coef = 0.75;
	}
	if (zone == "Corps") {
		coef = 0.5;
	}
	if (zone == "Jambes") {
		coef = 0.25;
	}
	float multiplicateurDegat = QTE(coef);
}
void Heros::coupDeBoule(Personnage& cible, string zone) {
	float coef;
	if (zone != "Tete" || zone != "Corps") {
		cout << "La zone visée n'est pas bonne" << endl;
		cin >> zone;
	}
	if (zone == "Tete") {
		coef = 0.75;
	}
	if (zone == "Corps") {
		coef = 0.5;
	}
}
void Heros::balayette(Personnage& cible, string zone) {
	float coef;
	if (zone == "Corps") {
		coef = 0.5;
	}
	if (zone == "Jambes") {
		coef = 0.25;
	}
}

float Heros::QTE(float coef) {
	if (coef == 0.75) {
		//qte
		return 1.25f;
	}
	else if (coef == 0.5f) {
		//qte
		return 1.00f;
	}
	else {
		//qte
		return 0.75f;
	}
}
