#include <vector>
#include "algobot.h"
#include <set>

using namespace std;

// Ejercicio 1

bool existe(int k, vector<int> v) {
    bool res = false;
    for(int i = 0;i < v.size();i++){
        if(k == v[i]){
            res = true;
        }
    }
    return res;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> v;
    for(int i = 0;i < s.size();i++){
        if(!existe(s[i],v)){
            v.push_back(s[i]);
        }
    }
    return v;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> c;
    vector<int> v;
    for(int i=0;i < s.size(); i++){
        if(c.count(s[i]) == 0){
            v.push_back(s[i]);
        }
        c.insert(s[i]);
    }
    return v;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;
    for(int i = 0; i < a.size(); i++){
        if(!existe(a[i],b)){
            res = false;
        }
    }
    for(int j = 0; j < b.size(); j++){
        if(!existe(b[j],a)) {
            res = false;
        }
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b){
    bool res = true;
    set<int> c;
    for(int i = 0; i < a.size(); i++){
        c.insert(a[i]);
    }
    for(int j = 0; j < b.size(); j++){
        if(c.count(b[j]) == 0){
            res = false;
        }
    }
    return res;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    return map<int, int>();
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    return vector<int>();
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    return set<int>();
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
