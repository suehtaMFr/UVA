#include <iostream>
#include <cstring>

using namespace std;

int dp[124][124];

int f(string a,string b,int i,int j){
	
	if(i==(int)a.size())
		return b.size()-j;
	
	if(j==(int)b.size())
		return a.size()-i;
		
	if(dp[i][j]!=-1)
		return dp[i][j];
		
	if(a[i]==b[j])
		return dp[i][j] = f(a,b,i+1,j+1);
		
	return dp[i][j] = 1 + min(min(f(a,b,i+1,j+1),f(a,b,i+1,j)),f(a,b,i,j+1));
}

int main () {
	
	int ct;
	cin >> ct;
	cin.ignore();
	string a,b;
	for(int i=0;i<ct;i++)
	{
		getline(cin,a);
		getline(cin,b);
		memset(dp,-1,sizeof(dp));
		cout << f(a,b,0,0) << "\n";
	}
}
