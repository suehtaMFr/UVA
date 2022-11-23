#include <iostream>
#include <map>

using namespace std;

map<char,char> mp;

void inimp(){
	
	mp['A']='A',mp['E']='3',mp['H']='H',mp['I']='I',mp['J']='L',mp['M']='M',mp['O']='O',mp['S']='2',mp['T']='T',mp['U']='U',mp['V']='V',mp['W']='W',mp['X']='X',mp['Y']='Y',mp['Z']='5',mp['1']='1',mp['2']='S',mp['3']='E',mp['5']='Z',mp['8']='8';
}

void f(string a,int i,int j,int m,int &mm,bool &p) {
	
	if(i>j)
	{
		mm=m;
	}
	else
	{
		if(a[i]!=a[j] || (a[i]==mp[a[j]] || mp[a[i]]==a[j]))
		{
			if(a[i]==mp[a[j]] || mp[a[i]]==a[j])
			{
				f(a,i+1,j-1,m+1,mm,p);
			}
			else
			{
				p=false;
				return;
			}
			if(a[i]!=a[j])
				p=false;
		}
		else
		{
			f(a,i+1,j-1,m,mm,p);
		}
	}
}

int main () {
	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	inimp();
	string a;
	while(cin >> a)
	{
		int mm=0,z=a.size()+(a.size()%2!=0);
		bool ans=true;
		f(a,0,(int)a.size()-1,0,mm,ans);
		cout << a << " -- ";
		if(ans)
		{
			if(mm==z/2)
			{
				cout << "is a mirrored palindrome.\n\n";
			}
			else
			{
				cout << "is a regular palindrome.\n\n";
			}
		}
		else
		{
			if(mm==(z/2))
			{
				cout << "is a mirrored string.\n\n";
			}
			else
			{
				cout << "is not a palindrome.\n\n";
			}
		}
	}
}
