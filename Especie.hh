/** @file Especie.hh
    @brief Especificació de la classe Especie 
*/

#ifndef ESP_HH
#define ESP_HH

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif

/** @class Especie
    @brief Representa una entitat o espècie amb atributs identificador i gen
*/
class Especie {

private:
    string id;
    string gen;
    vector<string> kmer;

public: 
    //Constructora

    /** @brief Creadora amb valors concrets 

      \pre Identificador "id" i gen "gen" no buits
      \post El resultat és una especie amb identificador "id", gen "gen". També es calcula el vector kmer.
    */ 
    Especie (string id, string gen);

    //Destructora

    /** @brief Destructora per defecte 
    */ 
    ~Especie();

    //Consultores
    
    /** @brief Consultora de l'identificador 

      \pre <em>cert</em>
      \post El resultat és l'identificador del paràmetre implícit
    */ 
    string consultar_id() const;
    
    /** @brief Consultora del gen 

      \pre <em>cert</em>
      \post El resultat és el gen del paràmetre implícit
    */ 
    string consultar_gen() const;
    
    /** @brief Consultora del conjunt kmer 

      \pre <em>cert</em>
      \post El resultat és el conjunt kmer del paràmetre implícit
    */ 
    vector<string> consultar_kmer() const;

    //Llegir i escriptura
    
    /** @brief Operació de lectura
    */
    void llegir();

    /** @brief Operació d'escriptura

      \pre <em>cert</em>
      \post S'han escrit els atributs del paràmetre implícit al canal standard de sortida. 
    */
    void escriure() const;
};

#endif