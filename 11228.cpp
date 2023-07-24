#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
//rapadura é doce, mas não é mole não
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//I see you
std::mt19937 rng((int) std::chrono ::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;

vector<int> pai(1000000),rannk(1000000);
vector<pair<double,pair<int,int>>> lis;

void inic(int n){

	for(int i=0;i<n;i++){
		pai[i] = i;
		rannk[i] = 1;
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

	u=findSet(u),v=findSet(v);
	if(rannk[u]>rannk[v]) pai[v]=u,rannk[u]+=rannk[v];
	else pai[u]=v,rannk[v]+=rannk[u];
}

int main () {
	
	int ct, z=1;
	cin >> ct;
	while(ct--)
	{
		int v,md;
		cin >> v >> md;
		vector<int> x(v), y(v);
		inic(v);
		for(int i=0;i<v;i++){ cin >> x[i] >> y[i];}
		for(int i=0;i<v;i++){
			for(int j=i+1;j<v;j++)
			{
				double d=sqrt(((double)(x[i]-x[j])*(x[i]-x[j])) + ((y[i]-y[j])*(y[i]-y[j])));
				lis.pb({d,{i,j}});
			}
		}
		sort(all(lis));
		int es = 0;
		double r = 0.0, f = 0.0;//ruas ferrovias
		for(int i=0;i<sz(lis);i++){
		    double p = lis[i].ff;
		    int a = lis[i].ss.ff, b = lis[i].ss.ss;
			if(!isSameSet(a,b))
			{
				unionSet(a,b);
				if(p<=md)
				{
					es++;
					r+=p;
				}
				else f+=p;
			}
		}
		cout << fixed << setprecision(0);
		cout << "Case #" << z++ << ": " << v-es << " " << r << " " << f << "\n";
		lis.clear();
	}
}
