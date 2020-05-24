#include "Cluster.hh"

Cluster::Cluster (const string& id) {
    cluster = BinTree <pair <string, double>> (make_pair(id, 0));
}

Cluster::Cluster (const Cluster& c1, const Cluster& c2, const double& dist) {
    string id = c1.consultar_cluster().value().first + c2.consultar_cluster().value().first;
    cluster = BinTree <pair <string, double>> (make_pair (id, dist/2), c1.consultar_cluster(), c2.consultar_cluster());
}

Cluster::~Cluster() {}

BinTree <pair <string, double>> Cluster::consultar_cluster() const {
    return cluster;
}

void Cluster::escriure_cluster() const {
    if (not cluster.empty()) {
        if (not cluster.left().empty() and not cluster.right().empty()) {
            cout << "[(" << cluster.value().first << ", " << cluster.value().second << ") ";
            escriure_priv(cluster.left());
            escriure_priv(cluster.right());
            cout << "]";
        }
        else cout << "[" << cluster.value().first << "]";
    }
}

void Cluster::escriure_priv(const BinTree <pair <string, double>>& clu) const {
    if (not clu.empty()) {
        if (not clu.left().empty() and not clu.right().empty()) {
            cout << "[(" << clu.value().first << ", " << clu.value().second << ") ";
            escriure_priv(clu.left());
            escriure_priv(clu.right());
            cout << "]";
        }
        else cout << "[" << clu.value().first << "]";
    }
}