#include "Personnage.h"
#include "Heros.h"


bool Combat(Heros* moi, Personnage* lui) {
	cout << "Le combat entre : " << moi->getName() << " et " << lui->getName() << " commence" << endl;
	cout << "Le barbare commence" << endl;
	while (true) {
		cout << *lui << endl;
		moi->attaque(*lui);
		lui->attackEnemy(*moi);
		if (moi->getHealth() < 0) {
			return false;
		}
		if (lui->getHealth() < 0) {
			return true;
		}
	}
}

void gameOver() {
	cout << "C est perdu" << endl;
	exit(0);
}

int main() {

	vector<Objet> inventaire;
	Heros heros(150, 25, "Barbare", 100, &inventaire);
	Objet prot("Proteine");
	Objet popo("Tape-toi la tete");
	heros.addInInventory(&popo);
	heros.addInInventory(&popo);
	heros.addInInventory(&prot);
	heros.addInInventory(&prot);
	Personnage Ennemis(100, 10, "Moine");
	char choix = -1;


	// --------------- DEBUT -------------- //
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << " .S_SSSs     .S_SSSs     .S_sSSs     .S_SSSs     .S_SSSs     .S_sSSs      sSSs  " << endl;
	cout << ".SS~SSSSS   .SS~SSSSS   .SS~YS%%b   .SS~SSSSS   .SS~SSSSS   .SS~YS%%b    d%%SP  " << endl;
	cout << "S%S   SSSS  S%S   SSSS  S%S   `S%b  S%S   SSSS  S%S   SSSS  S%S   `S%b  d%S'    " << endl;
	cout << "S%S    S%S  S%S    S%S  S%S    S%S  S%S    S%S  S%S    S%S  S%S    S%S  S%S     " << endl;
	cout << "S%S SSSS%P  S%S SSSS%S  S%S    d*S  S%S SSSS%P  S%S SSSS%S  S%S    d*S  S&S     " << endl;
	cout << "S&S  SSSY   S&S  SSS%S  S&S   .S*S  S&S  SSSY   S&S  SSS%S  S&S   .S*S  S&S_Ss  " << endl;
	cout << "S&S    S&S  S&S    S&S  S&S_sdSSS   S&S    S&S  S&S    S&S  S&S_sdSSS   S&S~SP  " << endl;
	cout << "S&S    S&S  S&S    S&S  S&S~YSY%b   S&S    S&S  S&S    S&S  S&S~YSY%b   S&S     " << endl;
	cout << "S*S    S&S  S*S    S&S  S*S   `S%b  S*S    S&S  S*S    S&S  S*S   `S%b  S*b     " << endl;
	cout << "S*S    S*S  S*S    S*S  S*S    S%S  S*S    S*S  S*S    S*S  S*S    S%S  S*S.    " << endl;
	cout << "S*S SSSSP   S*S    S*S  S*S    S&S  S*S SSSSP   S*S    S*S  S*S    S&S   SSSbs  " << endl;
	cout << "S*S  SSY    SSS    S*S  S*S    SSS  S*S  SSY    SSS    S*S  S*S    SSS    YSSP  " << endl;
	cout << "SP                 SP   SP          SP                 SP   SP                  " << endl;
	cout << "Y                  Y    Y           Y                  Y    Y                   " << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "Vous etes Jean-Ti , un sac de muscle furieux pret" << endl << "a tout pour recuperer le seul et unique livre d image" << endl << "qui lui permettra de devenir plus fort : 'Martine a la salle'." << endl << "Vous avez traverse tout l ocean a la nage a la force de vos gros" << endl << "bras et vous arrivez enfin sur l ile du repos introuvable." << endl << "Une ile ou les gens vont trouver le repos et la paix, non pas une grosse brute de votre accabit." << endl << endl;

	cout << "Vous arrivez sur la plage et tombez face a une bonne femme qui s apparente a une pauvre nonne, que voulez vous faire ?" << endl << endl;
	Personnage E1(100, 10, "Nonne");
	Personnage E2(150, 10, "Moine");
	Personnage E3(100, 15, "Sage");
	while (choix != '1') {
		cout << "1 : La tabasser" << endl;
		cin >> choix;
	}
	if (!Combat(&heros, &E1)) {
		gameOver();
	}
	heros.addInInventory(&popo);
	heros.addInInventory(&popo);
	heros.addInInventory(&prot);
	heros.addInInventory(&prot);
	if (!Combat(&heros, &E2)) {
		gameOver();
	}
	heros.addInInventory(&popo);
	heros.addInInventory(&popo);
	heros.addInInventory(&prot);
	heros.addInInventory(&prot);
	if (!Combat(&heros, &E3)) {
		gameOver();
	}


	cout << "FIN" << endl << endl;
}
