#include <vector>
#include "algobot.h"
#include <set>
#include <map>

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
    set<int> ca(a.begin(), a.end());
    set<int> cb(b.begin(), b.end());
    return ca == cb;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> contador_de_apariciones;
    for(int i = 0; i < s.size(); i++){
        contador_de_apariciones[s[i]] += 1;
    }
    return contador_de_apariciones;
}

// Ejercicio 6
int cantApariciones(int k, vector<int> s){
    int res = 0;
    for(int i = 0; i<s.size();i++){
        if(s[i]==k){
            res += 1;
        }
    }
    return res;
}

vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> v;
    for (int i=0; i<s.size();i++){
        if(cantApariciones(s[i],s)==1){
            v.push_back(s[i]);
        }
    }
    return v;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> c;
    for(auto i = a.begin(); i != a.end(); ++i){
        if(b.count(*i) == 1){
            c.insert(*i);
        }
    }
    return c;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> agrupar_mod_10;
    for(int i=0;i < s.size(); i++){
        agrupar_mod_10[s[i]%10].insert(s[i]);
    }

    return agrupar_mod_10;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    for(int i = 0;i < str.size(); i++){
        bool existe = false;
        for(int j = 0; j< tr.size(); j++){
            if(tr[j].first == str[i]){
                res.push_back(tr[j].second);
                existe = true;
                break;
            }
        }
        if(!existe){
            res.push_back(str[i]);
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    for(Mail m1: s){
        for(Mail m2: s){
            if(m1.libretas() != m2.libretas()){
                for(LU libreta: m1.libretas()){
                    if(m2.libretas().count(libreta) > 0) return true;
                }
            }
        }
    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for(Mail m: s){
        if(m.adjunto()) res[m.libretas()] = m;
    }
    return res;
}
