#include "Etudiant.h"
#include <sstream>
using namespace std;

void Etudiant::affiche() const
{
    Personne::affiche();
    cout<<" Moyenne globale : "<<getMoyenneGlobale()<<endl;
}

void Etudiant::saisir()
{
    Personne::saisir();
    cout<<"nombre de matieres : ";
    string temp;
    getline(cin,temp);
    stringstream(temp)>>nbMatieres;		// inclusion de <sstream>

    delete [] matieres;	// nécessaire si on appelle cette methode
    matieres = new matiere[nbMatieres];
    saisirMatieres();
}

void Etudiant::setNote(string mat,float note)
{
    int i=0;
    while (i<nbMatieres && mat!=matieres[i].nom)
        i++;
    if(i!=nbMatieres)
       matieres[i].note=note;
    else
        cout<<mat<<"non suivie "<<endl;
}

float Etudiant::getMoyenneGlobale() const
    // retourne la moyenne globale de l'etudiant.
{

	float moy=0;
    for (int i=0 ; i< nbMatieres;i++)
    {
        moy = moy + matieres[i].note;
	}
    if (nbMatieres)
        return moy/nbMatieres;
    else
        return -1;
}

void Etudiant::saisirMatieres()
{
	for (int i=0; i< nbMatieres; i++)
	{
		cout << "matiere " << i << " : ";
	    getline(cin,matieres[i].nom);
	    cout << "note obtenue : ";
	    //cin>>notes[i];
	    //cin.get(); //permet de vider le tampon d'entree
	    string temp;
	    getline(cin,temp);
	    stringstream(temp)>>matieres[i].note;
	}
}
Etudiant::~Etudiant()
{
	delete [] matieres;
}

Etudiant& Etudiant::operator =(const Etudiant &e)
{
	delete [] matieres;

	Personne::operator=(e);
	nbMatieres = e.nbMatieres;
	if(nbMatieres)
	{
		matieres = new matiere[nbMatieres];

		for(int i=0;i<nbMatieres;i++)
		{
			matieres[i] = e.matieres[i];
		}
	}
	return *this;
}

Etudiant::Etudiant(const Etudiant& e):Personne(e),nbMatieres(e.nbMatieres),matieres(NULL)
{
	operator=(e);
}

Etudiant::Etudiant(string nom, string prenom,int n): Personne(nom,prenom),nbMatieres(n),matieres(NULL)
{
	if(n>0)
	{
		matieres=new matiere[n];
    }
	//saisie des matieres ds appel de saisirMatieres
}
