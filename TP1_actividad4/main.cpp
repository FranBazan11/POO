// -----------------------------------------------------------------------------
// TP1 - Actividad 4 : programa principal de pruebas.
// Reemplaza al main() que en la Actividad 3 estaba dentro de Movil.cpp.
// Demuestra los requerimientos del anexo:
//   - dos formas de inicializacion,
//   - estado inicial de cada movil,
//   - desplazamiento en uno o mas intervalos de tiempo,
//   - cambios de velocidad y de estado (movimiento / detenido),
//   - que un movil detenido no cambia de posicion al pasar el tiempo,
//   - estado final y distancia total recorrida,
//   - registro opcional en un archivo .csv.
// -----------------------------------------------------------------------------
#include <iostream>

#include "Movil.h"
#include "Posicion.h"
#include "Velocidad.h"
#include "RegistradorCSV.h"

namespace {

void titulo(const std::string& texto) {
    std::cout << "\n===== " << texto << " =====\n";
}

}

int main() {
    RegistradorCSV registrador("estados_moviles.csv");
    if (!registrador.abrir()) {
        std::cerr << "Advertencia: no se pudo abrir el archivo CSV.\n";
    }
    registrador.escribirEncabezado();

    // --- Creacion de moviles con distintas formas de inicializacion --------
     // valores por defecto
    Movil movilA;                          
    // datos iniciales                   
    Movil movilSW4("SW4", Posicion(0.0, 0.0), Velocidad(10.0, 0.0));   
    // velocidad en polar
    Movil movilTITO("TITO", Posicion(-20.0, 5.0), Velocidad::desdePolar(15.0, 30.0));   

    titulo("Estado inicial");
    movilA.mostrarEstado();
    movilSW4.mostrarEstado();
    movilTITO.mostrarEstado();
    registrador.registrar(movilA);
    registrador.registrar(movilSW4);
    registrador.registrar(movilTITO);

    // --- Iniciar el movimiento -------------------------------------------
    titulo("Se inician SW4 y TITO");
    std::cout << "movilSW4.iniciar() -> " << std::boolalpha << movilSW4.iniciar() << "\n";
    std::cout << "movilTITO.iniciar() -> " << movilTITO.iniciar() << "\n";
    std::cout << "movilSW4.iniciar() de nuevo -> " << movilSW4.iniciar()
              << "  (ya estaba en movimiento)\n";

    // --- Desplazamiento durante varios intervalos de 2 s -----------------
    titulo("Desplazamiento: 3 intervalos de 2 s");
    for (int i = 1; i <= 3; ++i) {
        movilSW4.avanzar(2.0);
        movilTITO.avanzar(2.0);
        std::cout << "-- tras intervalo " << i << " (t = " << 2 * i << " s) --\n";
        movilSW4.mostrarEstado();
        movilTITO.mostrarEstado();
        registrador.registrar(movilSW4);
        registrador.registrar(movilTITO);
    }

    // --- Cambio de velocidad (valido y rechazado) -----------------------
    titulo("Cambios de velocidad en SW4");
    std::cout << "setVelocidad((0, 8))  -> " << movilSW4.setVelocidad(Velocidad(0.0, 8.0))
              << "  (valida)\n";
    std::cout << "setVelocidad((90, 0)) -> " << movilSW4.setVelocidad(Velocidad(90.0, 0.0))
              << "  (rechazada: supera la velocidad maxima)\n";
              
    movilSW4.avanzar(2.0);
    movilSW4.mostrarEstado();
    registrador.registrar(movilSW4);

    // --- Cambio de estado: detener y comprobar que no se mueve ---------
    titulo("Se detiene TITO y pasa el tiempo");
    std::cout << "movilTITO.detener() -> " << movilTITO.detener() << "\n";
    Posicion antes = movilTITO.getPosicion();
    movilTITO.avanzar(5.0); // no deberia cambiar nada
    Posicion despues = movilTITO.getPosicion();
    std::cout << "Posicion antes:   " << antes.aTexto() << "\n";
    std::cout << "Posicion despues: " << despues.aTexto()
              << "  (un movil detenido no cambia su posicion)\n";
    registrador.registrar(movilTITO);

    // --- Estado final y distancia total -------------------------------
    titulo("Estado final");
    movilA.mostrarEstado();
    movilSW4.mostrarEstado();
    movilTITO.mostrarEstado();
    registrador.registrar(movilA);
    registrador.registrar(movilSW4);
    registrador.registrar(movilTITO);

    registrador.cerrar();
    std::cout << "\nEl detalle de los estados quedo registrado en 'estados_moviles.csv'.\n";
    return 0;
}
