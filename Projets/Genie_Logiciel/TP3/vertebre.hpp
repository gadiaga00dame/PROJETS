/*
 * vertebre.hpp
 *
 *  Created on: 3 avr. 2024
 *      Author: denis
 */

#ifndef VERTEBRE_HPP_
#define VERTEBRE_HPP_

#include <string>
#include <iostream> // Pour la surcharge de <<

class Vertebre
{
	// protected ou private. Vu l'énoncé de l'exercice,
	// les classes dérivées n'ont à priori pas besoin d'accéder à ces attributs.
	// Ce serait donc plus logique de les mettre en privé.
protected:
	int pattes;
	std::string pelage;

public:
	Vertebre(int nb_pattes, std::string type_pelage);
	~Vertebre();
	void affiche();
	int get_pattes();
	std::string get_pelage();
};

// Surcharge de l'opérateur << pour un Vertebre.
// Remarque : pas besoin de mettre cette fonction en amie vu qu'on a accès
// à toutes les informations nécessaires via l'interface publique de Vertebre
std::ostream& operator<< (std::ostream& out, Vertebre & animal);

#endif /* VERTEBRE_HPP_ */
