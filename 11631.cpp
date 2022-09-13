#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back

struct aresta{
	
	int u,v,p;
	bool operator<(aresta const&b){
		return p<b.p;
	}
};

int pai[200024],rannk[200024];
vector<aresta> lis;

void inic(int n){
	
	for(int i=0;i<n;i++){
		pai[i]=i,rannk[i]=1;
	}
}

int findSet(int p){
	
	if(pai[p]==p) return p;
	return pai[p]=findSet(pai[p]);
}

bool isSameSet(int u,int v){
	
	return findSet(u)==findSet(v);
}

void unionSet(int u,int v){
	
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
