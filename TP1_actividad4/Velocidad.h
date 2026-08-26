#ifndef VELOCIDAD_H
#define VELOCIDAD_H

#include <string>

// -----------------------------------------------------------------------------
// Cambio respecto de la Actividad 3:
// En Act3 la velocidad era un unico 'int velocidadActual' (rapidez sobre una
// recta). Para una trayectoria bidimensional se necesita un VECTOR (vx, vy)
// que define rapidez y direccion. Esta clase encapsula ese vector y sus
// operaciones (modulo, angulo, construccion polar).
// -----------------------------------------------------------------------------
class Velocidad {
private:
    double vx; // [m/s]
    double vy; // [m/s]

public:
    Velocidad();
    Velocidad(double vx, double vy);

    // Construye una velocidad a partir de su modulo [m/s] y su angulo [grados]
    // medido desde el eje +x en sentido antihorario.
    static Velocidad desdePolar(double modulo, double anguloGrados);

    double getVx() const;
    double getVy() const;

    double modulo() const;        // rapidez [m/s]
    double anguloGrados() const;  // direccion [grados]
    bool esNula() const;          // true si el movil no se desplazaria

    std::string aTexto() const;
};

#endif // VELOCIDAD_H
