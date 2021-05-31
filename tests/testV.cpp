#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/Vector3D.hh"

TEST_CASE("Konstr Bezparm"){
    Vector3D tmpV;
    CHECK((tmpV[0] == 0) && (tmpV[1] == 0));
}

TEST_CASE("Konstr Param"){
    double Vek[] = {3.0, 4.0};
    Vector3D tmpV(Vek);
    CHECK(tmpV[0] == 3 && tmpV[1] == 4);

}

TEST_CASE("Operator indeks1"){
    double Vek[] = {3.0, 4.0};
    Vector3D tmpV(Vek);
    double a = tmpV[0], b = tmpV[1];
    CHECK(((a == 3)&&(b == 4)));
}

TEST_CASE("Operator indeks2"){
    Vector3D tmpV;
    double a = 3, b = 4;
    tmpV[0] = a;
    tmpV[1] = b;
    CHECK(tmpV[0] == 3 && tmpV[1] == 4);
}

TEST_CASE("Dodawanie"){
    Vector3D tmpV, tmpV1, tmpV2;
    double a[] = {3.0, 4.0};
    tmpV1 = Vector3D(a);
    tmpV2 = Vector3D(a);
    tmpV = tmpV1 + tmpV2;
    CHECK(tmpV[0] == 6 && tmpV[1] == 8);
}

TEST_CASE("Odejmowanie"){
    Vector3D tmpV, tmpV1, tmpV2;
    double a[] = {3.0, 4.0};
    double b[] = {2.0, 2.0};
    tmpV1 = Vector3D(a);
    tmpV2 = Vector3D(b);
    tmpV = tmpV1 - tmpV2;
    CHECK(tmpV[0] == 1 && tmpV[1] == 2);
}

TEST_CASE("Dzielenie"){
    Vector3D tmpV, tmpV1;
    double a[] = {3.0, 4.0};
    double b = 2;
    tmpV1 = Vector3D(a);
    tmpV = tmpV1 / b;
    CHECK(tmpV[0] == 1.5 && tmpV[1] == 2);
}

TEST_CASE("Dzielenie przez zero"){
    Vector3D tmpV, tmpV1;
    double a[] = {3.0, 4.0};
    double b = 0;
    tmpV1 = Vector3D(a);
    WARN_THROWS(tmpV = tmpV1 / b);
}


