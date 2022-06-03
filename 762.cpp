#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>

#define f first
#define s second

using namespace std;

map<string,vector<string>> putariadj;
vector<string>vai,vol;

void pai(string p,map<string,pair<int,string>> &ppd){
	
	if(ppd[p].f!=0)
	{
		vai.push_back(ppd[p].s);
		pai(ppd[p].s,ppd);
		vol.push_back(p);
	}
}

void bfs(string ori,map<string,pair<int,string>> &ppd){
	
	ppd[ori].f=0;
	queue<string>fila;
	fila.push(ori);
	while(!fila.empty())
	{
		string u=fila.front();
		fila.pop();
		int tam=putariadj[u].size();
		for(int itt=0;itt<tam;itt++)
		{
			if(ppd[putariadj[u][itt]].f==-1)
			{
				ppd[putariadj[u][itt]].f=ppd[u].f+1;
				ppd[putariadj[u][itt]].s=u;
				fila.push(putariadj[u][itt]);
			}
		}
	}
}

int main () {
	
	int n,v=0;
	while(cin >> n)
	{
		if(v)
		{
			cout << "\n";
		}
		v++;
		int i;
		map<string,string> reset;
		map<string,string>::iterator it;
		
		map<string,pair<int,string>> putariaPD;
		map<string,pair<int,string>>::iterator itpd;
		string c1,c2,ori,des;
		for(i=0;i<n;i++)
		{
			cin >> c1 >> c2;
			putariadj[c1].push_back(c2);
			putariadj[c2].push_back(c1);
			reset[c1]=c2;
			reset[c2]=c1;
		}
		cin >> ori >> des;
		
		for(it=reset.begin();it!=reset.end();it++)
		{
			putariaPD[it->f].f=-1;
		}
		putariaPD[ori].f=-1;
		putariaPD[des].f=-1;
		bfs(ori,putariaPD);
		if(putariaPD[des].f==-1)
		{
			cout << "No route\n";
		}
		else
		{
			pai(des,putariaPD);
			int tam=vol.size(),ini=vai.size()-1,fim=0;
			for(;fim<tam;ini--,fim++)
			{
				cout << vai[ini] << " " << vol[fim] << "\n";
			}
			
		}
		putariadj.clear(),vai.clear(),vol.clear();
	}	
}
