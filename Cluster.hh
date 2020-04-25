/** @file Cluster.hh
    @brief Especificació de la classe Cluster 
*/

#ifndef CLU_HH
#define CLU_HH

#include "Cjt_especies.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/** @class Cluster
    @brief Representa un clúster
*/
class Cluster {
private:
    BinTree <string> cluster;
    string id;

public:
    //Constructora

    /** @brief Creadora amb un únic identificador

      \pre Identificador no buit, pertanyent a una espècie del conjunt d'espècies
      \post El resultat és un clúster amb una única espècie amb identificador "id" = "id1"
    */ 
    Cluster (string id1); 

    /** @brief Creadora amb dos identificadors

      \pre Identificadors "id1" i "id2" no buits, pertanyents a dos clústers
      \post El resultat és un clúster, que conté dos clústers, amb identificador "id" = "id1"*"id2"
    */
    Cluster (string id1, string id2);

    //Destructora

    /** @brief Destructora per defecte 
    */ 
    ~Cluster();

    //Consultores

    /** @brief Consultora de l'identificador del clúster 

      \pre <em>cert</em>
      \post El resultat és l'identificador del paràmetre implícit
    */ 
    string consultar_id() const;

    /** @brief Consultora de l'identificador del fill esquerre del clúster 

      \pre El clúster està format per dos cústers
      \post El resultat és l'identificador del fill esquerre del clúster
    */ 
    string consultar_id_esq() const;
    
    /** @brief Consultora de l'identificador del fill dret del clúster 

      \pre El clúster està format per dos cústers
      \post El resultat és l'identificador del fill dret del clúster
    */ 
    string consultar_id_dret() const;

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