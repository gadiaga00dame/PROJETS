/*
 * main.cpp
 *
 *  Created on: 15 avr. 2024
 *      Author: denis
 */
#include <iostream>
#include <cmath> // Pour la fonction puissance std::pow

//#include "point_inline.hpp"
#include "point_outofline.hpp"

/* Version non générique d'une fonction
double incremente(double x)
{
	return x + 1;
}
*/

// Version générique de la même fonction
template <class T>
T incremente(T x)
{
	return x + 1;
}


int main()
{
	int n = 1;
	std::cout << incremente(n) << std::endl; // Le paramètre template est déduit de l'argument (pour les fonctions seulement)
	std::cout << incremente<int>(n) << std::endl; // Le paramètre template est spécifié explicitement

    // Point placé à l'origine par défaut
    Point<float, 1> pt;
    std::cout << "pt = " << pt << std::endl;
    std::cout << "||pt|| = " << pt.norme() << std::endl;
    std::cout << std::endl;

    // Remplissage générique du point (pour faciliter le boulot)
    for (std::size_t i = 0; i < pt.size(); ++i)
        pt[i] = std::pow(-1, i) * (i + 1);

    std::cout << "pt = " << pt << std::endl;
    std::cout << "||pt|| = " << pt.norme() << std::endl;
    std::cout << std::endl;

    // Quelques informations sur ce point
    std::cout
        << "pt est de dimension " << pt.size()
        << " et occupe " << sizeof(pt) << " octets en mémoire."
        << std::endl;

    //Point<float> pt2;
    return 0;
}



