#include "Calendar.h"
#include <iostream>
#include <ctime>
#include <array>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <string>

using namespace std;

const array<char,7> weekDaysLetters {'L', 'M', 'M', 'J', 'V', 'S', 'D'};
const array<string, 12> months = {
    "Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet",
    "Août", "Septembre", "Octobre", "Novembre", "Décembre"
};


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int daysInMonth(int month, int year) {

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
    }
}

int firstDayOfMonth(int month, int year) {

    struct tm date_info = {0};
    date_info.tm_year = year - 1900;
    date_info.tm_mon = month - 1;
    date_info.tm_mday = 1;
    mktime(&date_info);
    return date_info.tm_wday;
}

void displayMonth(int month, int year) {

    int compteur = 0;

    // Affichage Mois + année
    cout << endl;
    cout << setw(5) << months[month - 1] << ' ' << year << endl;

    for (size_t i = 0; i < weekDaysLetters.size(); i++) {
        cout << setw(5) << weekDaysLetters[i] ;
    }

    cout << endl;

    int firstDay = firstDayOfMonth(month, year);
    if (firstDay == 0) {
        firstDay = 7;
    }

    int nbDaysInMonth = daysInMonth(month, year);

    for (int j = 1; j < firstDay; j++) {
        cout << setw(5) << ' ';
        compteur++;
    }

    for (int k = 1; k <= nbDaysInMonth; k++) {
        cout << setw(5) << k;
        compteur++;
        if (compteur == 7) {
            cout << endl;
            compteur = 0;
        }
    }

    cout << endl;
}

void displayCalendar(int year) {

    for (int i = 1; i <= 12; i++) {
        displayMonth(i, year);
    }
}


