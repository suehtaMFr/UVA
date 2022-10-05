#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int dp[21][224];//index,values
int v[21],n;

int f(int i,int c){
	
	if(i==n)
		return c;
	
	if(dp[i][c]!=-1)
		return dp[i][c];
	
	int op1 = f(i+1,abs(c+v[i]));
	int op2 = f(i+1,abs(c-v[i]));
	return dp[i][c] = min(op1,op2);
}

int main () {
	
	int ct;
	cin >> ct;
	cin.ignore();
	for(int i=0;i<ct;i++)
	{
		for(int j=0;j<21;j++)
			for(int k=0;k<=200;k++)
				dp[j][k]=-1;
		string en,s;
		getline(cin,en);
		stringstream ss;
		ss<<en;
		n=0;
		while(ss>>s)
		{
			
			v[n++]=stoi(s);
		}
		int ans=f(0,0);
		cout << ((!ans) ? "YES\n":"NO\n");
	}
}
