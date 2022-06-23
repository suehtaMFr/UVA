#include <iostream>
#include <utility>
#include <cstring>
#include <cstdio>
#include <queue>

#define f first
#define s second

using namespace std;

int disf[1024][1024],disj[1024][1024],vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};
char mapa[1024][1024];
bool vis[1024][1024],visf[1024][1024],visj[1024][1024];

int saida(int orix,int oriy,int maxX,int maxY){
    vis[orix][oriy]=true;
    queue<pair<int,int> > q;
    q.push({orix,oriy});
    while(!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        if(u.f==0 || u.s==0 || u.f==maxX-1 || u.s==maxY-1)
        {
            return disj[u.f][u.s];
        }
        int k,nx,ny;
        for(k=0;k<4;k++)
        {
            nx=u.f+vx[k],ny=u.s+vy[k];
            if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !vis[nx][ny] && (disj[nx][ny]<disf[nx][ny] || disf[nx][ny]==-1))
            {
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}

void bjoes(int orix,int oriy,int maxX,int maxY){

    visj[orix][oriy]=true;
    disj[orix][oriy]=0;
    queue<pair<int,int> > q;
    q.push({orix,oriy});
    while(!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        int k,nx,ny;
        for(k=0;k<4;k++)
        {
            nx=u.f+vx[k],ny=u.s+vy[k];
            if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !visj[nx][ny])
            {
                visj[nx][ny]=true;
                disj[nx][ny]=disj[u.f][u.s]+1;
                q.push({nx,ny});
            }
        }
    }
}

void bfires(int orix,int oriy,int maxX,int maxY){

    visf[orix][oriy]=true;
    disf[orix][oriy]=0;
    queue<pair<int,int> > q;
    q.push({orix,oriy});
    while(!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        int k,nx,ny;
        for(k=0;k<4;k++)
        {
            nx=u.f+vx[k],ny=u.s+vy[k];
            if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !visf[nx][ny])
            {
                visf[nx][ny]=true;
                disf[nx][ny]=disf[u.f][u.s]+1;
                mapa[nx][ny]='F';
                q.push({nx,ny});
            }
            else
            {
				if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && mapa[nx][ny]=='F' && disf[nx][ny]>disf[u.f][u.s]+1)
				{
					visf[nx][ny]=true;
					disf[nx][ny]=disf[u.f][u.s]+1;
					mapa[nx][ny]='F';
					q.push({nx,ny});
				}
			}
        }
    }
}

int main () {
	int q;
	cin >> q ;
	for(int z=0;z<q;z++)
    {
        queue<pair<int,int> > orif;
        
        memset(visf,false,sizeof(visf));
        memset(disf,-1,sizeof(disf));
        memset(visj,false,sizeof(visj));
        memset(disj,-1,sizeof(disj));
        memset(vis,false,sizeof(vis));
        
        int m,n;
        char c;
        cin >> m >> n;
        int i,j,orijx,orijy;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin >> c;
                mapa[i][j]=c;
                if(c=='#')
                {
                    vis[i][j]=true,visf[i][j]=true,visj[i][j]=true;
                }
                else
                {
                    if(c=='F')
                    {
                        orif.push({i,j});
                         vis[i][j]=true,visf[i][j]=true,visj[i][j]=true;
                    }
                    else
                    {
                        if(c=='J')
                        {
                            orijx=i,orijy=j;
                        }
                    }
                }
            }
        }
        while(!orif.empty())
        {
            int fx=orif.front().f,fy=orif.front().s;
            bfires(fx,fy,m,n);
            orif.pop();
        }
        bjoes(orijx,orijy,m,n);
        int s=saida(orijx,orijy,m,n);
        if(s!=-1)
        {
            cout << s+1 << "\n";
        }
        else
        {
           cout << "IMPOSSIBLE\n";
        }
    }
}
