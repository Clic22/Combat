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
    auto object = std::make_unique<Object>(objectName,objectDamage,OneHandedWeapon);
    ASSERT_EQ(objectName, object->Name());
    ASSERT_EQ(objectDamage, object->Damage());
}

TEST(WarriorInitialization, Default) { 
    std::string objectName = "axe";
    auto warrior = std::make_unique<Warrior>(100, objectName);
    ASSERT_EQ(100, warrior->HitPoints());
    warrior->HitPoints(25);
    ASSERT_EQ(25, warrior->HitPoints());
    ASSERT_EQ(100, warrior->MaxHealth());
    std::unordered_map<type,std::shared_ptr<Object>> inventory =  warrior->Inventory();
    ASSERT_EQ(objectName, inventory[OneHandedWeapon]->Name());
    ASSERT_EQ(6, inventory[OneHandedWeapon]->Damage());;
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

TEST(Trait, Vicious) { 
    TraitFactory factory;
    std::shared_ptr<Trait> vicious = factory.createTrait("Vicious");

    int damage = 10;
    Swordsman swordsman;

    ASSERT_EQ(damage+20,vicious->BonusAttack(damage,swordsman));
    ASSERT_EQ(damage+20,vicious->BonusAttack(damage,swordsman));
    ASSERT_EQ(damage,vicious->BonusAttack(damage,swordsman));
}

TEST(Trait, Veteran) { 
    TraitFactory factory;
    std::shared_ptr<Trait> veteran = factory.createTrait("Veteran");

    int damage = 20;
    
    Swordsman Swordsman;

    ASSERT_EQ(damage,veteran->BonusAttack(damage, Swordsman));
    Swordsman.HitPoints(29);
    ASSERT_EQ(damage*2,veteran->BonusAttack(damage, Swordsman));
    Swordsman.HitPoints(10);
    ASSERT_EQ(damage*2,veteran->BonusAttack(damage, Swordsman));
    Swordsman.HitPoints(1);
    ASSERT_EQ(damage*2,veteran->BonusAttack(damage, Swordsman));
    Swordsman.HitPoints(30);
    ASSERT_EQ(damage,veteran->BonusAttack(damage, Swordsman));
}

TEST(SwordsmanInitialization, Default) { 
    auto swordsman = std::make_unique<Swordsman>();
    ASSERT_EQ(100, swordsman->HitPoints());
    std::unordered_map<type,std::shared_ptr<Object>> inventory =  swordsman->Inventory();
    ASSERT_EQ("sword", inventory[OneHandedWeapon]->Name());
    ASSERT_EQ(5, inventory[OneHandedWeapon]->Damage());
}

TEST(VikingInitialization, Default) { 
    auto viking = std::make_unique<Viking>();
    ASSERT_EQ(120, viking->HitPoints());
    std::unordered_map<type,std::shared_ptr<Object>> inventory =  viking->Inventory();
    ASSERT_EQ("axe", inventory[OneHandedWeapon]->Name());
    ASSERT_EQ(6, inventory[OneHandedWeapon]->Damage());
}

TEST(HighlanderInitialization, Default) { 
    auto highlander = std::make_unique<Highlander>();
    ASSERT_EQ(150, highlander->HitPoints());
    std::unordered_map<type,std::shared_ptr<Object>> inventory =  highlander->Inventory();
    ASSERT_EQ("greatSword", inventory[TwoHandedWeapon]->Name());
    ASSERT_EQ(12, inventory[TwoHandedWeapon]->Damage());
}

TEST(SwitchWeapon, Default) { 
    auto highlander = std::make_unique<Highlander>();
    std::unordered_map<type,std::shared_ptr<Object>> inventory =  highlander->Inventory();
    ASSERT_EQ("greatSword", inventory[TwoHandedWeapon]->Name());
    highlander->Equip("axe");
    inventory =  highlander->Inventory();
    ASSERT_EQ("axe", inventory[OneHandedWeapon]->Name());
    highlander->Equip("sword");
    inventory =  highlander->Inventory();
    ASSERT_EQ("sword", inventory[OneHandedWeapon]->Name());

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

TEST(ArmoredSwordsmanVsHighlander, Default){
    Highlander highlander;
    Swordsman swordsman;
    swordsman.Equip("buckler");
    swordsman.Equip("armor");
    swordsman.Engage(highlander);

    ASSERT_EQ(0,swordsman.HitPoints());
    ASSERT_EQ(10,highlander.HitPoints());
}

TEST(ViciousSwordsmanVsVeteranHighlander, Default){
    Swordsman swordsman("Vicious");
    swordsman.Equip("axe");
    swordsman.Equip("buckler");
    swordsman.Equip("armor");
    Highlander highlander("Veteran");
    swordsman.Engage(highlander);
    
    ASSERT_EQ(0,highlander.HitPoints());
    ASSERT_EQ(1,swordsman.HitPoints());
    
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}