#include <iostream>
#include <vector>
#include <string>

#include "compte.hpp"
#include "livreta.hpp"

// Affiche la liste des comptes
void affiche_comptes(std::vector<Compte*> & comptes)
{
    std::cout << "Liste des comptes:" << std::endl;
    for (auto it = comptes.begin(); it != comptes.end(); ++it)
        (*it)->affiche(); // Il faut déréférencer l'itérateur, puis le pointeur
    std::cout << std::endl;
}

// Met à jour le solde de tous les comptes
void update_comptes(std::vector<Compte*> & comptes)
{
    for (auto it = comptes.begin(); it != comptes.end(); ++it)
        (*it)->update();
}

// Libère la mémoire allouée pour les comptes
void delete_comptes(std::vector<Compte*> & comptes)
{
    for (auto it = comptes.begin(); it != comptes.end(); ++it)
        delete *it;
}

// Ouverture d'un nouveau compte de type spécifié
void ouverture_compte(std::vector<Compte*> & comptes, std::string type)
{
    // TODO (voir TP6)
	if (type == "livreta")
	{
		comptes.push_back(new CompteLivretA());
	}
	else
		std::cout << "Compte de type " << type
		<< " non existant!" << std::endl;
}

std::size_t trouve_compte(std::vector<Compte*> & comptes, int ident)
{
	for (int idx = 0; idx < comptes.size(); ++idx)
		if (comptes[idx]->getIdent() == ident)
			return idx;
	return comptes.size();
}

void depot(std::vector<Compte*> & comptes, int ident, double montant)
{
	std::size_t idx = trouve_compte(comptes, ident);
	if (idx >= comptes.size())
	{
		std::cout << "Comptes n°" << ident
				<< " non trouvé" << std::endl;
		return;
	}

	comptes[idx]->depot(montant);
}

int main()
{
    // Inventaire des comptes
    std::vector<Compte*> comptes;

    // Équivalent à un "while (true)" mais permet de prendre en compte
    // quand l'entrée clavier est "fermée"
    while (! std::cin.bad())
    {
        // Permet d'ignorer les erreurs de conversion précédentes
        // (par exemple si on rentre un texte au lieu d'un nombre)
        std::cin.clear();

        // Demande d'une action
        std::string action;
        std::cout << std::endl << "Action (ouverture, consultation, depot, update, quitter) ? ";
        std::cin >> action;

        // Traitement de l'action
        if (action == "ouverture")
        {
            std::string type;
            std::cout << "Type de compte (courant ou livreta) ? ";
            std::cin >> type;
            ouverture_compte(comptes, type);
        }      
        else if (action == "consultation")
        {
            affiche_comptes(comptes);
        }
        else if (action == "update")
        {
            update_comptes(comptes);
        }
        else if (action == "depot")
        {
        	int ident;
        	std::cout << "Numéro ? ";
        	std::cin >> ident;
        	double montant;
        	std::cout << "Montant ? ";
        	std::cin >> montant;
        	depot(comptes, ident, montant);
        }
        else if (action == "quitter")
        {
            break;
        }
        else
        {
            std::cout << "Action non implémentée : " << action << std::endl;
            continue;
        }
    }

    // Libération de la mémoire allouée pour chaque compte
    delete_comptes(comptes);

    return 0;
}
