#include "Capacity.h"

// Constructeur
Capacity::Capacity(CapacityType type, int value, int coolDown) : type(type), probability(value), coolDown(coolDown), counter(0) {}

// Constructeur de copie
Capacity::Capacity(const Capacity& other)
    : type(other.type), probability(other.probability), coolDown(other.coolDown), counter(other.counter) {}

// Constructeur de déplacement
Capacity::Capacity(Capacity&& other) noexcept
    : type(std::move(other.type)), probability(std::move(other.probability)), coolDown(std::move(other.coolDown)), counter(std::move(other.counter)) {}

// Opérateur d'assignation de copie
Capacity& Capacity::operator=(const Capacity& other) 
{
    if (this != &other) {
        type = other.type;
        probability = other.probability;
        coolDown = other.coolDown;
        counter = other.counter;
    }
    return *this;
}

// Opérateur d'assignation de déplacement
Capacity& Capacity::operator=(Capacity&& other) noexcept 
{
    if (this != &other) {
        type = std::move(other.type);
        probability = std::move(other.probability);
        coolDown = std::move(other.coolDown);
        counter = std::move(other.counter);
    }
    return *this;
}

// Destructeur
Capacity::~Capacity() 
{
    // Rien de particulier à faire dans ce cas simple
}

/// <summary>
/// Return the capacity's type
/// </summary>
/// <returns>the type</returns>
CapacityType Capacity::getType() const
{
    return type;
}
/// <summary>
/// Return the capacity's probability
/// </summary>
/// <returns>the probability</returns>
int Capacity::getProbability() const
{
    return probability;
}
int Capacity::getCounter() const
{
    return counter;
}
/// <summary>
/// Return the capacity's cooldown
/// </summary>
/// <returns>the cooldown</returns>
int Capacity::getCoolDown() const
{
    return coolDown;
}
void Capacity::decreaseCounter()
{
    counter = counter - 1 > 0 ? counter - 1 : 0;
}
void Capacity::SetCounter(int val)
{
    counter = val;
}
/// <summary>
/// Show capacity's informations
/// </summary>
void Capacity::displayInfo() const
{
    std::cout << "--Capacity Type: " << EnumClass::capacityTypeToString(type) << ", Proba/100: " << probability << ", CoolDown :" << coolDown << std::endl;
}