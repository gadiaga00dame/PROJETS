#include <iostream>

#include "felin.hpp"

Felin::Felin(std::string couleur_pelage)
    : Vertebre(4, "poils")
{
    couleur = couleur_pelage;
    std::cout << "Constructeur Felin" << std::endl;
}

Felin::~Felin()
{
    std::cout << "Destructeur Felin" << std::endl;
}

void Felin::affiche()
{
    std::cout << "Felin de pelage " << couleur << ", qui est un ";
    Vertebre::affiche();
}

std::string Felin::get_couleur()
{
    return couleur;
}
