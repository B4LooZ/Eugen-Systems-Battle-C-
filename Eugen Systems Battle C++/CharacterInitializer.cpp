#include "CharacterInitializer.h"

Character* CharacterInitializer::initializeOrc() 
{
    Weapon orcWeapon(WeaponType::Axe, 8);
    Capacity orcCapacity(CapacityType::Stun, 20, 5);
    CharacterType type(CharacterType::Orc);
    return new Character(60, 0, orcWeapon, orcCapacity, type);
}

Character* CharacterInitializer::initializeKnight()
{
    Weapon knightWeapon(WeaponType::Sword, 5);
    Capacity knightCapacity(CapacityType::Charge, 60, 3);
    CharacterType type(CharacterType::Knight);
    return new Character(20, 50, knightWeapon, knightCapacity, type);
}