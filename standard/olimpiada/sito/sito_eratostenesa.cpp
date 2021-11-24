#include <bits/stdc++.h>
using namespace std;


void sito(bool *tab, unsigned int n)
{
	for(int i=2; i<=sqrt(n); i++)
        if(tab[i])				
		    for(int j = i*i ; j<=n; j+=i)
                tab[j] = false;			
}

int main()
{
	int n;
	
	cout<<"Podaj zakres g¢rny przedziaˆu: ";
	cin>>n;
	
	bool *tab = new bool [n+1];
	
	for(int i=2; i<=n; i++)
		tab[i] = true;
	
	sito(tab, n); 
	stack<int> s;
	
	for(int i=2;i<=n;i++)
		if(tab[i])
			s.push(i);
	
	if(n == s.top()) cout<<boolalpha<<true;
	else cout<<boolalpha<<false;
	delete [] tab;

    return 0;
}