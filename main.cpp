/*
------------------------------------------------------------------------------
  Fichier     : main.cpp
  Auteur(s)   : Ruben Tomé
  Date        : 28.10.2026

  But         :

  Remarque(s) : les erreurs de saisie ne sont pas vérifiées

  Compilateur : gcc
  ------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Calendar.h"
#include "User.h"
using namespace std;

int main () {

    const int lowerLimit = 1800;
    const int upperLimit = 2100;
    int inputYear = 0;
    bool shouldContinue = 1; // Initialisation à True par défault
    char choiceContinue = 'N';

    do {

        bool isYearCorrect = 1;
        do {
            cout << "Entrer une valeur [1800 - 2100] : ";
            cin >> inputYear;

            isYearCorrect = checkYear(inputYear, lowerLimit, upperLimit);

            if (!isYearCorrect) {
                cout << "/!\ erreur de saisie" << endl;
            }
        }while (!isYearCorrect);


        // Code

        bool isChoiceCorrect = 1;
        do {

            cout << "Voulez-vous recommencer [O/N] : ";
            cin >> choiceContinue;
            isChoiceCorrect = checkChoiceContinue(choiceContinue, 'O', 'N');

        }while (!isChoiceCorrect);

        // Si le choix est non on établit choixRecommencer à false pour ne pas continuer
        if (choiceContinue == 'N') {
            shouldContinue = 0;
        }
    }while (shouldContinue);

    return EXIT_SUCCESS;
}