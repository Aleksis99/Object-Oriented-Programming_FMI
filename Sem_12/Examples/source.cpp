#include <iostream>
#include <fstream>
#include "Garage.h"

const size_t MAX_SIZE = 100;

struct A
{
    A(int a) : a(a) 
    {
        std::cout << "A" << std::endl;
    };
    int a;
};


struct B : virtual A
{
    B(int a, int b) : A(a),  b(b) 
    {
        std::cout << "B" << std::endl;
    };
    int b;
};


struct C : virtual A
{
    C(int a, int c) : A(a), c(c) 
    {
        std::cout << "C" << std::endl;
    };
    int c;
};

struct D : B, C
{
    D(int a, int b, int c, int d) : A(a), B(a, b), C(a, c), d(d)
    {
        std::cout << "D" << std::endl;
    };

    void foo()
    {
        C::a++;
    }

    int d;
};

int main()
{
    /*D d(1, 2, 3, 4);
    std::cout << sizeof(D) << std::endl;

    d.a++;

    std::cout << d.a;
    return 0;*/

    Car c("123", 4, true);
    MiniBus m("123", 300, 4, true, 1);

    Garage g;
    g.addVehicle(&c);
    g.addVehicle(&m);

    std::cout << g.getTotalParkingPrice();
}