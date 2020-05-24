#include "Taula_distancies.hh"

Taula_distancies::Taula_distancies() {}

Taula_distancies::~Taula_distancies() {}

void Taula_distancies::actualitza_taula(const string& id1, const string& id2) {
    string id = id1 + id2;
    map<string, map<string, double>>::iterator it = taula.begin();
    while (it != taula.end() and it->first < id) {
        if (it->first < id1) {
            it->second.emplace(id, (it->second.find(id1)->second + it->second.find(id2)->second)/2);
            it->second.erase(id1);
            it->second.erase(id2);
        }
        ++it;
    }
    map<string, double> taula_aux;
    map<string, map<string, double>>::iterator it1 = taula.find(id1);
    map<string, map<string, double>>::iterator it2 = taula.find(id2);
    while (it != taula.end()) {
        if (it->first < id2) {
            taula_aux.emplace(it->first, (it1->second.find(it->first)->second + it->second.find(it2->first)->second)/2);
            it->second.erase(id2);
        }
        else if (it->first > id2) {
            taula_aux.emplace(it->first, (it1->second.find(it->first)->second + it2->second.find(it->first)->second)/2);
        }
        ++it;
    }
    taula.emplace(id, taula_aux);
    taula.erase(id1);
    taula.erase(id2);
}

void Taula_distancies::afegeix_columna(const string& id1, const string& id2, const double& distancia) {
    taula.find(id1)->second.emplace(id2, distancia);
}

void Taula_distancies::afegeix_fila(const string& id) {
    map<string, double> aux;
    taula.emplace(id, aux);
}

void Taula_distancies::elimina(const string& id) {
    map<string, map<string, double>>::iterator aux = taula.find(id);
    for (map<string, map<string, double>>::iterator it = taula.begin(); it != aux; ++it) {
        it->second.erase(id);
    }
    taula.erase(id);
}

void Taula_distancies::buidar() {
    taula.clear();
}

void Taula_distancies::consultar_minim(double& distancia, string& id1, string& id2) const {
    distancia = 200;
    for (map<string, map<string, double>>::const_iterator it = taula.begin(); it != taula.end(); ++it) {
        for (map<string, double>::const_iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
            if (it1->second < distancia) {
                distancia = it1->second;
                id1 = it->first;
                id2 = it1->first;
            }
        }
    }
}

void Taula_distancies::escriure_taula() const {
    for (map<string, map<string, double>>::const_iterator it = taula.begin(); it != taula.end(); ++it) {
        cout << it->first << ':';
        for (map<string, double>::const_iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
            cout << ' ' << it1->first << " (" << it1->second << ')';
        }
        cout << endl;
    }
}