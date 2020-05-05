/**
 * @mainpage Pràctica PRO2: Construcció d'un arbre filogenètic.
 * 
 * Construcció de l'arbre filogenètic per a un conjunt d'N espècies utilitzant el mètode de WPGMA.
*/

/** @file main.cc
    @brief Programa principal de la <em>Construcció d'un arbre filogenètic</em>.
*/

using namespace std;
//#include "Cjt_clusters.hh"
#include "Cjt_especies.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

/** @brief Programa principal de la <em>Construcció d'un arbre filogenètic</em>.
*/

int main() {
    int k;
    cin >> k;

    Cjt_especies cesp(k);
    //Cjt_clusters cclu;

    string opcio;
    cin >> opcio;

    while (opcio != "fin") {
        cout << "# " << opcio; 

        if (opcio == "crea_especie") {
            string id, gen;
            cin >> id >> gen;
            cout << ' ' << id << ' ' << gen << endl;
            if (cesp.pertany(id)) cout << "ERROR: La especie " << id << " ya existe." << endl;
            else cesp.crea_especie(id, gen);
        }

        else if (opcio == "obtener_gen") {
            string id;
            cin >> id;
            cout << ' ' << id << endl;

            cesp.consultar_gen(id);
        }

        else if (opcio == "distancia") {
            string id1, id2;
            cin >> id1 >> id2;
            cout << ' ' << id1 << ' ' << id2 << endl;
            if (not cesp.pertany(id1) and not cesp.pertany(id2)) cout << "ERROR: La especie " << id1 << " y la especie " << id2 << " no existen." << endl;
            else if (not cesp.pertany(id1) and cesp.pertany(id2)) cout << "ERROR: La especie " << id1 << " no existe." << endl;
            else if (cesp.pertany(id1) and not cesp.pertany(id2)) cout << "ERROR: La especie " << id2 << " no existe." << endl;
            else {
                cout << cesp.distancia(id1, id2) << endl;
            }
        }

        else if (opcio == "elimina_especie") {
            string id;
            cin >> id;
            cout << ' ' << id << endl;

            cesp.elimina_especie(id);
        }

        else if (opcio == "existe_especie") {
            string id;
            cin >> id;
            cout << ' ' << id << endl;

            cesp.existeix_especie(id);
        }

        else if (opcio == "lee_cjt_especies") {
            int n;
            cin >> n;
            cout << endl;
            cesp.llegir(n);
        }

        else if (opcio == "imprime_cjt_especies") {
            cout << endl;
            cesp.escriure();
        }

        else if (opcio == "tabla_distancias") {
            cout << endl;
            cesp.taula_distancies();
            cesp.escriure_taula();
        }
        /*
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
            cin >> id;
            cclu.escriure_cluster(id);
        }

        else if (opcio == "imprime_arbol_filogenetico") {
            cclu.inicialitza_cluster(cesp);
            cclu.wpgma_total();
            cclu.escriure_arbre();
        }
        */
        cout << endl;
        cin >> opcio;
    }
}