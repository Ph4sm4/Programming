#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> wiezniowie;
    int ilosc;
    cin >> ilosc;
    for (int i = 0; i < ilosc; i++) {
        int numer_wiez, wartosc_nark;
        cin >> numer_wiez >> wartosc_nark;
        wiezniowie.push_back(make_pair(wartosc_nark, numer_wiez));
    }
    sort(wiezniowie.begin(), wiezniowie.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first < b.first;});
    for (auto elem : wiezniowie) cout << elem.second << endl;


    return 0;
}