#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, q; cin >> n >> m >> q;
	
	vector<vector<int>> graf(n+1, vector<int>(n+1, 1e9));
	for (int i = 0; i <= n; i++) graf[i][i] = 0;
	
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		graf[a][b] = min(c, graf[a][b]);
		graf[b][a] = min(c, graf[b][a]);
	}
	
	vector<int> komplek;
	for (int i = 0; i < q; i++){
		int x;
		cin >> x;
		komplek.pb(x);
	}
	
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i==j) graf[i][j] == 0;
				graf[i][j] = min(graf[i][j], graf[i][k]+graf[k][j]);
			}
		}
	}
	
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			cout << graf[i][j] << " ";
//		}
//		cout << endl;
//	}
	int sum = 0;
	for (int i = 1; i < q; i++){
		int a = komplek[i-1], b = komplek[i];
		sum += graf[a][b];
	}
	
	cout << sum << endl;

	return 0;
}
