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
	bool operator<(aresta const&b){
		return p<b.p;
	}
};

int pai[1002],rannk[1002];
vector<aresta> lis;

void inic(int n){
	
	for(int i=0;i<n;i++){
		pai[i]=i,rannk[i]=1;
	}
}

int findft(int p){
	
	if(pai[p]==p) return p;
	return pai[p]=findft(pai[p]);
}

void uniong(int u,int v){
	
	u=findft(u),v=findft(v);
	if(u==v) return;
	if(rannk[u]>rannk[v]) pai[v]=u,rannk[u]+=rannk[v]+1;
	else pai[u]=v,rannk[v]+=rannk[u]+1;
}

int main () {
	
	fast;
	int n, m;
	while(cin >> n >> m && (n||m)){
		for(int i = 0, x, y, z; i < m; i++){
			cin >> x >> y >> z;
			lis.pb({x,y,z});
		}
		priority_queue<int,vector<int>,greater<int>> ans;
		inic(n);
		sort(all(lis));
		for(int i=0;i<sz(lis);i++){
			aresta x = lis[i];
			if(findft(x.u)!=findft(x.v)){
				uniong(x.u,x.v);
			}
			else ans.push(x.p);
		}
		if(ans.empty()) cout << "forest\n";
		else{
			while(!ans.empty()){
				cout << ans.top() << (ans.size()>1 ? " ":"");
				ans.pop();
			}
			cout << "\n";
		}
		lis.clear();
	}
}
