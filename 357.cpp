#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long int no;

no dp[6][30024];//index,values
int v[6]={50,25,10,5,1};

no f(int i,no c){
	
	if(c==0)
	{
		return 1;
	}
	if(c<0 || i==5)
	{
		return 0;
	}
	if(dp[i][c]!=-1)
	{
		return dp[i][c]; 
	}
	no sum=0;
	if(c>=v[i])
	{
		sum=f(i,c-v[i]);
	}
	sum+=f(i+1,c);
	return dp[i][c]=sum;
}

int main () {
	
	int n;
	while(cin >> n)
	{
		for(int i=0;i<6;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=-1;
		no ans = f(0,(no)n);
		if(ans==1)
		{
			cout << "There is only 1 way to produce " << n << " cents change.\n";
		}
		else
		{
			cout << "There are " <<  ans << " ways to produce "<< n << " cents change.\n";
		}
	}
}
