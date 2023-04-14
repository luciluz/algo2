#include "SistemaDeMensajes.h"

// Completar...

SistemaDeMensajes::SistemaDeMensajes(): _conns() {}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i=0; i<4; i++) {
        if (_conns[i] != nullptr) {
            delete _conns[i];
        }
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(_conns[id] != nullptr){
        delete _conns[id];
        _conns[id] = new ConexionJugador(ip);
    } else{
        _conns[id] = new ConexionJugador(ip);
        }
}
void SistemaDeMensajes::desregistrarJugador(int id) {
    _conns[id] = nullptr;
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {

}
