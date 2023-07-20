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

struct aresta{
	int u,v,p;
	bool operator <(aresta const & b){
		return p<b.p;
	}
};

int rannk[10020], ft[10020];
vector<aresta> lis;

void inic(int n){
	for(int i=0;i<=n;i++) ft[i]=i,rannk[i]=1;
}

int findft(int u){
	if(ft[u]==u) return u;
	return ft[u] = findft(ft[u]);
}

void unionv(int u, int v){
	u = findft(u); v = findft(v);
	if(u==v)return;
	if(rannk[u]>=rannk[v]){ rannk[u]+=rannk[v]+1;ft[v]=u;}
	else { rannk[v]+=rannk[u]+1;ft[u]=v;}
}

int main () {
	
	fast;
	int tc; cin >> tc;
	for(int l=1;l<=tc;l++){
		int n, e, ar;
		cin >> n >> e >> ar;
		for(int i=0, x, y, z;i<e;i++){
			cin >> x >> y >> z;
			lis.pb({x,y,z});
		}
		sort(all(lis));
		inic(n);
		int s=0, c=0;
		for(int i=0;i<sz(lis);i++){
			aresta a = lis[i];
			if(findft(a.u)!=findft(a.v) && a.p<ar){
				unionv(a.u,a.v);
				s+=a.p;
			}
		}
		for(int i=1;i<=n;i++) c+=(ft[i]==i);
		c=(!c ? 1 : c);
		cout << "Case #" << l << ": " << s+c*ar << " " << c << "\n";
		lis.clear();
	}
}
