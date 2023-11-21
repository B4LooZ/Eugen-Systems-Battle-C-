#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <conio.h> 
#include <algorithm>

#include "Character.h"
// Autres inclusions nécessaires pour Battle
#include "Struct.h"

class Battle 
{
    private:
        std::vector<std::unique_ptr<Character>> characteres;
        bool manualInit;
    public:       
        Battle();
        void Initialisation();
        void startBattle();
        void reset();
        int doCapacity(std::unique_ptr<Character>& fromChara, std::unique_ptr<Character>& toChara);
        int capacityState(std::unique_ptr<Character>& fromChara, std::unique_ptr<Character>& toChara, bool autoCapacity);
        void attackState(std::unique_ptr<Character>& fromChara, std::unique_ptr<Character>& toChara, int currentDamage);
};
