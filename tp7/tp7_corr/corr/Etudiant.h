#ifndef _ETUDIANT_H
#define _ETUDIANT_H

#define MAX 5

#include "Personne.h"

class Etudiant : public Personne
{
    // Attributs
    int nbMatieres;
    // nombre de matieres suivies.

    string* matieres;
	// liste des matieres suivies

    float* notes ;
    // tableau des notes

    // Implementation
    public:

    Etudiant(string nom="inconnu", string prenom="inconnu",int nbre_matieres_suivies=0);
    // constructeur avec (ou sans) parametres.

    Etudiant(const Etudiant &);
    // constructeur par recopie

    Etudiant & operator =(const Etudiant& );
    //surcharge operateur affectation

    virtual ~Etudiant();

    void affiche() const;
    //affiche les caracteristiques d'un Etudiant

    void saisir();
    //saisie d un Etudiant

    void saisirMatieres();
    //saisie des matieres

    float getMoyenneGlobale() const;
    // retourne la moyenne globale de l'etudiant.

    void setNote(string matiere, float note);
    // ajoute une note a la matiere specifiee.

};   // fin de la classe

#endif
