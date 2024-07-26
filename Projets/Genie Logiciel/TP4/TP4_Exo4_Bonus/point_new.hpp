#pragma once

template <typename T>
class PointNew
{
private:
    T* data;
    unsigned char N; // On teste avec le plus type d'entier possible, occupe normalement 1 octet (valeurs entre 0 et 255).

public:
    // Constructeur par défaut
    PointNew(unsigned char dim = 0)
    {
        N = dim;
        data = new T[N];
        for (std::size_t i = 0; i < size(); ++i)
            data[i] = 0;
    }

    // Destructeur explicite nécessaire
    ~PointNew()
    {
        delete [] data;
    }


    // Dimension du vecteur
    std::size_t size()
    {
        return N;
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
