/**
 * @mainpage Pràctica PRO2: Construcció d'un arbre filogenètic.
 * 
 * Construcció de l'arbre filogenètic per a un conjunt d'N espècies utilitzant el mètode de WPGMA.
*/

/** @file main.cc
    @brief Programa principal de la <em>Construcció d'un arbre filogenètic</em>.
*/

using namespace std;
#include "Cjt_clusters.hh"
#include "Cjt_especies.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/** @brief Programa principal de la <em>Construcció d'un arbre filogenètic</em>.
*/

int main() {
    int k;
    cin >> k;

    Cjt_especies cesp(k);
    Cjt_clusters cclu;

    string opcio;
    cin >> opcio;

    while (opcio != "fin") {
        if (opcio == "crea_especie") {
            string id, gen;
            cin >> id >> gen;
            Especie esp (id, gen);
            cesp.crea_especie(esp);
        }

        else if (opcio == "obtener_gen") {
            string id;
            cin >> id;
            cesp.consultar_especie(id).consultar_gen();
        }

        else if (opcio == "distancia") {
            string id1, id2;
            cin >> id1 >> id2;
            cesp.distancia(id1, id2);
        }

        else if (opcio == "elimina_especie") {
            string id;
            cesp.elimina_especie(id);
        }

        else if (opcio == "existe_especie") {
            string id;
            cesp.existeix_especie(id);
        }

        else if (opcio == "lee_cjt_especies") {
            int n;
            cesp.llegir(n);
        }

        else if (opcio == "imprime_cjt_especies") {
            cesp.escriure();
        }

        else if (opcio == "tabla_distancias") {
            cesp.taula_distancies();
        }

        else if (opcio == "inicializa_clusters") {
            cclu.inicialitza_cluster(cesp);
            cclu.taula_distancies_clusters();
        }

        else if (opcio == "ejecuta_paso_wpgma") {
            cclu.wpgma_pas();
            cclu.taula_distancies_clusters();
        }

        else if (opcio == "imprime_cluster") {
            string id;
            cclu.escriure_cluster(id);
        }

        else if (opcio == "imprime_arbol_filogenetico") {
            cclu.inicialitza_cluster(cesp);
            cclu.wpgma_total();
            cclu.escriure_arbre();
        }

        cin >> opcio;
    }
}