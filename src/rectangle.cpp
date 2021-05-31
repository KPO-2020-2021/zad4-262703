#include "rectangle.hh"

Rectangle::Rectangle() {
    Vector3D W;
    for (int i = 0; i < WIER; ++i) {
            rect[i] = W;
    }
}

Rectangle::Rectangle(Vector3D A, Vector3D B,Vector3D C){
    double Vec_0[] = {10,10,10};
    Vector3D Vec0(Vec_0);
    rect[0] = Vec0;
    rect[1] = A;
    rect[2] = B;
    rect[3][0] = A[0];
    rect[3][1] = B[1];
    rect[3][2] = Vec0[2];
    rect[6] = C;
    rect[4] = B;
    rect[4][2] = C[2];
    rect[5] = rect[3];
    rect[5][2] = C[2];
    rect[7] = A;
    rect[7][2] = C[2];
}

std::ostream &operator << (std::ostream &out, Rectangle const &tmp){
    for (int i = 0; i < WIER; ++i) { 
        out << "| " << tmp[i] << "| "; //warto ustalic szerokosc wyswietlania dokladnosci liczb 
        std::cout << std::endl;
    }
    return out;
}

const Vector3D &Rectangle::operator [] (int index) const {
    if (index < 0 || index >= WIER) {
        std::cerr << "Error: Rectangle jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return rect[index];
}

Vector3D &Rectangle::operator[](int index) {
    return const_cast<Vector3D &>(const_cast<const Rectangle *>(this)->operator[](index));
}

Rectangle Rectangle::Przesuniencie(Vector3D const Vec){
    for(int i = 0; i < WIER; ++i){
        for (int j = 0; j < 3; j++)
        {
            rect[i][j] += Vec[j]; 
        }
    }
    return *this;
}


Rectangle Rectangle::Obrot(Macierz3x3 Obr, int const raz){
    for (int i = 0; i < raz; ++i){
        for (int j = 0; j < WIER; j++)
        {
            rect[j] = Obr * rect[j];
        }
    }
    return *this;
}

void Rectangle::Dlugosc(){
    double DlBok1, DlBok2, DlBok3, DlBok4, KrBok1, KrBok2, KrBok3, KrBok4, TrBok1, TrBok2, TrBok3, TrBok4;
    DlBok1 = sqrt(pow(rect[0][0] - rect[6][0],2) + pow(rect[0][1] - rect[6][1],2) + pow(rect[0][2] - rect[6][2],2));
    DlBok2 = sqrt(pow(rect[2][0] - rect[4][0],2) + pow(rect[2][1] - rect[4][1],2) + pow(rect[2][2] - rect[4][2],2));
    DlBok3 = sqrt(pow(rect[3][0] - rect[5][0],2) + pow(rect[3][1] - rect[5][1],2) + pow(rect[3][2] - rect[5][2],2));
    DlBok4 = sqrt(pow(rect[1][0] - rect[7][0],2) + pow(rect[1][1] - rect[7][1],2) + pow(rect[1][2] - rect[7][2],2));
    KrBok1 = sqrt(pow(rect[0][0] - rect[2][0],2) + pow(rect[0][1] - rect[2][1],2) + pow(rect[0][2] - rect[2][2],2));
    KrBok2 = sqrt(pow(rect[1][0] - rect[3][0],2) + pow(rect[1][1] - rect[3][1],2) + pow(rect[1][2] - rect[3][2],2));
    KrBok3 = sqrt(pow(rect[4][0] - rect[6][0],2) + pow(rect[4][1] - rect[6][1],2) + pow(rect[4][2] - rect[6][2],2));
    KrBok4 = sqrt(pow(rect[5][0] - rect[7][0],2) + pow(rect[5][1] - rect[7][1],2) + pow(rect[5][2] - rect[7][2],2));
    TrBok1 = sqrt(pow(rect[0][0] - rect[1][0],2) + pow(rect[0][1] - rect[1][1],2) + pow(rect[0][2] - rect[1][2],2));
    TrBok2 = sqrt(pow(rect[2][0] - rect[3][0],2) + pow(rect[2][1] - rect[3][1],2) + pow(rect[2][2] - rect[3][2],2));
    TrBok3 = sqrt(pow(rect[4][0] - rect[5][0],2) + pow(rect[4][1] - rect[5][1],2) + pow(rect[4][2] - rect[5][2],2));
    TrBok4 = sqrt(pow(rect[7][0] - rect[6][0],2) + pow(rect[7][1] - rect[6][1],2) + pow(rect[7][2] - rect[6][2],2));
    if ((DlBok1 == DlBok2) && (DlBok2 == DlBok3) && (DlBok3 == DlBok4)){
        std::cout << ":)  Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << DlBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << DlBok2 << std::endl;
        std::cout << "   Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << DlBok3 << std::endl;
        std::cout << "   Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << DlBok4 << std::endl << std::endl;
    }
    else{
        std::cout << ":o  Dluzsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << DlBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << DlBok2 << std::endl;
        std::cout << "   Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << DlBok3 << std::endl;
        std::cout << "   Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << DlBok4 << std::endl << std::endl;   
    }
    if ((KrBok1 == KrBok2) && (KrBok2 == KrBok3) && (KrBok3 == KrBok4)){
        std::cout << ":)  Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << KrBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << KrBok2 << std::endl;
        std::cout << "   Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << KrBok3 << std::endl;
        std::cout << "   Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << KrBok4 << std::endl << std::endl;  
    }
    else{
        std::cout << ":o  Krotsze przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << KrBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << KrBok2 << std::endl;
        std::cout << "   Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << KrBok3 << std::endl;
        std::cout << "   Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << KrBok4 << std::endl << std::endl;      
    }
        if ((TrBok1 == TrBok2) && (TrBok2 == TrBok3) && (TrBok3 == TrBok4)){
        std::cout << ":)  Poprzeczne przeciwlegle boki sa sobie rowne." << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << TrBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << TrBok2 << std::endl;
        std::cout << "   Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << TrBok3 << std::endl;
        std::cout << "   Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << TrBok4 << std::endl << std::endl;  
    }
    else{
        std::cout << ":o  Poprzeczne przeciwlegle boki nie sa rowne!!!" << std::endl;
        std::cout << "  Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << TrBok1 << std::endl;
        std::cout << "    Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << TrBok2 << std::endl;
        std::cout << "   Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << TrBok3 << std::endl;
        std::cout << "   Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(16) << TrBok4 << std::endl << std::endl;      
    }
}