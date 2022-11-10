#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

#define f first
#define s second

int main (){
	
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	cout << fixed << setprecision (4);
    int ct;
    cin >> ct;
    cin.ignore();
    for(int i=0;i<ct;i++)
	{
		if(i)cout<< "\n";
		map<string,int> mp;
		string a;
		getline(cin,a);
		while(a=="\0")
		{
			getline(cin,a);
		}
		int c=0;
		while(a!="\0")
		{
			c++;
			mp[a]++;
			getline(cin,a);
		}
		for(auto x: mp)
		{
			cout << x.f << " "  << (((double)x.s/c)*100) << "\n";
		}
	}
}
