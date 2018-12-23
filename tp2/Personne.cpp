#include "Personne.h"



int Personne::nb_pers=0;


Personne::Personne(const string& n,const  string& p):nom(n), prenom(p),id(nb_pers++)
{}

Personne::Personne():nom("inconnu"),prenom("inconnu"),id(nb_pers++)
{
    //ctor
}


Personne::~Personne()
{
    //dtor
    cout<<"Destruction de :"<<endl;
    affiche();
}


void Personne::affiche() const{
    //cout << "nom : "<<nom << " prenom : "<< prenom
    cout<<id<<" "<<nom<< " "<<prenom<<" saisi le "<<endl;
    //date_saisie.affiche();
    cout<<endl;
}

void Personne::saisir()
{
    string temp;

    cout<<"Donnez le nom de la personne : ";
    getline(cin,temp);  //permet de saisir une chaine avec des espaces
    setNom(temp);

    cout<<"Donnez son prenom : ";
    getline(cin,temp);
    setPrenom(temp);
}
