#ifndef CHARACTER_INITIALIZER_H
#define CHARACTER_INITIALIZER_H

//#include "Orc.h"
#include "Character.h"
#include "Weapon.h"
#include "Capacity.h"

class CharacterInitializer 
{
    public:
        static Character* initializeOrc();
        static Character* initializeKnight();
};

#endif // CHARACTER_INITIALIZER_H