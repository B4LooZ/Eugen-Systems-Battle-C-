#ifndef BATTLE_H
#define BATTLE_H
//#include "Knight.h"
//#include "Orc.h"
#include "Character.h"
class Battle 
{
    private:
        Character* knight;
        Character* orc;

    public:
        Battle(Character* orc, Character* knight);
        void startBattle();
        int doCapacity(Character* fromChara, Character* toChara);
        int capacityState(Character* fromChara, Character* toChara, bool autoCapacity);
        void attackState(Character* fromChara, Character* toChara, int currentDamage);
};
#endif // BATTLE_H
