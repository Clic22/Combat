#pragma once
#include <string>
#include <memory>

enum type { OneHandedWeapon, TwoHandedWeapon, OneHandedDefense, BodyArmor };

class Warrior;

class Object{
    public:
        Object(std::string name, int damage, type type);
        virtual ~Object() = default;
        virtual int Attack(Warrior& attacker, Warrior& opponent, int penality){return 0;};
        virtual int Defense(std::shared_ptr<Object> weapon, int damage){return 0;};
        int BasicAttack(Warrior& attacker,Warrior& opponent, int penality);
        std::string Name();
        int Damage();
        type Type();

    private :
        std::string name_;
        type type_;
        int damage_;
};