/** @file Cjt_especies.hh
    @brief Especificació de la classe Cjt_especies 
*/

#ifndef CONJ_ESP_HH
#define CONJ_ESP_HH

#include "Especie.hh"
using namespace std;

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <string>
#endif

/** @class Cjt_especies
    @brief Representa un conjunt d'espècies
*/
class Cjt_especies {

private:
    map<string, Especie> cesp;
    map<string, map<string, double>> taula;
    static int k;

public:
    //Constructora

    /** @brief Creadora per defecte 

      \pre k >= 0
      \post El resultat és un conjunt d'espècies buit i s'inicialitza el valor k
    */ 
    Cjt_especies(int k);

    //Destructora

    /** @brief Destructora per defecte 
    */ 
    ~Cjt_especies();

    //Modificadores

    /** @brief Modificadora que crea una espècie

      \pre La espècie amb identificador "id" no forma part del conjunt d'espècies del paràmetre implícit
      \post Es modifica el conjunt d'espècies del paràmetre implícit amb la unió de la espècie amb identificador "id" i gen "gen"
    */
    void crea_especie(const string& id, const string& gen);

    /** @brief Modificadora que elimina una espècie

      \pre La espècie "esp" forma part del conjunt d'espècies del paràmetre implícit
      \post Es modifica el conjunt d'espècies del paràmetre implícit amb la eliminació de la espècie "esp"
    */
    void elimina_especie(const string& id);

    //Consultores

    /** @brief Consultora de la pertanyença de la espècie amb identificador "id"

      \pre L'identificador "id" és l'identificador d'una espècie
      \post El resultat és cert si la espècie amb identificador "id" pertany al paràmetre implícit, o fals en cas contrari
    */
    bool pertany(string id) const;

    /** @brief Consultora del gen de la espècie amb identificador "id"

      \pre L'identificador "id" és l'identificador d'una espècie del paràmetre implícit
      \post El resultat és el gen de la espècie del paràmetre implícit amb identificador "id"
    */
    void consultar_gen(string id) const;

    /** @brief Consultora de la espècie amb identificador "id"

      \pre L'identificador "id" és l'identificador d'una espècie del paràmetre implícit
      \post El resultat és la espècie del paràmetre implícit amb identificador "id" després de recórrer el map
    */
    Especie consultar_especie(string id) const;

    /** @brief Consultora de distàncies entre espècies

      \pre Els identificadors "id1" i "id2" son els identificador de dues espècies del paràmetre implícit
      \post El resultat és la distància entre les espècies del paràmetre implícit associades amb els identificador "id1" i "id2" 
    */
    double distancia(string id1, string id2) const;

    /** @brief Consultora d'existència d'una espècie

      \pre <em>cert</em>
      \post El resultat és la indicació de si existeix una espècie que formi part del paràmetre implícit amb identificador "id" 
    */
    void existeix_especie(string id) const;

    /** @brief Consultora de taula de distàncies

      \pre <em>cert</em>
      \post El resultat és la taula de distàncies entre totes les espècies del paràmetre implícit 
    */
    void taula_distancies();

    //Llegir i escriure

    /** @brief Operació de lectura
      \pre n >= 0
      \post El paràmetre implícit està format per n espècies donades, amb identificadors diferents entre si.
    */
    void llegir(const int& n);

    /** @brief Operació d'escriptura

      \pre <em>cert</em>
      \post S'han escrit els atributs identificador i gen de totes les espècies del paràmetre implícit al canal standard de sortida. 
    */
    void escriure() const;

    /** @brief Operació d'escriptura de la taula de distàncies

      \pre <em>cert</em>
      \post S'han escrit els atributs identificador i distància de totes les espècies del paràmetre implícit respecte a les altres espècies al canal standard de sortida. 
    */
    void escriure_taula() const;
};

#endif