#include "Weapon.h"
#include <iostream>

Weapon::Weapon(WeaponType type, int damage) : type(type), damage(damage) {}
/// <summary>
/// The weapon type
/// </summary>
/// <returns>the type</returns>
WeaponType Weapon::getType() const 
{
    return type;
}
/// <summary>
/// Weapon's damage
/// </summary>
/// <returns>damage</returns>
int Weapon::getDamage() const
{
    return damage;
}
/// <summary>
/// Set the weapon type
/// </summary>
/// <param name="typeValue">type</param>
void Weapon::setType(WeaponType typeValue)
{
    type = typeValue;
}
/// <summary>
/// Set weapon's damage
/// </summary>
/// <param name="damageValue">damage</param>
void Weapon::setDamage(int damageValue) 
{
    damage = damageValue;
}
/// <summary>
/// Show Weapon's informations
/// </summary>
void Weapon::displayInfo() const
{
    std::cout << "--Weapon Type: " << EnumClass::weaponTypeToString(type) << ", Damage: " << damage << std::endl;
}