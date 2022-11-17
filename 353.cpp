#include <iostream>
#include <set>

using namespace std;

bool f(string a,int i,int j){
	
	if(i>j)
		return true;
	
	if(a[i]!=a[j])
		return false;
	
	return f(a,i+1,j-1);
}

int main () {
	
	string a;
	while(cin >> a)
	{
		set<string> b;
		for(int i=0;i<(int)a.size();i++)
		{
			for(int j=0;j<(int)a.size();j++)
			{
				if(i<=j&&f(a,i,j))
				{
					string s;
					for(int k=i;k<=j;k++)
						s+=a[k];
					b.insert(s);
				}
			}
		}
		cout << "The string '" << a << "' contains " << b.size() << " palindromes.\n"; 
	}	
}
