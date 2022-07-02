#pragma once
#include <string>
#include <memory>

enum class ObjectType { OneHandedWeapon, TwoHandedWeapon, OneHandedDefense, BodyArmor };

class Warrior;

class Object{
    public:
        Object(const std::string& name, int damage, ObjectType type);
        virtual ~Object() = default;
        virtual int Attack(const Warrior& attacker,const Warrior& opponent, int penality){return 0;};
        virtual int Defense(std::shared_ptr<Object> weapon, int damage){return 0;};
        int BasicAttack(const Warrior& attacker,const Warrior& opponent, int penality);
        std::string Name() const;
        int Damage() const;
        ObjectType Type() const;

    private :
        std::string name_;
        int damage_;
        ObjectType type_;
};