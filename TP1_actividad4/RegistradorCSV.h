#ifndef REGISTRADOR_CSV_H
#define REGISTRADOR_CSV_H

#include <fstream>
#include <string>

#include "Movil.h"

// -----------------------------------------------------------------------------
// Clase nueva en la Actividad 4 (punto opcional del anexo).
// Su unica responsabilidad es PERSISTIR en un .csv los estados de los moviles.
// El Movil no sabe nada de archivos: el registrador lo USA (relacion de
// dependencia ..> en el diagrama), no lo contiene ni lo modifica.
// Formato pedido por el anexo:  movil,estado,distancia_recorrida
// -----------------------------------------------------------------------------
class RegistradorCSV {
private:
    std::string rutaArchivo;
    std::ofstream archivo;
    bool abierto;

public:
    explicit RegistradorCSV(std::string ruta);
    ~RegistradorCSV();

    bool abrir();                       // abre el archivo (truncando lo previo)
    void escribirEncabezado();          // "movil,estado,distancia_recorrida"
    void registrar(const Movil& m);     // una fila con el estado actual de 'm'
    void cerrar();
};

#endif // REGISTRADOR_CSV_H
