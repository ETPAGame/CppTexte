#include "Personnage.h"
#include "Heros.h"

bool Combat(Heros* moi, Personnage* lui) {
	cout << "Le combat entre : " << moi->getName() << " et " << lui->getName() << " commence" << endl;
	cout << "Le barbare commence" << endl;
	moi->attaque(*lui);
	return true;
}

void gameOver() {
	cout << "C est perdu" << endl;
	exit(0);
}

int main() {
	vector<Objet> inventaire;
	Heros heros(100, 10, "Barbare", 100, &inventaire);
	Objet popo("Proteine");
	Objet prot("Tape-toi la tete");
	Personnage Ennemis(100, 10, "Moine");
	char choix = -1;


	// --------------- DEBUT -------------- //
	cout << " ---------------------------------------" << endl;
	cout << " --------------- BARBARE ---------------" << endl;
	cout << " ---------------------------------------" << endl << endl;
	cout << "Vous etes Jean-Ti , un sac de muscle furieux pret" << endl << "a tout pour recuperer le seul et unique livre d image" << endl << "qui lui permettra de devenir plus fort : 'Martine a la salle'." << endl << "Vous avez traverse tout l ocean a la nage a la force de vos gros" << endl << "bras et vous arrivez enfin sur l ile du repos introuvable." << endl<<"Une ile ou les gens vont trouver le repos et la paix, non pas une grosse brute de votre accabit." << endl << endl;

	cout << "Vous arrivez sur la plage et tombez face a une bonne femme qui s apparente a une pauvre nonne, que voulez vous faire ?" << endl << endl;
	Personnage E1(100, 10, "Nonne");
	while (choix != '1') {
		cout << "1 : La tabasser" << endl;
		cin >> choix;
	 }
	if (!Combat(&heros, &E1)) {
		gameOver();
	}


	cout << "FIN" << endl << endl;
}
