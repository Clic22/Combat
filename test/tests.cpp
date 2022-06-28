#include <iostream>
#include <gtest/gtest.h>
#include "Swordsman.h"
#include "Viking.h"
#include "Object.h"


TEST(ObjectInitialization, Default) { 
    std::string objectName = "random object";
    int objectDamage = 15;
    auto object = std::make_unique<Object>(objectName,objectDamage);
    ASSERT_EQ(objectName, object->Name());
    ASSERT_EQ(objectDamage, object->Damage());
}

TEST(WarriorInitialization, Default) { 
    std::string objectName = "random object";
    int objectDamage = 15;
    Object object(objectName,objectDamage);
    auto warrior = std::make_unique<Warrior>(100, object);
    ASSERT_EQ(100, warrior->HitPoints());
    std::vector<Object> inventory =  warrior->Inventory();
    ASSERT_EQ(objectName, inventory.at(0).Name());
    ASSERT_EQ(objectDamage, inventory.at(0).Damage());;
}

TEST(WarriorReceiveDamage, Default) { 
    std::string objectName = "random object";
    int objectDamage = 15;
    Object object(objectName,objectDamage);
    Warrior warrior(120,object);
    ASSERT_EQ(120, warrior.HitPoints());
    warrior.ReceiveDamage(10);
    ASSERT_EQ(110, warrior.HitPoints());
    warrior.ReceiveDamage(150);
    ASSERT_EQ(0, warrior.HitPoints());
}

TEST(WarriorEquipTwoWeapons, Default) { 
    std::string objectName = "random object";
    int objectDamage = 15;
    Object object(objectName,objectDamage);
    Warrior warrior(120,object);
    std::string anotherObjectName = "another random object";
    int anotherObjectDamage = 25;
    Object anotherObject(anotherObjectName,anotherObjectDamage);
    warrior.Equip(anotherObject);
    std::vector<Object> inventory =  warrior.Inventory();
    ASSERT_EQ(2, inventory.size());
    ASSERT_EQ(objectName, inventory.at(0).Name());
    ASSERT_EQ(objectDamage, inventory.at(0).Damage());;
    ASSERT_EQ(anotherObjectName, inventory.at(1).Name());
    ASSERT_EQ(anotherObjectDamage, inventory.at(1).Damage());;
}

TEST(SwordsmanInitialization, Default) { 
    auto swordsman = std::make_unique<Swordsman>();
    ASSERT_EQ(100, swordsman->HitPoints());
    std::vector<Object> inventory =  swordsman->Inventory();
    ASSERT_EQ("sword", inventory.at(0).Name());
    ASSERT_EQ(5, inventory.at(0).Damage());
}

TEST(VikingInitialization, Default) { 
    auto viking = std::make_unique<Viking>();
    ASSERT_EQ(120, viking->HitPoints());
    std::vector<Object> inventory =  viking->Inventory();
    ASSERT_EQ("axe", inventory.at(0).Name());
    ASSERT_EQ(6, inventory.at(0).Damage());
}


TEST(SwordsmanVsViking, Default) { 
    Swordsman swordsman;
    Viking viking;
    swordsman.Engage(viking);
    ASSERT_EQ(0,swordsman.HitPoints());
    ASSERT_EQ(35,viking.HitPoints());
}
 /*
TEST(SwordsmanWithBucklerVsVikingWithBuckler, Default) {
    Swordsman swordsman;
    swordsman.Equip("buckler");
    Viking viking;
    viking.Equip("buckler");
    swordsman.Engage(viking);

    ASSERT_EQ(0,swordsman.HitPoints());
    ASSERT_EQ(70,viking.HitPoints());
}*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}