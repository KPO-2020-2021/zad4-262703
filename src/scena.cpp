#include "scena.hh"

Macierz3x3 Scena::ObrotMac(double const kat, int const Os, int const raz)
{
    Macierz3x3 result;
    if (Os == 0) 
    {
        result.ObrKatX(kat);
    }
    if (Os == 1)
    {
        result.ObrKatY(kat);
    }
    if (Os == 2)
    {
        result.ObrKatZ(kat);
    }
    if (raz == 1)
    {
        Obrot = Obrot + result;
    }
    else 
    {
        Obrot = Obrot * result;
    }
    return Obrot;
} 

Rectangle Scena::ObrotProstopadl()
{
    Prostopadl.Obrot(Obrot, IloscPowt);
    return Prostopadl;
}


