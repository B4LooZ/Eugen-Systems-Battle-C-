#pragma once
#include <vector>
#include "Weapon.h"
#include "Capacity.h"
#include "RandomNumberGenerator.h"
#include <string> 
class Character 
{
    protected:
        int health;
        int shield;      
        //int capacityCounter;
        bool canPlay;
        int incapacityCounter;
        Weapon weapon;
        std::vector<Capacity> capacities;
        CharacterType characterType;
        std::string name;
    private:
        RandomNumberGenerator rng;
    public:
        Character(int initialHealth, int initialShield, const Weapon& initialWeapon, const std::vector<Capacity>& initialCapacity, const CharacterType& InitialCharacter, std::string initialName);
        // Destructeur (si nécessaire)
        ~Character();
        // Constructeur de copie (si nécessaire)
        Character(const Character& other);
        // Constructeur de déplacement (si nécessaire)
        Character(Character&& other) noexcept;
        // Opérateur d'assignation par copie (si nécessaire)
        Character& operator=(const Character& other);
        // Opérateur d'assignation par déplacement (si nécessaire)
        Character& operator=(Character&& other) noexcept;
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
        bool CanPerformCapacity(int index);
        std::vector<Capacity> getCapacities() const;
        CharacterType getCharacterType() const;
        int getIncapacityCounter() const;
        int getCapacityCounter(int index) const;
        void UpdateCapacityCounter(int index);
        std::string GetName() const;
};

