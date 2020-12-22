#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

int n, l, t, awal, akhir;
vector<vector<int>> jalan(501), tol(501);
vector<int> blmlewat(501, 1e9), dahlewattol(501, 1e9);

void solve(int a, int b){
	if (a == b) return;
	
	for (int i = 0; i < jalan[a].size(); i++){
		int k = jalan[a][i];
		if (blmlewat[a]+1<blmlewat[k]){
			blmlewat[k] = blmlewat[a]+1;
			solve(k, b);
		}
		if (dahlewattol[a]+1<dahlewattol[k]){
			dahlewattol[k] = dahlewattol[a]+1;
			solve(k, b);
		}
	}
	
	for (int i = 0; i < tol[a].size(); i++){
		int k = tol[a][i];
		if (blmlewat[a]+1<dahlewattol[k]){
			dahlewattol[k] = blmlewat[a]+1;
			solve(k,b);
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> l >> t >> awal >> akhir;
	for (int i = 0; i < l; i++){
		int a,b;
		cin >> a >> b;
		jalan[a].pb(b);
		jalan[b].pb(a);
	}
	
	for (int i = 0; i < t; i++){
		int a,b;
		cin >> a >> b;
		tol[a].pb(b);
		tol[b].pb(a);
	}
	
	blmlewat[awal] = 0;
	solve(awal, akhir);
	
	cout << min(blmlewat[akhir], dahlewattol[akhir]) << endl;
	
	
	return 0;
}
