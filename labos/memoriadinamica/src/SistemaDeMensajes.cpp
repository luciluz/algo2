#include "SistemaDeMensajes.h"
// Completar...

SistemaDeMensajes::SistemaDeMensajes(): _conns() {}

SistemaDeMensajes::~SistemaDeMensajes() {
    for(int i=0; i<4; i++) {
        if (_conns[i] != nullptr) {
            delete _conns[i];
        }
    }
    for(int j=0; j<_proxys.size(); j++){
        delete _proxys[j];
    }

}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(_conns[id] != nullptr){
        delete _conns[id];
    }
    _conns[id] = new ConexionJugador(ip);
}
void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
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

/*
    Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy *p = new Proxy(_conns[id]);
    _proxys.push_back(p);
    return p;
}*/

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy *p = new Proxy(&_conns[id]);
    _proxys.push_back(p);
    return p;
}