#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back

int dp[124][124];

int f (vector<int>& a,vector<int>& b,int i,int j) {
	
	if(i==(int)a.size() || j==(int)b.size())
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	if(a[i]==b[j])
		return dp[i][j] = 1 + f(a,b,i+1,j+1); 
	
	return dp[i][j] = max(f(a,b,i+1,j),f(a,b,i,j+1));
}

int main ()	{
	
	int n,m,c=1;
	while(cin>>n && cin >> m && (n||m))
	{
		vector<int> a,b;
		int v;
		for(int i=0;i<n;i++)
			cin >> v,a.pb(v);
			
		for(int i=0;i<m;i++)
			cin >> v,b.pb(v);
			
		memset(dp,-1,sizeof(dp));
		cout << "Twin Towers #"<< c++ << "\n";
		cout << "Number of Tiles : " << f(a,b,0,0)<< "\n\n";
	}
}
