/*
 * volante.cpp
 *
 *  Created on: 15 avr. 2024
 *      Author: denis
 */

#include "volante.hpp"
#include <iostream>

Volante::Volante(int nb_ailes)
{
	ailes = nb_ailes;
	std::cout << "Constructeur Volante" << std::endl;
}

Volante::~Volante()
{
	std::cout << "Destructeur Volante" << std::endl;
}

int Volante::get_ailes()
{
	return ailes;
}

void Volante::affiche()
{
	std::cout << "Volante avec " << ailes << " ailes" << std::endl;
}

std::ostream& operator<< (std::ostream& out, Volante & animal)
{
	out << "Volante avec " << animal.get_ailes() << " ailes";
	return out;
}


