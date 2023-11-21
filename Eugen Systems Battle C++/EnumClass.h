#pragma once
enum class WeaponType 
{
    Sword,
    Axe,
    // Ajoutez au besoin
    Count,   
};
enum class CapacityType
{
    Charge,
    Stun,
    // Ajoutez au besoin
    Count,
};
enum class CharacterType
{
    Knight,
    Orc,
    // Ajoutez au besoin
    Count,
};
class EnumClass 
{
    public: 
        static const char* weaponTypeToString(WeaponType type);
    public:
        static const char* capacityTypeToString(CapacityType type);
    public:
        static const char* characterTypeToString(CharacterType type);
};