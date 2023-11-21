#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H
#include <cstdlib>
#include <ctime>
class RandomNumberGenerator
{
public:
    RandomNumberGenerator();
    int getRandomValue() const;
    int getRandomValueBetween(int max) const;
};

#endif // RANDOM_NUMBER_GENERATOR_H