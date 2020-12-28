#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	
	int a, b; cin >> a >> b;
	a--; b--;
	
	stack<pii> s;
	s.push(mp(a,b));
	
	vector<vector<int>> val(n, vector<int>(m,1e9));
	val[a][b]=1;
	
	while (!s.empty()){
		int x = s.top().fi;
		int y = s.top().se;
		s.pop();
		
		int k = val[x][y];
		for (int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 or yy < 0 or xx >= n or yy >= m) continue;
			if (grid[xx][yy]==-1) continue;
			if (k+1 >= val[xx][yy]) continue;
			
			val[xx][yy] = k+1;
			s.push(mp(xx,yy));
		}
	}

	int ans = 1e9;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (i==0 or j==0 or i==n-1 or j==m-1){
				if (grid[i][j]==0) ans = min(ans, val[i][j]);
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}
