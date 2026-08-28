/*
 * vecteur.cpp
 *
 *  Created on: 20 mars 2024
 *      Author: denis
 */

#include "vecteur.hpp"

#include <iostream>
/*
Vecteur::Vecteur(double x, double y, double z)
	: data{x, y, z}
{
}
*/

Vecteur::Vecteur(unsigned int n)
{
	data = new double[n];
	size = n;
	// Initialisation à 0 ?
}

Vecteur::Vecteur(unsigned int n, double (*fn)(unsigned int i))
{
	data = new double[n];
	size = n;
	for (unsigned int i = 0; i < n; ++i)
		data[i] = fn(i);
}

/*
Vecteur::Vecteur(unsigned int n, double (*fn)(unsigned int i))
	: Vecteur(n)
{
	for (unsigned int i = 0; i < n; ++i)
		data[i] = fn(i);
}
*/

Vecteur::Vecteur(Vecteur const& v)
	// : Vecteur(v.size)
{
	data = new double[v.size];
	size = v.size;
	for (unsigned int i = 0; i < size; ++i)
		data[i] = v.data[i];
}

Vecteur& Vecteur::operator= (Vecteur const& other)
{
	if (this != &other)
	{
		delete [] data;
		data = new double[other.size];
		size = other.size;
		for (unsigned int i = 0; i < size; ++i)
			data[i] = other.data[i];
	}

	return *this;
}

/*
Vecteur& Vecteur::operator= (Vecteur const& other)
{
	double* new_data = new double[other.size];

	size = other.size;
	for (unsigned int i = 0; i < size; ++i)
		new_data[i] = other.data[i];

	delete [] data;
	data = new_data;

	return *this;
}
*/

/*
// "Copy and swap" idiom
Vecteur& Vecteur::operator= (Vecteur other)
{
	using std::swap; // a, b = b, a
	// T c = a; a = b; b = c;
	swap(data, other.data);
	swap(size, other.size);

	return *this;
}
*/

Vecteur::~Vecteur()
{
	delete [] data;
	//std::cout << "Destructeur Vecteur" << std::endl;
}

void Vecteur::affiche()
{
	std::cout << "Vecteur(";
	for (unsigned int i = 0; i < size; ++i)
		std::cout << data[i] << ",";
	std::cout << ")" << std::endl;
}

void Vecteur::echelle(double factor)
{
	for (unsigned int i = 0; i < size; ++i)
		data[i] *= factor;
}

double produit(Vecteur const& u, Vecteur const& v)
{
	//assert( u.size == v.size );
	double result = 0;
	for (std::size_t i = 0; i < u.size; ++i)
		result += u.data[i] * v.data[i];
	return result;
}

