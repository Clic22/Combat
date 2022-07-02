#include <iostream>
#include <gtest/gtest.h>
#include "Swordsman.h"
#include "Viking.h"
#include "Highlander.h"
#include "ObjectFactory.h"
#include "Object.h"
#include "TraitFactory.h"


TEST(WarriorInitialization, Default) { 
    std::string objectName = "axe";
    auto warrior = std::make_unique<Warrior>(100, objectName);
    ASSERT_EQ(100, warrior->HitPoints());
    warrior->HitPoints(25);
    ASSERT_EQ(25, warrior->HitPoints());
    ASSERT_EQ(100, warrior->MaxHealth());
    std::unordered_map<ObjectType,std::shared_ptr<Object>> inventory =  warrior->Inventory();
    ASSERT_EQ(objectName, inventory[ObjectType::OneHandedWeapon]->Name());
    ASSERT_EQ(6, inventory[ObjectType::OneHandedWeapon]->Damage());;
}

TEST(WarriorReceiveDamage, Default) { 
    std::string objectName = "axe";
    Warrior warrior(120,objectName);
    ASSERT_EQ(120, warrior.HitPoints());
    warrior.ReceiveDamage(10);
    ASSERT_EQ(110, warrior.HitPoints());
    warrior.ReceiveDamage(150);
    ASSERT_EQ(0, warrior.HitPoints());
}

TEST(SwordsmanInitialization, Default) { 
    auto swordsman = std::make_unique<Swordsman>();
    ASSERT_EQ(100, swordsman->HitPoints());
    std::unordered_map<ObjectType,std::shared_ptr<Object>> inventory =  swordsman->Inventory();
    ASSERT_EQ("sword", inventory[ObjectType::OneHandedWeapon]->Name());
    ASSERT_EQ(5, inventory[ObjectType::OneHandedWeapon]->Damage());
}

TEST(VikingInitialization, Default) { 
    auto viking = std::make_unique<Viking>();
    ASSERT_EQ(120, viking->HitPoints());
    std::unordered_map<ObjectType,std::shared_ptr<Object>> inventory =  viking->Inventory();
    ASSERT_EQ("axe", inventory[ObjectType::OneHandedWeapon]->Name());
    ASSERT_EQ(6, inventory[ObjectType::OneHandedWeapon]->Damage());
}

TEST(HighlanderInitialization, Default) { 
    auto highlander = std::make_unique<Highlander>();
    ASSERT_EQ(150, highlander->HitPoints());
    std::unordered_map<ObjectType,std::shared_ptr<Object>> inventory =  highlander->Inventory();
    ASSERT_EQ("greatSword", inventory[ObjectType::TwoHandedWeapon]->Name());
    ASSERT_EQ(12, inventory[ObjectType::TwoHandedWeapon]->Damage());
}