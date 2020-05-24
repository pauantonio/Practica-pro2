/** @file Taula_distancies.hh
    @brief Especificació de la classe Taula_distancies
*/

#ifndef TAULA_DISTANCIES_HH
#define TAULA_DISTANCIES_HH

using namespace std;

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

/** @class Taula_distancies
    @brief Representa una taula de distàncies
*/
class Taula_distancies{
private: 
    /** @brief Emmagatzema la taula de distàncies entre diferènts espècies o clústers, del conjunt d'espècies o del conjunt de clústers */ 
    map <string, map<string, double>> taula;

public:
    //Constructora

    /** @brief Creadora per defecte 

      \pre <em>cert</em>
      \post El resultat és una taula de distàncies buida
    */ 
    Taula_distancies();

    //Destructora

    /** @brief Destructora per defecte 
    */
    ~Taula_distancies();

    //Modificadora

    /** @brief Modificadora que actualitza clusters

      \pre "id1" i "id2" no buits i pertanyen a la taula
      \post Es modifica la taula de distàncies afegint un identificador "id", resultat de la concatenació de "id1" i "id2", a les columnes on calgui, i creant una fila;
            utilitzant les distàncies d'"id1" i "id2" respecte a altres identificadors. També s'elimina qualsevol rastre dels identificadors "id1" i "id2"
    */
    void actualitza_taula(const string& id1, const string& id2);

    /** @brief Modificadora que afegeix una columna

      \pre "id1" i "id2" no buits. "id1" pertany a la taula i "id2" pot ser que no
      \post S'afegeix una columna a la fila de l'identificador "id1" amb paràmetres "id2" i distància "distancia"
    */
    void afegeix_columna(const string& id1, const string& id2, const double& distancia);

        /** @brief Modificadora que afegeix una fila

      \pre "id" no té cap fila a la taula
      \post S'afegeix una fila amb l'identificador "id" sense columnes
    */
    void afegeix_fila(const string& id);

    /** @brief Modificadora que elimina un identificador

      \pre "id" no buit i pertany a la taula
      \post Es modifica la taula de distàncies, eliminant qualsevol rastre de l'identificador "id" de les files i columnes
    */
    void elimina(const string& id);

    /** @brief Modificadora que buida la taula

      \pre <em>cert</em>
      \post La taula de distàncies és buida
    */
    void buidar();

    //Consultores

    /** @brief Consultora de la distància mínima

      \pre <em>cert</em>
      \post Es retornen per paràmetres la distància mínima de la taula "distancia" i els identificadors "id1" i "id2" que indiquen els clusters entre els quals hi ha la distància
    */
    void consultar_minim(double& distancia, string& id1, string& id2) const;

    //Escriure

    /** @brief Operació d'escriptura de la taula de distàncies

      \pre <em>cert</em>
      \post S'han escrit els atributs identificador i distància de totes les espècies del paràmetre implícit respecte a les altres espècies
    */
    void escriure_taula() const;
};

#endif