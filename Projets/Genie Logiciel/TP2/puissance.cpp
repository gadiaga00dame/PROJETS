/*
 * puissance.cpp
 *
 *  Created on: 27 mars 2024
 *      Author: denis
 */

#include "puissance.hpp"

#include <cmath> // Pour std::sqrt

double puissance(Matrice & A, Vecteur & v, unsigned int iter)
{
	Vecteur w = v;
	for (unsigned int i = 0; i < iter; ++i)
	{
		w = A.produit(w);
		w.echelle(1. / std::sqrt(produit(w, w))); // On peut éventuellement rajouter un epsilon, genre 1e-16,
			// au dénominateur pour "éviter" les divisions par 0...
	}

	Vecteur Aw = A.produit(w);
	return produit(w, Aw) / produit(w, w);
}




