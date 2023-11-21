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
        // Destructeur (si n�cessaire)
        ~Character();
        // Constructeur de copie (si n�cessaire)
        Character(const Character& other);
        // Constructeur de d�placement (si n�cessaire)
        Character(Character&& other) noexcept;
        // Op�rateur d'assignation par copie (si n�cessaire)
        Character& operator=(const Character& other);
        // Op�rateur d'assignation par d�placement (si n�cessaire)
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

