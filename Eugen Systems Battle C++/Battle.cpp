#include "Battle.h"

Battle::Battle(): manualInit(false) {}
void Battle::Initialisation()
{
    // Tableau associatif pour stocker les informations 
    const std::unordered_map<WeaponType, Struct::WeaponInfo> weaponInfoMap =
    {
        {WeaponType::Sword, Struct::WeaponInfo(5)},  // Valeur d'attaque pour l'épée
        {WeaponType::Axe, Struct::WeaponInfo(8)},    // Valeur d'attaque pour la hache
        // Ajoutez au besoin
    };
    const std::unordered_map<int, Struct::CharacterInfo> characterInfoMap =
    {
        {0, Struct::CharacterInfo(20,50,CharacterType::Knight, WeaponType::Sword,{CapacityType::Charge},"Dark Knight")},
        {1, Struct::CharacterInfo(60,0,CharacterType::Orc, WeaponType::Axe,{CapacityType::Stun},"Azog")},
        // Ajoutez au besoin
    };
    const std::unordered_map<CapacityType, Struct::CapacityInfo> capacityInfoMap =
    {
        {CapacityType::Charge, Struct::CapacityInfo(60,3)},
        {CapacityType::Stun, Struct::CapacityInfo(20,5)},
        // Ajoutez au besoin
    };

    char keyPressed;
    std::cout << "Welcome to the fight arena simulator !";
    std::cout << "\n Do you want to set characteres manualy ? If not, one Orc and one Knight will fights. Yes (y) / No (n)" << std::endl;;
    keyPressed = _getch();
    switch (keyPressed)
    {
        case 'y':
        case 'Y':
            manualInit = true;
            break;
        default:
        case 'n':
        case 'N':
            manualInit = false;
            break;
    }
    if (manualInit)
    {
        int nbChara = -1;
        while (nbChara < 2)
        {
            std::cout << "Enter number of fighter : " << std::endl;
            std::cin >> nbChara;
            if (nbChara < 2)
            {
                std::cout << "Needed minimum of two characters to start a fight " << std::endl;
            }
        }
        
             
        for (int i = 0; i < nbChara; ++i)
        {
            std::string tempName;
            std::cout << "Enter a character name: ";
            std::cin >> tempName;
            //CHOIX TYPE DE PERSO
            int SelectedChara = -1;
            // Demander à l'utilisateur de choisir
            std::cout << "Select character "<< i + 1<<" : " << std::endl;
            int userChoice = -1;
            while (userChoice < 0 || userChoice >= static_cast<int>(CharacterType::Count))
            {
                for (int y = 0; y < static_cast<int>(CharacterType::Count); ++y)
                {
                    CharacterType type = static_cast<CharacterType>(y);
                    std::cout << static_cast<int>(type) << " : " << EnumClass::characterTypeToString(type) << std::endl;
                }
                std::cout << "Enter number of the selected type: ";
                std::cin >> userChoice;
                SelectedChara = userChoice;
                if (userChoice < 0 || userChoice >= static_cast<int>(CharacterType::Count))
                {
                    std::cout << "Error. Please enter correct value." << std::endl;
                }
            }
            // Traiter le choix de l'utilisateur
            CharacterType selectedType = static_cast<CharacterType>(userChoice);
            // Afficher le choix de l'utilisateur
            std::cout << "Selected : " << EnumClass::characterTypeToString(selectedType) << std::endl;

            //CHOIX DE L'ARME
            std::cout << "Select weapons: " << std::endl;
            userChoice = -1;
            while (userChoice < 0 || userChoice >= static_cast<int>(WeaponType::Count))
            {
                for (int y = 0; y < static_cast<int>(WeaponType::Count); ++y)
                {
                    WeaponType type = static_cast<WeaponType>(y);
                    std::cout << static_cast<int>(type) << " : " << EnumClass::weaponTypeToString(type) << std::endl;
                }
                std::cout << "Enter number of the selected weapon: ";
                std::cin >> userChoice;
                if (userChoice < 0 || userChoice >= static_cast<int>(WeaponType::Count))
                {
                    std::cout << "Error. Please enter correct value." << std::endl;
                }
            }
            WeaponType selectedWeaponType = static_cast<WeaponType>(userChoice);
            std::cout << "Selected : " << EnumClass::weaponTypeToString(selectedWeaponType) << std::endl;
            std::cout << "Select capacity: " << std::endl;

            //CHOIX DES CAPACITés
            userChoice = -1;
            bool validateCapacities = false;
            std::vector<Capacity> capacities;
            while (userChoice < 0 || userChoice >= static_cast<int>(CapacityType::Count) || validateCapacities == false)
            {
                for (int y = 0; y < static_cast<int>(CapacityType::Count); ++y)
                {
                    CapacityType type = static_cast<CapacityType>(y);
                    std::cout << static_cast<int>(type) << " : " << EnumClass::capacityTypeToString(type) << std::endl;
                }
                std::cout << "Enter number of the selected capacity: ";
                std::cin >> userChoice;
                if (userChoice < 0 || userChoice >= static_cast<int>(CapacityType::Count))
                {
                    std::cout << "Error. Please enter correct value." << std::endl;
                }
                else
                {
                    // Récupérer les informations associées à CapacityType
                    auto capacityeInfoIterator = capacityInfoMap.find(static_cast<CapacityType>(userChoice));
                    if (capacityeInfoIterator != capacityInfoMap.end())
                    {
                        // Utiliser les informations trouvées
                        Struct::CapacityInfo chargeInfo = capacityeInfoIterator->second;
                        CapacityType searchType = static_cast<CapacityType>(userChoice);
                        auto it = std::find_if(capacities.begin(), capacities.end(),
                            [searchType](const Capacity& capacity) { return capacity.getType() == searchType; });
                        if (it != capacities.end()) 
                        {
                            // L'élément est présent
                            std::cout << "Capacity already present." << std::endl;
                            validateCapacities = false;
                        }
                        else 
                        {
                            // L'élément n'est pas présent
                            capacities.push_back(Capacity(static_cast<CapacityType>(userChoice), chargeInfo.probability, chargeInfo.coolDown));
                            std::cout << "Capacity added." << std::endl;
                        }
                    }
                    std::cout << "\n Do you want to add more capacities ? Yes (y) / No (n)" << std::endl;
                    keyPressed = _getch();
                    switch (keyPressed)
                    {
                        case 'y':
                        case 'Y':
                            if (capacities.size() >= static_cast<int>(CapacityType::Count))
                            {
                                validateCapacities = true;
                                std::cout << "You already have all capacities";
                            }                              
                            else
                            {
                                validateCapacities = false;
                            }                            
                            break;
                        default:
                        case 'n':
                        case 'N':
                            validateCapacities = true;
                            break;
                    }
                }
            }
            std::cout << "Character Validated" << std::endl;
            auto WeaponInfoIterator = weaponInfoMap.find(selectedWeaponType);
            Struct::WeaponInfo weaponInfo = WeaponInfoIterator->second;
            auto CharactereInfoIterator = characterInfoMap.find(SelectedChara);
            Struct::CharacterInfo charaInfo = CharactereInfoIterator->second;  

            characteres.push_back(std::make_unique<Character>(charaInfo.health, charaInfo.shield, Weapon(selectedWeaponType, weaponInfo.attackValue), capacities, selectedType, tempName));
            characteres[i]->displayAllInfo();          
        }
    }
    else
    {
        std::cout << "Automatic characters creations" << std::endl;
        for (size_t  i = 0; i < characterInfoMap.size(); i++)
        {
            auto CharactereInfoIterator = characterInfoMap.find(i);
            Struct::CharacterInfo charaInfo = CharactereInfoIterator->second;
            auto WeaponInfoIterator = weaponInfoMap.find(charaInfo.weapon);
            Struct::WeaponInfo weaponInfo = WeaponInfoIterator->second;

            std::vector<Capacity> convertedCapacities;
            for (const auto& capacityType : charaInfo.capacities)
            {
                auto capacityInfoIterator = capacityInfoMap.find(capacityType);
                if (capacityInfoIterator != capacityInfoMap.end()) {
                    Struct::CapacityInfo capacityInfo = capacityInfoIterator->second;
                    convertedCapacities.push_back(Capacity(capacityType, capacityInfo.probability, capacityInfo.coolDown));
                }
            }
            characteres.push_back(std::make_unique<Character>(charaInfo.health, charaInfo.shield, Weapon(charaInfo.weapon, weaponInfo.attackValue), convertedCapacities, charaInfo.type, charaInfo.name));
        }
    }
}

