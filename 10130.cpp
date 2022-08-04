#include <iostream>
#include <cstring>

using namespace std;

int peso[1024],valor[1024],pd[1024][1024],N;

int knap(int at,int w){
	
	if(at==N || w==0)
	{
		return 0;
	}
	if(pd[at][w]!=-1)
	{
		return pd[at][w];
	}
	if(peso[at]>w)
	{
		return pd[at][w]=knap(at+1,w);
	}
	
	int op1 = knap(at+1,w-peso[at])+valor[at];
	int op2 = knap(at+1,w);
	return pd[at][w] = max(op1,op2);
	
}

int main () {
	
	int ct;
	cin >> ct;
	for(int z=0;z<ct;z++)
	{
		int qe,p,w,f,ps;
		memset(pd,-1,sizeof(pd));
		cin >> qe;
		N=qe;
		for(int y=0;y<qe;y++)
		{
			cin >> p >> w;
			valor[y]=p;
			peso[y]=w;
		}
		cin >> f;
		int s=0;
		for(int y=0;y<f;y++)
		{
			cin >> ps;
			s+=knap(0,ps);
		}
		cout << s << "\n";
	}	
}
