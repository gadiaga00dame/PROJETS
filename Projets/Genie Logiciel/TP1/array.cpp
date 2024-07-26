#include "array.hpp"

#include <iostream> // Pour std::cout et co.

Array::Array(std::size_t N)
{
    std::cout << "Constructeur Array" << std::endl;
    data = new double[N];
    n = N;
}

Array::~Array()
{
    std::cout << "Destructeur Array" << std::endl;
    delete [] data;
}

std::size_t Array::size()
{
    return n;
}

double Array::get(std::size_t i)
{
    //return this->data[i];
    return data[i];
}

void Array::set(std::size_t i, double v)
{
    data[i] = v;
}


