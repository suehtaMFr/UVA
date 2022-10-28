#include <iostream>
#include <cstring>

using namespace std;

int dp[1024][1024];

int f (string a,int i,int j) {
	
	if(i>j)
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	if(a[i]==a[j])
		return dp[i][j] = 1+(i!=j) + f(a,i+1,j-1);
			
	return dp[i][j] = max(f(a,i+1,j),f(a,i,j-1));
}

int main () {
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	int ct;
	cin >> ct;
	cin.ignore();
	string s;
	for(int i=0;i<ct;i++)
	{
		memset(dp,-1,sizeof(dp));
		getline(cin,s);
		cout << f(s,0,(int)s.size()-1) << "\n";
	}
}
