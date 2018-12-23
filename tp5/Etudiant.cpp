#include "Etudiant.h"


using namespace std;

void Etudiant::affiche() const
{
    Personne::affiche();
    cout<<"Moyenne globale : "<<getMoyenneGlobale()<<endl;
}

void Etudiant::saisir()
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

void Etudiant::setNote(string matiere, float note)
{
    notes[matiere] = note;


   /*
    list<matiere>::iterator it;
    for (it = matieres.begin(); it != matieres.end();it++)
    {
        if (mat==it->nom){
            it->note = note ;
            return;
        }
	}
    cerr<<mat<<"non suivie "<<endl;*/
}

float Etudiant::getMoyenneGlobale() const
    // retourne la moyenne globale de l'etudiant.
{
	float moy=0;
	//1ere methode c++ 2011
//	for(const matiere& m : matieres)
  //      moy+=m.note;
	//2eme methode
	/*list<matiere>::const_iterator it;

    for (it = matieres.begin(); it != matieres.end();it++)
    {
        moy = moy + it->note;
	}*/
    // const_iterator car méthode déclaree const
	for (map<string, int>::const_iterator it=notes.begin(); it!=notes.end(); ++it)
    //std::cout << it->first << " => " << it->second << '\n';
    moy+= it->second;

    if (nbMatieres)
        return moy/nbMatieres;
    else
        return -1;
}

void Etudiant::saisirMatieres()
{
	for (int i=0; i< nbMatieres; i++)
	{
		string matiere;
		float note;
		cout << "matiere " << i << " : ";
	    getline(cin,matiere);
	    cout << "note obtenue : ";
	    //cin>>notes[i];
	    //cin.get(); //permet de vider le tampon d'entree
	    string note_temp;
	    getline(cin,note_temp);
	    stringstream(note_temp)>>note;

	    notes[matiere]=note;

	    //matieres.push_back(temp);
	}
}
Etudiant::~Etudiant(){}

Etudiant::Etudiant(string nom, string prenom,int n): Personne(nom,prenom),nbMatieres(n)
{
	//saisie des matieres ds appel de saisirMatieres
}
