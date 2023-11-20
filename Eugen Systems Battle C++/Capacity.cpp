#include "Capacity.h"
#include <iostream>

Capacity::Capacity(CapacityType type, int value, int coolDown) : type(type), probability(value), coolDown(coolDown) {}

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
/// <summary>
/// Return the capacity's cooldown
/// </summary>
/// <returns>the cooldown</returns>
int Capacity::getCoolDown() const
{
    return coolDown;
}
/// <summary>
/// Show capacity's informations
/// </summary>
void Capacity::displayInfo() const
{
    std::cout << "--Capacity Type: " << EnumClass::capacityTypeToString(type) << ", Proba/100: " << probability << ", CoolDown :" << coolDown << std::endl;
}