#include <iostream>
#include <type_traits>
using namespace std;

template <typename T, typename R, typename I = conditional_t<is_floating_point<T>::value, T, R>>
I suma(T a, R b)
{
    return a + b;
}

int main()
{

    cout << suma(1, 2.5);

    return 0;
}