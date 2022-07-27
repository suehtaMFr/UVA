#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

#define pb push_back

using namespace std;

int INF = 999999999;

int capacity[61][61];
vector<int> adj[61];

map<string,int> tra;

void ini(int n){
	
	adj[54].pb(60);//l
	adj[55].pb(60);//xl
	adj[56].pb(60);//xxl
	adj[57].pb(60);//sx
	adj[58].pb(60);//m
	adj[59].pb(60);//s

	adj[60].pb(54);
	adj[60].pb(55);
	adj[60].pb(56);
	adj[60].pb(57);
	adj[60].pb(58);
	adj[60].pb(59);
	
	tra["L"]=54;
	tra["XL"]=55;
	tra["XXL"]=56;
	tra["XS"]=57;
	tra["M"]=58;
	tra["S"]=59;
	
	capacity[54][60]=(n/6);
	capacity[55][60]=(n/6);
	capacity[56][60]=(n/6);
	capacity[57][60]=(n/6);
	capacity[58][60]=(n/6);
	capacity[59][60]=(n/6);
}

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(61);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main () {
	
	
	int l,nn,m;
	cin >> l;
	
	for(int z=0;z<l;z++)
	{
		
		cin >> nn  >> m;
		string st1,st2;
		ini(nn);
		for(int y=1;y<=m;y++)
		{
			cin >> st1 >> st2;
			
			adj[y].pb(tra[st1]);
			adj[tra[st1]].pb(y);
			adj[y].pb(tra[st2]);
			adj[tra[st2]].pb(y);
			adj[0].pb(y);
			adj[y].pb(0);
			
			capacity[y][tra[st1]]=1;
			capacity[y][tra[st2]]=1;
			capacity[0][y]=1;
		}

		int res = maxflow(0,60);
		if(m==res)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		for(int it=0;it<61;it++)
		{
			adj[it].clear();
		}
		memset(adj,0,sizeof(adj));
	}
	
}