/// <summary>
/// Lanch the battle
/// </summary>
void Battle::startBattle() 
{
    RandomNumberGenerator rng;
    Initialisation();

    //Fonctionality ?
    //did capacity will be lanch when avaible or not
    bool autoCapacity = false;
    bool autoTarget = false;
    bool shieldRegen = false;
    int regenValue = 0;
    char keyPressed;
    std::cout << "\n Press 'y' to auto Capacity (capacity like 'Stun' or 'Charge' would be lanch when they are avaible)" << std::endl;;
    keyPressed = _getch();
    switch (keyPressed)
    {
        case 'y':
        case 'Y':
            autoCapacity = true;       
    }
    std::cout << "\n Press 'y' to auto Target (capacity and attacks would target a random fighter)" << std::endl;;
    keyPressed = _getch();
    switch (keyPressed)
    {
        case 'y':
        case 'Y':
            autoTarget = true;
    }  
    std::cout << "\n Press 'y' to regen shield for all knight" << std::endl;;
    keyPressed = _getch();
    switch (keyPressed)
    {
        case 'y':
        case 'Y':
            shieldRegen = true;
            std::cout << "\n Enter regen value ";
            std::cin >> regenValue;
            std::cout << "\n Regen value set to " << regenValue << std::endl;
    }
    // Pause for readability
    std::cout << "\n LET'S FIGHT !";
    std::cin.ignore();

    int nbTour = 1;
    bool isOneMoreThanOneUnitAlive = true;
    while (isOneMoreThanOneUnitAlive)
    {
        PerformTurn(nbTour, autoCapacity, autoTarget, rng);      
        nbTour++;
        int nbCharaAlive = std::count_if(characteres.begin(), characteres.end(), [](const auto& character) {
            return character->isAlive();
            });
        isOneMoreThanOneUnitAlive = nbCharaAlive > 1;
        //Apply fonctionality
        if (shieldRegen && isOneMoreThanOneUnitAlive)
        {
            for (size_t j = 0; j < characteres.size(); j++)
            {
                if (characteres[j]->getCharacterType() == CharacterType::Knight)
                {
                    characteres[j]->regenShield(regenValue);
                    std::cout << characteres[j]->GetName() << "'s Shield Regenerate by " << regenValue << ". Current shield Value: " << characteres[j]->getShield() << ".\n" << std::endl;
                }
            }
        }
    }
    bool findAlive = false;
    for (size_t  y = 0; y < characteres.size(); y++)
    {
        if (characteres[y]->isAlive())
        { // Display the winner
            std::cout << "\n" << characteres[y]->GetName() << " WIN !" << std::endl;
            findAlive = true;
        }
    }
    if (!findAlive)
    {
        std::cout << "\n" <<" It's a draw !" << std::endl;
    }
    //end
    std::cout << "\n END" << std::endl;
    std::cout << "\n Do you play want another games ? y(yes) " << std::endl;;
    keyPressed = _getch();
    switch (keyPressed)
    {
        case 'y':
        case 'Y':
            reset();
            startBattle();       
    }
    std::cout << "\n=====>Press Enter to finish<=====" << std::endl;
    std::cin.ignore();

}
/// <summary>
/// Do a turn
/// </summary>
/// <param name="nbTour">actual turn</param>
/// <param name="autoCapacity"></param>
/// <param name="autoTarget"></param>
/// <param name="rng"></param>
void Battle::PerformTurn(int nbTour, bool autoCapacity, bool autoTarget, RandomNumberGenerator rng)
{
    // Pause
    std::cout << "\n=====>>Press Enter to continue<=====" << std::endl;
    std::cin.ignore();
    std::cout << "TURN : " << nbTour << std::endl;
    std::vector<int> damageCollection;
    std::vector<int> cibleCollection;
    std::vector<int> listAttaquants;
    // Déterminer les cibles pour chaque personnage
    for (size_t y = 0; y < characteres.size(); y++)
    {
        if (characteres[y]->isAlive())
        {
            if (autoTarget)
            {
                // Trouver une cible vivante aléatoire (différente de l'attaquant)
                int indexCible = y;
                while (indexCible == y || !characteres[indexCible]->isAlive())
                {
                    indexCible = rng.getRandomValueBetween(characteres.size());
                }
                listAttaquants.push_back(y);
                cibleCollection.push_back(indexCible);
                damageCollection.push_back(capacityState(characteres[y], characteres[indexCible], autoCapacity));
            }
            else
            {
                std::cout << "Select target for " << characteres[y]->GetName() << "." << std::endl;
                std::cout << "Targets : " << std::endl;

                int indexCible = -1;
                while (indexCible == -1 || indexCible == y)
                {
                    std::vector<int> listTargets;
                    for (size_t z = 0; z < characteres.size(); ++z)
                    {
                        if (characteres[z]->isAlive() && z != y)
                        {
                            std::cout << "Name: " << characteres[z]->GetName() << " Type: " << EnumClass::characterTypeToString(characteres[z]->getCharacterType()) << " : " << z << "." << std::endl;
                            listTargets.push_back(z);
                        }
                    }
                    std::cin >> indexCible;
                    auto it = std::find(listTargets.begin(), listTargets.end(), indexCible);
                    if (it == listTargets.end())
                    {
                        indexCible = -1;
                    }
                }
                listAttaquants.push_back(y);
                cibleCollection.push_back(indexCible);
                damageCollection.push_back(capacityState(characteres[y], characteres[indexCible], autoCapacity));
            }
        }
        else
        {
            cibleCollection.push_back(0);
            damageCollection.push_back(0);
        }
    }
    // Appliquer les dégâts aux cibles
    for (size_t y = 0; y < characteres.size(); y++)
    {
        auto it = std::find(listAttaquants.begin(), listAttaquants.end(), y);
        if (it != listAttaquants.end())
        {
            attackState(characteres[y], characteres[cibleCollection[y]], damageCollection[y]);
        }
    }
    // Afficher les informations après chaque tour
    for (size_t j = 0; j < characteres.size(); j++)
    {
        characteres[j]->displayInfo();
    }
}
void Battle::reset()
{
    characteres.clear();
}

