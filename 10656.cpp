#include <iostream>
#include <vector>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int ct,a;
	while(cin >> ct && ct)
	{
		vector<int> v;
		for(int i=0;i<ct;i++)
		{
			cin >> a;
			if(a)
				v.push_back(a);
		}
		if(!(int)v.size())
			v.push_back(0);
		for(int i=0;i<(int)v.size();i++)
		{
			cout << v[i];
			if(i<(int)v.size()-1)
				cout << " ";
		}
		cout << "\n";
	}
}
