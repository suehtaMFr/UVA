#include <iostream>

using namespace std;

int main () {	
	
	int tc;
	cin >> tc;
	for(int i=0;i<tc;i++)
	{
		string a,c;
		int b;
		cin >> a >> b;
		for(int j=0;j<b;j++)
		{
			bool ans=false;
			cin >> c;
			for(int k=0,l=0;k<(int)a.size()&&!ans;k++)
			{
				l=(a[k]==c[l] ? l+1:0);
				ans=(l==(int)c.size());
			}
			cout << (ans ? 'y':'n') << '\n';
		}
	}
}
