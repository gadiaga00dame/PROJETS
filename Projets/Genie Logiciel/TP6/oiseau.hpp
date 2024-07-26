#pragma once

#include "vertebre.hpp"

class Oiseau : public Vertebre
{
protected:
    unsigned int oeufs;

public:
    Oiseau(unsigned int nb_oeufs);
    ~Oiseau();
    void affiche();
    unsigned int get_oeufs();
};