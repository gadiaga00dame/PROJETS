/*
 * vertebre.cpp
 *
 *  Created on: 3 avr. 2024
 *      Author: denis
 */


#include "vertebre.hpp"

#include <iostream>

Vertebre::Vertebre(int nb_pattes, std::string type_pelage)
{
	pattes = nb_pattes;
	pelage = type_pelage;
	std::cout << "Constructeur Vertebre" << std::endl;
}

Vertebre::~Vertebre()
{
	std::cout << "Destructeur Vertebre" << std::endl;
}

void Vertebre::affiche()
{
	std::cout << "Vertebre avec " << pattes << " pattes et des " << pelage << std::endl;
}

int Vertebre::get_pattes()
{
	return pattes;
}

std::string Vertebre::get_pelage()
{
	return pelage;
}

std::ostream& operator<< (std::ostream& out, Vertebre & animal)
{
	out << "Vertebre avec " << animal.get_pattes() << " pattes et des " << animal.get_pelage();
	// On ne met pas de retour chariot, ça permet un meilleur contrôle du formattage de la sortie.
	return out;
}

