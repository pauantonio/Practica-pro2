/** @file Cjt_clusters.hh
    @brief Especificació de la classe Cjt_clusters 
*/

#ifndef CONJ_CLU_HH
#define CONJ_CLU_HH

#include "Cluster.hh"

#ifndef NO_DIAGRAM
#include <set>
#endif

/** @class Cjt_clusters
    @brief Representa un conjunt de clústers
*/
class Cjt_clusters{
private: 
    set <Cluster> cclu;
    vector <vector<double>> taula;

public:
    //Constructora

    /** @brief Creadora per defecte 

      \pre <em>cert</em>
      \post El resultat és un conjunt de clústers buit
    */ 
    Cjt_clusters();

    /** @brief Creadora a partir d'un conjunt d'espècies 

      \pre "cesp" és un conjunt d'espècies no buit
      \post El resultat és un conjunt de clústers format a partir de les espècies del conjunt d'espècies "cesp"
    */ 
    Cjt_clusters(Cjt_especies cesp);

    //Destructora

    /** @brief Destructora per defecte 
    */
    ~Cjt_clusters();

    //Modificadora

    /** @brief Modificadora que aplica un pas de l'algorisme WPGMA

      \pre El paràmetre implícit està format per dos o més clústers
      \post El resultat és un conjunt de clústers modificat al aplicar un pas de l'algorisme WPGMA
    */
    void wpgma_pas();

    /** @brief Modificadora que aplica l'algorisme WPGMA

      \pre El paràmetre implícit està format per dos o més clústers
      \post El resultat és conjunt de clústers que conté un únic clúster format per totes les especies, resultat d'aplicar l'algorisme WPGMA totes les vegades possibles
    */
    void wpgma_total();
    
    //Consultora

    /** @brief Consultora de taula de distàncies entre clústers

      \pre <em>cert</em>
      \post El resultat és la taula de distàncies entre tots els clústers del paràmetre implícit 
    */
    void taula_distancies_clusters() const;

    //Llegir i escriure

    /** @brief Inicialitza el conjunt de clústers

      \pre "cesp" es un conjunt d'espècies no buit
      \post El resultat es un conjunt de clústers inicialitzat a partir de les espècies del conjunt d'espècies "cesp"
    */ 
    void inicialitza_cluster(const Cjt_especies& cesp);

    /** @brief Operació d'escriptura de clúster

      \pre "id" és l'identificador d'un clúster que pertany al paràmetre implícit
      \post S'han escrit els atributs del paràmetre implícit del clúster al canal standard de sortida. 
    */
    void escriure_cluster(const string& id) const;

    /** @brief Operació d'escriptura de l'arbre filogenètic

      \pre <em>cert</em>
      \post S'ha escrit l'estructura arborescent amb els identificadors dels clústers i les distàncies entre clústers del paràmetre implícit, al canal standard de sortida. 
    */
    void escriure_arbre() const;
};

#endif