#include <iostream>
#include <algorithm>
#include <cstring>

int pd[124][50024];// indice da quantidade , valor
int v[124];

using namespace std;

int f(int i,int j){
	
	if(i==0)
	{
		return j;
	}
	if(pd[i][j]!=-1)
	{
		return pd[i][j];
	}
	return pd[i][j]=min(abs(f(i-1,j+v[i-1])),abs(f(i-1,j-v[i-1])));	
}

int main () {
	
	int ct;
	cin >> ct;
	for(int i=0;i<ct;i++)
	{
		memset(pd,-1,sizeof(pd));
		int n;
		cin >> n;
		for(int j=0;j<n;j++)
		{
			cin >> v[j];
		}
		cout << f(n,0) << "\n";
	}
}
