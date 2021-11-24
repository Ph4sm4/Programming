#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

int main()
{

    ifstream plik;
    plik.open("dane6.txt");
    string tab[2023];
    for (int i = 0; i < 2023; i++)
    {
        plik >> tab[i];
    }  

    for (int p = 1; p < 10; p++)
    {
        int count = 0, max_sum = 0, what_index;
        for (int i = 0; i < 2023; i++)
        {
            int sum = 0;
            bool contains = false, is_greater = false;
            if (p < 10 && p != 1)
            {
                for (int j = 0; j < 100; j++)
                {
                    if (tab[i][j] == ('0' + p))
                        contains = true;
                    if ((tab[i][j] - '0') > p)
                    {
                        is_greater = 1;
                        break;
                    }
                }
            }
            else
            {
                regex reg("10");
                if (regex_search(tab[i], reg))
                    contains = true;
                regex reg2("[^1^0]");
                if (regex_search(tab[i], reg2))
                    is_greater = 1;
            }

            if (!is_greater && contains){
                count++;
                for(int g = 0; g < 100; g++){
                    sum += (tab[i][g] - '0');
                }
                if(max_sum < sum){
                    max_sum = sum;
                    what_index = i;
                }
            }
        }
        cout<<p + 1<<" "<<tab[what_index]<<endl;  
    }
    plik.close();

    return 0;
}