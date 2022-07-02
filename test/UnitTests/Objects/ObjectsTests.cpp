#include <iostream>
#include <gtest/gtest.h>
#include "Swordsman.h"
#include "Viking.h"
#include "Highlander.h"
#include "ObjectFactory.h"
#include "Object.h"
#include "TraitFactory.h"


TEST(ObjectInitialization, Default) { 
    std::string objectName = "random object";
    int objectDamage = 15;
    auto object = std::make_unique<Object>(objectName,objectDamage,ObjectType::OneHandedWeapon);
    ASSERT_EQ(objectName, object->Name());
    ASSERT_EQ(objectDamage, object->Damage());
}

TEST(AxeWeapon, Default) { 
    std::string objectName = "axe";
    ObjectFactory factory;
    std::shared_ptr<Object> axe = factory.createObject(objectName);

    Swordsman opponent;
    Swordsman attacker;
    int penality = 0;
    ASSERT_EQ(6,axe->Attack(attacker,opponent,penality));
    ASSERT_EQ(0,axe->Defense(axe,axe->Damage()));
    ASSERT_EQ(6,axe->Damage());
}

TEST(SwordWeapon, Default) { 
    std::string objectName = "sword";
    ObjectFactory factory;
    std::shared_ptr<Object> sword = factory.createObject(objectName);

    Swordsman opponent;
    Swordsman attacker;
    int penality = 0;

    ASSERT_EQ(5,sword->Attack(attacker,opponent,penality));
    ASSERT_EQ(0,sword->Defense(sword,sword->Damage()));
    ASSERT_EQ(5,sword->Damage());
}

TEST(GreatSwordWeapon, Default) { 
    std::string objectName = "greatSword";
    ObjectFactory factory;
    std::shared_ptr<Object> greatSword = factory.createObject(objectName);

    Swordsman opponent;
    Swordsman attacker;
    int penality = 0;

    ASSERT_EQ(12,greatSword->Attack(attacker,opponent,penality));
    ASSERT_EQ(12,greatSword->Attack(attacker,opponent,penality));
    ASSERT_EQ(0,greatSword->Attack(attacker,opponent,penality));
    ASSERT_EQ(12,greatSword->Attack(attacker,opponent,penality));
    ASSERT_EQ(0,greatSword->Defense(greatSword,greatSword->Damage()));
    ASSERT_EQ(12,greatSword->Damage());
}

TEST(GreatSwordWeapon, Penality) { 
    std::string objectName = "greatSword";
    ObjectFactory factory;
    std::shared_ptr<Object> greatSword = factory.createObject(objectName);

    Swordsman opponent;
    Swordsman attacker;
    int penality = 1;

    ASSERT_EQ(greatSword->Damage()-penality,greatSword->Attack(attacker,opponent,penality));
    ASSERT_EQ(greatSword->Damage()-penality,greatSword->Attack(attacker,opponent,penality));
    ASSERT_EQ(0,greatSword->Attack(attacker,opponent,penality));
    ASSERT_EQ(greatSword->Damage()-penality,greatSword->Attack(attacker,opponent,penality));
    ASSERT_EQ(0,greatSword->Defense(greatSword,greatSword->Damage()));
}

TEST(BucklerArmor, AgainstAxe) { 
    ObjectFactory factory;
    std::shared_ptr<Object> buckler = factory.createObject("buckler");
    std::shared_ptr<Object> axe = factory.createObject("axe");

    Swordsman opponent;

    ASSERT_EQ(0,buckler->Damage());
    ASSERT_EQ(axe->Damage(),buckler->Defense(axe,axe->Damage()));
    ASSERT_EQ(0,buckler->Defense(axe,axe->Damage()));
    ASSERT_EQ(axe->Damage(),buckler->Defense(axe,axe->Damage()));
    ASSERT_EQ(0,buckler->Defense(axe,axe->Damage()));
    ASSERT_EQ(axe->Damage(),buckler->Defense(axe,axe->Damage()));
    ASSERT_EQ(0,buckler->Defense(axe,axe->Damage()));
    ASSERT_EQ(0,buckler->Defense(axe,axe->Damage()));
}

TEST(BucklerArmor, AgainstSword) { 
    ObjectFactory factory;
    std::shared_ptr<Object> buckler = factory.createObject("buckler");
    std::shared_ptr<Object> sword = factory.createObject("sword");

    Swordsman opponent;

    ASSERT_EQ(0,buckler->Damage());
    ASSERT_EQ(sword->Damage(),buckler->Defense(sword,sword->Damage()));
    ASSERT_EQ(0,buckler->Defense(sword,sword->Damage()));
    ASSERT_EQ(sword->Damage(),buckler->Defense(sword,sword->Damage()));
    ASSERT_EQ(0,buckler->Defense(sword,sword->Damage()));
    ASSERT_EQ(sword->Damage(),buckler->Defense(sword,sword->Damage()));
    ASSERT_EQ(0,buckler->Defense(sword,sword->Damage()));
    ASSERT_EQ(sword->Damage(),buckler->Defense(sword,sword->Damage()));
}

TEST(Armor, Default) { 
    ObjectFactory factory;
    std::shared_ptr<Object> armor = factory.createObject("armor");
    std::shared_ptr<Object> sword = factory.createObject("sword");

    Swordsman opponent;
    Swordsman attacker;

    ASSERT_EQ(0,armor->Damage());
    ASSERT_EQ(0,armor->Attack(attacker,opponent,0));
    ASSERT_EQ(3,armor->Defense(sword,sword->Damage()));
}

TEST(SwitchWeapon, Default) { 
    auto highlander = std::make_unique<Highlander>();
    std::unordered_map<ObjectType,std::shared_ptr<Object>> inventory =  highlander->Inventory();
    ASSERT_EQ("greatSword", inventory[ObjectType::TwoHandedWeapon]->Name());
    highlander->Equip("axe");
    inventory =  highlander->Inventory();
    ASSERT_EQ("axe", inventory[ObjectType::OneHandedWeapon]->Name());
    highlander->Equip("sword");
    inventory =  highlander->Inventory();
    ASSERT_EQ("sword", inventory[ObjectType::OneHandedWeapon]->Name());
}