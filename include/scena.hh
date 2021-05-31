#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include <iomanip>
#include "size.hh"
#include "rectangle.hh"

struct Scena{

    Rectangle Prostopadl;

    Macierz3x3 Obrot;

    int IloscPowt;

    Macierz3x3 ObrotMac(double const kat, int const Os, int const raz);

    Rectangle ObrotProstopadl();

    

};

#endif