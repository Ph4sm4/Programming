#include <iostream>
using namespace std;

class Animal{
    public:
    static void przywitanie(){
        cout<<"SIeeeema"<<endl;
    }
};

class Cat : public Animal{
    public:
        static void miau(string x){
            cout<<x<<endl;
        } 
};


int main(){

    Animal::przywitanie();
    Cat cat;
    cat.miau("miaaaau");

    return 0;
}