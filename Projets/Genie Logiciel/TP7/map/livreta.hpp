/*
 * livreta.hpp
 *
 *  Created on: 24 mai 2024
 *      Author: denis
 */

#ifndef LIVRETA_HPP_
#define LIVRETA_HPP_

#include <iostream>
#include <cmath> // pour std::pow

#include "compte.hpp"

class CompteLivretA : public Compte
{
private:
	double taux; // Ce serait mieux en statique => initialisation dans .cpp

public:
	CompteLivretA()
		: Compte()
	{
		taux = 3;
	}

	double interet()
	{
		return credit * (taux / 100);
		//return credit * std::pow(taux / 100, 1/12);
	}

	void update()
	{
		credit += interet();
	}

	void affiche()
	{
		std::cout << "LivretA n°" << ident
				<< " avec un credit de " << credit << std::endl;
	}
};



#endif /* LIVRETA_HPP_ */
