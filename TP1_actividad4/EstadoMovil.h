#ifndef ESTADO_MOVIL_H
#define ESTADO_MOVIL_H

// -----------------------------------------------------------------------------
// Cambio respecto de la Actividad 3:
// En Act3 el estado de marcha se representaba con un 'bool encendido'. Se
// reemplaza por un enumerado para que el estado sea explicito y ampliable,
// y para que coincida con el diagrama UML de la Actividad 4.
// -----------------------------------------------------------------------------
enum class EstadoMovil {
    DETENIDO,
    EN_MOVIMIENTO
};

#endif // ESTADO_MOVIL_H
