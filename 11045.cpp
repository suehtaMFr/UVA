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


/*
t | out =  0
XXL     =  1
XL      =  2
L       =  3
M       =  4
S       =  5
XS      =  6
s | in  =  7
*/

int n;
vector<vector<int>> adj(40), cp(40,vector<int> (40));// cp = capacity

int bfs(int s, int t, vector<int>& parent) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, INT_MAX});
	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		for (int next : adj[cur]) {
			if (parent[next] == -1 && cp[cur][next]) {
				parent[next] = cur;
				int new_flow = min(flow, cp[cur][next]);
				if (next == t) return new_flow;
				q.push({next, new_flow});
			}
		}
	}
	return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(40);
    int new_flow;
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cp[prev][cur] -= new_flow;
            cp[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

inline int posi(string s){ return (s == "XXL" ? 1 : (s == "XL" ? 2 : (s == "L" ? 3 : (s == "M" ? 4 : (s == "S" ? 5 : 6)))));}

int main () {
	
	fast;
	for(int i = 1; i <= 6; i++) adj[i].pb(0);
	int tc,n,m; cin >> tc;
	string l, r;
	while(tc--){
		cin >> n >> m;
		cp = vector<vector<int>>(40, vector<int>(40, 0));
		for(int i = 1; i <= 6; i++) cp[i][0] = n/6;
		for(int i = 8, x, y; i < m+8; i++){
			cin >> l >> r;
			x = posi(l), y = posi(r); 
			adj[7].pb(i);
			cp[7][i] = 1;
			adj[i].pb(x); adj[i].pb(y); adj[x].pb(i); adj[y].pb(i);
			cp[i][x] = cp[i][y] = 1; cp[x][i] = cp [y][i] = 1;
		}
		cout << (maxflow(7,0)>=m ? "YES\n" : "NO\n");
		for(int i = 7;i<40;i++) adj[i].clear();
	}
}
