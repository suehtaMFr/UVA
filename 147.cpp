#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

typedef unsigned long long int no;

no dp[12][30024];//index vet,value
int v[11]={10000,5000,2000,1000,500,200,100,50,20,10,5};

no f(int i,int c){
	if(c==0)
	{
		return 1;
	}
	if(c<0 || i==11)
	{
		return 0;
	}
	if(dp[i][c]!=(no)-1)
	{
		return dp[i][c];
	}
	no sum=0;
	if(c>=v[i])
	{
		sum=f(i,c-v[i]);
	}
	sum+=f(i+1,c);
	return dp[i][c] =sum;
}

int main(){
	
	double n;
	cin >> n;
	while(n!=0.0)
	{
		memset(dp,-1.0,sizeof(dp));
		int v=n*10000;
    v=v/100;
		cout << fixed <<setprecision(2) << setfill (' ') << setw(6) << n;
		cout << setfill (' ') << setw(17) << f(0,v) << "\n";
		cin >> n;
	}
}
