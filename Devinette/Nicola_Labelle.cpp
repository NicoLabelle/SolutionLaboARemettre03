//But : 
/*
L�utilisateur doit deviner un nombre myst�re se situant entre 1 et 100 avec un maximum de 5 chances. Le programme v�rifie 
que l�utilisateur a bien entr� un nombre entre 0 et 100 et lui indique s�il gagne ou dans le cas contraire lui indique le 
nombre d�essais restant et lui redemande un nombre. Le programme indique si la valeur � trouver est plus grande ou plus 
petite que la derni�re proposition que l'utilisateur a faite.
 */
 //Auteur : Nicola Labelle
 //Date : 2020-10-02

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    // D�claration des variables
    int iRandom;
    int essai;
    int nbEssai = 1;
    const int MAX = 100;
    const int MIN = 0;
    const int ESSAI_TOTAL = 5;

    //Pour activer l�al�atoire dans le programme
    srand(time(0));

    //L�ordinateur calcule un nombre al�atoire entre 0 et 100 et le stocke dans iRandom
    iRandom = rand() % 101;

    //Informe l'utilisateur du but du jeu
    cout << "Devinez le nombre qui se situe entre 0 et 100 !" << endl << endl;

    //Demande � l'utilisateur d'entrer un nombre se situant entre 1 et 100
    cout << "Tentative 1 de " << ESSAI_TOTAL << " : ";
    cin >> essai;
    //V�rifie que le nombre est bien situ� entre 0 et 100
    while (essai < MIN || essai > MAX)
    {
        cout << "Votre nombre n'est pas valide. Veuillez entrer un nombre se situant entre 0 et 100." << endl << endl;
        cout << "Tentative 1 de " << ESSAI_TOTAL << " : ";
        cin >> essai;
    }

    //R�p�te jusqu'� ce que l'utilisateur devine le nombre myst�re ou qu'il �puise ses chances de jouer
    while (essai != iRandom && nbEssai < ESSAI_TOTAL)
    {
            //Si le nombre est plus petit que le nombre myst�re
            if (essai < iRandom)
            {
                cout << "Le nombre recherch� est plus grand que " << essai << ". R�essayez !" << endl << endl;  
                //Pour faire diminuer le nombre de chances restantes
                nbEssai = nbEssai + 1;
            }
            //Si le nombre est plus grand que le nombre myst�re
            else
            {
                cout << "Le nombre recherch� est plus petit que " << essai << ". R�essayez !" << endl << endl;
                //Pour faire diminuer le nombre de chances restantes
                nbEssai = nbEssai + 1;
            }

            //Demande � l'utilisateur d'entrer un nombre se situant entre 0 et 100
            cout << "Tentative " << nbEssai << " de " << ESSAI_TOTAL << " : ";
            cin >> essai;
            //V�rifie que le nombre est bien situ� entre 1 et 100
            while (essai <= MIN || essai >= MAX)
            {
                cout << "Votre nombre n'est pas valide. Veuillez entrer un nombre se situant entre 0 et 100." << endl << endl;
                cout << "Tentative " << nbEssai << " de " << ESSAI_TOTAL << " : ";
                cin >> essai;
            }

    }
    //Saute une ligne afin que le programme soit plus beau � voir
    cout << endl;

    //Si l'utilisateur a r�ussi � deviner le nombre myst�re
    if (essai == iRandom)
    {
        cout << "Vous avez gagn� ! Bien jou� !" << endl;;
    }
    //Si l'utilisateur a �puis� toutes ses chances sans succ�s
    else
    {
        cout << "Vous avez perdu. Le nombre myst�re �tait : " << iRandom << "." << endl;;
    }
    return 0;
}