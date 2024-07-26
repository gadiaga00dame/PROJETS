/*
 * main.cpp
 *
 *  Created on: 17 avr. 2024
 *      Author: denis
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // pour std::find et std::find_if

/*
Remarque sur les différences entre `++it` et `it++`:

`it++` est équivalent au code suivant :
it2 = it;
it = it + 1;
return it2; // On retourne l'ancienne valeur => copie nécessaire

`++it` est équivalent au code suivant :
it = it + 1;
return it; // On retourne la valeur incrémentée => aucune copie nécessaire

Pour éviter cette copie inutile (même si c'est en général indolore),
il est conseillé d'utiliser `++it` plutôt que `it++`.
*/

void affiche(std::list<double> & c)
{
	for (std::list<double>::iterator it = c.begin();
			it != c.end() ; ++it)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}

void affiche(std::vector<int> & c)
{
	for (std::vector<int>::iterator it = c.begin();
			it != c.end() ; ++it)
		std::cout << (*it) << ",";
	std::cout << std::endl;
}

// passage du conteneur par référence pour que sa modification soit répercutée dans la fonction appelante!
void efface(std::list<double> & l, double v)
{
	std::list<double>::iterator it = std::find(l.begin(), l.end(), v);
	// si std::find ne trouve pas la valeur v, cela renvoie l'itérateur de fin, ici l.end()
	// il faut donc tester que l'itérateur renvoyé est bien différent de la fin
	// avant d'effacer l'élément
	if (it != l.end())
		l.erase(it);
}

void efface(std::vector<int> & l, int v)
{
	std::vector<int>::iterator it = std::find(l.begin(), l.end(), v);
	// Syntaxe alternative en utilisant auto pour que le compilateur déduise le type de l'itérateur :
	// auto it = std::find(l.begin(), l.end(), v);
	if (it != l.end())
		l.erase(it);
}

// Exo 1 Bonus 1 (version non générique)
bool est_pair(int value)
{
    return value % 2 == 0;
}

// Exo 1 Bonus 1 (pour vector<int> uniquement)
void efface_pairs(std::vector<int> & v)
{
    // Comme on doit supprimer **tous** les nombres pairs
    // on doit réitérer la recherche/suppression jusqu'à
    // ne plus en trouver.
    while (true)
    {
        auto it = std::find_if(v.begin(), v.end(), est_pair);
        if (it == v.end())
            break; // On arrête la boucle si aucun nombre pair n'est trouvé
        v.erase(it);
    }
}

// Exo 1 Bonus 2
void efface_pairs_it(std::vector<int> & v)
{
    /**
     * Le résultat va être un effacement partiel des nombres pairs (si on est chanceux)
     * ou plus probablement une erreur à l'exécution de type
     * "Stack Overflow" (dépassement de pile) due par exemple à une boucle infinie.
     *
     * Le problème ici est que, après effacement d'un élément, l'itérateur `it`
     * n'est plus valide (c'est d'ailleurs indiqué dans la documentation).
     * Ça aurait été le même problème avec des indices : quand on efface l'élément courant,
     * l'indice que l'on a utilisé se réfère maintenant à l'élément suivant donc quand
     * l'incrémente, on loupe un élément (et potentiellement la fin du vecteur).
    */
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (est_pair(*it))
            v.erase(it);
    }
}


// Première version générique de l'affichage d'une liste
template <typename T>
void affiche_list(std::list<T> & c)
{
	// typename est nécessaire pour dire au compilateur que std::list<T>::iterator
	// est bien un type et non le nom d'une variable (T n'est pas forcément connu
	// à la première lecture du code par le compilateur)
	for (typename std::list<T>::iterator it = c.begin();
			it != c.end() ; ++it)
		std::cout << (*it) << " ";
	std::cout << std::endl;
}

int main()
{
	std::cout << "Introduction:" << std::endl;
	// Transition depuis la boucle classique vers la syntaxe "type itérateur"
	double data[10]; // Étant donné data qui pointe vers (le début de) 10 valeurs doubles

	// Voici la boucle standard utilisée jusque là, basée sur l'indice
	// Celle-ci n'est utilisable que si on est capable rapidement d'accéder à n'importe quel élément
	for (std::size_t i = 0; i < 10; ++i)
		std::cout << data[i] << ", ";
	std::cout << std::endl;

	// On peut réécrire la boucle différemment en parcourant le conteneur de proche en proche
	// et en n'ayant moins de contrainte sur le conteneur. En effet, il faut juste :
	// 1) connaître le pointeur vers le début (ici data)
	// 2) connaître le pointeur vers l'élément (fictif) qui est après la fin (ici data + 10)
	// 3) savoir comparer deux pointeurs (!=) et savoir passer à l'élément suivant (++it ou it++)
	for (double* it = data; it != data + 10 ; ++it)
		std::cout << (*it) << ", ";
	std::cout << std::endl;

	// Pour un conteneur v, si on remplace data par v.begin() et data + 10 par v.end(),
	// on obtient un parcours similaire en utilisant des itérateurs
	// et qui est compatible avec une plus large classe de conteneurs (vector, list, set, ...).
	std::cout << std::endl;

	std::cout << "Exercice 1:" << std::endl;
	std::list<double> l; // Syntaxe alternative : std::vector<double> a = {2.5, 1.8, 2.2, 0.15};
	l.push_back(2.5); // la méthode push_back ajoute un élément à la fin du conteneur
	l.push_back(1.8);
	l.push_back(2.2);
	l.push_back(0.15);

	std::vector<int> v; // Idem : std::vector<int> v = {10, 8, 15, 28};
	v.push_back(10);
	v.push_back(8);
	v.push_back(15);
	v.push_back(28);

	std::cout << "l = ";
	affiche(l);

	std::cout << "v = ";
	affiche(v);

	std::cout << "Effacement de 1.8 dans l:" << std::endl;
	efface(l, 1.8);
	std::cout << "l = ";
	affiche(l);

	// Le conteneur doit resté inchangé si on tente d'effacer un élément qui n'y est pas présent
	std::cout << "Effacement de 2.0 dans l:" << std::endl;
	efface(l, 2.0);
	std::cout << "l = ";
	affiche(l);

	std::cout << "Effacement de 15 dans v:" << std::endl;
	efface(v, 15);
	std::cout << "v = ";
	affiche(v);

	// Idem
	std::cout << "Effacement de 18 dans v:" << std::endl;
	efface(v, 18);
	std::cout << "v = ";
	affiche(v);
	std::cout << std::endl;

	std::cout << "Bonus de l'exercice 1:" << std::endl;

	v.push_back(13);
	v.push_back(7);
	v.push_back(4);
	std::cout << "v = ";
	affiche(v);

	std::cout << "Effacement de tous les pairs dans v:" << std::endl;
	efface_pairs(v);
	std::cout << "v = ";
	affiche(v);
	std::cout << std::endl;

	// Pour tester le Bonus 2 (le code est commenté car cela fait planter le programme)
	/*
	std::cout << "Bonus (bis) de l'exercice 1:" << std::endl;
	v.push_back(4);
	v.push_back(8);
	v.push_back(17);
	v.push_back(23);
	v.push_back(2);
	std::cout << "v = ";
	affiche(v);
	std::cout << "Effacement de tous les pairs dans v:" << std::endl;
	efface_pairs_it(v);
	std::cout << "v = ";
	affiche(v);
	std::cout << std::endl;
	*/

	return 0;
}




