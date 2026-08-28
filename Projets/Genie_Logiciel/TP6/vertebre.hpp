#pragma once

#include <string>

class Vertebre
{
protected:
    unsigned int pattes;
    std::string pelage;

public:
    Vertebre(int nb_pattes, std::string const& type_pelage);
    virtual ~Vertebre();
    virtual void affiche() = 0; // => Vertebre abstraite
    unsigned int get_pattes();
    std::string const& get_pelage();
};
