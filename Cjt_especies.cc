#include "Cjt_especies.hh"

int Cjt_especies::k = 0;

Cjt_especies::Cjt_especies(int k) {
    this-> k = k;
}

Cjt_especies::~Cjt_especies() {}

void Cjt_especies::crea_especie(const string& id, const string& gen) {
    Especie e(gen, k);
    cesp.emplace(id, e);
}

void Cjt_especies::elimina_especie(const string& id) {
    map<string, Especie>::const_iterator it = cesp.find(id);
    if (it != cesp.end()) {
        cesp.erase(it);
    }
    else {
        cout << "ERROR: La especie " << id << " no existe." << endl;
    }
}

bool Cjt_especies::pertany(string id) const {
    map<string, Especie>::const_iterator it = cesp.find(id);
    return it != cesp.end();
}

void Cjt_especies::consultar_gen(string id) const {
    map<string, Especie>::const_iterator it = cesp.find(id);
    if (it != cesp.end()) {
        cout << it-> second.consultar_gen() << endl;
    }
    else {
        cout << "ERROR: La especie " << id << " no existe." << endl;
    }
}

Especie Cjt_especies::consultar_especie(string id) const {
    map<string, Especie>::const_iterator it = cesp.find(id);
    return it-> second;
}

double Cjt_especies::distancia(string id1, string id2) const {
    double num = 0;
    double div = 0;
    map<string, int> kmer1 = consultar_especie(id1).consultar_kmer();
    map<string, int> kmer2 = consultar_especie(id2).consultar_kmer();

    map<string, int>::const_iterator it1 = kmer1.begin();
    map<string, int>::const_iterator it2 = kmer2.begin();

    while (it1 != kmer1.end() and it2 != kmer2.end()) {
        if (it1->first == it2->first) {
            num += min(it1->second, it2->second);
            div += max(it1->second, it2->second);
            ++it1;
            ++it2;
        }
        else if (it1->first < it2->first) {
            div += it1->second;
            ++it1;
        }
        else {
            div += it2->second;
            ++it2;
        }
    }

    if (it1 != kmer1.end()) {
        while (it1 != kmer1.end()) {
            div += it1->second;
            ++it1;
        }
    }

    else {
        while (it2 != kmer2.end()) {
            div += it2->second;
            ++it2;
        }
    }

    return (1 - num/div)*100;
}

void Cjt_especies::existeix_especie(string id) const {
    if (pertany(id)) cout << "SI" << endl;
    else cout << "NO" << endl;
}

void Cjt_especies::taula_distancies() {
    taula.clear();
    for (map<string, Especie>::iterator it = cesp.begin(); it != cesp.end(); ++it) {
        map<string, double> fila;
        map<string, Especie>::iterator it1 = it;
        ++it1;
        while (it1 != cesp.end()) {
            fila.emplace(it1->first, distancia(it->first, it1->first));
            ++it1;
        }
        taula.emplace(it->first, fila);
    }
}

void Cjt_especies::llegir(const int& n) {
    cesp.clear();
    for (int i = 0; i < n; ++i) {
        string id, gen;
        cin >> id >> gen;
        Especie e(gen, k);
        cesp.emplace(id, e);
    }
}

void Cjt_especies::escriure() const {
    for (map<string, Especie>::const_iterator it = cesp.begin(); it != cesp.end(); ++it) {
        cout << it-> first << ' ' << it-> second.consultar_gen() << endl;
    }
}

void Cjt_especies::escriure_taula() const {
    for (map<string, map<string, double>>::const_iterator it = taula.begin(); it != taula.end(); ++it) {
        cout << it->first << ':';
        for (map<string, double>::const_iterator it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
            cout << ' ' << it1->first << " (" << it1->second << ')';
        }
        cout << endl;
    }
}