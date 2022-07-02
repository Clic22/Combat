#include "Object.h"
#include "Warrior.h"
#include <iostream>

Object::Object(const std::string& name, int damage, ObjectType type) : name_(name), damage_(damage), type_(type){}

std::string Object::Name() const{
    return name_;
}

int Object::Damage() const{
    return damage_;
}

ObjectType Object::Type() const{
    return type_;
}

int  Object::BasicAttack(const Warrior& attacker,const Warrior& opponent, int penality){
    int damage = damage_;
    auto trait = attacker.GetTrait();
    if (trait != nullptr){
       damage = attacker.GetTrait()->BonusAttack(damage,attacker);
    }
    damage = damage - penality;
    for(const auto& [type, object] : opponent.Inventory()){
        damage -= object->Defense(std::make_shared<Object>(*this),damage);
    }

    if (damage < 0 )
    {
        damage = 0;
    }

    return damage;
}