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
    @brief Representa una entitat o espècie amb atributs identificador i gen
*/
class Especie {

private:
    string gen;
    map<string, int> kmer;

public: 
    //Constructora

    /** @brief Creadora amb valors concrets 

      \pre Identificador "id" i gen "gen" no buits
      \post El resultat és una especie amb identificador "id", gen "gen". També es calcula el vector kmer.
    */ 
    Especie (string gen, int k);

    //Destructora

    /** @brief Destructora per defecte 
    */ 
    ~Especie();

    //Consultores
    
    /** @brief Consultora del gen 

      \pre <em>cert</em>
      \post El resultat és el gen del paràmetre implícit
    */ 
    string consultar_gen() const;
    
    /** @brief Consultora del conjunt kmer 

      \pre <em>cert</em>
      \post El resultat és el conjunt kmer del paràmetre implícit
    */ 
    map<string, int> consultar_kmer() const;
};

#endif