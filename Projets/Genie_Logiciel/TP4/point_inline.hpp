// Remplace avantageusement les "include guard" classiques à base de #ifnded #define #endif
#pragma once

#include <cstddef> // Pour std::size_t, à remplacer par (unsigned) int si vous préférez
#include <cmath>   // Pour la racine carrée std::sqrt
#include <ostream> // Pour la surcharge de l'opérateur <<

// Point dans R^N
template <typename T, int N> // <class T>
class Point
{
private:
    T data[N];

public:
    // Constructeur par défaut
    Point()
    {
        for (std::size_t i = 0; i < size(); ++i)
            data[i] = 0;
    }

    // Dimension du vecteur
    std::size_t size()
    {
        return N;
    }

    // Opérateur [] permettant de lire et écrire les coordonnées du Point,
    // grâce au fait qu'il retourne la valeur par référence mutable.
    T& operator[] (std::size_t i)
    {
        return data[i];
    }

    // Norme l2 du vecteur
    T norme()
    {
        T result = 0;
        for (std::size_t i = 0; i < size(); ++i)
            result += data[i] * data[i];
        return std::sqrt(result);
    }
};

template <typename T> // ou <class T>
class Point<T, 1> // la partie <T, 1> indique qu'on est entrain de spécialiser une classe générique définie avant
{
private:
    T data[1];

public:
    // Constructeur par défaut
    Point()
    {
        for (std::size_t i = 0; i < size(); ++i)
            data[i] = 0;
    }

    // Dimension du vecteur
    std::size_t size()
    {
        return 1;
    }

    // Opérateur [] permettant de lire et écrire les coordonnées du Point,
    // grâce au fait qu'il retourne la valeur par référence mutable.
    T& operator[] (std::size_t i)
    {
        return data[i];
    }

    // Norme l2 du vecteur
    T norme()
    {
    	//std::cout << "Dimension 1" << std::endl;
    	return std::abs(data[0]);
    }
};

// Affichage d'un Point
// (fonctionne quelque soit le type et la dimension, donc pas besoin de le redéfinir en dimension 1)
template <typename T, int N>
std::ostream& operator<< (std::ostream& out, Point<T, N> & pt)
{
    out << "Point(";
    for (std::size_t i = 0; i < pt.size(); ++i)
        out << pt[i] << ((i < pt.size() - 1) ? "," : "");
    out << ")";
    return out;
}

