#include "Velocidad.h"

#include <cmath>
#include <sstream>

namespace {
    const double EPSILON = 1e-9;
    const double GRADOS_POR_RAD = 180.0 / M_PI;
}

Velocidad::Velocidad() : vx(0.0), vy(0.0) {}

Velocidad::Velocidad(double vx, double vy) : vx(vx), vy(vy) {}

Velocidad Velocidad::desdePolar(double modulo, double anguloGrados) {
    double rad = anguloGrados / GRADOS_POR_RAD;
    return Velocidad(modulo * std::cos(rad), modulo * std::sin(rad));
}

double Velocidad::getVx() const {
    return vx;
}

double Velocidad::getVy() const {
    return vy;
}

double Velocidad::modulo() const {
    return std::hypot(vx, vy);
}

double Velocidad::anguloGrados() const {
    return std::atan2(vy, vx) * GRADOS_POR_RAD;
}

bool Velocidad::esNula() const {
    return modulo() < EPSILON;
}

std::string Velocidad::aTexto() const {
    std::ostringstream os;
    os.setf(std::ios::fixed);
    os.precision(2);
    os << "(" << vx << ", " << vy << ") m/s | |v| = " << modulo() << " m/s";
    return os.str();
}
