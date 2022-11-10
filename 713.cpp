#include <iostream>

using namespace std;

void complet(string & a,string & b){
	
	int x=a.size();
	int z=b.size();
	int tam;
	if(x>z)
	{
		tam=x-z;
		for(int i=0;i<tam;i++)
			b+='0';
	}
	else
	{
		tam=z-x;
		for(int i=0;i<tam;i++)
			a+='0';
	}
}

string sum(string a,string b){
	string r,res;
	complet(a,b);
	bool c=false;
	int va;
	for(int i=0;i<(int)a.size();i++)
	{
		va=((a[i]-48)+(b[i]-48)+c);
		char ca=(va%10)+48;
		r+=ca;
		c=va/10;
		if(i==(int)a.size()-1 && c)
		{
			r+=((char)(c+48));
		}
	}
	bool v=false;
	for(int i=0;i<(int)r.size();i++)
	{	
		if(v||(r[i]!='0'&&!v))
		{
			v=true;
			res+=r[i];
		}
	}
	return res;
}

int main () {
	
	int ct;
	cin >> ct;
	string a,b;
	for(int i=0;i<ct;i++)
	{
		cin >> a >> b;
		cout << sum(a,b) << "\n";
	}
}
