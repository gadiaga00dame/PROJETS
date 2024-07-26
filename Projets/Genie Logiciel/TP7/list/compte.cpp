#include "compte.hpp"

// L'attribut statique doit être initialisé dans le fichier .cpp
int Compte::compteur = 0;

Compte::Compte()
{
    ident = ++compteur;
    credit = 0.;
}

Compte::~Compte()
{
}

void Compte::affiche()
{
}

int Compte::getIdent()
{
    return ident;
}

void Compte::depot(double montant)
{
    credit += montant;
}

void Compte::retrait(double montant)
{
    credit -= montant;
}

double Compte::solde()
{
    return credit;
}

void Compte::update()
{
}

CompteException::CompteException(int ident, std::string message) throw()
    : ident(ident)
    , message(message)
{
    what_str = "Compte n°" + std::to_string(ident) + " : " + message;
}

const char* CompteException::what() const throw()
{
    return what_str.c_str();
}