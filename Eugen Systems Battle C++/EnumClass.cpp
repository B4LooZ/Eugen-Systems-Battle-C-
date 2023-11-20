#include "EnumClass.h"

const char* EnumClass::weaponTypeToString(WeaponType type) 
{
    switch (type) 
    {
        case WeaponType::Sword:
            return "Sword";
        case WeaponType::Axe:
            return "Axe";
        // Ajoutez d'autres cas au besoin
        default:
            return "Unknown";
    }
}
const char* EnumClass::capacityTypeToString(CapacityType type)
{
    switch (type)
    {
        case CapacityType::Charge:
            return "Charge";
        case CapacityType::Stun:
            return "Stun";
        // Ajoutez d'autres cas au besoin
        default:
            return "Unknown";
    }
}
const char* EnumClass::characterTypeToString(CharacterType type)
{
    switch (type)
    {
    case CharacterType::Knight:
        return "Knight";
    case CharacterType::Orc:
        return "Orc";
        // Ajoutez d'autres cas au besoin
    default:
        return "Unknown";
    }
}