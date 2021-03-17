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
	int choixZone;
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
		uppercut(cible, choixZone);
		break;
	case 2:
		cout << "Droite, mais ou ?";
		cout << "1 : Tete" << endl;
		cout << "2 : Corps" << endl;
		cout << "3 : Jambes" << endl;
		cin >> choixZone;
		droite(cible, choixZone);
		break;
	case 3:
		cout << "Coup de boule, mais ou ?";
		cout << "1 : Tete" << endl;
		cout << "2 : Corps" << endl;
		cin >> choixZone;
		coupDeBoule(cible, choixZone);
		break;
	case 4:
		cout << "Balayette, mais ou ?";
		cout << "1 : Corps" << endl;
		cout << "2 : Jambes" << endl;
		cin >> choixZone;
		balayette(cible, choixZone);
		break;
    case 5:
        Heros::inventoryChoice();
	default:
		cin >> choixCoup;
	}

}

void Heros::uppercut(Personnage& cible, int zone) {
	float coef;
	if (zone != 1 && zone != 2) {
		cout << "La zone visee n'est pas bonne" << endl;
		cin >> zone;
	}
	if (zone ==1) {
		coef = 0.75;
	}
	if (zone ==2) {
		coef = 0.5;
	}
	float multiplicateurDegat = QTE(coef);
	cout <<"mult "  <<  multiplicateurDegat << endl << endl;
}
void Heros::droite(Personnage& cible, int zone) {
	float coef;
	if (zone ==1) {
		coef = 0.75;
	}
	if (zone == 2) {
		coef = 0.5;
	}
	if (zone ==3) {
		coef = 0.25;
	}
	float multiplicateurDegat = QTE(coef);
}
void Heros::coupDeBoule(Personnage& cible, int zone) {
	float coef;
	if (zone !=1 || zone !=2) {
		cout << "La zone visee n'est pas bonne" << endl;
		cin >> zone;
	}
	if (zone == 1) {
		coef = 0.75;
	}
	if (zone == 2) {
		coef = 0.5;
	}
}
void Heros::balayette(Personnage& cible, int zone) {
	float coef;
	if (zone == 1) {
		coef = 0.5;
	}
	if (zone ==2) {
		coef = 0.25;
	}
}

float Heros::QTE(float coef) {
    srand (time(NULL));
    vector<string> tblMot{"Bagarre","Baston","Taper","Frapper","Cogner","Detruire","Briser","Eclater","Tabasser","Defoncer","Obliterer","Eliminer","Casser","Enfoncer","Claquer","Brutaliser","Meurtrir","Rosser","Boxer","Castagner","Baffer","Combattre","Etrangler","Pied-bouche","Crochet","Enfoncer","Peter","Slapper","Etirer","Ecarteler","Saigner"};
    string entree;
    cout << rand() % tblMot.size() << endl;
		string mot = tblMot[rand() % tblMot.size()];
		time_t timeA = time(NULL);
		cout << "Recopiez le mot suivant : " << mot << endl;
		while (entree != mot){
            cout << "GO" << endl;
            cin >> entree;
		}
        time_t timeB = time(NULL);
        int vitesse = difftime(timeB, timeA) ;
        cout << "vitesse " << vitesse << endl;


    if (vitesse > 10){
        return 0;
    }

	if (coef == 0.75f) {
		//qte
		if (vitesse <= 2){
            return 1;
        }
        else {
            return 1-(vitesse/10.f);

        }
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

void Heros::inventoryChoice(){

}
