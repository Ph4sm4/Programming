#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v = {1,2,2,3,3,3,3,2,3};
	
	int lider = v[0], do_pary = 1;

	//wykre˜lanie par o r¢¾nych warto˜ciach
	for(int i=1;i<v.size();i++)
        if(do_pary > 0)
		    if(v[i]==lider) 
			    ++do_pary; 
		    else
			    --do_pary; 
	    else
	    {
		    ++do_pary;
		    lider = v[i];
	    }
	//koniec wykre˜lania

	if(do_pary==0)
		lider = -1; //zwr¢cenie -1 oznacza, ¾e zbi¢r nie posiada lidera
	
	int ile = 0; //zmienna zliczaj¥ca wyst¥pieäia potencjalnego lidera
	
	for(int i=0;i<v.size();i++)  //zliczamy wyst¥pienia lidera
		if(v[i]==lider) 
			++ile;
	
	if(!(ile>v.size()/2)) //sprawdzamy, czy potencjalny lider wyst©puje oczekiwan¥ ilo˜† razy
		lider = -1;
	
	if(lider==-1)
		cout<<"Zbi¢r nie posiada lidera"<<endl;
	else
		cout<<"Liderem zbioru jest "<<lider<<endl;
		
	
	return 0;
}