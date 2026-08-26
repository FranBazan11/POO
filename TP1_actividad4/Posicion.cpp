#include "Posicion.h"

#include <cmath>
#include <sstream>

Posicion::Posicion() : x(0.0), y(0.0) {}

Posicion::Posicion(double x, double y) : x(x), y(y) {}

double Posicion::getX() const {
    return x;
}

double Posicion::getY() const {
    return y;
}

void Posicion::trasladar(double dx, double dy) {
    x += dx;
    y += dy;
}

double Posicion::distanciaA(const Posicion& otra) const {
    return std::hypot(otra.x - x, otra.y - y);
}

std::string Posicion::aTexto() const {
    std::ostringstream os;
    os.setf(std::ios::fixed);
    os.precision(2);
    os << "(" << x << ", " << y << ") m";
    return os.str();
}
