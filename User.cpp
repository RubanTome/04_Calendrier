#include "User.h"


bool checkYear(int input, int min, int max) {
    return (input >= min && input <= max);
}

bool checkChoiceContinue(char input, char yes, char no) {
    return (input == yes || input == no);
}