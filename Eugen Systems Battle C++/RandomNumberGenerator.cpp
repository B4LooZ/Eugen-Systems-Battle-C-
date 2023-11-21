#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
{
    // Initialize random number generator with current seed of time
    srand(static_cast<unsigned int>(time(nullptr)));
}

int RandomNumberGenerator :: getRandomValue() const {
    // Using rand()
    return rand() % 100;
}
int RandomNumberGenerator::getRandomValueBetween(int max) const {
    // Using rand()
    return rand() % max;
}
