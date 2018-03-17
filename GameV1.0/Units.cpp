#include <stdio.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;


//Базывай класс всего
class basicUnit{
private:
    
public:
    int Health = 0;
    int maxHealth = 0;
    int Mana = 0;
    int maxMana = 0;
    int Force = 0;
    virtual void improve() = 0;
    virtual ~basicUnit(){}
};


//Базовые типы
class infantry : protected basicUnit{
public:
    virtual void improve() = 0;
    virtual ~infantry(){}
};

class archers : protected basicUnit{
public:
    virtual void improve() = 0;
    virtual ~archers(){}
};

class wizard : protected basicUnit{
public:
    virtual void improve() = 0;
    virtual ~wizard(){}
};

class cavalry : protected basicUnit{
public:
    virtual void improve() = 0;
    virtual ~cavalry(){}
};


//классы армии орков (орки более выносливые, средняя система прокачки)
class infantryOrcs : public infantry{
public:
    void improve(){
        Health = maxHealth;
        Mana = maxMana;
        maxMana = maxMana * 3;
    }
    infantryOrcs(){
        Health = 50;
        Mana = 75;
        Force = 50;
        cout << "орк пехота создан";
    }
    virtual ~infantryOrcs(){}
};

class archersOrcs : public archers{
public:
    void improve(){
        Health = maxHealth;
        Mana = maxMana;
        Force = Force * 3;
    }
    archersOrcs(){
        Health = 50;
        Mana = 75;
        Force = 75;
        cout << "орк лучник создан";
    }
    
    ~archersOrcs(){}
};

class wizardOrcs : public wizard{
public:
    void improve(){
        Health = maxHealth * 3;
        Mana = maxMana;
    }
    wizardOrcs(){
        Health = 75;
        Mana = 75;
        Force = 50;
        cout << "орк волшебник создан";

    }
    
    ~wizardOrcs(){}
};
class cavalryOrcs : public cavalry{
public:
    void improve(){
        Health = maxHealth * 3;
        Mana = maxMana;
    }
    cavalryOrcs(){
        Health = 50;
        Mana = 100;
        Force = 75;
        cout << "человек кавалерия создан";
    }
    ~cavalryOrcs(){}
};


//классы армии людей   (имеют более крутую систему прокачки, но изначально люди слабее)
class infantryPeople : public infantry{
public:
    void improve(){
        maxMana = maxMana * 4;
        Health = maxHealth;
        Mana = maxMana;
    }
    infantryPeople(){
        Health = 25;
        Mana = 50;
        Force = 25;
        cout << "человек пехота создан";
    }
    ~infantryPeople(){}
};

class archersPeople : public archers{
public:
    void improve(){
        Health = maxHealth;
        Mana = maxMana;
        Force = Force * 4;
    }
    archersPeople(){
        Health = 25;
        Mana = 50;
        Force = 25;
        cout << "человек лучник создан";
    }
    
    ~archersPeople(){}
};

class wizardPeople : public wizard{
public:
    void improve(){
        Health = maxHealth * 4;
        Mana = maxMana;
    }
    wizardPeople(){
        Health = 50;
        Mana = 50;
        Force = 25;
        cout << "человек волшебник создан";
        
    }
    
    ~wizardPeople(){}
};

class cavalryPeople : public cavalry{
public:
    void improve(){
        Health = maxHealth * 4;
        Mana = maxMana;
    }
    cavalryPeople(){
        Health = 50;
        Mana = 75;
        Force = 75;
        cout << "человек кавалерия создан";
    }
    ~cavalryPeople(){}
};


//классы армии Эльфов (изначально сильные более сильные, имеют слабую систему прокачки)
class infantryElfs : public infantry{
public:
    void improve(){
        maxMana = maxMana * 4;
        Health = maxHealth;
        Mana = maxMana;
    }
    infantryElfs(){
        Health = 50;
        Mana = 75;
        Force = 50;
        cout << "человек пехота создан";
    }
    ~infantryElfs(){}
};
class archersElfs : public archers{
public:
    void improve(){
        Health = maxHealth;
        Mana = maxMana;
        Force = Force * 2;
    }
    archersElfs(){
        Health = 50;
        Mana = 75;
        Force = 75;
        cout << "эльф лучник создан";
    }
    
    ~archersElfs(){}
};

class wizardElfs : public wizard{
public:
    virtual void improve(){
        Health = maxHealth * 2;
        Mana = maxMana;
    }
    wizardElfs(){
        Health = 75;
        Mana = 75;
        Force = 50;
        cout << "эльф волшебник создан";
    }
    
    ~wizardElfs(){}
};

class cavalryElfs : public cavalry{
public:
    void improve(){
        Health = maxHealth * 2;
        Mana = maxMana;
    }
    cavalryElfs(){
        Health = 100;
        Mana = 75;
        Force = 100;
        cout << "эльф кавалерия создан";
    }
    ~cavalryElfs(){}
};


//Абстрактная фабрика создания войнов
class ArmyFactory {
public:
    virtual infantry* makeInfantry() = 0;
    virtual archers* makeArchers() = 0;
    virtual wizard* makeWizard() = 0;
    virtual cavalry* makeCavalry() = 0;
    virtual ~ArmyFactory(){}
};

//фабрик
class OrcsArmyFactory : ArmyFactory{
public:
    infantry* makeInfantry(){
        return new infantryOrcs;
    }
    archers* makeArchers(){
        return new archersOrcs;
    }
    wizard* makeWizard(){
        return new wizardOrcs;
    }
    cavalry* makeCavalry(){
        return new cavalryOrcs;
    }
};

class PeopleArmyFactory : public ArmyFactory{
public:
    infantry* makeInfantry(){
        return new infantryPeople;
    }
    archers* makeArchers(){
        return new archersPeople;
    }
    cavalry* makeCavalry(){
        return new cavalryPeople;
    }
    wizard* makeWizard(){
        return new wizardPeople;
    }
};

class ElfsArmyFactory : ArmyFactory{
public:
    infantry* makeInfantry(){
        return new infantryElfs;
    }
    archers* makeArchers(){
        return new archersElfs;
    }
    wizard* makeWizard(){
        return new wizardElfs;
    }
    cavalry* makeCavalry(){
        return new cavalryElfs;
    }
};

class Army
{
public:
    ~Army() {
        for(int i = 0; i < infantries.size(); ++i)  delete infantries[i];
        for(int i = 0; i < archers.size(); ++i)  delete archers[i];
        for(int i = 0; i < wizards.size(); ++i)  delete wizards[i];
        for(int i = 0; i < cavalries.size(); ++i)  delete cavalries[i];
    }
    void info() {
        cout << infantries.size();
        cout << archers.size();
        cout << wizards.size();
        cout << cavalries.size();
    }
    vector<infantry*> infantries;
    vector<archers*> archers;
    vector<wizard*> wizards;
    vector<cavalry*> cavalries;
};

class ArmyCreater{
public:
    Army* create(ArmyFactory& factory){
        Army * newArmy = new Army;
        newArmy -> infantries.push_back(factory.makeInfantry());
        newArmy -> archers.push_back(factory.makeArchers());
        newArmy -> wizards.push_back(factory.makeWizard());
        newArmy -> cavalries.push_back(factory.makeCavalry());
        return newArmy;
    }
    
};
