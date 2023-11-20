#ifndef WEAPON_H
#define WEAPON_H

#include "EnumClass.h"

class Weapon 
{
    private:
        WeaponType type;
        int damage;

    public:
        Weapon(WeaponType type, int damage);
        WeaponType getType() const;
        int getDamage() const;
        void setType(WeaponType type);
        void setDamage(int damage);
        void displayInfo() const;
};

#endif // WEAPON_H