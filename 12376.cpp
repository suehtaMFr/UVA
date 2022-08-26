#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define f first
#define s second

void bfs(int& o,int& q,vector<priority_queue<pair<int,int>>> adj){
    
    if(adj[o].size())
    {
        q=q+adj[o].top().f;
        o=adj[o].top().s;
        bfs(o,q,adj);
    }
}

int main(){
   
   int ct;
   cin >> ct;
   for(int i=0;i<ct;i++)
   {
       int v,e,v1,v2;
       cin >> v >> e;
       int p[v];
       vector<priority_queue<pair<int,int>>> adj(v);
       for(int j=0;j<v;j++)
       {
           cin >> p[j];
       }
       for(int j=0;j<e;j++)
       {
           cin >> v1 >> v2;
           adj[v1].push({p[v2],v2});
       }
       int o=0,q=0;
       bfs(o,q,adj);
       cout <<"Case " << i+1 << ": " <<q << " " << o << "\n";
   }
}
