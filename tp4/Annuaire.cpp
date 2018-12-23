#include "Annuaire.h"

using namespace std;




// Exo 1
void Annuaire::ajouter_personne()
{

    Personne toto;
    string nom,prenom;
    cout << "nom ? "<<endl;
    cin>> nom;
    toto.setNom(nom);
    cout << "prenom ? "<<endl;
    cin>> nom;
    toto.setPrenom(prenom);
    rep.push_back(toto);
}

void Annuaire::visualiser() const
{

    vector<Personne>::const_iterator it;
    for(it=rep.begin(); it!=rep.end(); it++) {

        it->affiche();
    }

}


// exo 2
bool Annuaire::rechercher_personne() const
{
    string nom;
    bool boule = false;
    cout<<"taper nom de la personne à rechercher : ";
    cin>>nom;
    for(const Personne & p:rep) {
        if(p.getNom()==nom) {
            p.affiche();
            boule = true;
        }
        return boule;
    }
}

/**
saisie du nom puis affichage de tous les contacts ayant ce nom
puis saisie de l id du contact à supprimer
*/


void Annuaire::supprimer_personne()
{

    if(rechercher_personne()) {
    string temp;
    int id;

        cout<<"Saisir l'id du contact a supprimer : ";
        //cin >> id;
        getline(cin,temp);
        stringstream(temp)>>id;

        for(vector<Personne>::iterator it=rep.begin(); it!=rep.end(); it++)
            if(id==it->getId()) {
                rep.erase(it);
                return;
            }

    }
}


void Annuaire::modifier_personne(){
	if(rechercher_personne()){
		string temp;
		int id;
		cout<<"id de la personne à modifier :";
		getline(cin,temp);
		stringstream(temp)>>id;

		for(const Personne&p : rep)
            if(id==p.getId()){
                cout<<p;
                //tri si nom modifié
                sort(rep.begin(),rep.end());
                return;
            }
    }
}







/**********************************************************************/

void Annuaire::traiter(int choix)
{
    switch(choix) {
    case 0:
        cout<<"A bientot !";
        break;
    case 1:
        visualiser();
        break;
    case 2:
        ajouter_personne();
    case 3:
        rechercher_personne();
        break;
    default:
        cerr<<"erreur de programmation";
    }
}
int Annuaire::selection() const
{
    int resultat;
    bool selection_valide;
    do {
        cout<<endl<<"Votre choix : ";
        cin>>resultat;  // si saisie d'un caractere boucle infinie
        selection_valide = (resultat>=0 && resultat<=100);
        if(!selection_valide) {
            cout<<"erreur saisie "<<endl;
        }
        // pour vider le tampon d'entree
        cin.clear(); // effacer les bits d'erreurs
        cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer

    } while(!selection_valide);

    return resultat;
}
void Annuaire::affiche_menu() const
{
    cout<<"\t\t 0 Quitter"<<endl;
    cout<<"\t\t 1 Visualiser Annuaire"<<endl;
    cout<<"\t\t 2 Ajouter Personne"<<endl;
    cout<<"\t\t 2 Rechercher Personne"<<endl;
}
void Annuaire::gerer()
{
    bool quitter;
    do {
        cout<<endl;
        affiche_menu();
        int choix = selection();
        quitter = choix == 0;
        traiter(choix);
    } while (!quitter);
}

Annuaire::~Annuaire() {}
