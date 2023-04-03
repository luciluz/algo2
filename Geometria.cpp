#include <iostream>

using namespace std;

using uint = unsigned int;
float pi = 3.14;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};

uint Rectangulo::alto() { return alto_;}

// Completar definición: ancho
uint Rectangulo::ancho() { return ancho_;}

// Completar definición: area
float Rectangulo::area() { return ancho_*alto_;}

// Ejercicio 2

// Clase Elipse
class Elipse {
    public:
        Elipse(uint r_a, uint r_b);
        uint r_a();
        uint r_b();
        float area();

    private:
        int radio_a;
        int radio_b;
};

Elipse::Elipse(uint r_a, uint r_b) : radio_a(r_a), radio_b(r_b) {};

uint Elipse::r_a() { return radio_a;}

uint Elipse::r_b() { return radio_b;}

float Elipse::area() { return radio_a*radio_b*pi;}



// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}
uint Cuadrado::lado() {return r_.alto();}
float Cuadrado::area() {return r_.alto()*r_.ancho();}

// Ejercicio 4

// Clase Circulo
class Circulo {
public:
    Circulo(uint radio);
    uint radio();
    float area();

private:
    int radio_;
};

Circulo::Circulo(uint radio) : radio_(radio){};

uint Circulo::radio() { return radio_;}
float Circulo::area() { return radio_*radio_*pi;}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse
ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}


// Ejercicio 6

ostream& operator<<(ostream& os, Cuadrado c) {
    os << "Cuad(" << c.lado() << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo o) {
    os << "Circ(" << o.radio() << ")";
    return os;
}
