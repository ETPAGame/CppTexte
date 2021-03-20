#ifndef HEROS_H
#define HEROS_H

#pragma once
#include "Personnage.h"
#include "Objet.h"
#include <vector>
#include <time.h>
//#include <unistd.h>

class Heros : public Personnage
{
private:
	int vieMental;
	vector<Objet> inventaire;
	float QTE(float coef);

public:
	Heros(int viePhysique, int attack, string name, int vieMental, vector<Objet>* inventaire);
	~Heros();

	void setVieMental(int vieMental);
	int getVieMental();
	void addInInventory(Objet * newObjet);
	bool getInInventory(string objetName);
	void getInventory();

	void attaque(Personnage& cible);

	float uppercut(Personnage& cible, int zone);
	float droite(Personnage& cible, int zone);
	float coupDeBoule(Personnage& cible, int zone);
	float balayette(Personnage& cible, int zone);

	void inventoryChoice();

};
#endif // HEROS_H


