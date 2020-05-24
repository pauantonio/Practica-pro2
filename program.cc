/** @mainpage Construcció d'un arbre filogenètic
    
    - <b>Projecte</b>: Construcció d'un arbre filogenètic
    - <b>Autor</b>: Pau Antonio Soler
    - <b>Data</b>: 20 de maig de 2020
    - <b>Versió</b>: 1.14
    - <b>Llenguatge</b>: Català
    
    En aquest projecte es construeix un arbre filogenètic per a un conjunt donat d'espècies, que es pot anar moficant 
    a través de diverses comandes, utilitzant el mètode WPGMA. 
    El programa principal, on s'indica quina acció ha de dur a terme el programa, està situat al modul program.cc.
    Per altra banda i per tal de poder realitzar aquestes accions, el projecte està organitzat en 5 mòduls o classes.
    
    La primera classe que utilitzem és la classe Especie, que representa i inclou les funcions relatives a una espècie.
    La segons és la classe Cjt_especies, que ens permet emmagatzemar un conjunt d'espècies. Per altra banda, també tenim
    les classes de Cluster, que emmagatzema un cluster; i la de Cjt_clusters, que emmagatzema un conjunt de clústers.
    Per últim, per tal de facilitar la implementació de les funcions i l'emmagatzematge de les taules de distàncies, tenim la 
    classe Taula_distancies, que ens permet gestionar una taula de distàncies.
*/

/** @file program.cc
 
    @brief Programa principal de la <em>Construcció d'un arbre filogenètic</em>.

    En aquest mòdul, controlem les accions que duu a terme el programa, a través de diverses opcions .
    En primer lloc, llegim el paràmetre <b>k</b> necessari per a inicialitzar el conjunt d'espècies <b>cesp</b> que creem. 
    També creem un conjunt de clústers <b>cclu</b>.

    Aquestes són les diferents opcions que pot executar el programa principal:

    - <b>crea_especie</b>: crea una espècie amb l'identificador i gen donats, que s'afegeix al conjunt d'espècies. 
        Escriu un missatge d'error si ja existeix una espècie amb el mateix identificador.
    - <b>obtener_gen</b>: donat un identificador d'una espècie, imprimeix el gen associat a la espècie. 
        Escriu un missatge d'error si no existeix una espècie amb l'identificador donat.
    - <b>distancia</b>: donats dos identificadors d'espècies, imprimeix la distància entre les dues.    
        Escriu un missatge d'error si alguna de les dues espècies amb l'identificador donat no existeix.
    - <b>elimina_especie</b>: donat l'identificador d'una espècie, la elimina del conjunt d'espècies.
        Escriu un missatge d'error si no existeix una espècie amb l'identificador donat.
    - <b>existe_especie</b>: donat l'identificador d'una espècie, imprimeix una indicació de si forma part o no del conjunt d'espècies.
    - <b>lee_cjt_especies</b>: llegeix un enter n >= 0 i una seqüència d'n espècies, totes amb identificador diferent. Els continguts previs
        del conjunt es descarten i les espècies llegides d'afegeixen al conjunt.
    - <b>imprime_cjt_especies</b>: imprimeix el conjunt d'espècies. En cas que aquest sigui buit, no s'imprimeix res.
    - <b>tabla_distancias</b>: imprimex la taula de distàncies entre cada parell d'espècies del conjunt d'espècies. En cas que aquest sigui buit, no s'imprimeix res.
    - <b>inicializa_clusters</b>: inicialitza el conjunt de clústers amb el conjunt d'espècies en l'estat en el que es troba, 
        i imprimeix la taula de distàcies entre clústers. En cas que el conjunt sigui buit, no s'imprimeix res.
    - <b>ejecuta_paso_wpgma</b>: executa un pas de l'algoritme WPGMA i imprimeix la taula de distàncies entre clústers resultant. 
        En cas que el conjunt sigui buit, no s'imprimeix res.
    - <b>imprime_cluster</b>: donat un identificador, imprimeix el clúster associat. Escriu un missatge d'error si no existeix un clúster amb l'identificador donat.
    - <b>imprime_arbol_filogenetico</b>: s'inicialitza el conjunt de clústers i s'aplica l'algorisme WPGMA. S'imprimeix l'abre filogenètic resultant.
        En cas que el conjunt sigui buit, s'imprimeix un missatge d'error.
    - <b>fin</b>: finalitza l'execució del programa.
*/

using namespace std;
#include "Cjt_clusters.hh"
#include "Cjt_especies.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif

int main() {
    int k;
    cin >> k;

    Cjt_especies cesp(k);
    Cjt_clusters cclu;

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

            if (cesp.pertany(id)) cesp.escriure_gen(id);
            else cout << "ERROR: La especie " << id << " no existe." << endl;
        }

        else if (opcio == "distancia") {
            string id1, id2;
            cin >> id1 >> id2;
            cout << ' ' << id1 << ' ' << id2 << endl;
            if (not cesp.pertany(id1) and not cesp.pertany(id2)) cout << "ERROR: La especie " << id1 << " y la especie " << id2 << " no existen." << endl;
            else if (not cesp.pertany(id1) and cesp.pertany(id2)) cout << "ERROR: La especie " << id1 << " no existe." << endl;
            else if (cesp.pertany(id1) and not cesp.pertany(id2)) cout << "ERROR: La especie " << id2 << " no existe." << endl;
            else cout << cesp.consultar_distancia(id1, id2) << endl;
        }

        else if (opcio == "elimina_especie") {
            string id;
            cin >> id;
            cout << ' ' << id << endl;

            if (cesp.pertany(id)) cesp.elimina_especie(id);
            else cout << "ERROR: La especie " << id << " no existe." << endl;
        }

        else if (opcio == "existe_especie") {
            string id;
            cin >> id;
            cout << ' ' << id << endl;

            if (cesp.pertany(id)) cout << "SI" << endl;
            else cout << "NO" << endl;
        }

        else if (opcio == "lee_cjt_especies") {
            int n;
            cin >> n;
            cout << endl;
            cesp.llegir(n);
        }

        else if (opcio == "imprime_cjt_especies") {
            cout << endl;
            cesp.escriure_conjunt();
        }

        else if (opcio == "tabla_distancias") {
            cout << endl;
            cesp.escriure_taula();
        }
        
        else if (opcio == "inicializa_clusters") {
            cclu.inicialitza_cluster(cesp);
            cout << endl;
            cclu.escriure_taula();
        }

        else if (opcio == "ejecuta_paso_wpgma") {
            cout << endl;
            if (cclu.consultar_tamany() > 1) {
                cclu.pas_wpgma();
                cclu.escriure_taula();
            }
            else cout << "ERROR: num_clusters <= 1" << endl;
        }

        else if (opcio == "imprime_cluster") {
            string id;
            cin >> id;
            cout << ' ' << id << endl;

            if (cclu.pertany(id)) cclu.escriure_cluster(id);
            else cout << "ERROR: El cluster " << id << " no existe.";
            cout << endl;
        }

        else if (opcio == "imprime_arbol_filogenetico") {
            cclu.inicialitza_cluster(cesp);
            cout << endl;

            if (cclu.consultar_tamany() >= 1) cclu.escriure_arbre();
            else cout << "ERROR: El conjunto de clusters es vacio.";
            cout << endl;
        }
        
        cout << endl;
        cin >> opcio;
    }
}