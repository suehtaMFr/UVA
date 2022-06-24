#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define f first
#define s second
#define pb push_back

using namespace std;

vector<int> bot;
vector<pair<int,bool>> dv(10000);

int bfsum(int ori,int des){
	
	dv[ori]={0,true};
	queue<int> q;
	q.push(ori);
	while(!q.empty())
	{
		int u=q.front(),tam=bot.size();
		q.pop();
		if(u==des)
		{
			return dv[u].f;
		}
		for(int k=0;k<tam;k++)
		{
			int nx=(u+bot[k])%10000;
			if(!dv[nx].s)
			{
				dv[nx]={dv[u].f+1,true};
				q.push(nx);
			}
		}
	}
	return -1;
}


int main () {
	
	int l,u,r,v=1;
	cin >> l >> u >> r;
	while(l||u||r)
	{	
		for(int i=0;i<10000;i++){dv[i]={-1,false};}
		
		for(int i=0,v;i<r;i++)
		{
			cin >> v;
			bot.pb(v);
		}
		int d=bfsum(l,u);;
		cout << "Case " << v << ": ";
		if(d!=-1)
		{
			cout << d << "\n";
		}
		else
		{
			cout << "Permanently Locked\n";
		}
		cin >> l >> u >> r;
		bot.clear();
		v++;
	}
}
