/*
 * main.cpp
 *
 *  Created on: 20 mars 2024
 *      Author: denis
 */

#include "vecteur.hpp"
#include "matrice.hpp"
#include "puissance.hpp"

#include <iostream>

double fn(unsigned int i)
{
	return i + 1;
}

double fn2(unsigned int i)
{
	return i + 1.5;
}

int main()
{
	Vecteur v(3, fn);
	std::cout << "v = "; v.affiche();
	Vecteur w(v); // Constructeur par copie

	Vecteur z(3); // Constructeur par défaut
	std::cout << "Avant assignation, z = "; z.affiche();
	z = w; // Opérateur d'assignation
	std::cout << "Après assignation, z = "; z.affiche();
	z.echelle(2.5);
	std::cout << "Après mise à l'échelle, z = "; z.affiche();

	std::cout << "(v, z) = " << produit(v, z) << std::endl;

	Matrice m(1, 2, 3, 0, 4, 5, 0, 0, 6);
	m.affiche();

	Vecteur uu = m.produit(v);
	std::cout << "uu = ";
	uu.affiche();

	Matrice A(1, 2, 3, 4, 5, 6, 7, 8, -9);
	Vecteur w0(3, fn2);
	double lambda1 = puissance(A, w0, 1000);
	std::cout << "lambda1 = " << lambda1 << std::endl;

	return 0;
}



