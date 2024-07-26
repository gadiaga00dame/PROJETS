/*
 * matrice.cpp
 *
 *  Created on: 27 mars 2024
 *      Author: denis
 */

#include <iostream>

#include "matrice.hpp"
Matrice::Matrice(
		double a11, double a12, double a13,
		double a21, double a22, double a23,
		double a31, double a32, double a33)
	//: data{{a11, a12, a13}, {a21, a22, a23}, {a31, a32, a33}}
{
	data[0][0] = a11;
	data[0][1] = a12;
	data[0][2] = a13;
	data[1][0] = a21;
	data[1][1] = a22;
	data[1][2] = a23;
	data[2][0] = a31;
	data[2][1] = a32;
	data[2][2] = a33;
}

Matrice::Matrice(Matrice const& other)
{
	for (unsigned int i = 0; i < 3; ++i)
		for (unsigned int j = 0; j < 3; ++j)
			data[i][j] = other.data[i][j];
}

Matrice::~Matrice()
{
	// pas de delete
}

void Matrice::affiche()
{
	std::cout << "["
		<< "[" << data[0][0] << "," << data[0][1] << "," << data[0][2] << "]"
		<< "[" << data[1][0] << "," << data[1][1] << "," << data[1][2] << "]"
		<< "[" << data[2][0] << "," << data[2][1] << "," << data[2][2] << "]"
		<< "]" << std::endl;
}

Vecteur Matrice::produit(Vecteur & v)
{
	// assert(v.size == 3);
	Vecteur w(v.size);
	for (unsigned int i = 0; i < 3; ++i)
	{
		w.data[i] = 0;
		for (unsigned int j = 0; j < 3; ++j)
			w.data[i] += v.data[j] * data[i][j];
	}
	return w;
}


