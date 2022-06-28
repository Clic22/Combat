#include <iostream>
#include <gtest/gtest.h>
#include "Swordsman.h"
#include "Viking.h"
#include "ObjectFactory.h"
#include "Object.h"


TEST(ObjectInitialization, Default) { 
    std::string objectName = "random object";
    int objectDamage = 15;
    auto object = std::make_unique<Object>(objectName,objectDamage);
    ASSERT_EQ(objectName, object->Name());
    ASSERT_EQ(objectDamage, object->Damage());
}

TEST(WarriorInitialization, Default) { 
    std::string objectName = "axe";
    auto warrior = std::make_unique<Warrior>(100, objectName);
    ASSERT_EQ(100, warrior->HitPoints());
    std::vector<std::shared_ptr<Object>> inventory =  warrior->Inventory();
    ASSERT_EQ(objectName, inventory.at(0)->Name());
    ASSERT_EQ(6, inventory.at(0)->Damage());;
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

TEST(AxeWeapon, Default) { 
    std::string objectName = "axe";
    ObjectFactory factory;
    std::shared_ptr<Object> axe = factory.createObject(objectName);

    Swordsman opponent;

    ASSERT_EQ(6,axe->Attack(opponent));
    ASSERT_EQ(0,axe->Defense(axe));
    ASSERT_EQ(6,axe->Damage());
}

TEST(SwordWeapon, Default) { 
    std::string objectName = "sword";
    ObjectFactory factory;
    std::shared_ptr<Object> sword = factory.createObject(objectName);

    Swordsman opponent;

    ASSERT_EQ(5,sword->Attack(opponent));
    ASSERT_EQ(0,sword->Defense(sword));
    ASSERT_EQ(5,sword->Damage());
}

TEST(BucklerArmor, AgainstAxe) { 
    ObjectFactory factory;
    std::shared_ptr<Object> buckler = factory.createObject("buckler");
    std::shared_ptr<Object> axe = factory.createObject("axe");

    Swordsman opponent;

    ASSERT_EQ(0,buckler->Damage());
    ASSERT_EQ(axe->Damage(),buckler->Defense(axe));
    ASSERT_EQ(0,buckler->Defense(axe));
    ASSERT_EQ(axe->Damage(),buckler->Defense(axe));
    ASSERT_EQ(0,buckler->Defense(axe));
    ASSERT_EQ(axe->Damage(),buckler->Defense(axe));
    ASSERT_EQ(0,buckler->Defense(axe));
    ASSERT_EQ(0,buckler->Defense(axe));
}

TEST(BucklerArmor, AgainstSword) { 
    ObjectFactory factory;
    std::shared_ptr<Object> buckler = factory.createObject("buckler");
    std::shared_ptr<Object> sword = factory.createObject("sword");

    Swordsman opponent;

    ASSERT_EQ(0,buckler->Damage());
    ASSERT_EQ(sword->Damage(),buckler->Defense(sword));
    ASSERT_EQ(0,buckler->Defense(sword));
    ASSERT_EQ(sword->Damage(),buckler->Defense(sword));
    ASSERT_EQ(0,buckler->Defense(sword));
    ASSERT_EQ(sword->Damage(),buckler->Defense(sword));
    ASSERT_EQ(0,buckler->Defense(sword));
    ASSERT_EQ(sword->Damage(),buckler->Defense(sword));
}

TEST(SwordsmanInitialization, Default) { 
    auto swordsman = std::make_unique<Swordsman>();
    ASSERT_EQ(100, swordsman->HitPoints());
    std::vector<std::shared_ptr<Object>> inventory =  swordsman->Inventory();
    ASSERT_EQ("sword", inventory.at(0)->Name());
    ASSERT_EQ(5, inventory.at(0)->Damage());
}

TEST(VikingInitialization, Default) { 
    auto viking = std::make_unique<Viking>();
    ASSERT_EQ(120, viking->HitPoints());
    std::vector<std::shared_ptr<Object>> inventory =  viking->Inventory();
    ASSERT_EQ("axe", inventory.at(0)->Name());
    ASSERT_EQ(6, inventory.at(0)->Damage());
}


TEST(SwordsmanVsViking, Default) { 
    Swordsman swordsman;
    Viking viking;
    swordsman.Engage(viking);
    ASSERT_EQ(0,swordsman.HitPoints());
    ASSERT_EQ(35,viking.HitPoints());
}

TEST(SwordsmanWithBucklerVsVikingWithBuckler, Default) {
    Swordsman swordsman;
    swordsman.Equip("buckler");
    Viking viking;
    viking.Equip("buckler");
    swordsman.Engage(viking);

    ASSERT_EQ(0,swordsman.HitPoints());
    ASSERT_EQ(70,viking.HitPoints());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}