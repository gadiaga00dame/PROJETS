#pragma once

#include <string>

#include "vertebre.hpp"

class Felin : public Vertebre
{
protected:
    std::string couleur;

public:
    Felin(std::string couleur_pelage);
    ~Felin();
    void affiche();
    std::string get_couleur();
};