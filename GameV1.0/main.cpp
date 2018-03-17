#include <iostream>
#include "Units.cpp"

int main() {
    ArmyCreater creater;
    PeopleArmyFactory peopleFactory;
    OrcsArmyFactory orcsFactory;
    ElfsArmyFactory elfsFactory;
    
   Army *people = creater.create(peopleFactory);
    
    return 0;
}
