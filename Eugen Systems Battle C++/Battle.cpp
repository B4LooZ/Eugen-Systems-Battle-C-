#include "Battle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> 

Battle::Battle(Character* orc, Character* knight) : orc(orc), knight(knight) {}

/// <summary>
/// Lanch the battle
/// </summary>
void Battle::startBattle() 
{
    //Info 
    std::cout << "Orc Info: ";
    orc->displayAllInfo();
    std::cout << "Knight Info: ";
    knight->displayAllInfo();

    //Fonctionality ?
    //did capacity will be lanch when avaible or not
    bool autoCapacity = false;
    char keyPressed;
    std::cout << "\n Press A to auto Capacity (capacity like 'Stun' or 'Charge' would be lanch when they are avaible)" << std::endl;;
    keyPressed = _getch();
    switch (keyPressed)
    {
        case 'a':
        case 'A':
            autoCapacity = true;       
    }
    //Did the knight's shield could regenerate
    bool shieldRegen = false;
    int regenValue = 0;
    std::cout << "\n Press A to allow the regeneration of the Knight's shield between two attacks (poor men): " << std::endl;
    keyPressed = _getch();
    switch (keyPressed)
    {
        case 'a':
        case 'A':
        {
            shieldRegen = true;
            std::cout << " Set regeneration value: " << std::endl;
            std::cin >> regenValue;
        }
            
    }
    // Pause for readability
    std::cout << "\n LET'S FIGHT !";
    std::cin.ignore();

    int nbTour = 1;
    while (orc->isAlive() && knight->isAlive()) 
    {       
        // Pause
        std::cout << "\n=====>Press Enter to continue<=====" << std::endl;
        std::cin.ignore();

        std::cout << "\nTURN: " << nbTour << std::endl;
        //Capacity      
        //try to do capacity and get extra damage if exist
        int orcDamage =  capacityState(orc, knight, autoCapacity);
        int knightDamage = capacityState(knight, orc, autoCapacity);

        //Try to apply attack
        attackState(orc, knight, orcDamage);
        attackState(knight, orc, knightDamage);       

        // Display information after each turn
        std::cout << "--Orc Info: ";
        orc->displayInfo();
        std::cout << "--Knight Info: ";
        knight->displayInfo();
       
        nbTour++;

        //Apply fonctionality
        if (shieldRegen && orc->isAlive() && knight->isAlive())
        {
            knight->regenShield(regenValue);
            std::cout << "Knight Shield Regenerate by "<< regenValue << ". Current shield Value: "<< knight->getShield()<<".\n" << std::endl;
        }
    }

    // Display the winner
    if (orc->isAlive()) 
    {
        std::cout << "\nOrc wins the battle! That a normal day..." << std::endl;       
    }
    else if (knight->isAlive())
    {
        std::cout << "\nKnight wins the battle! That an impossible day..." << std::endl;
    }
    else {
        std::cout << "\nIt's a draw! That a lucky day..." << std::endl;
    }
    //end
    std::cout << "\n=====>Press Enter to finish<=====" << std::endl;
    std::cin.ignore();
}
    /// <summary>
    /// Apply capacity
    /// </summary>
    /// <param name="fromChara">Character who attacks</param>
    /// <param name="toChara">Target character</param>
    /// <returns>Damage value of the capacity</returns>
    int Battle::doCapacity(Character* fromChara, Character* toChara)
    {
        switch (fromChara->getCapacity().getType())
        {
            case CapacityType::Charge:
                //std::cout << "Charge" << std::endl;
                return fromChara->getWeapon().getDamage();
            case CapacityType::Stun:
                //std::cout << "Stun" << std::endl;
                toChara->setCanPlay(false, 1);
                return 0;
                // Ajoutez d'autres cas au besoin
            default:
                return 0;
        }
    }
    /// <summary>
    /// Try to lanch the capacity
    /// </summary>
    /// <param name="fromChara">Character who lanch capacity</param>
    /// <param name="toChara">Character who receive capacity</param>
    /// <param name="autoCapacity">if user decide to use auto attack for capacity </param>
    /// <returns>Damage value of the capacity</returns>
    int Battle::capacityState(Character* fromChara, Character* toChara, bool autoCapacity)
    {
        if (fromChara->getCapacityCounter() == 0)
        {
            if (!autoCapacity)
            {
                char keyPressed;
                std::cout << EnumClass::characterTypeToString(fromChara->getCharacterType());
                std::cout << ": Press 'A' to attempt to cast the capacity " << EnumClass::capacityTypeToString(fromChara->getCapacity().getType()) << std::endl;
                keyPressed = _getch();
                // Décider d'une action en fonction de la touche
                switch (keyPressed)
                {
                    case 'a':
                    case 'A':
                        if (fromChara->CanPerformCapacity())
                        {
                            std::cout << EnumClass::characterTypeToString(fromChara->getCharacterType()) << "'s Capacity Perfomed! (" << EnumClass::capacityTypeToString(fromChara->getCapacity().getType()) << ")" << std::endl;
                            return doCapacity(fromChara, toChara);
                        }
                        else
                        {
                            std::cout << EnumClass::characterTypeToString(fromChara->getCharacterType()) << "'s Capacity Failed... (" << EnumClass::capacityTypeToString(fromChara->getCapacity().getType()) << ")" << std::endl;
                            return 0;
                        }
                    default:
                        return 0;
                }
            } 
            else
            {
                if (fromChara->CanPerformCapacity())
                {
                    std::cout << EnumClass::characterTypeToString(fromChara->getCharacterType()) << "'s Capacity Perfomed! ("<< EnumClass::capacityTypeToString(fromChara->getCapacity().getType())<<")" << std::endl;
                    return doCapacity(fromChara, toChara);
                }
                else
                {
                    std::cout << EnumClass::characterTypeToString(fromChara->getCharacterType()) << "'s Capacity Failed... (" << EnumClass::capacityTypeToString(fromChara->getCapacity().getType())<<")" << std::endl;
                    return 0;
                }
            }
        }
        else
        {
            fromChara->UpdateCapacityCounter();
            return 0;
        }
    }
    /// <summary>
    /// Try to attack
    /// </summary>
    /// <param name="fromChara">Character who attacks</param>
    /// <param name="toChara">Target character</param>
    /// <param name="currentDamage">Damage apply</param>
    void Battle::attackState(Character* fromChara, Character* toChara, int currentDamage)
    {
        if (fromChara->getCanPlay())
        {
            //attacks
            currentDamage += fromChara->performAttack();
            toChara->takeDamage(currentDamage);
            std::cout << EnumClass::characterTypeToString(fromChara->getCharacterType()) << " attacks " << EnumClass::characterTypeToString(toChara->getCharacterType()) << " for " << currentDamage << " damage." << std::endl;
        }
        else
        {           
            std::cout << EnumClass::characterTypeToString(fromChara->getCharacterType()) << " can't attacks "<< EnumClass::characterTypeToString(toChara->getCharacterType()) << ", wait for " << fromChara->getIncapacityCounter() << " turn(s)." << std::endl;
            fromChara->UpdateIncapacity();
        }
    }
