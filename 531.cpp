#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back

int dp[124][124];

void recover(vector<string>&ans,vector<string>& a,vector<string>& b,int i,int j){
	
	if(i==(int)a.size() || j==(int)b.size())
		return;
		
	if(a[i]==b[j])
	{
		ans.pb(a[i]);
		recover(ans,a,b,i+1,j+1);
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1])
			recover(ans,a,b,i+1,j);
		else
			recover(ans,a,b,i,j+1);
	}
}

int f(vector<string>& a,vector<string>& b,int i,int j){
	
	if(i==(int)a.size() || j==(int)b.size())
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	if(a[i]==b[j])
		return dp[i][j] = 1 + f(a,b,i+1,j+1);
	
	return dp[i][j] = max(f(a,b,i+1,j),f(a,b,i,j+1));
}

int main () {

	string c;
	while(cin >> c)
	{
		memset(dp,-1,sizeof(dp));
		vector<string> a,b,ans;
		while(c!="#")
		{
			a.pb(c);
			cin >> c;
		}
		cin >> c;
		while(c!="#")
		{
			b.pb(c);
			cin >> c;
		}
		f(a,b,0,0);
		recover(ans,a,b,0,0);
		for(int i=0;i<(int)ans.size();i++)
		{
			cout << ans[i];
			if(i<(int)ans.size()-1)
				cout << " ";
		}
		cout << "\n";
	}
}
