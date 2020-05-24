#include "Especie.hh"

Especie::Especie (const string& gen, const int& k) {
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

double Especie::consultar_distancia(const Especie& e1, const Especie& e2) {
    double num = 0;
    double div = 0;

    map<string, int>::const_iterator it1 = e1.kmer.begin();
    map<string, int>::const_iterator it2 = e2.kmer.begin();

    while (it1 != e1.kmer.end() and it2 != e2.kmer.end()) {
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

    if (it1 != e1.kmer.end()) {
        while (it1 != e1.kmer.end()) {
            div += it1->second;
            ++it1;
        }
    }

    else {
        while (it2 != e2.kmer.end()) {
            div += it2->second;
            ++it2;
        }
    }

    return (1 - num/div)*100;
}