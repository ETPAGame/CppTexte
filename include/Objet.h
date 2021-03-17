#pragma once
#include <iostream>
#include <string>

using namespace std;

class Objet {
	private:
		string name;
	public:
		Objet(string name);
		~Objet();

		void setName(string n);
		string getName();

};
