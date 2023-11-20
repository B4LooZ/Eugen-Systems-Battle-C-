#include <cstdlib>
#include <ctime>

class RandomNumberGenerator 
{
    public:
    RandomNumberGenerator() 
    {
        // Initialize random number generator with current seed of time
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    int getRandomValue() const {
        // Using rand()
        return rand() % 100;
    }
};