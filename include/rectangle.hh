#pragma once

#include "size.hh"
#include "Vector3D.hh"
#include "Macierz3x3.hh"
#include <iostream>
#include <iomanip>

class Rectangle {

private:

    Vector3D rect[WIER];   

public:

    Rectangle();

    Rectangle(Vector3D A, Vector3D B, Vector3D C);

    const Vector3D &operator [] (int index) const;

    Vector3D &operator [] (int index);

    Rectangle Przesuniencie(Vector3D const Vec);

    Rectangle Obrot(Macierz3x3 Obr, int const raz);

    void Dlugosc();
};

std::ostream &operator << (std::ostream &out, Rectangle const &tmp);

