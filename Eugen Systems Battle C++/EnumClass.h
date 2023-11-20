#ifndef ENUMCLASS_H
#define ENUMCLASS_H

enum class WeaponType 
{
    Sword,
    Axe,
    // Ajoutez d'autres types d'armes au besoin
};
enum class CapacityType
{
    Charge,
    Stun,
};
enum class CharacterType
{
    Knight,
    Orc,
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

#endif // ENUMCLASS_H