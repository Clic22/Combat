#include "ObjectFactory.h"
#include "Buckler.h"
#include "Armor.h"
#include "Sword.h"
#include "Axe.h"
#include "GreatSword.h"

std::shared_ptr<Object> ObjectFactory::createObject(const std::string& object) const {
    if (object == "buckler")
    {
        return std::make_shared<Buckler>();
    }
    else if (object == "axe")
    {
        return std::make_shared<Axe>();
    }
    else if (object == "sword")
    {
        return std::make_shared<Sword>();
    }
    else if (object == "greatSword")
    {
        return std::make_shared<GreatSword>();
    }
    else if (object == "armor")
    {
        return std::make_shared<Armor>();
    }
    else{
        return nullptr;
    }
}