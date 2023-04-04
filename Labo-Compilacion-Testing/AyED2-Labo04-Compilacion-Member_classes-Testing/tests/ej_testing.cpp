#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int valor_calculado = 2+5;
    int valor_esperado = 7;
    EXPECT_EQ(valor_calculado,valor_esperado);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    int valor_calculado = 10*10;
    int valor_esperado = 100;
    EXPECT_EQ(valor_calculado, valor_esperado);
}

// Ejercicios 6..9

// Ejercicio 6
TEST(Aritmetica, potenia_general) {
    for(int n = -5; n = 5; n++){
        if(!(n=0)){
            int res = pow(n,2);
            EXPECT_EQ(res, n*n);
        }
    }
}

// Ejercicio 7
TEST(Diccionario, obtener) {
    map<int,int> d;
    d[1]=2;
    EXPECT_EQ(d[1],2);
}

// Ejercicio 8
TEST(Diccionario, definir) {
    map<int,int> d;
    EXPECT_EQ(d.count(5),0);
    d[5]=6;
    EXPECT_EQ(d[5],6);
}

// Ejercicio 9

TEST(Truco, inicio) {
    Truco t;
    EXPECT_EQ(t.puntaje_j1(),0);
    EXPECT_EQ(t.puntaje_j2(),0);
}

// Ejercicio 10

TEST(Truco, buenas) {
    Truco t;
    EXPECT_FALSE(t.buenas(1));
    for(int i = 0; i<15; i++){
        t.sumar_punto(1);
    }
    EXPECT_FALSE(t.buenas(1));
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
    t.sumar_punto(1);
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
}