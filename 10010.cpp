#include <iostream>

using namespace std;

#define f first
#define s second

int vi[8] = {-1,-1,0,1,1,1,0,-1},vj[8] = {0,1,1,1,0,-1,-1,-1},cc=0;

char mat[54][54];

void res (int i,int j,int maxi,int maxj,string a,int p,int d) {
	if(p==(int)a.size()){
		 cc=p;
		 return;
	 }
	for(int k=0;k<8;k++)
	{
		int ni = i + vi[k],nj = j + vj[k];
		if(ni>=0 && ni<maxi && nj>=0 && nj<maxj && (d==9||d==k) && mat[ni][nj]==a[p])
		{
			res(ni,nj,maxi,maxj,a,p+1,k);
		}
	}
}

int main () {
	
	int ct;
	cin >> ct;
	for(int z=0;z<ct;z++)
	{
		if(z) cout << "\n";
		int n,m,qt;
		string a,c;
		cin >> n >> m;
		char ca;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> ca;
				mat[i][j] = tolower(ca);
			}
		}
		cin >> qt;
		for(int i=0;i<qt;i++)
		{
			a="";
			cin >> c;
			for(int j=0;j<(int)c.size();j++)
				a+=tolower(c[j]);
				
			pair<int,int> b={0,0};
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<m;k++)
				{
					if(mat[j][k]==a[0])
					{
						cc=0;
						b={j,k};
						int p=1;
						res(j,k,n,m,a,p,9);
						if(cc==(int)a.size())j=n,k=m;
					}
				}
			}
			cout << b.f+1 << " " << b.s+1 << "\n";
		}
	}
}
