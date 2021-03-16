#include "Personnage.h"
#include "Heros.h"

int main() {
  vector<Objet> inventaire;
  Heros heros(100,10,"Barbare",100, &inventaire);
  Personnage Ennemis(100,10,"Moine");
  cout << heros;
  cout <<Ennemis;
  /*heros.addInInventory(potion);

  heros.getInventory();*/
}
