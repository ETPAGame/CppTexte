#ifndef HEROS_H
#define HEROS_H

#include "Personnage.h"
#include "Objet.h"
#include <vector>

class Heros : public Personnage
{
  private :
	int vieMental;
	vector<Objet> inventaire;

  public :
    Heros(int viePhysique,int attack,string name,int vieMental, vector<Objet> * inventaire);
    ~Heros();

	void setVieMental(int vieMental);
	int getVieMental();
	void addInInventory(Objet newObjet);
	bool getInInventory(string objetName);
	void getInventory();


    void uppercut (Personnage * cible, string zone);
    void droite(Personnage * cible, string zone);
    void coupDeBoule(Personnage * cible, string zone);
    void balayette(Personnage * cible, string zone);

};
#endif // HEROS_H


