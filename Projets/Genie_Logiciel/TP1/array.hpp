#ifndef HEADER_ARRAY
#define HEADER_ARRAY
// Les deux lignes au-dessus permettent d'éviter l'inclusion multiple de ce fichier
// On peut aussi simplement utiliser
// #pragma once
// au début du fichier seulement

#include <cstddef> // Pour std::size_t

class Array
{
	std::size_t n; // Privé
	double* data;

public:
	Array(std::size_t N = 0);
	~Array();
	std::size_t size();
	double get(std::size_t i);
	void set(std::size_t i, double v);
};

#endif
