#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

string perfect(int v){
	
	int s=0;
	for(int z=1;z<=v/2;z++)
	{
		if(v%z==0)
		{
			s+=z;
		}
	}
	if(s==v)
	{
		return "PERFECT";
	}
	if(s<v)
	{
		return "DEFICIENT";
	}
	return "ABUNDANT";
}

int sizecria(int n){
	
	int si=0;
	while(n!=0){
		n=n/10;
		si++;
	}
	return si;
}

int main () {
	
	vector<int> vet;
	int t;
	cout << "PERFECTION OUTPUT\n";
	cin >> t;
	while(t)
	{
		vet.pb(t);
		cin >> t;
	}
	for(int z=0;z<vet.size();z++)
	{
		int ta=sizecria(vet[z]);
		int vai=5-ta;
		for(int y=0;y<vai;y++)cout << " ";//printf
		cout << vet[z];
		string b=perfect(vet[z]);
		cout << "  " <<b << "\n";
	}
	cout << "END OF OUTPUT\n";
}
