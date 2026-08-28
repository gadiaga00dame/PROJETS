/*
 * main.cpp
 *
 *  Created on: 21 févr. 2024
 *      Author: denis
 */

#include <iostream> // Pour std::cout, cin, endl, ...
#include <cmath> // Pour les fonctions mathématiques, std::cos, sin, acos, pow, sqrt, ...

#include "array.hpp"

double f(double x)
{
	return x * x - 3 * x;
}

double F(double x)
{
	return x * x * x / 3 - 3 * x * x / 2;
}

//double quadrature( double (*fn) (double), double a, double b, double* x, double* w, std::size_t n)
double quadrature( double (*fn) (double), double a, double b, Array & x, Array & w , std::size_t n)
{
	double result = 0; // Variable d'accumulation de la somme
    for (std::size_t i = 0; i <= n; ++i) // Somme de 0 à n inclus
    {
    	// x[i] => x.get(i)
        double xi = ((b - a) * x.get(i) + b + a) / 2;
        result += fn(xi) * w.get(i); // Accumulation
    }
    return result * (b - a) / 2;
}

int main()
{
	/*
	double x;
	std::cout << "x = ";
	std::cin >> x;
	double y = f(x);
	std::cout << "f(x) = " << y << std::endl;
	*/

	std::cout << "n = ";
	std::size_t n;
	std::cin >> n;

	//double* x = new double[n + 1]; // on va de 0 à n compris d'où n + 1 éléments
	//double* w = new double[n + 1];
	Array x(n + 1);
	Array w(n + 1);

	using std::cout;
	using std::cin;

	double pi = std::acos(-1);

	for (std::size_t i = 0; i <= n; ++i) // i <= n car on veut aller de 0 à n compris
	{
		// x[i] = v => x.set(i, v)
		// 3 * x[i] => 3 * x.get(i)
		x.set(i, std::cos((2 * i + 1) * pi / (2 * n + 2)));
		w.set(i, pi / (n + 1) * std::sqrt(1 - x.get(i) * x.get(i)));
	}

	double a, b;
	std::cout << "a = "; std::cin >> a;
	std::cout << "b = "; std::cin >> b;

	double value = quadrature(f, a, b, x, w, n); // Il faut compléter quadrature pour que ça fonctionne
	double ref = F(b) - F(a);

	std::cout << "Valeur calculée : " << value << std::endl;
	std::cout << "Valeur exacte : "   << ref   << std::endl;

	// delete

	/*
	Array tableau(100);
	std::cout << "Taille du tableau: " << tableau.size() << std::endl;
	tableau.set(42, -3.14);
	std::cout << "tableau[42] = " << tableau.get(42) << std::endl;
	*/

	return 0;
}






