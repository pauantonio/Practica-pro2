/** @file Cluster.hh
    @brief Especificació de la classe Cluster 
*/

#ifndef CLU_HH
#define CLU_HH

using namespace std;

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <string>
#include <iostream>
#endif

/** @class Cluster
    @brief Representa el conjunt de característiques i operacions del clúster
*/
class Cluster {
private:
    /** @brief Arbre binari de clústers, formats per altra banda, d'un identificador i la distància mitja respecte als seus fills */
    BinTree <pair <string, double>> cluster;

    /** @brief Operació d'escriptura privada 

      \pre Clúster "clu" amb el node, com a mínim, no buit. També pot tenir fills
      \post Escriu el clúster passat per referència, i els fills en cas que els tingui
    */ 
    void escriure_priv(const BinTree <pair <string, double>>& clu) const;
    
    /** @brief Consultora del clúster 

      \pre <em>cert</em>
      \post Retorna el clúster del paràmetre implícit
    */ 
    BinTree <pair <string, double>> consultar_cluster() const;

public:
    //Constructora

    /** @brief Creadora amb un únic identificador

      \pre Identificador no buit
      \post El resultat és un clúster sense fills i amb identificador "id" i distància 0
    */ 
    Cluster (const string& id); 

    /** @brief Creadora a partir de dos clústers

      \pre Clústers "c1" i "c2" no buits i distància entre ells "dist" >= 0
      \post El resultat és un clúster, que té a "c1" i "c2" com a fills, amb identificador "id" que es forma a partir
            de la concatenació dels identificadors dels dos clústers donats, i distància "dist"/2;
    */
    Cluster (const Cluster& c1, const Cluster& c2, const double& dist);

    //Destructora

    /** @brief Destructora per defecte 
    */ 
    ~Cluster();

    //Escriure

    /** @brief Operació d'escriptura

      \pre <em>cert</em>
      \post S'ha escrit el clúster del paràmetre implícit, i els fills en cas que els tingui
    */
    void escriure_cluster() const;
};

#endif