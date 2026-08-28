/*
 * matrice.hpp
 *
 *  Created on: 27 mars 2024
 *      Author: denis
 */

#ifndef MATRICE_HPP_
#define MATRICE_HPP_

#include "vecteur.hpp"

class Matrice
{
private:
	double data[3][3];
public:
	Matrice(
			double a11 = 0, double a12 = 0, double a13 = 0,
			double a21 = 0, double a22 = 0, double a23 = 0,
			double a31 = 0, double a32 = 0, double a33 = 0);

	Matrice(Matrice const& other);
	~Matrice();
	void affiche();
	Vecteur produit(Vecteur & v);
};



#endif /* MATRICE_HPP_ */
