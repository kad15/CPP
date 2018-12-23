#ifndef PERSONNE_H
#define PERSONNE_H

#include "Date.h"
#include <iostream>
//using std::string;
using namespace std;


class Personne
{
    public:
        Personne(const string& nom, const string& prenom);
        Personne();
        virtual ~Personne();

    void setPrenom(const string& p){
        prenom = p;
    }
    string getPrenom() const{
        return prenom;
    }

     void setNom(const string& n){
        nom = n;
    }
    string getNom(){
        return prenom;
    }

    void affiche() const;

      void saisir();
    // saisie une personne






    private:

        string nom, prenom;
        static int nb_pers;
        const int id;
        const Date date_saisie;
    //compteur du nombre de personnes

};

#endif // PERSONNE_H
