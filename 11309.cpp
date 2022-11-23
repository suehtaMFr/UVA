#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v;//vector containing all palindromes

bool f(string a,int i,int j){//verify palimdrome
	
	if(i>j)
		return true;
		
	if(a[i]!=a[j])
		return false;
	
	return f(a,i+1,j-1);
}

void precompute(){//precompute all palindromes in the range 00:00 to 23:59
	
	for(int i=0; i<1440; i++){
		int minutos=i;
		string m,h;
		string str,str2,aux;
		
		aux=to_string(minutos/60);
		h=(minutos/60<=9? "0":"")+aux;
		str2=(aux!="0" ? aux:"");
		
		aux=to_string(minutos%60);
		m=(minutos%60<=9 ? "0":"")+aux;
		str2=(h=="00" ? aux:str2+m);
		str=h+":"+m;
		if(f(str2,0,(int)str2.size()-1))
			v.push_back(str);
	}
}

int main () {
	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	precompute();
	
	int tc;
	cin >> tc;
	string a;
	for(int i=0;i<tc;i++)
	{
		cin >> a;
		int p=upper_bound(v.begin(),v.end(),a) - v.begin();
		cout << (p==(int)v.size()? "00:00":v[p+(v[p]==a)]) << "\n";
	}
}
