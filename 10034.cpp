#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef pair<double,double> ii;

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
map<ii,int> rannk;
vector<aresta> lis;
vector<ii> en;

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

int main (){
	
	int ct;
	cin >> ct;
	for(int z=0;z<ct;z++)
	{
		if(z&&z<ct)
		{
			cout <<"\n";
		}
		int qd;
		cin >> qd;
		for(int i=0;i<qd;i++){
			double x,y;
			cin >> x >> y;
			en.pb({x,y});
		}
		aresta aux;
		for(int i=0;i<qd;i++)
		{
			for(int j=i+1;j<qd;j++)
			{
				double x1=en[i].f,x2=en[j].f,y1=en[i].s,y2=en[j].s;
				double d=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
				aux.p=d,aux.u=en[i],aux.v=en[j];
				lis.pb(aux);
			}
		}
		inic();
		sort(lis.begin(),lis.end());
		double res=0.0;
		for(auto ele: lis)
		{
			if(findSet(ele.u)!=findSet(ele.v))
			{
				res+=ele.p;
				unionSet(ele.u,ele.v);
			}
		}
		cout << fixed << setprecision(2);
		cout << res <<"\n";
		en.clear();
		lis.clear();
		pai.clear();
		rannk.clear();
	}
}
