#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>

#define f first
#define s second

using namespace std;

map<string,vector<string>> putariadj;
vector<string> vol;
void pai(string p,map<string,pair<int,string>> &ppd){
	
	if(ppd[p].f!=0)
	{
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
	
	int n,cn,qt,v=0;
	cin >> n;
	for(int y=0;y<n;y++)
	{	
		if(v)
		{
			cout << "\n";
		}
		v++;
		string c1,c2,ori,des;
		map<string,string> reset;
		map<string,pair<int,string>> putariaPD;
		cin >> cn >> qt;
		for(int i=0;i<cn;i++)
		{
			cin >> c1 >> c2;
			putariadj[c1].push_back(c2);
			putariadj[c2].push_back(c1);
			reset[c1]=c2;
			reset[c2]=c1;
			
		}
		
		for(int i=0;i<qt;i++)
		{
			for(map<string,string>::iterator it=reset.begin();it!=reset.end();it++)
			{
				putariaPD[it->f].f=-1;
			}
			cin >> ori >> des;
			putariaPD[ori].f=-1;
			putariaPD[des].f=-1;
			bfs(ori,putariaPD);
			vol.push_back(ori);
			pai(des,putariaPD);
			int tam=vol.size();
			for(int j=0;j<tam;j++)
			{
				char a=vol[j][0];
				cout << a;
			}
			cout << "\n";
			vol.clear();
		}
		putariadj.clear();
	}
}
