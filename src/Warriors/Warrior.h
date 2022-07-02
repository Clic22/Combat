#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "Trait.h"
#include "Object.h"

class Warrior{
    public:
        Warrior() = default;
        Warrior(int const MaxHealth, const std::string& object);
        Warrior(int const MaxHealth, const std::string& object, const std::string& trait);
        int HitPoints() const;
        void HitPoints(int HitPoints);
        int MaxHealth() const;
        void Engage(Warrior& opponent);
        void Equip(const std::string& object);
        std::unordered_map<ObjectType,std::shared_ptr<Object>> Inventory() const;
        std::shared_ptr<Trait> GetTrait() const;
        void ReceiveDamage(int damage);

    private:
        void fight(Warrior& opponent) const;
        int hitPoints_;
        int maxHealth_;
        std::unordered_map<ObjectType,std::shared_ptr<Object>> inventory_;
        std::shared_ptr<Trait> trait_;
};