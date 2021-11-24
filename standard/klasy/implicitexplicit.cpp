#include <iostream>
#include <string>
using namespace std;

class Entity{
    string m_Name;
    int m_Age;
public:
    Entity(const string &name)
        : m_Name(name), m_Age(-1) {}
    explicit Entity(int age)
        : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity &entity){
    //printing
}

int main(){

    //niemozliwe: PrintEntity(22);
    PrintEntity(Entity("Olaf"));
    PrintEntity(string("Olaf"));

    Entity a = string("Olaf");
    //z explicit niemozliwe: Entity b = 22;

    Entity b = Entity(22);
    Entity c(22);

    return 0;
}