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
    delete [] notes;	// sur un Etudiant dejà initialisé
    matieres = new string[nbMatieres];
    notes = new float[nbMatieres];
    saisirMatieres();
}

void Etudiant::setNote(string mat,float note)
{
    int i=0;
    while (i<nbMatieres && mat!=matieres[i])
        i++;
    if(i!=nbMatieres)
       notes[i]=note;
    else
        cout<<mat<<"non suivie "<<endl;
}

float Etudiant::getMoyenneGlobale() const
    // retourne la moyenne globale de l'etudiant.
{

	float moy=0;
    for (int i=0 ; i< nbMatieres;i++)
    {
        moy = moy + notes[i];
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
	    getline(cin,matieres[i]);
	    cout << "note obtenue : ";
	    //cin>>notes[i];
	    //cin.get(); //permet de vider le tampon d'entree
	    string temp;
	    getline(cin,temp);
	    stringstream(temp)>>notes[i];
	}
}
Etudiant::~Etudiant()
{
	delete [] matieres;
	delete [] notes;
}

Etudiant& Etudiant::operator =(const Etudiant &e)
{
	delete [] matieres;
	delete [] notes;

	Personne::operator=(e);
	nbMatieres = e.nbMatieres;
	if(nbMatieres)
	{
		matieres = new string[nbMatieres];
		notes = new float[nbMatieres];

		for(int i=0;i<nbMatieres;i++)
		{
			matieres[i] = e.matieres[i];
			notes[i] = e.notes[i];
		}
	}
	return *this;
}

Etudiant::Etudiant(const Etudiant& e):Personne(e),nbMatieres(e.nbMatieres),matieres(NULL),notes(NULL)
{
	operator=(e);
}

Etudiant::Etudiant(string nom, string prenom,int n): Personne(nom,prenom),nbMatieres(n),matieres(NULL),notes(NULL)
{
	if(n>0)
	{
		matieres=new string[n];
		notes= new float[n];
	}
	//saisie des matieres ds appel de saisirMatieres
}
