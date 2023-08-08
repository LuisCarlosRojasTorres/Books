#include <iostream>
#include <string>
#include "Animal.h"

class Persona
{
    public:
        std::string name;
        int age;

        Persona(){
            name = "Lobo";
            age = 5;
        }
        Persona(std::string dname, int dage){
            name = dname;
            age = dage;
        }
    
};
int main()
{
    Persona p1;
    Persona p2("Rufa", 11);

    std::cout << "Name:" << p1.name << std::endl;
    std::cout << "Age:" << p1.age << std::endl;
    std::cout << "Name:" << p2.name << std::endl;
    std::cout << "Age:" << p2.age << std::endl;
    
    Animal a1;
    return 0;
}
