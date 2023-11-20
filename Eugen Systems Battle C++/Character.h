#ifndef CHARACTER_H
#define CHARACTER_H
#include "Weapon.h"
#include "Capacity.h"
#include "RandomNumberGenerator.cpp"
class Character 
{
    protected:
        int health;
        int shield;      
        int capacityCounter;
        bool canPlay;
        int incapacityCounter;
        Weapon weapon;
        Capacity capacity;
        CharacterType characterType;
    private:
        RandomNumberGenerator rng;
    public:
        Character(int initialHealth, int initialShield, const Weapon& initialWeapon, const Capacity& initialCapacity, const CharacterType& InitialCharacter);
        bool isAlive() const;
        void takeDamage(int damage);
        void regenShield(int regenValue);
        int getHealth() const;
        int getShield() const;
        bool getCanPlay();  
        void UpdateIncapacity();
        void setCanPlay(bool canPlay, int counter);  
        const Weapon& getWeapon() const;
        void setWeapon(const Weapon& weapon);
        void displayInfo() const;
        void displayAllInfo() const;
        int performAttack();
        bool CanPerformCapacity();
        Capacity getCapacity() const;
        CharacterType getCharacterType() const;
        int getIncapacityCounter() const;
        int getCapacityCounter() const;
        void UpdateCapacityCounter();

};
#endif // CHARACTER_H

