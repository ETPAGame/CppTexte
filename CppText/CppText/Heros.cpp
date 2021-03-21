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
	inventaire.push_back(*newObjet);
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
	int choixZone;
	float degat;
	cout << "Faut faire quoi ?" << endl;
	cout << "1 : Uppercut" << endl;
	cout << "2 : Droite" << endl;
	cout << "3 : Coup de boule" << endl;
	cout << "4 : Balayette" << endl;
	cout << "5 : Inventaire" << endl;
	cin >> choixCoup;
	switch (choixCoup) {
	case 1:
		cout << "Uppercut, mais ou ?" << endl;
		cout << "1 : Tete" << endl;
		cout << "2 : Corps" << endl;
		cin >> choixZone;
		degat = uppercut(cible, choixZone);
		break;
	case 2:
		cout << "Droite, mais ou ?";
		cout << "1 : Tete" << endl;
		cout << "2 : Corps" << endl;
		cout << "3 : Jambes" << endl;
		cin >> choixZone;
		degat = droite(cible, choixZone);
		break;
	case 3:
		cout << "Coup de boule, mais ou ?";
		cout << "1 : Tete" << endl;
		cout << "2 : Corps" << endl;
		cin >> choixZone;
		degat = coupDeBoule(cible, choixZone);
		break;
	case 4:
		cout << "Balayette, mais ou ?";
		cout << "1 : Corps" << endl;
		cout << "2 : Jambes" << endl;
		cin >> choixZone;
		degat = balayette(cible, choixZone);
		break;
	case 5:
		Heros::inventoryChoice();
		return;
	default:
		cin >> choixCoup;
	}
	cout << degat << endl;
	cout << getName() << " attaque " << cible.getName() << " pour " << getAttack() *degat << " degats : " << endl;
	cible.setHealth(cible.getHealth() - (getAttack()*degat));

}

float Heros::uppercut(Personnage& cible, int zone) {
	float coef;
	while (zone != 1 && zone != 2) {
		cout << "La zone visee n'est pas bonne" << endl;
		cin >> zone;
	}
	if (zone == 1) {
		coef = 0.75;
	}
	if (zone == 2) {
		coef = 0.5;
	}
	float multiplicateurDegat = QTE(coef);
	return (coef * multiplicateurDegat);
	cout << "mult " << multiplicateurDegat << endl << endl;
}
float Heros::droite(Personnage& cible, int zone) {
	float coef;
	while (zone != 1 && zone != 2 && zone != 3) {
		cout << "La zone visee n'est pas bonne" << endl;
		cin >> zone;
	}
	if (zone == 1) {
		coef = 0.75;
	}
	if (zone == 2) {
		coef = 0.5;
	}
	if (zone == 3) {
		coef = 0.25;
	}
	float multiplicateurDegat = QTE(coef);
	return (coef * multiplicateurDegat);
}
float Heros::coupDeBoule(Personnage& cible, int zone) {
	float coef;
	while (zone != 1 || zone != 2) {
		cout << "La zone visee n'est pas bonne" << endl;
		cin >> zone;
	}
	if (zone == 1) {
		coef = 0.75;
	}
	if (zone == 2) {
		coef = 0.5;
	}
	float multiplicateurDegat = QTE(coef);
	return (coef * multiplicateurDegat);
}
float Heros::balayette(Personnage& cible, int zone) {
	float coef;
	while (zone != 1 && zone != 2 && zone != 3) {
		cout << "La zone visee n'est pas bonne" << endl;
		cin >> zone;
	}
	if (zone == 1) {
		coef = 0.5;
	}
	if (zone == 2) {
		coef = 0.25;
	}
	float multiplicateurDegat = QTE(coef);
	return (coef * multiplicateurDegat);
}

float Heros::QTE(float coef) {
	srand(time(NULL));
	vector<string> tblMot{ "Bagarre","Baston","Taper","Frapper","Cogner","Detruire","Briser","Eclater","Tabasser","Defoncer","Obliterer","Eliminer","Casser","Enfoncer","Claquer","Brutaliser","Meurtrir","Rosser","Boxer","Castagner","Baffer","Combattre","Etrangler","Pied-bouche","Crochet","Enfoncer","Peter","Slapper","Etirer","Ecarteler","Saigner" };
	string entree;
	cout << rand() % tblMot.size() << endl;
	string mot = tblMot[rand() % tblMot.size()];
	time_t timeA = time(NULL);
	cout << "Recopiez le mot suivant : " << mot << endl;
	while (entree != mot) {
		cout << "GO" << endl;
		cin >> entree;
	}
	time_t timeB = time(NULL);
	int vitesse = difftime(timeB, timeA);
	cout << "vitesse " << vitesse << endl;


	if (vitesse > 10) {
		return 0;
	}

	if (coef == 0.75f) {
		//qte
		if (vitesse <= 2) {
			return 1;
		}
		else {
			return 1 - (vitesse / 10.f);

		}
	}
	else if (coef == 0.5f) {
		//qte
		if (vitesse <= 4) {
			return 0.75f;
		}
		else {
			return 1 - (vitesse / 13.f);

		}
	}
	else {
		//qte
		if (vitesse <= 6) {
			return 0.5f;
		}
		else {
			return 1 - (vitesse / 16.f);

		}
	}
}

void Heros::inventoryChoice() {
	int prot = 0;
	int choix = -1;
	int tape = 0;
	for (int i = 0; i < inventaire.size(); i++) {
		if (inventaire[i].getName() == "Proteine") {
			prot += 1;
		}
		else if (inventaire[i].getName() == "Tape-toi la tete") {
			tape += 1;
		}
	}
	cout << "Vous avez " << prot << " shakers de proteine et " << tape << " fois la possiblite de vous taper la tete pour vous raisonner." << endl;
	cout << "Vous avez " << getHealth() << " points de vie et " << vieMental << " point de raisonnement" << endl;
	cout << "Que voulez vous faire ?" << endl;
	cout << "1 : prendre un shaker" << endl;
	cout << "2 : vous tapez la tete" << endl;
	while ((choix != 1)  && (choix != 2)) {
		cin >> choix;
	}
	if (choix == 1 && prot > 0) {
		setHealth(getHealth() + 10);
		for (int i = 0; i < inventaire.size(); i++) {
			if (inventaire[i].getName() == "Proteine") {
				inventaire[i].setName("Utilise");
				break;
			}
		}
	}
	if (choix == 2 && tape > 0) {
		setVieMental(getVieMental() + 10);
		for (int i = 0; i < inventaire.size(); i++) {
			if (inventaire[i].getName() == "Tape-toi la tete") {
				inventaire[i].setName("Utilise");
				break;
			}
		}
	}
}