/// <summary>
/// Try to lanch the capacity
/// </summary>
/// <param name="fromChara">Character who lanch capacity</param>
/// <param name="toChara">Character who receive capacity</param>
/// <param name="autoCapacity">if user decide to use auto attack for capacity </param>
/// <returns>Damage value of the capacity</returns>
int Battle::capacityState(std::unique_ptr<Character>& fromChara, std::unique_ptr<Character>& toChara, bool autoCapacity)
{
    // une seule tentative d'envoie de capacité par tour, si deux capacité peuvent se declenché le meme tour, l'une serra envoyé et l'autre le tour suivant
    for (size_t  i = 0; i < fromChara->getCapacities().size(); i++)
    {
        if (fromChara->getCapacityCounter(i) == 0)
        {
            if (!autoCapacity)
            {
                char keyPressed;
                std::cout << EnumClass::characterTypeToString(fromChara->getCharacterType());
                std::cout << ": Press 'A' to attempt to cast the capacity " << EnumClass::capacityTypeToString(fromChara->getCapacities()[i].getType()) << std::endl;
                keyPressed = _getch();
                // Décider d'une action en fonction de la touche
                switch (keyPressed)
                {
                    case 'a':
                    case 'A':
                        if (fromChara->CanPerformCapacity(i))
                        {
                            std::cout << fromChara->GetName() << "'s Capacity Perfomed! (" << EnumClass::capacityTypeToString(fromChara->getCapacities()[i].getType()) <<"=>"<< toChara->GetName() << ")" << std::endl;
                            return fromChara->doCapacity(toChara);
                        }
                        else
                        {
                            std::cout << fromChara->GetName() << "'s Capacity Failed... (" << EnumClass::capacityTypeToString(fromChara->getCapacities()[i].getType()) << "=>" << toChara->GetName() << ")" << std::endl;
                            return 0;
                        }
                }
            }
            else
            {
                if (fromChara->CanPerformCapacity(i))
                {
                    std::cout << fromChara->GetName() << "'s Capacity Perfomed! (" << EnumClass::capacityTypeToString(fromChara->getCapacities()[i].getType()) << "=>" << toChara->GetName() << ")" << std::endl;
                    return fromChara->doCapacity(toChara);
                }
                else
                {
                    std::cout << fromChara->GetName() << "'s Capacity Failed... (" << EnumClass::capacityTypeToString(fromChara->getCapacities()[i].getType()) << "=>" << toChara->GetName() << ")" << std::endl;
                    return 0;
                }
            }
        }
        else
        {
            fromChara->UpdateCapacityCounter(i);               
        }
    }
    return 0;
    
}
/// <summary>
/// Try to attack
/// </summary>
/// <param name="fromChara">Character who attacks</param>
/// <param name="toChara">Target character</param>
/// <param name="currentDamage">Damage apply</param>
void Battle::attackState(std::unique_ptr<Character>& fromChara, std::unique_ptr<Character>& toChara, int currentDamage)
{
    if (fromChara->getCanPlay())
    {
        //attacks
        currentDamage += fromChara->performAttack();
        toChara->takeDamage(currentDamage);
        std::cout << fromChara->GetName() << " attack " << toChara->GetName() << " for " << currentDamage << " damage." << std::endl;
    }
    else
    {
        std::cout << fromChara->GetName() << " can't attacks " << toChara->GetName() << ", wait for " << fromChara->getIncapacityCounter() << " turn(s)." << std::endl;    
        fromChara->UpdateIncapacity();
    }
}
