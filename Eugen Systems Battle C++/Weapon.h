#pragma once
#include "EnumClass.h"

class Weapon 
{
    private:
        WeaponType type;
        int damage;

    public:
        Weapon(WeaponType type, int damage);
        // Constructeur de copie
        Weapon(const Weapon& other);
        // Constructeur de d�placement
        Weapon(Weapon&& other) noexcept;
        // Op�rateur d'assignation de copie
        Weapon& operator=(const Weapon& other);
        // Op�rateur d'assignation de d�placement
        Weapon& operator=(Weapon&& other) noexcept;
        // Destructeur (s'il est n�cessaire)
        ~Weapon();
        WeaponType getType() const;
        int getDamage() const;
        void setType(WeaponType type);
        void setDamage(int damage);
        void displayInfo() const;
};