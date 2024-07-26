/*
 * vecteur.hpp
 *
 *  Created on: 20 mars 2024
 *      Author: denis
 */

// #pragma once

#ifndef VECTEUR_HPP_
#define VECTEUR_HPP_

#include <cstddef>

class Vecteur
{
private:
	//double data[3];
	double* data;
	unsigned int size;

public:
	//Vecteur(double x = 0, double y = 0, double z = 0);
	Vecteur(unsigned int n = 0);
	Vecteur(unsigned int n, double (*fn)(unsigned int));

	Vecteur(Vecteur const& other);
	~Vecteur();
	void affiche();
	// friend std::ostream & operator<< (std::ostream & out, Vecteur const& v);
	Vecteur & operator= (Vecteur const& v);
	void echelle(double factor);
	friend double produit(Vecteur const& u, Vecteur const& v);
	friend class Matrice; // Amitié de classe
};


#endif /* VECTEUR_HPP_ */
