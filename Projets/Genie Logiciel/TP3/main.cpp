/*
 * main.cpp
 *
 *  Created on: 3 avr. 2024
 *      Author: denis
 */

#include <string>
#include <iostream>

#include "vertebre.hpp"
#include "oiseau.hpp"

int main()
{
	Vertebre v(4, "poils");
	//v.affiche();
	//std::cout << "v = " << v << std::endl;
	std::cout << "Nombre de pattes de v = " << v.get_pattes() << std::endl;

	Oiseau oiseau(1);
	oiseau.affiche();
	std::cout << "Nombre de pattes de oiseau = " << oiseau.get_pattes() << std::endl;
	std::cout << "Nombre d'oeufs de oiseau = " << oiseau.get_oeufs() << std::endl;
	std::cout << "Nombre d'ailes de oiseau = " << oiseau.get_ailes() << std::endl;
	std::cout << std::endl;

	// Exercice bonus
	std::cout << "Affichage avec les surchages de l'opérateur << :" << std::endl;
	std::cout << "oiseau = " << oiseau << std::endl; // Cette syntaxe est tout de même plus sympa à utiliser non ?
	return 0;
}


