/** @file Cjt_clusters.hh
    @brief Especificació de la classe Cjt_clusters 
*/

#ifndef CONJ_CLU_HH
#define CONJ_CLU_HH

#include "Cluster.hh"
#include "Cjt_especies.hh"
#include "Taula_distancies.hh"
using namespace std;

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

/** @class Cjt_clusters
    @brief Representa el conjunt de característiques i operacions d'un conjunt de clústers
*/
class Cjt_clusters{
private: 
    /** @brief Emmagatzema el conjunt de clústers */
    map <string, Cluster> cclu;
    /** @brief Emmagatzema la taula de distàncies entre els diferents clústers del conjunt */
    Taula_distancies taula;

public:
    //Constructora

    /** @brief Creadora per defecte 

      \pre <em>cert</em>
      \post El resultat és un conjunt de clústers buit
    */ 
    Cjt_clusters();

    //Destructora

    /** @brief Destructora per defecte 
    */
    ~Cjt_clusters();

    //Modificadora

    /** @brief Modificadora que aplica un pas de l'algorisme WPGMA

      \pre El conjunt de clústers del paràmetre implícit està format per dos o més clústers
      \post El resultat és un conjunt de clústers modificat al aplicar un pas de l'algorisme WPGMA
    */
    void pas_wpgma();

    //Consultores

    /** @brief Consultora del tamany del conjunt

      \pre <em>cert</em>
      \post Retorna el tamany del conjunt de clústers del paràmetre implícit
    */
    double consultar_tamany() const;

    /** @brief Consultora de pertanyença

      \pre L'identificador "id" no és buit
      \post Es retorna cert si la espècie amb identificador "id" pertany al conjunt d'espècies del paràmetre implícit, o fals en cas contrari
    */
    bool pertany(const string& id) const;

    
    //Llegir

    /** @brief Inicialitza el conjunt de clústers

      \pre "cesp" es un conjunt d'espècies no buit
      \post El resultat és el conjunt de clústers del paràmetre implícit inicialitzat a partir de les espècies del conjunt d'espècies "cesp"
    */ 
    void inicialitza_cluster(Cjt_especies cesp);

    //Escriure

    /** @brief Operació d'escriptura de clúster

      \pre "id" és l'identificador d'un clúster que pertany al conjunt de clústers del paràmetre implícit
      \post S'han escrit els atributs del paràmetre implícit del clúster
    */
    void escriure_cluster(const string& id) const;

    /** @brief Operació d'escriptura de l'arbre filogenètic

      \pre <em>cert</em>
      \post S'ha escrit l'estructura arborescent amb els identificadors dels clústers i les distàncies entre clústers del paràmetre implícit, al canal standard de sortida. 
    */
    void escriure_arbre();
    
    /** @brief Operació d'escriptura de taula de distàncies entre clústers

      \pre <em>cert</em>
      \post S'ha escrit la taula de distàncies entre tots els clústers del paràmetre implícit 
    */
    void escriure_taula() const;
};

#endif