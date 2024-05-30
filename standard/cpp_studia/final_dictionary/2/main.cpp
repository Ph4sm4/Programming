#include <iostream>
#include <string>
using namespace std;

class MyException : public exception
{
private:
    int arrayInd;
    int value;

public:
    MyException() = default;
    explicit MyException(int arrInd, int val) : arrayInd(arrInd), value(val) {}

    const char *what()
    {
        return ("Negative value intercepted at index: " + to_string(arrayInd) + " with value: " + to_string(value)).c_str();
    }
};

int total(int tab[], int n, bool considerNegative)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] < 0 && !considerNegative)
            throw MyException(i, tab[i]);
        else
            sum += tab[i];
    }

    return sum;
}

int main()
{

    int n;
    cout << "Size of the array: ";
    cin >> n;

    int *tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }

    bool considerNegatives;

    cout << "Should negative values be considered during summation (0, 1): ";
    cin >> considerNegatives;

    try
    {
        int t = total(tab, n, considerNegatives);
        cout << "The total is: " << t << endl;
    }
    catch (MyException err)
    {
        cout << err.what() << endl;
    }

    return 0;
}