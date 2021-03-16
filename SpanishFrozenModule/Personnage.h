#pragma once
#include <iostream>
#include <string>

using namespace std;

class Personnage{
private:
  string name;
  int viePhysique = 100;
  int attack = 10;


public:
  Personnage();
  Personnage(int h, int a, string n);
  int getHealth()const;
  int getAttack()const;
  string getName()const;
  void setHealth(int h);
  void setAttack(int a);
  void setName(string n);

  void attackEnemy(Personnage &cible);
  friend ostream& operator<<(ostream& os,Personnage const & p);

};
