#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<double,double> dd;

#define f first
#define s second
#define pb push_back

struct aresta{
	
	double p;
	dd u,v;
	bool operator<(aresta const& b){
		return p<b.p;
	}
};

map<dd,dd> pai;
map<dd,int> rannk;
vector<aresta> lis;
vector<dd> en;

void inic(){
	
	for(auto i: en){
		pai[i] = i;
		rannk[i] = 1;
	}
}

dd findSet(dd p){
	
	if(pai[p]==p) return p;
	return pai[p]=findSet(pai[p]);
}

bool isSameSet(dd u,dd v){
	
	return findSet(u)==findSet(v);
}

void unionSet(dd u,dd v){
	
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

int main (){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int v,e;
	cin >> v >> e;
	while(v||e)
	{
		aresta aux;
		int sum=0,u,v1,p;
		for(int i=0;i<e;i++)
		{
			cin >> u >> v1 >> p;
			aux.u=u,aux.v=v1,aux.p=p;
			lis.pb(aux);
			sum+=p;
		}
		inic(v+1);
		sort(lis.begin(),lis.end());
		int burro=0;
		for(auto i: lis)
		{
			if(findSet(i.u)!=findSet(i.v))
			{
				burro+=i.p;
				unionSet(i.u,i.v);
			}
		}
		cout << sum-burro << "\n";
		lis.clear();
		cin >> v >> e;
	}
}
