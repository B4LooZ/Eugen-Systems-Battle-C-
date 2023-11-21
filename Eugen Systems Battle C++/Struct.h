//#ifndef STRUCT_H
//#define STRUCT_H
#pragma once
#include "Weapon.h"
#include <vector>
#include "Capacity.h"
#include <string>
class Struct
{
    public:
        // Structure pour représenter une arme avec une valeur d'attaque
        struct WeaponInfo 
        {
            int attackValue;
            // Constructeur pour faciliter l'initialisation
            WeaponInfo(int attack) : attackValue(attack) {}
        };
        struct CharacterInfo
        {
            int health;
            int shield;
            CharacterType type;
            WeaponType weapon;
            std::vector<CapacityType> capacities;
            std::string name;
            // Constructeur pour faciliter l'initialisation
            CharacterInfo(int health, int shield, CharacterType type, WeaponType weapon, std::vector<CapacityType> capacities, std::string name) : health(health), shield(shield), type(type), weapon(weapon), capacities(capacities), name(name) {}
        };
        struct CapacityInfo
        {
            int probability;
            int coolDown;
            // Constructeur pour faciliter l'initialisation
            CapacityInfo(int probability, int coolDown) : probability(probability), coolDown(coolDown) {}
        };
};

