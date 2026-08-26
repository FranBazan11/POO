#ifndef MOVIL_H
#define MOVIL_H

#include <string>

#include "Posicion.h"
#include "Velocidad.h"
#include "EstadoMovil.h"

// -----------------------------------------------------------------------------
// Cambios respecto de la Actividad 3 (se mantiene el concepto, se completa el
// modelo para cumplir el anexo y el diagrama UML de la Actividad 4):
//   - 'nombre' + 'id' (dos strings) -> un unico 'id' identificatorio.
//   - 'int posicion'        -> 'Posicion posicion'  (trayectoria 2D).
//   - 'int velocidadActual' -> 'Velocidad velocidad' (vector vx, vy).
//   - 'bool encendido'      -> 'EstadoMovil estado'.
//   - 'int desplazamientoTotal' -> 'double distanciaRecorrida' (acumulador).
//   - 'iniciarMovil/detenerMovil' -> 'iniciar/detener' y devuelven bool.
//   - 'modificarVelocidad(int)'   -> 'setVelocidad(Velocidad)' con validacion.
//   - 'desplazar(int)'            -> 'avanzar(double dt)' en segundos.
//   - Se agregan validaciones privadas (intervalo y velocidad maxima).
// -----------------------------------------------------------------------------
class Movil {
private:
    std::string id;
    Posicion posicion;
    Velocidad velocidad;
    EstadoMovil estado;
    double distanciaRecorrida; // [m], acumulada desde el inicio de la simulacion

    // Rapidez maxima admitida [m/s]. Es detalle de la clase.
    static constexpr double VELOCIDAD_MAXIMA = 50.0;

    // Validaciones internas: no deben verse desde el programa principal.
    bool validarIntervalo(double dt) const;
    bool validarVelocidad(const Velocidad& v) const;

public:
    // Crea un movil con valores iniciales predeterminados.
    Movil();
    // Crea un movil indicando sus datos iniciales. Si 'id' viene vacio se
    // reemplaza por el valor por defecto.
    Movil(std::string id, Posicion pos, Velocidad vel);

    // Inicia el movimiento de un movil detenido. Devuelve false si ya estaba
    // en movimiento.
    bool iniciar();
    // Detiene un movil en movimiento. Devuelve false si ya estaba detenido.
    bool detener();
    // Modifica la velocidad. Devuelve false (y no cambia nada) si la rapidez
    // pedida supera VELOCIDAD_MAXIMA.
    bool setVelocidad(Velocidad nueva);

    // Simula el desplazamiento durante 'dt' segundos a velocidad constante.
    // Un movil detenido, o un dt negativo, no modifican posicion ni distancia.
    void avanzar(double dt);

    // Consultas de estado (accesibles desde el programa principal).
    std::string getId() const;
    Posicion getPosicion() const;
    Velocidad getVelocidad() const;
    EstadoMovil getEstado() const;
    double getDistanciaRecorrida() const;
    bool estaDetenido() const;
    std::string estadoATexto() const; // "detenido" / "en_movimiento"

    // Muestra la informacion del movil de forma clara y ordenada.
    void mostrarEstado() const;
};

#endif // MOVIL_H
