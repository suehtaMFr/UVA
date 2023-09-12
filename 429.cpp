#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define import python
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
typedef long long int ll;
// long double pi = 3.141592653589793;
// priority_queue<int,vector<int>,greater<int>> pq;

bool ord(string &a, string &b){
	return sz(a)<sz(b);
}

struct no{
	int v=0;
};

vector<string> v;
map<string,vector<string>> adj;

int bfs(string a, string b){
	map<string,no> dist, vis;
	vis[a].v=1;
	queue<string> q;q.push(a);
	while(!q.empty()){
		string u = q.front();q.pop();
		if(u==b)return dist[b].v;
		for(string x : adj[u]){
			if(!vis[x].v){
				dist[x].v = dist[u].v+1;
				vis[x].v = 1;
				q.push(x);
			}
		}
	}
	return 0;
}

int main () {
	
	fast;
	string a, b;
	int n;
	cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		cout << (i ? "\n":""); 
		getline(cin,a);
		while(a=="\0") getline(cin,a);
		while(a!="*"){
			v.pb(a);
			getline(cin,a);
		}
		sort(all(v),ord);
		for(int i=0;i<sz(v);i++){
			for(int j=i+1,k=0,c=0;j<sz(v) && sz(v[i])==sz(v[j]);j++){
				for(k=0,c=0;k<sz(v[i]);k++) c+=v[i][k]!=v[j][k];
				if(c==1){
					adj[v[i]].pb(v[j]);
					adj[v[j]].pb(v[i]);
				}
			}
		}
		getline(cin,a);
		while(a!="\0"){
			stringstream ss; ss<<a;
			ss>>a; ss>>b;
			cout << a << " " << b << " " << bfs(a,b) << "\n";
			getline(cin,a);
		} 
		v.clear();
	}
}
