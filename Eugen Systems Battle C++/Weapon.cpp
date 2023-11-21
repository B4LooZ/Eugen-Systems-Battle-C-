#include "Weapon.h"
#include <iostream>

Weapon::Weapon(WeaponType type, int damage) : type(type), damage(damage) {}
// Constructeur de copie
Weapon::Weapon(const Weapon& other)
    : type(other.type), damage(other.damage) {}

// Constructeur de déplacement
Weapon::Weapon(Weapon&& other) noexcept
    : type(std::move(other.type)), damage(std::move(other.damage)) {}

// Opérateur d'assignation de copie
Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        type = other.type;
        damage = other.damage;
    }
    return *this;
}
// Opérateur d'assignation de déplacement
Weapon& Weapon::operator=(Weapon&& other) noexcept {
    if (this != &other) {
        type = std::move(other.type);
        damage = std::move(other.damage);
    }
    return *this;
}
// Destructeur
Weapon::~Weapon()
{
    // Rien de particulier à faire dans ce cas simple
}
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