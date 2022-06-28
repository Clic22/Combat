#pragma once
#include <string>
#include <vector>
#include "Object.h"

class Warrior{
    public:
        Warrior(int HitPoints, Object object);
        int HitPoints();
        void HitPoints(int HitPoints);
        void Engage(Warrior& opponent);
        void Equip(Object object);
        std::vector<Object> Inventory();
        void ReceiveDamage(int damage);

    private:
        void fight(Warrior& opponent);
        int hitPoints_;
        std::vector<Object> inventory_; 
};