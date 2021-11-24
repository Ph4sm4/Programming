#include <bits/stdc++.h>
using namespace std;

void sito(bool *tab, int n)
{
	for(int i=2; i<=sqrt(n); i++)
        if(tab[i])				
		    for(int j = i*i ; j<=n; j+=i)
                tab[j] = false;			
}

void setTab(bool *tab, int n){
    for(int i=2; i<=n; i++)
		tab[i] = true;
}

int main(){ 
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];

    for(int i = 0; i < n; i++){
        bool *tab = new bool [v[i]+1];
        setTab(tab, v[i]);
        sito(tab, v[i]);
        int last;
        for(int j=2;j<=v[i];j++)
		    if(tab[j])
			    last = j;
        cout<<last<<'\n';
        delete [] tab;
    }

    return 0;
}