#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first.first
#define se first.second
#define th second

vector<int> par(101);
bool cmp(pair<pii, int> a, pair<pii, int> b){
	return (a.th < b.th);
}

int getpar(int a){
	if (par[a] == a) return a;
	int x = getpar(par[a]);
	par[a] = x;
	return x;
}

void join(int a, int b){
	int parA = getpar(a);
	int parB = getpar(b);
	par[parA] = parB;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	
	vector<pair<pii, int>> edge;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int x; cin >> x;
			if (j > i){
				edge.pb(mp(mp(i,j), x));
			}
		}
	}

	int sz = edge.size();
	
	sort(edge.begin(), edge.end(), cmp);
	int cnt = 0, sum = 0;
	
	for (int i = 0; i < n; i++) par[i] = i;
	
	for (int i = 0; i < sz; i++){
		int a = edge[i].fi, b = edge[i].se;
		if (getpar(a)!=getpar(b)){
			join(a,b);
			cnt++;
			sum += edge[i].th;
			if (cnt == n-1) break;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
