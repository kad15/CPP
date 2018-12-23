#ifndef _PERSONNE_H
#define _PERSONNE_H

#include <iostream>

#include "Date.h"

using std::string;

class Personne
{
    string nom;
    // le nom de la personne(objet string).

    string prenom;
    // le prenom de la personne (objet string).

    //const int id;
    int id;
    // identifiant de la personne

    static int no_id;
    // compteur du nombre de personne

    //const Date dateSaisie;
    Date dateSaisie;
    // date

    public:
    Personne(string nom="inconnu", string prenom="inconnu");
    // constructeur

    string getNom() const;
    //retourne le prenom de la personne

    void setNom(string nouveau_nom);
    // change le nom de la personne.

    string getPrenom() const;
    // retourne le prenom de la personne.

    void setPrenom(string nouveau_prenom);
    // change le prenom de la personne.

    int getId() const ;
    // retourne l'identifiant

    virtual void saisir();
    // saisie une personne

    virtual void affiche() const;
    //affiche une personne

  /**

  */
    bool operator<(const Personne& p ) const {
     return (nom < p.nom);
    }

    virtual ~Personne();
    // detruit cette personne et ses ressources allouees.

};   // fin de la classe Personne

std::istream& operator>>(std::istream&, Personne& p);
std::ostream& operator<<(std::ostream&,const Personne&);

#endif
