/** @file Especie.hh
    @brief Especificació de la classe Especie 
*/

#ifndef ESP_HH
#define ESP_HH

using namespace std;

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif

/** @class Especie
    @brief Representa el conjunt de característiques i operacions de les espècies
*/
class Especie {

private:
    /** @brief Gen de la espècie */
    string gen;
    /** @brief Conjunt de subseqüències del gen de tamany k */
    map<string, int> kmer;

public: 
    //Constructora

    /** @brief Creadora amb valors concrets 

      \pre Gen "gen" no buit i "k" >= 1
      \post El resultat és una especie amb gen "gen". També es calcula el vector kmer donat el paràmetre "k"
    */ 
    Especie (const string& gen, const int& k);

    //Destructora

    /** @brief Destructora per defecte 
    */ 
    ~Especie();

    //Consultores
    
    /** @brief Consultora del gen 

      \pre <em>cert</em>
      \post Es retorna el "gen" del paràmetre implícit
    */ 
    string consultar_gen() const;

    /** @brief Calcular distància

      \pre Les espècies "e1" i "e2" no són buides
      \post Es retorna la distància entre les dues espècies, utilitzant el "kmer" del paràmetre implícit
    */ 
    static double consultar_distancia(const Especie& e1, const Especie& e2);
};

#endif