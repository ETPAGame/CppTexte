#ifndef HEROS_H
#define HEROS_H

#pragma once
#include "Personnage.h"
#include "Objet.h"
#include <vector>
#include <time.h>
#include <unistd.h>

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

	void uppercut(Personnage& cible, int zone);
	void droite(Personnage& cible, int zone);
	void coupDeBoule(Personnage& cible, int zone);
	void balayette(Personnage& cible, int zone);

	void inventoryChoice();

};
#endif // HEROS_H


