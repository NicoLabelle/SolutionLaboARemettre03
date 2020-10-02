//But : 
/*
L’utilisateur doit deviner un nombre mystère se situant entre 1 et 100 avec un maximum de 5 chances. Le programme vérifie 
que l’utilisateur a bien entré un nombre entre 0 et 100 et lui indique s’il gagne ou dans le cas contraire lui indique le 
nombre d’essais restant et lui redemande un nombre. Le programme indique si la valeur à trouver est plus grande ou plus 
petite que la dernière proposition que l'utilisateur a faite.
 */
 //Auteur : Nicola Labelle
 //Date : 2020-10-02

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    // Déclaration des variables
    int iRandom;
    int essai;
    int nbEssai = 1;
    const int MAX = 100;
    const int MIN = 0;
    const int ESSAI_TOTAL = 5;

    //Pour activer l’aléatoire dans le programme
    srand(time(0));

    //L’ordinateur calcule un nombre aléatoire entre 0 et 100 et le stocke dans iRandom
    iRandom = rand() % 101;

    //Informe l'utilisateur du but du jeu
    cout << "Devinez le nombre qui se situe entre 0 et 100 !" << endl << endl;

    //Demande à l'utilisateur d'entrer un nombre se situant entre 1 et 100
    cout << "Tentative 1 de " << ESSAI_TOTAL << " : ";
    cin >> essai;
    //Vérifie que le nombre est bien situé entre 0 et 100
    while (essai < MIN || essai > MAX)
    {
        cout << "Votre nombre n'est pas valide. Veuillez entrer un nombre se situant entre 0 et 100." << endl << endl;
        cout << "Tentative 1 de " << ESSAI_TOTAL << " : ";
        cin >> essai;
    }

    //Répète jusqu'à ce que l'utilisateur devine le nombre mystère ou qu'il épuise ses chances de jouer
    while (essai != iRandom && nbEssai < ESSAI_TOTAL)
    {
            //Si le nombre est plus petit que le nombre mystère
            if (essai < iRandom)
            {
                cout << "Le nombre recherché est plus grand que " << essai << ". Réessayez !" << endl << endl;  
                //Pour faire diminuer le nombre de chances restantes
                nbEssai = nbEssai + 1;
            }
            //Si le nombre est plus grand que le nombre mystère
            else
            {
                cout << "Le nombre recherché est plus petit que " << essai << ". Réessayez !" << endl << endl;
                //Pour faire diminuer le nombre de chances restantes
                nbEssai = nbEssai + 1;
            }

            //Demande à l'utilisateur d'entrer un nombre se situant entre 0 et 100
            cout << "Tentative " << nbEssai << " de " << ESSAI_TOTAL << " : ";
            cin >> essai;
            //Vérifie que le nombre est bien situé entre 1 et 100
            while (essai <= MIN || essai >= MAX)
            {
                cout << "Votre nombre n'est pas valide. Veuillez entrer un nombre se situant entre 0 et 100." << endl << endl;
                cout << "Tentative " << nbEssai << " de " << ESSAI_TOTAL << " : ";
                cin >> essai;
            }

    }
    //Saute une ligne afin que le programme soit plus beau à voir
    cout << endl;

    //Si l'utilisateur a réussi à deviner le nombre mystère
    if (essai == iRandom)
    {
        cout << "Vous avez gagné ! Bien joué !" << endl;;
    }
    //Si l'utilisateur a épuisé toutes ses chances sans succès
    else
    {
        cout << "Vous avez perdu. Le nombre mystère était : " << iRandom << "." << endl;;
    }
    return 0;
}