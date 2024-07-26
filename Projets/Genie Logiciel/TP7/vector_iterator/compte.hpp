#pragma once

#include <stdexcept>
#include <string>

// Classe de base pour tout compte bancaire
class Compte
{
private:
    static int compteur; // Pour généré un numéro de compte unique

protected:
    int ident; // Numéro de compte unique
    double credit;      // Crédit du compte

public:
    Compte();
    virtual ~Compte();

    int getIdent();

    virtual void affiche() = 0;
    virtual void depot(double montant);
    virtual void retrait(double montant);
    virtual double solde();
    virtual void update();
};

// Exception liée à une opération sur un compte
class CompteException : public std::exception 
{
    // Utilisé pour stocker la chaîne de caractère retournée par what()
    std::string what_str;

public:
    int ident; // Numéro du compte concerné
    std::string message; // Message d'erreur

    // "noexcept" à la place de "throw()" à partir de C++11
    CompteException(int ident, std::string message) throw();
    const char* what() const throw();
};
