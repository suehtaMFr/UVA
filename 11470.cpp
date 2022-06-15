#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

int main() {
	
	int n,zz=1;
	cin >> n;
	
	while(n)
	{
		vector<int> soma;
		int mat[n+1][n+1],i,j,q;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin >> mat[i][j];
			}
		}
		q=ceil((float)n/2);
		if(n%2==0)
		{
			for(int z=0,ini=1,fin=n;z<q;z++)
			{
				int s=0;
				for(i=ini;i<=fin;i++)
				{
					if((i==ini||i==fin))
					{
						for(j=ini;j<=fin;j++)
						{
							s+=mat[i][j];
						}
					}
					else
					{
						for(j=ini;j<=fin;j=j+(fin-ini))
						{
							s+=mat[i][j];
						}
					}
				}
				soma.pb(s);
				ini++;
				fin--;
			}
		}
		else
		{
			for(int z=0,ini=1,fin=n;z<q;z++)
			{
				int s=0;
				for(i=ini;i<=fin;i++)
				{
					if((i==ini||i==fin))
					{
						for(j=ini;j<=fin;j++)
						{
							s+=mat[i][j];
						}
					}
					else
					{
						if(ini!=fin)
						{
							for(j=ini;j<=fin;j=j+(fin-ini))
							{
								s+=mat[i][j];
							}
						}
						else
						{
							s=mat[i][ini];
						}	
					}
				}
				soma.pb(s);
				ini++;
				fin--;
			}
		}
		cout << "Case " << zz << ": ";
		int tam=soma.size();
		for(int y=0;y<tam;y++)
		{
			cout << soma[y];
			if(y<tam-1)
			{
				cout << " ";
			}
		}
		cout << "\n";
		cin >> n;
		zz++;
	}
}
