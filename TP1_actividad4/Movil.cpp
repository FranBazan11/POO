#include "Movil.h"

#include <iostream>

namespace {
    const std::string ID_POR_DEFECTO = "MovilSinNombre";
}

// --- Constructores ----------------------------------------------------------

Movil::Movil()
    : id(ID_POR_DEFECTO),
      posicion(0.0, 0.0),
      velocidad(0.0, 0.0),
      estado(EstadoMovil::DETENIDO),
      distanciaRecorrida(0.0) {}

Movil::Movil(std::string id, Posicion pos, Velocidad vel)
    : id(id.empty() ? ID_POR_DEFECTO : id),
      posicion(pos),
      velocidad(vel),
      estado(EstadoMovil::DETENIDO),
      distanciaRecorrida(0.0) {}

// --- Validaciones privadas ------------------------------------------------

bool Movil::validarIntervalo(double dt) const {
    return dt >= 0.0; // el tiempo no retrocede
}

bool Movil::validarVelocidad(const Velocidad& v) const {
    return v.modulo() <= VELOCIDAD_MAXIMA;
}

// --- Verbos del movil ---------------------------------------------------

bool Movil::iniciar() {
    if (estado == EstadoMovil::EN_MOVIMIENTO) {
        return false;
    }
    estado = EstadoMovil::EN_MOVIMIENTO;
    return true;
}

bool Movil::detener() {
    if (estado == EstadoMovil::DETENIDO) {
        return false;
    }
    estado = EstadoMovil::DETENIDO;
    return true;
}

bool Movil::setVelocidad(Velocidad nueva) {
    if (!validarVelocidad(nueva)) {
        return false;
    }
    velocidad = nueva;
    return true;
}

void Movil::avanzar(double dt) {
    if (!validarIntervalo(dt)) {
        return; // dt negativo: no pasa nada
    }
    if (estado == EstadoMovil::DETENIDO) {
        return; // un movil detenido no cambia su posicion
    }
    // Durante el intervalo la velocidad se considera constante.
    posicion.trasladar(velocidad.getVx() * dt, velocidad.getVy() * dt);
    distanciaRecorrida += velocidad.modulo() * dt;
}

// --- Consultas -----------------------------------------------------------

std::string Movil::getId() const {
    return id;
}

Posicion Movil::getPosicion() const {
    return posicion;
}

Velocidad Movil::getVelocidad() const {
    return velocidad;
}

EstadoMovil Movil::getEstado() const {
    return estado;
}

double Movil::getDistanciaRecorrida() const {
    return distanciaRecorrida;
}

bool Movil::estaDetenido() const {
    return estado == EstadoMovil::DETENIDO;
}

std::string Movil::estadoATexto() const {
    return estaDetenido() ? "detenido" : "en_movimiento";
}

void Movil::mostrarEstado() const {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Movil " << id
              << " | Estado: " << estadoATexto()
              << " | Posicion: " << posicion.aTexto()
              << " | Velocidad: " << velocidad.aTexto()
              << " | Distancia recorrida: " << distanciaRecorrida << " m"
              << std::endl;
}
