/*
 * volante.hpp
 *
 *  Created on: 15 avr. 2024
 *      Author: denis
 */

#ifndef VOLANTE_HPP_
#define VOLANTE_HPP_

#include <iostream> // Pour la surcharge de <<

class Volante
{
protected:
	int ailes;
public:
	Volante(int nb_ailes);
	~Volante();
	int get_ailes();
	void affiche();
};

// Surcharge de l'opérateur << pour un Volante.
// Remarque : pas besoin de mettre cette fonction en amie vu qu'on a accès
// à toutes les informations nécessaires via l'interface publique de Volante
std::ostream& operator<< (std::ostream& out, Volante & animal);

#endif /* VOLANTE_HPP_ */
