#include <iostream>
#include <cstring>

using namespace std;

int dp[1024][1024];

int tmin(int a,int b,int c){
	return min(min(a,b),c);
}

int f(string a,int i,int j) {
	
	if(i>j)
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	if(a[i]==a[j])
		return dp[i][j] = f(a,i+1,j-1);
	
	return dp[i][j] = 1 + tmin(f(a,i+1,j-1),f(a,i+1,j),f(a,i,j-1));
}

int main () {
	
	int tc;
	cin >> tc;
	string a;
	for(int i=0;i<tc;i++)
	{
		memset(dp,-1,sizeof(dp));
		cin >> a;
		cout << "Case " << i+1 << ": " << f(a,0,((int)a.size()-1)) << "\n";
	}
}
