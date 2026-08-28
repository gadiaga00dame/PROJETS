#include <iostream>
#include <cmath> // Pour la fonction puissance std::pow

#include "point.hpp"
#include "point_new.hpp"
#include "point_vector.hpp"

// On teste avec plusieurs dimensions pour un type T donné
template <typename T>
void test_points()
{
    std::cout << "class Point:" << std::endl;
    Point<T, 1> pt1;
    std::cout << "\tdim 1: sizeof(pt) = " << sizeof(pt1) << std::endl;
    Point<T, 2> pt2;
    std::cout << "\tdim 2: sizeof(pt) = " << sizeof(pt2) << std::endl;
    Point<T, 3> pt3;
    std::cout << "\tdim 3: sizeof(pt) = " << sizeof(pt3) << std::endl;
    Point<T, 4> pt4;
    std::cout << "\tdim 4: sizeof(pt) = " << sizeof(pt4) << std::endl;
    std::cout << std::endl;

    std::cout << "class PointNew:" << std::endl;
    for (unsigned char i = 1; i <= 4; ++i)
    {
        PointNew<T> pt_new(i);
        std::cout << "\tdim " << int(i) << ": sizeof(pt_new) = " << pt_new.mem_usage() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "class PointVector:" << std::endl;
    for (unsigned char i = 1; i <= 4; ++i)
    {
        PointVector<T> pt_vec(i);
        std::cout << "\tdim " << int(i) << ": sizeof(pt_vec) = " << pt_vec.mem_usage() << std::endl;
    }
    std::cout << std::endl;


}

int main()
{
    // On teste avec plusieurs types

    std::cout << "#############" << std::endl;
    std::cout << "# Type float:" << std::endl;
    std::cout << std::endl;
    test_points<float>();

    std::cout << "##############" << std::endl;
    std::cout << "# Type double:" << std::endl;
    std::cout << std::endl;
    test_points<double>();
    
    std::cout << "##################" << std::endl;
    std::cout << "# Type long double:" << std::endl;
    std::cout << std::endl;
    test_points<long double>();
    
    return 0;
}
