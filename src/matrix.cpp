#include "matrix.hh"

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template<typename TYP, int SIZE>
Matrix<TYP, SIZE>::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Matr[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template<typename TYP, int SIZE>
Matrix<TYP, SIZE>::Matrix(TYP tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Matr[i][j] = tmp[i][j];
        }
    }
}


template<typename TYP, int SIZE>
Matrix<TYP, SIZE>::~Matrix()
{

}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template<typename TYP, int SIZE>
Vector3D Matrix<TYP, SIZE>::operator * (Vector3D tmp) {
    Vector3D result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += Matr[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template<typename TYP, int SIZE>
TYP &Matrix<TYP, SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return Matr[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template<typename TYP, int SIZE>
const TYP &Matrix<TYP, SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return Matr[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template<typename TYP, int SIZE>
Matrix<TYP, SIZE> Matrix<TYP, SIZE>::operator + (Matrix<TYP,SIZE> tmp) {
    Matrix<TYP, SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->Matr[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template<typename TYP, int SIZE>
std::istream &operator>>(std::istream &in, Matrix<TYP, SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template<typename TYP, int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<TYP, SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << std::setw(16) << std::fixed << std::setprecision(10) <<  mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

template<typename TYP, int SIZE>
Matrix<TYP, SIZE> Matrix<TYP, SIZE>::ObrKatX(double kat){
    double rad = kat * M_PI / 180;
    Matr[0][0] = 1;
    Matr[0][1] = 0;
    Matr[0][2] = 0;
    Matr[1][0] = 0;
    Matr[1][1] = cos(rad);
    Matr[1][2] = -sin(rad);
    Matr[2][0] = 0;
    Matr[2][1] = sin(rad);
    Matr[2][2] = cos(rad);
    return Matr;
}

template<typename TYP, int SIZE>
Matrix<TYP, SIZE> Matrix<TYP, SIZE>::ObrKatY(double kat){
    double rad = kat * M_PI / 180;
    Matr[0][0] = cos(rad);
    Matr[0][1] = 0;
    Matr[0][2] = sin(rad);
    Matr[1][0] = 0;
    Matr[1][1] = 1;
    Matr[1][2] = 0;
    Matr[2][0] = -sin(rad);
    Matr[2][1] = 0;
    Matr[2][2] = cos(rad);
    return Matr;
}

template<typename TYP, int SIZE>
Matrix<TYP, SIZE> Matrix<TYP, SIZE>::ObrKatZ(double kat){
    double rad = kat * M_PI / 180;
    Matr[0][0] = cos(rad);
    Matr[0][1] = -sin(rad);
    Matr[0][2] = 0;
    Matr[1][0] = sin(rad);
    Matr[1][1] = cos(rad);
    Matr[1][2] = 0;
    Matr[2][0] = 0;
    Matr[2][1] = 0;
    Matr[2][2] = 1;
    return Matr;
}

template<typename TYP, int SIZE>
void Matrix<TYP, SIZE>::Gauss(){
    TYP r;
    for (int i = 1; i <= SIZE - 1; i++){
        if (Matr[i][i] == 0.0){
            std::cout << "Mathematical Error!";
            exit(0);
        }
        for (int j = i + 1; j <= SIZE; j++){
            r = Matr[j][i]/Matr[i][i];
            for (int k = 1; k <= SIZE + 1; k++){
                Matr[j][k] = Matr[j][k] - r * Matr[i][k];
            }
        }
    }
}

template<typename TYP, int SIZE>
Matrix<TYP, SIZE> Matrix<TYP,SIZE>::operator*(Matrix<TYP, SIZE> tmp)
{
    Matrix<TYP, SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                result(i, j) += Matr[i][k] * tmp(k, j);
            }
        }
    }
    return result;
}