/*
 * oiseau.hpp
 *
 *  Created on: 3 avr. 2024
 *      Author: denis
 */

#ifndef OISEAU_HPP_
#define OISEAU_HPP_

#include "vertebre.hpp"
#include "volante.hpp"

#include <iostream> // Pour la surcharge de <<

// Bien veiller à hériter publiquement de Vertebre
// À tester sans et voir l'erreur qui se produit quand on essaie
// d'accéder à une méthode de Vertebre, par exemple get_pattes
class Oiseau : public Vertebre, public Volante // l'ordre d'inclusion n'importe pas (à notre niveau)
{
protected:
	int oeufs;
public:
	Oiseau(int nb_oeufs);
	~Oiseau();
	void affiche();
	int get_oeufs();
};

// Surcharge de l'opérateur << pour un Oiseau.
// Remarque : pas besoin de mettre cette fonction en amie vu qu'on a accès
// à toutes les informations nécessaires via l'interface publique de Oiseau
std::ostream& operator<< (std::ostream& out, Oiseau & animal);

#endif /* OISEAU_HPP_ */
