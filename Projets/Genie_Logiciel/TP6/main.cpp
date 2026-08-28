#include <iostream>

#include "vertebre.hpp"
#include "oiseau.hpp"
#include "felin.hpp"

#include <vector>

void affiche_enclos(Vertebre & v)
{
	std::cout << "Dans l'enclos :";
	v.affiche();
}

class Rongeur : public Vertebre
{
public:
	Rongeur()
		: Vertebre(4, "poils")
	{
	}

	void affiche() {}
};

int main()
{
    std::cout << "Test Oiseau:" << std::endl;
    Oiseau oiseau(4);
    oiseau.affiche();
    std::cout << std::endl;

    std::cout << "Test Felin:" << std::endl;
    Felin felin("tacheté");
    felin.affiche();
    std::cout << std::endl;

    affiche_enclos(oiseau);
    affiche_enclos(felin);

    std::vector<Vertebre*> zoo;

    // utilisateur veut ajouter un oiseau
    zoo.push_back(new Oiseau(2));

    // utilisateur veut ajouter un felin
    zoo.push_back(new Felin("tacheté"));

    // utilisatuer veut ajouter un oiseau
    zoo.push_back(new Oiseau(0));

    std::cout << "Inventaire du zoo :" << std::endl;
    for (std::size_t i = 0; i < zoo.size(); ++i)
    	//(*zoo[i]).affiche();
    	zoo[i]->affiche();

    std::cout << "Fin code:" << std::endl;

    for (std::size_t i = 0; i < zoo.size(); ++i)
    	delete zoo[i];

    //Vertebre v(3, "piquants");

    Rongeur r;
    r.affiche();

    return 0;
}
