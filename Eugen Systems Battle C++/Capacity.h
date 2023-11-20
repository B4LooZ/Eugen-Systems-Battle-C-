#ifndef CAPACITY_H
#define CAPACITY_H

#include "EnumClass.h"
class Capacity
{
    private:
        CapacityType type;
        int probability;
        int coolDown;
    public:
        Capacity(CapacityType type, int probability, int coolDown);
        CapacityType getType() const;
        int getProbability() const;
        int getCoolDown() const;
        void displayInfo() const;
};
#endif // CAPACITY_H

