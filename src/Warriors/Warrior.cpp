#include "Warrior.h"
#include "Object.h"
#include "Trait.h"
#include "ObjectFactory.h"
#include "TraitFactory.h"

Warrior::Warrior(int MaxHealth, const std::string& object) : hitPoints_(MaxHealth), maxHealth_(MaxHealth){
    this->Equip(object);
}

Warrior::Warrior(int MaxHealth, const std::string& object, const std::string& trait) : hitPoints_(MaxHealth), maxHealth_(MaxHealth){
    this->Equip(object);
    TraitFactory factory;
    trait_ = factory.createTrait(trait);
}

int Warrior::MaxHealth() const {
    return maxHealth_;
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

void Warrior::fight(Warrior& opponent) const{
    int damage = 0;
    int penality = 0;
    if (inventory_.count(ObjectType::BodyArmor)){
        penality = 1;
    }
    for(const auto& [type, object] : inventory_){
        if (object != nullptr)
        {
            damage += object->Attack(*this, opponent, penality);
        }  
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
    if (object->Type() == ObjectType::OneHandedWeapon || object->Type() == ObjectType::OneHandedDefense)
    {
        inventory_.erase(ObjectType::TwoHandedWeapon);
    }
    else if (object->Type() == ObjectType::TwoHandedWeapon)
    {
        inventory_.erase(ObjectType::OneHandedWeapon);
        inventory_.erase(ObjectType::OneHandedDefense);
    }
    inventory_[object->Type()]=object;
}

std::unordered_map<ObjectType,std::shared_ptr<Object>> Warrior::Inventory() const {
    return inventory_;
}

std::shared_ptr<Trait> Warrior::GetTrait() const {
    return trait_;
}