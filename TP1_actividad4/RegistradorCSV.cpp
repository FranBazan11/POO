#include "RegistradorCSV.h"

RegistradorCSV::RegistradorCSV(std::string ruta)
    : rutaArchivo(std::move(ruta)), abierto(false) {}

RegistradorCSV::~RegistradorCSV() {
    cerrar();
}

bool RegistradorCSV::abrir() {
    archivo.open(rutaArchivo, std::ios::out | std::ios::trunc);
    abierto = archivo.is_open();
    return abierto;
}

void RegistradorCSV::escribirEncabezado() {
    if (!abierto) {
        return;
    }
    archivo << "movil,estado,distancia_recorrida\n";
}

void RegistradorCSV::registrar(const Movil& m) {
    if (!abierto) {
        return;
    }
    archivo << m.getId() << ","
            << m.estadoATexto() << ","
            << m.getDistanciaRecorrida() << "\n";
}

void RegistradorCSV::cerrar() {
    if (abierto) {
        archivo.close();
        abierto = false;
    }
}
