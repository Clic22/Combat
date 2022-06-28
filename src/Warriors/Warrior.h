#pragma once
#include <string>
#include <vector>
#include <memory>

class Object; 

class Warrior{
    public:
        Warrior() = default;
        Warrior(int HitPoints, const std::string& object);
        int HitPoints() const;
        void HitPoints(int HitPoints);
        void Engage(Warrior& opponent);
        void Equip(const std::string& object);
        std::vector<std::shared_ptr<Object>> Inventory() const;
        void ReceiveDamage(int damage);

    private:
        void fight(Warrior& opponent);
        int hitPoints_;
        std::vector<std::shared_ptr<Object>> inventory_; 
};