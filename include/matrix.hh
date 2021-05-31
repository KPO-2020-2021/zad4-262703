#pragma once


#include "Vector3D.hh"
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "initializer_list"

template<typename TYP, int SIZE>
class Matrix {

private:
    TYP Matr[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(TYP [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    ~Matrix();
    
    Vector3D operator * (Vector3D tmp);           // Operator mnożenia przez wektor

    Matrix<TYP, SIZE> operator + (Matrix<TYP,SIZE> tmp);

    Matrix<TYP, SIZE> operator * (Matrix<TYP,SIZE> tmp);

    TYP  &operator () (unsigned int row, unsigned int column);
    
    const TYP &operator () (unsigned int row, unsigned int column) const;

    Matrix<TYP, SIZE> ObrKatX(double kat);

    Matrix<TYP, SIZE> ObrKatY(double kat);

    Matrix<TYP, SIZE> ObrKatZ(double kat);

    void Gauss();
};

template<typename TYP, int SIZE>
std::istream &operator>>(std::istream &in, Matrix<TYP, SIZE> &mat);

template<typename TYP, int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix<TYP, SIZE> const &mat);