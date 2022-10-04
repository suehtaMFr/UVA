#include <iostream>
#include <cstring>

using namespace std;

int pd[26][8000];//cents, capacity
int v[5]={50,25,10,5,1};

int f(int i,int c){
	if(c==0)
	{
		return 1;
	}
	if(c<0 || i>4)
	{
		return 0;
	}
	if(pd[i][c]!=-1)
	{
		return pd[i][c];
	}
	int sum=0;
	if(c>=v[i])sum+= f(i,c-v[i]);
	sum+=f(i+1,c);
	return pd[i][c] = sum;
}

int main () {
	
	int n;
	while(cin >> n)
	{
		for(int i=1; i<=n; i++)
			for(int j=0; j<5; j++)
				pd[j][i]=-1;
				
		cout << f(0,n) << "\n";
	}
}
