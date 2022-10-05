#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef unsigned long long int no;

no dp[22][10024];//index,values
int v[22];

no f(int i,int c){
	
	if(c==0)
		return 1;
	if(c<0 || i==0)
		return 0;
	if(dp[i][c]!=-1)
		return dp[i][c];
	no sum=0;
	if(c>=v[i])
		sum+=f(i,c-v[i]);
	sum+=f(i-1,c);
	return dp[i][c] = sum;
}

int main () {
	
	for(int i=1;i<=21;i++)
	{
		v[i]=i*i*i;
	}
	int n;
	while(cin >> n)
	{
		for(int i=1;i<=21;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=-1;
		cout << f(21,n) << "\n";
	}
}
