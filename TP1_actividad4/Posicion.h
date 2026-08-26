#ifndef POSICION_H
#define POSICION_H

#include <string>

// -----------------------------------------------------------------------------
// Cambio respecto de la Actividad 3:
// En Act3 la posicion era un unico 'int posicion' (movimiento en una recta).
// El anexo pide una trayectoria BIDIMENSIONAL, por lo que se crea la clase
// Posicion con coordenadas (x, y) en metros. Concentra las operaciones
// geometricas para que Movil no se llene de 'double' sueltos.
// -----------------------------------------------------------------------------
class Posicion {
private:
    double x; // [m]
    double y; // [m]

public:
    Posicion();
    Posicion(double x, double y);

    double getX() const;
    double getY() const;

    // Unico modo de cambiar la posicion: se traslada un delta (dx, dy).
    // No hay setters directos para que la posicion solo cambie como
    // consecuencia de un desplazamiento real.
    void trasladar(double dx, double dy);

    // Distancia euclidea en linea recta hasta otra posicion.
    double distanciaA(const Posicion& otra) const;

    std::string aTexto() const;
};

#endif // POSICION_H
