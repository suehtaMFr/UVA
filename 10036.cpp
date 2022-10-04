#include <iostream>
#include <cstring>

using namespace std;

int pd[10024][114];//values,sum
int v[10024];

int f(int i,int sum,int d){
	
	if(i==0)
	{
		return (!(sum%d));
	}
	if(pd[i][sum]!=-1)
	{
		return pd[i][sum];
	}
	
	int op1=f(i-1,(sum+v[i-1])%d,d);
	int op2=f(i-1,(sum-v[i-1])%d,d);
	return pd[i][sum] = (op1 || op2);
}

int main (){
	
	int ct;
	cin >> ct;
	for(int i=0;i<ct;i++)
	{
		memset(pd,-1,sizeof(pd));
		int n,div;
		cin >> n >> div;
		for(int j=0;j<n;j++) 
			cin >> v[j];
		cout << (f(n,0,div) ? "Divisible\n" : "Not divisible\n");
	}
}
