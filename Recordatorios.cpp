#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10


// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();

    // Completar declaraciones funciones
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {}

int Fecha::mes() {return mes_;}
int Fecha::dia() {return dia_;}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia() && this->mes() == o.mes();
    // Completar iguadad (ej 9)
    return igual_dia;
}
#endif

void Fecha::incrementar_dia(){
    if(dia_ == dias_en_mes(mes_)){
        if(mes() == 12){
            mes_ = 1;
            dia_ = 1;
        }
        else{
            mes_ += 1;
            dia_ = 1;
        }
    }
    else dia_ += 1;
}

// Ejercicio 11, 12

// Clase Horario
class Horario {
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator<(Horario h);

    private:
        uint hora_;
        uint min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {}

uint Horario::hora() {return hora_;}
uint Horario::min() {return min_;}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator<(Horario h) {
    return this->hora() < h.hora() || (this->hora() == h.hora() && this->min() < h.min());
}

// Ejercicio 13

// Clase Recordatorio

class Recordatorio {
    public:
        Recordatorio(Fecha fecha, Horario horario, string mensaje);
        Fecha fecha();
        Horario horario();
        string mensaje();

    private:
        Fecha fecha_;
        Horario horario_;
        string mensaje_;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje)
    : fecha_(fecha), horario_(horario), mensaje_(mensaje) {}

Fecha Recordatorio::fecha() {return fecha_;}
Horario Recordatorio::horario() {return horario_;}
string Recordatorio::mensaje() {return mensaje_;}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}
/*
bool Recordatorio::operator<(Recordatorio r) {
    return this->horario() < r.horario();
}*/

// Ejercicio 14

// Clase Agenda

class Agenda {
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();

    private:
        Fecha fecha_hoy_;
        list<Recordatorio> recordatorios_;
};

Agenda::Agenda(Fecha fecha_inicial) : fecha_hoy_(fecha_inicial) {}

void Agenda::agregar_recordatorio(Recordatorio rec) { recordatorios_.push_back(rec); }

void Agenda::incrementar_dia() { fecha_hoy_.incrementar_dia();}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> recordatorios_hoy;
    map<Horario, string> mapa_de_recordatorios;
    for(Recordatorio r: recordatorios_){
        if(r.fecha() == fecha_hoy_) recordatorios_hoy.push_back(r);
    }
    return recordatorios_hoy;
}

Fecha Agenda::hoy() {return fecha_hoy_;}

/*
list<Recordatorio> ordenarRecordatorios(list<Recordatorio> list_rec){
    list<Recordatorio> recordatorios_ordenados = list_rec;
    sort(recordatorios_ordenados.begin(), recordatorios_ordenados.end(), [](Recordatorio a, Recordatorio b){
        return a.horario() < b.horario();
    });
}


list<Recordatorio> Agenda::ordenarRecordatorios(list<Recordatorio> list_rec){
    list<Recordatorio> list_rec_copy = list_rec;
    list<Recordatorio> rec_ordenados;
    while(!list_rec_copy.empty()){
        Recordatorio primer_rec = list_rec_copy.front();
        for(Recordatorio r: list_rec_copy){
            if(r.horario() < primer_rec.horario()) primer_rec = r;
        }
        rec_ordenados.push_back(primer_rec);
        list_rec_copy.remove(primer_rec);
    }
    return rec_ordenados;
}


list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> recordatorios_hoy;
    map<Horario, string> mapa_de_recordatorios;
    for(Recordatorio r: recordatorios_){
        if(r.fecha() == fecha_hoy_) recordatorios_hoy.push_front(r);
        mapa_de_recordatorios[r.horario()] = r.mensaje();
    }


    return recordatorios_hoy;
}
*/

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl;
    os << "=====" << endl;
    for(Recordatorio rec: a.recordatorios_de_hoy()){
        os << rec << endl;
    }
    return os;
}
