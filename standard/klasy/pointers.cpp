#include <iostream>
#include <memory>
using namespace std;

class Test{
    public:
        Test(){
            cout<<"Created test!"<<endl;
        }
        ~Test(){
            cout<<"Destroyed test!"<<endl;
        }
        void Print(){}
};

int main(){
    
    {
        //unique_ptr<Test> test(new Test());
        //bezpieczniej zrobic tak:
        unique_ptr<Test> test = make_unique<Test>();
        //tak nie mozna zrobic : unique_ptr<Test> test1 = test;
        test->Print();
    }

    shared_ptr<Test> shared = make_shared<Test>();
    shared_ptr<Test> t1 = shared;   

    weak_ptr<Test> weak = shared;

    return 0;
}