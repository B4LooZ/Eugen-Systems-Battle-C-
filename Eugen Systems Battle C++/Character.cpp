#include "Character.h"
#include <iostream>

Character::Character(int initialHealth, int initialShield, const Weapon& initialWeapon, const Capacity& initialCapacity, const CharacterType& initialCharacter) :
    health(initialHealth), shield(initialShield), weapon(initialWeapon), capacity(initialCapacity), characterType(initialCharacter),
    capacityCounter(0), canPlay(true), incapacityCounter(0)  
{
}
/// <summary>
/// Check if the caractere is still alive
/// </summary>
/// <returns>value</returns>
bool Character::isAlive() const 
{
    return health > 0;
}
/// <summary>
/// Taking damage
/// </summary>
/// <param name="damage">Damage value</param>
void Character::takeDamage(int damage) 
{
    if (shield > 0) 
    {
        shield -= damage;
        if (shield < 0) 
        {
            health += shield;  // Apply excess damage to health
            shield = 0;
        }
    }
    else 
    {
        health -= damage;
    }
}
/// <summary>
/// Fonctionality paramater, that allow to a character to regen te shield between each turn 
/// Used here for the poor knight who lose every fight
/// </summary>
/// <param name="regenValue">regenration value for the shield</param>
void Character::regenShield(int regenValue)
{
    shield += regenValue;
}
/// <summary>
/// Returnr the health value of the character
/// </summary>
/// <returns>health value</returns>
int Character::getHealth() const 
{
    return health;
}
/// <summary>
/// Return the shield value of the character 
/// </summary>
/// <returns>shield value</returns>
int Character::getShield() const 
{
    return shield;
}
/// <summary>
/// Return if the caractere can play
/// </summary>
/// <returns></returns>
bool Character::getCanPlay() 
{
    canPlay = incapacityCounter <= 0;
    return canPlay;
}
/// <summary>
/// Used for minus 1 the incapacity counter
/// </summary>
void Character::UpdateIncapacity()
{
    incapacityCounter = incapacityCounter - 1 < 0 ? 0 : incapacityCounter - 1;
}
/// <summary>
/// Update canPlay value, and for how many time (used here to set it to false)
/// </summary>
/// <param name="canPlayValue">Value</param>
/// <param name="counter">How many time</param>
void Character::setCanPlay(bool canPlayValue, int counter) 
{
    canPlay = canPlayValue;
    incapacityCounter = counter;
}
/// <summary>
/// Display all informations about the charater
/// </summary>
void Character::displayAllInfo() const 
{
    displayInfo();    
    weapon.displayInfo();
    capacity.displayInfo();
}
/// <summary>
/// Display classics information abaout the character
/// </summary>
void Character::displayInfo() const
{    
    std::cout << "Health: " << health << ", Shield: " << shield << ", CanPlay: " << (canPlay ? "true" : "false") << ", Type: " << EnumClass::characterTypeToString(characterType) << std::endl;
    std::cout << "Time to wait before the next Capacity: " << capacityCounter << std::endl;
}
/// <summary>
/// Return character's weapon
/// </summary>
/// <returns>the weapon</returns>
const Weapon& Character::getWeapon() const 
{
    return weapon;
}
/// <summary>
/// Return the character's type
/// </summary>
/// <returns>the type</returns>
CharacterType Character::getCharacterType() const
{
    return characterType;
}
/// <summary>
/// Update the weapon
/// </summary>
/// <param name="weaponValue">new weapon</param>
void Character::setWeapon(const Weapon& weaponValue) 
{
    weapon = weaponValue;
}
/// <summary>
/// Check if the caractere can perform his capacity
/// </summary>
/// <returns></returns>
bool Character::CanPerformCapacity()
{   
        //-1 car "Cette capacité ne peut être utilisée que tous les X tours de jeu." 
        //ex: Si on utilise tour 1, c'est actif, donc le tour 1 compte dans les X de cooldowns et on peux retenter tour 1 + X
        capacityCounter = capacity.getCoolDown() - 1; 

        int tempRandomVal = rng.getRandomValue();       
       
        if (tempRandomVal < capacity.getProbability())
        {           
            return true;
        } 
        else
        {
            return false;
        }
   
}
/// <summary>
/// Update the Capacity Counter
/// </summary>
void Character::UpdateCapacityCounter()
{
    capacityCounter--;
}
/// <summary>
/// Charactere doing attack
/// </summary>
/// <returns>the damage</returns>
int Character::performAttack()
{   
    return weapon.getDamage();  
}
/// <summary>
/// Return the capacity
/// </summary>
/// <returns>the capacity</returns>
Capacity Character::getCapacity() const
{
    return capacity;
}
/// <summary>
/// Return the incapacity counter
/// </summary>
/// <returns>the incapacity counter</returns>
int Character::getIncapacityCounter() const
{
    return incapacityCounter; 
}
/// <summary>
/// Return the capacity counter
/// </summary>
/// <returns>the capacity counter</returns>
int Character::getCapacityCounter() const
{
    return capacityCounter;
}