#include "Especie.hh"

Especie::Especie (string gen, int k) {
    this->gen = gen;
    
    map<string, int> kmer;
    for (int i = 0; i < gen.length() - k + 1; ++i) {
        string s;
        for (int j = 0; j < k; ++j) s.push_back(gen[i+j]);

        map<string, int>::iterator it = kmer.find(s);
        if (it == kmer.end()) kmer.emplace(s, 1);
        else it -> second = it -> second+1;
    }
    this->kmer = kmer;
}

Especie::~Especie(){}

string Especie::consultar_gen() const {
    return gen;
}

map<string, int> Especie::consultar_kmer() const {
    return kmer;
}