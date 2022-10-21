#include <iostream>
#include <cstring>

using namespace std;

int dp[1024][1024];
string a,b;

int f(int i,int j){

	if(i==(int)a.size()) return b.size()-j;
	if(j==(int)b.size()) return a.size()-i;
	
	if(a[i]==b[j]) return f(i+1,j+1);
	
	if(dp[i][j]!=-1) return dp[i][j];
		
	return dp[i][j] = 1+min(min(f(i+1,j+1),f(i+1,j)),f(i,j+1));
} 
int main () {
	
	int v1,v2;
	while(cin >> v1 >> a >> v2 >> b)
	{
		memset(dp,-1,sizeof(dp));
		cout << f(0,0) << "\n";
	}
}
