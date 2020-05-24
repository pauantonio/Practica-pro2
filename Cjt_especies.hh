/** @file Cjt_especies.hh
    @brief Especificació de la classe Cjt_especies 
*/

#ifndef CONJ_ESP_HH
#define CONJ_ESP_HH

#include "Especie.hh"
#include "Taula_distancies.hh"
using namespace std;

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif

/** @class Cjt_especies
    @brief Representa el conjunt de característiques i operacions d'un conjunt d'espècies
*/
class Cjt_especies {

private:
    /** @brief Emmagatzema el conjunt d'espècies */
    map<string, Especie> cesp;
    /** @brief Emmagatzema la taula de distàncies entre les diferènts espècies del conjunt */
    Taula_distancies taula;
    /** @brief Iterador que recorre el conjunt d'espècies */
    map<string, Especie>::iterator it = cesp.begin();
    /** @brief Indica el tamany de les subseqüències per tal de formar el kmer de les espècies */
    static int k;

    
    /** @brief Consultora de la espècie amb identificador "id"

      \pre L'identificador "id" és l'identificador d'una espècie del paràmetre implícit
      \post Es retorna la espècie del paràmetre implícit amb identificador "id"
    */
    Especie consultar_especie(const string& id) const;

public:
    //Constructora

    /** @brief Creadora per defecte 

      \pre "k" >= 1
      \post El resultat és un conjunt d'espècies buit i s'inicialitza el valor "k"
    */ 
    Cjt_especies(const int& k);

    //Destructora

    /** @brief Destructora per defecte 
    */ 
    ~Cjt_especies();

    //Modificadores

    /** @brief Modificadora que afegeix una espècie al conjunt

      \pre La espècie amb identificador "id" i gen "gen" no forma part del conjunt d'espècies del paràmetre implícit
      \post Es modifica el conjunt d'espècies del paràmetre implícit, amb la unió de la espècie amb identificador "id" i gen "gen"
    */
    void crea_especie(const string& id, const string& gen);

    /** @brief Modificadora que elimina una espècie del conjunt

      \pre La espècie amb identificador "id" forma part del conjunt d'espècies del paràmetre implícit
      \post Es modifica el conjunt d'espècies del paràmetre implícit amb la eliminació de la espècie amb identificador "id"
    */
    void elimina_especie(const string& id);

    /** @brief Modificadora que inicialitza iterador

      \pre <em>cert</em>
      \post L'iterador del paràmetre implícit s'inicialitza al primer element del conjunt
    */
    void inicialitza_iterador();
    
    /** @brief Modificadora que incrementa iterador

      \pre <em>cert</em>
      \post L'iterador del paràmetre implícit apunta al següent element del conjunt
    */
    void incrementa_iterador();

    //Consultores

    /** @brief Consultora de final del conjunt

      \pre <em>cert</em>
      \post Retorna és cert si l'iterador del paràmetre implícit apunta al final del conjunt d'espècies, o fals en cas contrari
    */
    bool final_iterador() const;

    /** @brief Consultora de la pertanyença de la espècie

      \pre L'identificador "id" no buit
      \post Retorna cert si la espècie amb identificador "id" pertany al conjunt d'espècies del paràmetre implícit, o fals en cas contrari
    */
    bool pertany(const string& id) const;

    /** @brief Consultora de distàncies entre espècies

      \pre Els identificadors "id1" i "id2" son els identificador de dues espècies que pertanyen al conjunt d'espècies del paràmetre implícit
      \post Es retorna la distància entre les espècies delconjunt associades amb els identificador "id1" i "id2" 
    */
    double consultar_distancia(const string& id1, const string& id2) const;

    /** @brief Consultora del conjunt d'espècies

      \pre <em>cert</em>
      \post Retorna l'identificador de l'espècie del conjunt a la que apunta l'iterador "it" del paràmetre implícit
    */
    string consultar_identificador() const;

    /** @brief Consultora de la taula de distàncies

      \pre <em>cert</em>
      \post Retorna la taula de distàncies "taula" entre les espècies del conjunt
    */
    Taula_distancies consultar_taula() const;

    //Llegir

    /** @brief Operació de lectura
      \pre n >= 0
      \post S'inicialitza el conjunt d'espècies del paràmetre implícit, que passa a estar format per "n" espècies donades, amb identificadors diferents entre si
    */
    void llegir(const int& n);

    //Escriure

    /** @brief Operació d'escriptura del gen

      \pre L'identificador "id" és l'identificador d'una espècie del conjunt d'espècies del paràmetre implícit
      \post S'ha escrit el gen de la espècie del paràmetre implícit amb identificador "id"
    */
    void escriure_gen(const string& id) const;

    /** @brief Operació d'escriptura del conjunt

      \pre <em>cert</em>
      \post S'han escrit els atributs identificador i gen de totes les espècies del conjunt d'espècies del paràmetre implícit
    */
    void escriure_conjunt() const;

    /** @brief Operació d'escriptura de la taula de distàncies

      \pre <em>cert</em>
      \post S'han escrit els atributs identificador i distància de totes les espècies del paràmetre implícit respecte a les altres espècies
    */
    void escriure_taula() const;
};

#endif