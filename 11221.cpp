#include <iostream>
#include <math.h>

using namespace std;

bool f(string a,int i,int j){
	
	if(i>j)
		return true;
	
	if(a[i]!=a[j])
		return false;
	
	return f(a,i+1,j-1);
}

int main () {
	
	int ct;
	cin >> ct;
	cin.ignore();
	for(int z=0;z<ct;z++)
	{
		string a,s;
		getline(cin,a);
		for(int i=0;i<(int)a.size();i++)
		{
			if(a[i]>=95 && a[i]<=122)
				s+=a[i];
		}
		cout << "Case #" << z+1 << ":\n";
		int raiz=sqrt(s.size());
		if(f(s,0,(int)s.size()-1) && raiz*raiz==s.size())
		{
			cout << raiz << "\n";	
		}
		else
		{
			cout << "No magic :(\n";
		}
	}	
}
