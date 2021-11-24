#include <iostream>
#include <map>
#include <utility>
#include <tuple>
using namespace std;

tuple<string, int> CreatePerson(){
    return {"Cherno", 24};
}

int main(){

    auto [name, age] = CreatePerson();
    cout<<name<<" this is working! "<<age<<endl;

    map<float, float, greater<float>> malej{ {1,2},{2.4,2.1},{0,10} };	for (auto [k, v] : malej) cout << k << "=" << v << " ";
	cout << "[" << malej.size() << "]" << endl;


}