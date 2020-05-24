#include "Cjt_clusters.hh"

Cjt_clusters::Cjt_clusters() {}

Cjt_clusters::~Cjt_clusters() {}

void Cjt_clusters::pas_wpgma() {
    string id1, id2;
    double min;
    taula.consultar_minim(min, id1, id2);
    taula.actualitza_taula(id1, id2);
    
    Cluster clu (cclu.find(id1)->second, cclu.find(id2)->second, min);
    cclu.emplace(id1+id2, clu);
    cclu.erase(id1);
    cclu.erase(id2);
}

double Cjt_clusters::consultar_tamany() const {
    return cclu.size();
}

bool Cjt_clusters::pertany(const string& id) const {
    map<string, Cluster>::const_iterator it = cclu.find(id);
    return it != cclu.end();
}

void Cjt_clusters::inicialitza_cluster(Cjt_especies especies) {
    taula.buidar();
    cclu.clear();
    taula = especies.consultar_taula();
    especies.inicialitza_iterador();
    while (not especies.final_iterador()) {
        string id = especies.consultar_identificador();
        Cluster clu (id);
        cclu.emplace(id, clu);
        especies.incrementa_iterador();
    }
}

void Cjt_clusters::escriure_cluster(const string& id) const {
    cclu.find(id)->second.escriure_cluster();
}

void Cjt_clusters::escriure_arbre(){
    while (cclu.size() > 1) pas_wpgma();
    cclu.begin()->second.escriure_cluster();
}

void Cjt_clusters::escriure_taula() const {
    taula.escriure_taula();
}