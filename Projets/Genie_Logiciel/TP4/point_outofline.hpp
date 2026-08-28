// Remplace avantageusement les "include guard" classiques à base de #ifnded #define #endif
#pragma once

#include <cstddef> // Pour std::size_t, à remplacer par (unsigned) int si vous préférez
#include <cmath>   // Pour la racine carrée std::sqrt
#include <ostream> // Pour la surcharge de l'opérateur <<

// Point dans R^N
template <typename T, int N>
class Point
{
    private:
    T data[N];

public:
    // Constructeur par défaut
    Point();

    // Dimension du vecteur
    std::size_t size();

    // Opérateur [] permettant de lire et écrire les coordonnées du Point,
    // grâce au fait qu'il retourne la valeur par référence mutable.
    T& operator[] (std::size_t i);

    // Norme l2 du vecteur
    T norme();
};

// Point dans T¹ où T est un type en paramètre template
template <typename T>
class Point<T, 1>
{
private:
    T data[1];

public:
    // Constructeur par défaut
    Point();

    // Dimension du vecteur
    std::size_t size();

    // Opérateur [] permettant de lire et écrire les coordonnées du Point,
    // grâce au fait qu'il retourne la valeur par référence mutable.
    T& operator[] (std::size_t i);

    // Norme l2 du vecteur
    T norme();
};

// Affichage d'un Point
template <typename T, int N>
std::ostream& operator<< (std::ostream& out, Point<T, N>& pt);


///////////////////////////////////////////////////////////////////////////////
// Définitions
template <typename T, int N>
Point<T, N>::Point()
{
    for (std::size_t i = 0; i < size(); ++i)
        data[i] = 0;
}

template <typename T, int N>
std::size_t Point<T, N>::size()
{
    return N;
}

template <typename T, int N>
T& Point<T, N>::operator[] (std::size_t i)
{
    return data[i];
}

template <typename T, int N>
T Point<T, N>::norme()
{
    T result = 0;
    for (std::size_t i = 0; i < size(); ++i)
        result += data[i] * data[i];
    return std::sqrt(result);
}

template <typename T>
Point<T, 1>::Point()
{
    for (std::size_t i = 0; i < size(); ++i)
        data[i] = 0;
}

template <typename T>
std::size_t Point<T, 1>::size()
{
    return 1;
}

template <typename T>
T& Point<T, 1>::operator[] (std::size_t i)
{
    return data[i];
}

template <typename T>
T Point<T, 1>::norme()
{
	return std::abs(data[0]);
}

template <typename T, int N>
std::ostream& operator<< (std::ostream& out, Point<T, N>& pt)
{
    out << "Point(";
    for (std::size_t i = 0; i < pt.size(); ++i)
        out << pt[i] << ((i < pt.size() - 1) ? "," : "");
    out << ")";
    return out;
}
