#include <iostream>
using namespace std;

class Punkt{
public:
    int x, y;
    Punkt(){}
    Punkt(int a, int b): x(a), y(b){}
    Punkt operator+(const Punkt& punkt){
        Punkt nowy;
        nowy.x = x + punkt.x;
        nowy.y = y + punkt.y;
        return nowy;
    }
    bool operator==(Punkt& punkt){
        if(x == punkt.x && y == punkt.y) return true;
        else return false;
    }
    bool operator<(Punkt& punkt){
        if(x + y < punkt.x + punkt.y) return true;
        else return false;
    }
    bool operator>(Punkt& punkt){
        if(x + y > punkt.x + punkt.y) return true;
        else return false;
    }
    bool operator<=(Punkt& punkt){
        if(x + y <= punkt.x + punkt.y) return true;
        else return false;
    }
    bool operator>=(Punkt& punkt){
        if(x + y >= punkt.x + punkt.y) return true;
        else return false;
    }
    Punkt operator-(Punkt& punkt){
        Punkt nowy(x - punkt.x, y - punkt.y);
        return nowy;
    }
    void wyswietl(){
        cout<<x<<" "<<y<<endl;
    }
    Punkt operator()(int x, int y){
        this->x = x;
        this->y = y;
        return *this;
    }
    bool operator!=(Punkt& punkt){
        if(x != punkt.x || y != punkt.y) return true;
        else return false;
    }
};
int main(){

    Punkt X(5, 5);
    Punkt Y(5, 5);
    Punkt Z;
    Z = X + Y;

    Z.wyswietl();

    if(X != Y) cout<<"tak"<<endl;
    else cout<<"nie"<<endl;

    Punkt K = Z - X;
    K.wyswietl();

    K(1, 1);
    K.wyswietl();
    
    return 0;
}