#include "Cjt_especies.hh"

int Cjt_especies::k = 0;

Cjt_especies::Cjt_especies(const int& k) {
    this-> k = k;
}

Cjt_especies::~Cjt_especies() {}

void Cjt_especies::crea_especie(const string& id, const string& gen) {
    Especie e(gen, k);
    cesp.emplace(id, e);

    for (map <string, Especie>::const_iterator it = cesp.begin(); it != cesp.end(); ++it) {
        if (it->first < id) taula.afegeix_columna(it->first, id, consultar_distancia(it->first, id));
        else if (it->first > id) taula.afegeix_columna(id, it->first, consultar_distancia(it->first, id));
        else {
            taula.afegeix_fila(id);
        }
    }
}

void Cjt_especies::elimina_especie(const string& id) {
    cesp.erase(id);
    taula.elimina(id);
}

void Cjt_especies::inicialitza_iterador() {
    it = cesp.begin();
}

void Cjt_especies::incrementa_iterador() {
    ++it;
}

bool Cjt_especies::final_iterador() const{
    return it == cesp.end();
}

bool Cjt_especies::pertany(const string& id) const {
    map<string, Especie>::const_iterator it = cesp.find(id);
    return it != cesp.end();
}

Especie Cjt_especies::consultar_especie(const string& id) const {
    return cesp.find(id)->second;
}

double Cjt_especies::consultar_distancia(const string& id1, const string& id2) const {
    return consultar_especie(id1).consultar_distancia(consultar_especie(id1), consultar_especie(id2));
}

string Cjt_especies::consultar_identificador() const{
    return it->first;
}

Taula_distancies Cjt_especies::consultar_taula() const{
    return taula;
}

void Cjt_especies::llegir(const int& n) {
    cesp.clear();
    taula.buidar();
    for (int i = 0; i < n; ++i) {
        string id, gen;
        cin >> id >> gen;
        crea_especie(id, gen);
    }
}

void Cjt_especies::escriure_gen(const string& id) const {
    cout << cesp.find(id)-> second.consultar_gen() << endl;
}

void Cjt_especies::escriure_conjunt() const {
    for (map<string, Especie>::const_iterator it = cesp.begin(); it != cesp.end(); ++it) {
        cout << it-> first << ' ' << it-> second.consultar_gen() << endl;
    }
}

void Cjt_especies::escriure_taula() const {
    taula.escriure_taula();
}