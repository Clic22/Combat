#include "Buckler.h"


Buckler::Buckler() : Object("buckler",DAMAGE,ObjectType::OneHandedDefense){};

int Buckler::Defense(std::shared_ptr<Object> weapon, int damage){
    if (durability_ > 0 && block_){
        block_ = false;
        if (weapon->Name() == "axe"){
            durability_--;
        }
        return damage;
    }
    else{
        block_ = true;
        return 0;
    }  
}