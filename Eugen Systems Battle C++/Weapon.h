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
        // Constructeur de déplacement
        Weapon(Weapon&& other) noexcept;
        // Opérateur d'assignation de copie
        Weapon& operator=(const Weapon& other);
        // Opérateur d'assignation de déplacement
        Weapon& operator=(Weapon&& other) noexcept;
        // Destructeur (s'il est nécessaire)
        ~Weapon();
        WeaponType getType() const;
        int getDamage() const;
        void setType(WeaponType type);
        void setDamage(int damage);
        void displayInfo() const;
};