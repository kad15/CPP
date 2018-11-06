#include "Etudiant.h"

using namespace std;

void Etudiant::affiche(std::ostream & os ) const
{
    Personne::affiche();
    cout<<"Moyenne globale : "<<getMoyenneGlobale()<<endl;
}

void Etudiant::saisir(std::istream& is)
{
    Personne::saisir();
    cout<<"nombre de matieres : ";
    //cin>>nbMatieres;
    //cin.get();
    //saisie plus securisee si valeur erronnee
    string temp;
    getline(cin,temp);
    stringstream(temp)>>nbMatieres;		// inclusion de <sstream>
    saisirMatieres();
}

void Etudiant::setNote(string mat,float note)
{
    //list<matiere>::iterator it;
     matieres = new string[nbMatieres];
     notes = new float[nbMatieres];

    //for (it = matieres.begin(); it != matieres.end();it++)
    for(int i = 0; i<nbMatieres;++i)
    {
        if (mat==matieres[i]){
            notes[i] = note ;
            return;
        }
	}
    cerr<<mat<<"non suivie "<<endl;
}

float Etudiant::getMoyenneGlobale() const
    // retourne la moyenne globale de l'etudiant.
{
	float moy=0;
	//1ere methode c++ 2011
	for(int i =0; i<nbMatieres;++i)
        moy+=notes[i];
	//2eme methode
	/*list<matiere>::const_iterator it;

    for (it = matieres.begin(); it != matieres.end();it++)
    {
        moy = moy + it->note;
	}*/

    if (nbMatieres)
        return moy/nbMatieres;
    else
        return -1;
}

 Etudiant(const Etudiant &){

 }


void Etudiant::saisirMatieres(std::istream& is)
{
	for (int i=0; i< nbMatieres; i++)
	{
		string temp;
		cout << "matiere " << i << " : ";
	    getline(cin,matieres[i]);
	    cout << "note obtenue : ";
	    //cin>>notes[i];
	    //cin.get(); //permet de vider le tampon d'entree
	    string note_temp;
	    getline(cin,note_temp);
	    stringstream(note_temp)>>notes[i];


	}
}
Etudiant::~Etudiant(){
   delete [] notes;
   delete [] matieres;
}

Etudiant::Etudiant(string nom, string prenom,int n): Personne(nom,prenom), nbMatieres(n)
{
	//saisie des matieres ds appel de saisirMatieres
}
