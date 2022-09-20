#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef string ii;

#define f first
#define s second
#define pb push_back

struct aresta{

	double p;
	ii u,v;
	bool operator<(aresta const& b){
		return p<b.p;
	}
};

map<ii,ii> pai;
set<ii> en;
map<ii,int> rannk;
vector<aresta> lis;

void inic(){

	for(auto i: en){
		pai[i] = i;
		rannk[i] = 1;
	}
}

ii findSet(ii p){

	if(pai[p]==p) return p;
	return pai[p]=findSet(pai[p]);
}

bool isSameSet(ii u,ii v){

	return findSet(u)==findSet(v);
}

void unionSet(ii u,ii v){

	if(isSameSet(u,v)) return;
	u=findSet(u),v=findSet(v);
	if(rannk[u]>rannk[v])
	{
		pai[v]=u,rannk[u]++;
	}
	else
	{
		pai[u]=v,rannk[v]++;
	}
}	

int main () {
	
	int ct;
	cin >> ct;
	for(int z=0;z<ct;z++)
	{
		if(z)
		{
			cout << "\n";
		}
		int v,e;
		cin >> v >> e;
		for(int i=0;i<e;i++)
		{
			aresta aux;
			cin >> aux.u >> aux.v >> aux.p;
			lis.pb(aux);
			en.insert(aux.u),en.insert(aux.v);
		}
		inic();
		sort(lis.begin(),lis.end());
		int res=0;
		for(auto ele: lis)
		{
			if(findSet(ele.u)!=findSet(ele.v))
			{
				res+=ele.p;
				unionSet(ele.u,ele.v);
			}
		}
		cout << res << "\n";
		lis.clear();
		rannk.clear();
		pai.clear();
		en.clear();
	}
}
