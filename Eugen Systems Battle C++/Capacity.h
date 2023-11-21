#pragma once
#include "EnumClass.h"
#include <iostream>
class Capacity
{
    private:
        CapacityType type;
        int probability;
        int coolDown;
        int counter;
    public:
        Capacity(CapacityType type, int probability, int coolDown);
        Capacity(const Capacity& other);  // Constructeur de copie
        Capacity(Capacity&& other) noexcept;  // Constructeur de déplacement
        // Opérateurs d'assignation
        Capacity& operator=(const Capacity& other);  // Opérateur d'assignation de copie
        Capacity& operator=(Capacity&& other) noexcept;  // Opérateur d'assignation de déplacement
        //Destructeur
        ~Capacity();
        CapacityType getType() const;
        int getProbability() const;
        int getCoolDown() const;
        int getCounter() const;
        void decreaseCounter();
        void SetCounter(int val);
        void displayInfo() const;
};

