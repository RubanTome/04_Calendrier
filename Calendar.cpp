#include "Calendar.h"
#include <iostream>
#include <ctime>
#include <array>

using namespace std;


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

}

void displayCalendar() {


}


