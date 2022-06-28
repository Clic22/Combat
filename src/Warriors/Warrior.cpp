#include "Warrior.h"

Warrior::Warrior(int HitPoints, Object object){
    hitPoints_ = HitPoints;
    this->Equip(object);
}

int Warrior::HitPoints(){
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
            opponent.fight((*this));
        }
    }
}

void Warrior::fight(Warrior& opponent){
    int damage = 0;
    for(Object object : inventory_){
        damage += object.Damage();
    }
    opponent.ReceiveDamage(damage);
}

void Warrior::ReceiveDamage(int damage){
    this->HitPoints(this->HitPoints() - damage);
    if ( this->HitPoints() < 0){
        this->HitPoints(0);
    }      
}

void Warrior::Equip(Object object){
    inventory_.push_back(object);
}

std::vector<Object> Warrior::Inventory(){
    return inventory_;
}