#include <iostream>
#include <cstring>

using namespace std;

typedef string corda;

int dp[1001][1001];

int f(corda a,corda b,int i,int j){
	if(i==(int)a.size() || j==(int)b.size())
		return 0;
		
	if(a[i]==b[j])
		return dp[i][j] = 1 + f(a,b,i+1,j+1);
		
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	return dp[i][j] = max(f(a,b,i+1,j),f(a,b,i,j+1));
}

int main () {
	
	corda a,b;
	while(getline(cin,a))
	{
		memset(dp,-1,sizeof(dp));
		getline(cin,b);
		cout << f(a,b,0,0) << "\n";
	}	
}
