#pragma once

#include <vector>
template <typename T>
class PointVector
{
private:
    std::vector<T> data;

public:
    // Constructeur par défaut
    PointVector(std::size_t dim = 0)
        : data(dim, 0.)
    {
    }

    // Libération de la mémoire automatique dans le descructeur de std::vector

    // Dimension du vecteur
    std::size_t size()
    {
        return data.size();
    }

    // Occupation mémoire (taille de la classe courante + la mémoire allouée)
    std::size_t mem_usage()
    {
        return sizeof(*this) + size() * sizeof(T);
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
