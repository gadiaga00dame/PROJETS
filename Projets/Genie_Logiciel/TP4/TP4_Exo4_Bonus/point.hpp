// Remplace avantageusement les "include guard" classiques à base de #ifnded #define #endif
#pragma once

#include <cstddef> // Pour std::size_t, à remplacer par (unsigned) int si vous préférez
#include <cmath>   // Pour la racine carrée std::sqrt
#include <ostream> // Pour la surcharge de l'opérateur <<

// Point dans T^N où T est un type en paramètre template
template <typename T, std::size_t N>
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

// Affichage d'un Point
template <typename T, std::size_t N>
std::ostream& operator<< (std::ostream& out, Point<T, N>& pt)
{
    out << "Point(";
    for (std::size_t i = 0; i < pt.size(); ++i)
        out << pt[i] << ((i < pt.size() - 1) ? "," : "");
    out << ")";
    return out;
}