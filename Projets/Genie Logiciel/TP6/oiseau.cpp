#include <iostream>

#include "oiseau.hpp"

Oiseau::Oiseau(unsigned int nb_oeufs)
    : Vertebre(2, "plumes")
{
    oeufs = nb_oeufs;
    std::cout << "Constructeur Oiseau" << std::endl;
}

Oiseau::~Oiseau()
{
    std::cout << "Destructeur Oiseau" << std::endl;
}

void Oiseau::affiche()
{
    std::cout << "Oiseau avec " << oeufs << " oeufs, qui est un ";
    Vertebre::affiche();
}

unsigned int Oiseau::get_oeufs()
{
    return oeufs;
}
