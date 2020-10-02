//But : 
/* 
Demande � l'utilisateur d'entrer les ventes brutes hebdomadaires de chaque repr�sentant et calcul et affiche son salaire.
 Les valeurs de vente et de semaine doivent �tre sup�rieures � 0.
 Entrer la valeur -1 dans vente pour quitter le programme et afficher le salaire total de tous les repr�sentants.
 */
 //Auteur : Nicola Labelle
 //Date : 2020-10-02

/*Plan de tests
     vente        semaine          salaire            salaireTotal
     5000         1                625 $
     3610         2                770.75 $
     9535         3                1465.13 $
     -1                                               2860.88 $
 */

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    // D�claration des variables
    const int QUITTER = -1;
    float vente;
    int semaine;
    float salaire;
    float salaireTotal = 0;

    //Demande la valeur des ventes brutes en s'assurant que la valeur entr�e est sup�rieure � 0
    cout << "Entrez la valeur des ventes brutes : ";
    cin >> vente;
    while (vente <= 0 && vente != QUITTER)
    {
        cout << "ERREUR : Veuillez entrer un nombre sup�rieur � 0." << endl;
        cout << "Entrez la valeur des ventes brutes : ";
        cin >> vente;
    }

    //Tant que la valeur des ventes entr�e n'est pas -1
    while (vente != QUITTER)
    {
        //Demande le nombre de semaine en s'assurant que la valeur entr�e est sup�rieure � 0
        cout << "Entrez le nombre de semaine : ";
        cin >> semaine;
        while (semaine <= 0)
        {
            cout << "ERREUR : Veuillez entrer un nombre sup�rieur � 0." << endl;
            cout << "Entrez le nombre de semaine : ";
            cin >> semaine;
        }

        //Calcule et affiche le salaire du repr�sentant
        salaire = (semaine * 250) + (vente / 100 * 7.5);
        cout << "Le salaire du repr�sentant est de : " << salaire << " $." << endl << endl;

        //Calcule le salaire total de tous les repr�sentants
        salaireTotal = salaireTotal + salaire;

        //Demande la valeur des ventes brutes en s'assurant que la valeur entr�e est sup�rieure � 0
        cout << "Entrez la valeur des ventes brutes : ";
        cin >> vente;
        while (vente <= 0 && vente != QUITTER)
        {
            cout << "ERREUR : Veuillez entrer un nombre sup�rieur � 0." << endl;
            cout << "Entrez la valeur des ventes brutes : ";
            cin >> vente;
        }
    }

    //Affiche le salaire total de tous les repr�sentants
    if (salaireTotal)
    {
        cout << "Le salaire total de tous les repr�sentants est de :" << salaireTotal << " $." << endl;
    }

    return 0;
}