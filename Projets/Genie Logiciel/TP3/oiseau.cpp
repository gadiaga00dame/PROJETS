/*
 * oiseau.cpp
 *
 *  Created on: 3 avr. 2024
 *      Author: denis
 */

#include "oiseau.hpp"

#include <iostream>

Oiseau::Oiseau(int nb_oeufs)
	: Vertebre(2, "plumes") // Initialisation de la classe mère Vertebre
	, Volante(2) // Initialisation de la 2ème classe mère Volante avec 2 ailes
{
	std::cout << "Constructeur Oiseau" << std::endl;
	oeufs = nb_oeufs;
}

Oiseau::~Oiseau()
{
	std::cout << "Destructeur Oiseau" << std::endl;
}

void Oiseau::affiche()
{
	std::cout << "Oiseau avec " << oeufs << "oeufs, qui est un ";
	// Plusieurs versions:
	// 1) On spécifie la classe par laquelle passer pour accéder à la méthode affiche
	Vertebre::affiche();

	// 2) Idem, le this étant implicite dans la version au-dessus
	//this->Vertebre::affiche();

	// 3) this est un pointeur sur Oiseau (Oiseau*).
	// On le convertit en Vertebre* et ainsi c'est la méthode affiche de Vertebre qu'on appelle
	//((Vertebre*) this)->affiche();

	// 4) La conversion au-dessus est dans le style C et n'est pas toujours très recommandé
	// car on peut convertir de cette manière des bananes en des pommes.
	// En C++, il est recommandé d'utiliser un parmi trois fonctions dédiées en fonction de la partée de la conversion
	// static_cast avec le type cible en paramètre template est la fonction la plus sûre
	// (conversion entre types "compatibles")
	//static_cast<Vertebre*>(this)->affiche();

	std::cout << ", et ";
	Volante::affiche();
}

int Oiseau::get_oeufs()
{
	return oeufs;
}

std::ostream& operator<< (std::ostream& out, Oiseau & animal)
{
	out << "Oiseau avec " << animal.get_oeufs() << " oeufs, ";

	/** On doit convertir la référence vers Oiseau vers une référence vers Verterbre
	 * pour que le compilateur comprenne qui faut utiliser la surcharge
	 * operator<< (std::ostream &, Vertebre &)
	 *
	 * Une manière plus moderne de faire cette conversion (évite des conversions "non valides")
	 * est d'utiliser static_cast templaté par le type voulu :
	 * out << "qui est un " << static_cast<Vertebre&>(animal);
	 *
	 * Si l'animal était passé par référence constante,
	 * il faudrait adapter le type cible pour maintenir cette constance :
	 * out << "qui est un " << static_cast<Vertebre const&>(animal);
	 */
	out << "qui est un " << ((Vertebre&) animal);
	out << " et " << ((Volante&) animal);
	return out;
}


