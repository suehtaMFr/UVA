#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main () {
	
	string n;
	cin >> n;
	while(n!="0")
	{
		long long int a = stoll(n),b=0;
		map<long long int,int> mp;
		int c=0;
		cout << "Original number was " << n << "\n";
		while(mp[a]!=2)
		{
			sort(n.begin(),n.end());
			a = stoll(n);
			sort(n.rbegin(),n.rend());
			b = stoll (n);
			cout << b  << " - " << a << " = " << b-a << "\n";
			a=b-a;
			n = to_string(a);
			mp[a]++;
			c++;
		}
		cout << "Chain length " << c << "\n\n";
		cin >> n;
	}
}
