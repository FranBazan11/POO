#include <iostream>
#include <string>
#include <cstdlib>

class Movil {
private:
    std::string nombre;
    std::string id;
    bool encendido;
    int velocidadActual;
    int posicion;
    int desplazamientoTotal;

public:
    Movil(
        std::string nombre = "",
        std::string id = "",
        bool encendido = false,
        int velocidadActual = 0,
        int posicion = 0,
        int desplazamientoTotal = 0) :
            nombre(nombre),
            id(id),
            encendido(encendido),
            velocidadActual(velocidadActual),
            posicion(posicion),
            desplazamientoTotal(desplazamientoTotal)
            {}

    void iniciarMovil() {
        encendido = true;
    }

    void modificarVelocidad(int velocidad) {
        velocidadActual = velocidad;
        encendido = (velocidad != 0);
    }

    int getVelocidadActual() {
        return velocidadActual;
    }

    void detenerMovil() {
        velocidadActual = 0;
        encendido = false;
    }

    void desplazar(int tiempoSegundos) {
        if (!encendido || tiempoSegundos <= 0) {
            return;
        }

        int desplazamiento = velocidadActual * tiempoSegundos;

        posicion += desplazamiento;
        desplazamientoTotal += std::abs(desplazamiento);
    }

    void mostrarDatosActuales() {
        std::cout << "Movil: " << nombre
                  << " | Patente: " << id
                  << " | Estado: " << (encendido ? "en movimiento" : "detenido")
                  << " | Velocidad: " << velocidadActual
                  << " | Posicion: " << posicion
                  << " | Desplazamiento total: " << desplazamientoTotal << std::endl;
    }
};

int main() {
    Movil TITO("TITO", "AB123CD");

    Movil SW4(
        /* nombre = */ "SW4",
        /* id = */ "SW4-001",
        /* encendido = */ true,
        /* velocidadActual = */ 20,
        /* posicion = */ 100,
        /* desplazamientoTotal = */ 0
    );

    // Estados iniciales.
    std::cout << "Estado inicial de TITO:" << std::endl;
    TITO.mostrarDatosActuales();

    std::cout << "Estado inicial de SW4:" << std::endl;
    SW4.mostrarDatosActuales();

    // Desplazamientos y cambios de velocidad.
    TITO.iniciarMovil();
    TITO.modificarVelocidad(10);
    TITO.desplazar(5);
    TITO.desplazar(2);
    TITO.detenerMovil();

    SW4.desplazar(3);
    SW4.modificarVelocidad(5);
    SW4.desplazar(2);
    SW4.detenerMovil();

    // Estados finales y distancias totales.
    std::cout << "\nEstado final de TITO:" << std::endl;
    TITO.mostrarDatosActuales();

    std::cout << "Estado final de SW4:" << std::endl;
    SW4.mostrarDatosActuales();

    return 0;
}