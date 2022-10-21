#include <iostream>
#include <cstring>

using namespace std;

int dp[124][124];

int f(string a,string b,int i,int j){
	
	if(i==(int)a.size() || j==(int)b.size())
		return 0;
		
	if(dp[i][j]!=-1)
		return dp[i][j];
		
	if(a[i]==b[j])
		return dp[i][j] = 1 + f(a,b,i+1,j+1);
	
	return dp[i][j] = max(f(a,b,i+1,j),f(a,b,i,j+1));
}

int main (){
	
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	string a,b;
	int v=1;
    while(getline(cin,a))
    {
      if(a[0]=='#') break;
      getline(cin,b);
      memset(dp,-1,sizeof(dp));
      cout << "Case #" << v++ << ": you can visit at most " << f(a,b,0,0) << " cities.\n";  
    }
}
