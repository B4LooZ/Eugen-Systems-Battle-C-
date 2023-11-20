// Eugen Systems Battle C++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include "CharacterInitializer.h"
#include "Battle.h"

int main()
{   
    Character* orc = CharacterInitializer::initializeOrc();
    Character* knight = CharacterInitializer::initializeKnight();
    Battle battle(orc, knight) ;
   
    // Display final result
    battle.startBattle();

    return 0;
}
