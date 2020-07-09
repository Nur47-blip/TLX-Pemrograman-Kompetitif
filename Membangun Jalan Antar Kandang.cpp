#include <bits/stdc++.h>

using namespace std;

int n,q;
int par[100001];

int getpar(int x){
	if (par[x]==x) return x;
	else {
		par[x]=getpar(par[x]);
		return par[x];
	}
}

int cek(int a, int b){
	int x=getpar(a);
	int y=getpar(b);
	return (x==y);
}

void join(int a, int b){
	int x=getpar(a);
	int y=getpar(b);
	par[x]=y;
}

int main(){

	cin>>n>>q;
	
	for (int i=1;i<=n;i++) {
		par[i]=i;
	}
	
	while (q--){
		int a,b,c;
		cin>>a>>b>>c;
		if (a==1) {
			join(b,c);
		}
		else {
			if (cek(b,c)) cout<<"Y\n";
			else cout<<"T\n";
		}
	}

	return 0;
}
