#include <iostream>
#include <cstring>

using namespace std;

int dp[1024][1024];

void recover(string &s,int i,int j,int k,int l){
	
	if(i<=j)
	{
		if(s[i]==s[j])
		{	
			recover(s,i+1,j-1,k+1,l-1);
		}
		else
		{
			string aux;
			int t = s.size();
			if(dp[k+1][l]<dp[k][l-1])// k+1 best path
			{
				for(int x=0;x<=j;x++)
				{
					aux+=s[x];
				}
				aux+=s[i];
				for(int x=j+1;x<t;x++)
				{
					aux+=s[x];
				}
				s=aux;
				recover(s,i+1,j,k+1,l);
			}
			else// l-1 best path
			{
				for(int x=0;x<i;x++)
				{
					aux+=s[x];
				}
				aux+=s[j];
				for(int x=i;x<t;x++)
				{
					aux+=s[x];
				}
				s=aux;
				recover(s,i+1,j,k,l-1);
			}
		}
	}
}

int f(string a,int i,int j){
	
	if(i>j)
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	if(a[i]==a[j])
		return dp[i][j] = f(a,i+1,j-1);
	
	return dp[i][j] = 1 + min(f(a,i+1,j),f(a,i,j-1));
}

int main () {
	
	string s;
	while(cin >> s)
	{
		memset(dp,-1,sizeof(dp));
		int r = f(s,0,s.size()-1);
		recover(s,0,s.size()-1,0,s.size()-1);
		cout << r << " " << s << "\n";
	}
}
