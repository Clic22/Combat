#include "Warrior.h"
#include "ObjectFactory.h"
#include "Object.h"
#include <iostream>

Warrior::Warrior(int HitPoints, const std::string& object){
    hitPoints_ = HitPoints;
    this->Equip(object);
}

int Warrior::HitPoints() const {
    return hitPoints_;
}

void Warrior::HitPoints(int hitPoints){
    hitPoints_ = hitPoints;
}

void Warrior::Engage(Warrior& opponent){
    while(this->HitPoints()>0 && opponent.HitPoints()>0)
    {
        this->fight(opponent);
        if (opponent.HitPoints()>0)
        {
            opponent.fight(*this);
        }
    }
}

void Warrior::fight(Warrior& opponent){
    int damage = 0;
    int penality = 0;
    for(std::shared_ptr<Object> object : inventory_){
        if (object->Name() == "armor"){
            penality = 1;
        }     
    }
    for(std::shared_ptr<Object> object : inventory_){
        damage += object->Attack(opponent, penality);
    }
    opponent.ReceiveDamage(damage);
}

void Warrior::ReceiveDamage(int damage){
    this->HitPoints(this->HitPoints() - damage);
    if (this->HitPoints() < 0){
        this->HitPoints(0);
    }      
}

void Warrior::Equip(const std::string& objectName){
    ObjectFactory factory;
    std::shared_ptr<Object> object = factory.createObject(objectName);
    inventory_.push_back(object);
}

std::vector<std::shared_ptr<Object>> Warrior::Inventory() const {
    return inventory_;
}