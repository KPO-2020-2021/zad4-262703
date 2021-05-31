// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>


#include "exampleConfig.h"
#include "example.h"
#include "Vector3D.hh"
#include "Macierz3x3.hh"
#include "rectangle.hh"
#include "scena.hh"
#include "../include/lacze_do_gnuplota.hh"


void PrzykladZapisuWspolrzednychDoStrumienia(std::ostream& StrmWy, Rectangle tmpR2)
{
for (int i = 0; i < WIER;  ++i){
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[i][0] 
       << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[i][1]
       << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[i][2] << std::endl;
}
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[0][0] 
       << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[0][1]
       << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[0][2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[1][0] 
       << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[1][1]
       << std::setw(16) << std::fixed << std::setprecision(10) << tmpR2[1][2] << std::endl;
 // Jeszcze raz zapisujemy pierwszy punkt,
 // aby gnuplot narysowal zamkniętą linię.
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Rectangle  tmpR2)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, tmpR2);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

void Menu()
{
  std::cout << "o - obrot prostopadlosciana o zadany kat" << std::endl;
  std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
  std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
  std::cout << "p - przesuniecie prostopadlosciana o zadany wektor" << std::endl;
  std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
  std::cout << "m - wyswietl menu" << std::endl;
  std::cout << "d - demonstracja prostokata w gnuplocie " << std::endl;
  std::cout << "b - dlugosc bokow" << std::endl;
  std::cout << "k - koniec dzialania programu" << std::endl << std::endl;
}

Scena MacObrZapis(Scena Prost)
{
  int kat, raz = 0;
  char b = ' ';
  int Os;
  while (b != '.')
  {
    std::cin >> b;
    switch (b)
    {
      case 'x':
        std::cin >> kat;
        Os = 0;
        raz++;
        Prost.Obrot = Prost.ObrotMac(kat, Os, raz);
        break;
      case 'y':
        std::cin >> kat;
        Os = 1;
        raz++;
        Prost.Obrot = Prost.ObrotMac(kat, Os, raz);
        break;
      case 'z':
        std::cin >> kat;
        Os = 2;
        raz++;
        Prost.Obrot = Prost.ObrotMac(kat, Os, raz);
        break;
      case '.':
        break;
      default:
        std::cout << ":( Bledne oznaczenie osi. Dopuszczalne znaki to: x y z ." << std::endl;
        std::cout << ":( Sprobuj jeszcze raz." << std::endl; 
        break;   
    }
  }
  return Prost;
}

int main() {
  //std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
  //          << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
  //          << "."
  //          << PROJECT_VERSION_MINOR /* istotne zmiany */
  //          << "."
  //          << PROJECT_VERSION_PATCH /* naprawianie bugów */
  //          << "."
  //          << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
  //          << std::endl;
  // std::system("cat ../LICENSE");
  // do zadania Rotacja 2D
  
  char a = ' ';
  Scena Prost;
  double VekA[] = {20.0, 10.0, 10.0};
  Vector3D A = Vector3D(VekA);
  double VekB[] = {10.0, 15.0, 10.0};
  Vector3D B = Vector3D(VekB);
  double VekC[] = {10.0, 10.0, 30.0};
  Vector3D C = Vector3D(VekC);
  Prost.Prostopadl = Rectangle(A, B, C);
  double Vec[3];
  Vector3D tmpV;
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata
  while (a != 'k'){
    std::cout << "Twoj wybor? (m - menu) > ";
    std::cin >> a;
    std::cout << std::endl;
    switch (a)
    {
    case 'o':
    {
      std::cout << "Podaj sekwenccje oznaczen osi oraz katy obrotu w stopniach" << std::endl;
      Prost = MacObrZapis(Prost);
      std::cout << "Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
      std::cin >> Prost.IloscPowt;
      Prost.ObrotProstopadl();
      break;
    }
    case 't':
    Prost.ObrotProstopadl();
    break;
    case 'r':
    std::cout << "Macierz rotacji:" << std::endl;
    std::cout << Prost.Obrot << std::endl;
    break;
    case 'p':
    double x, y, z;
      std::cout << "Wprowadz wspolrzedne wektora translacji w postaci trzeh liczb" << std::endl;
      std::cout << "tzn. wspolrzednej x, wspolrzednej y oraz wspolrzednej z." << std::endl;
      std::cin >> x >> y >> z;
      Vec[0] = x;
      Vec[1] = y;
      Vec[2] = z;
      tmpV = Vector3D(Vec);
      Prost.Prostopadl.Przesuniencie(tmpV);
      break;
    case 'w':
      std::cout << Prost.Prostopadl << std::endl;
      break;
    case 'm':
      Menu();
      break;
    case 'b':
      Prost.Prostopadl.Dlugosc();
      break;
    case 'd':
      //-------------------------------------------------------
      //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
      //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
      //  na dwa sposoby:
      //   1. Rysowane jako linia ciagl o grubosci 2 piksele
      //
      Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,0.2);
      //
      //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
      //      których połowa długości boku wynosi 2.
      //
      Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,0.2);
      //
      //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
      //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
      //  jako wspolrzedne punktow podajemy tylko x,y.
      //
      Lacze.ZmienTrybRys(PzG::TR_3D);

      PrzykladZapisuWspolrzednychDoStrumienia(std::cout,Prost.Prostopadl);
      if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat",Prost.Prostopadl)) return 1;
      Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
      std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl << std::endl;
      std::cin.ignore(100000,'\n');
      break;
    case 'k':
      std::cout << "Koniec dzialania program" << std::endl;
      break;
    default:
      std::cout << ":(  Blad: Nie ma takiej opcji." << std::endl;
      break;
  }
  }
  
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
