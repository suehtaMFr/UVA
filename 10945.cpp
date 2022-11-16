#include <iostream>

using namespace std;

bool f(string a,int i,int j) {
	
	if(i>j)
		return true;
	if(a[i]!=a[j])
		return false;
	return f(a,i+1,j-1);
}

int main () {
	
	string b;
	while(getline(cin,b) && b!="DONE")
	{
		string a;
		for(int i=0;i<(int)b.size();i++)
		{
			if((b[i]>=65 && b[i]<=90))
			{
				a+=tolower(b[i]);
			}
			if(b[i]>=97 && b[i]<=122)
			{
				a+=b[i];
			}
		}
		if(f(a,0,(int)a.size()-1))
		{
			cout << "You won't be eaten!\n";
		}
		else
		{
			cout << "Uh oh..\n";
		}
	}	
}
