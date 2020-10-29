#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[50][50];
bool vis[50][50];

bool isValid(int a, int b, int c){
	if (a >= 0 and a < n and b >=0 and b < m and vis[a][b] == false and arr[a][b] == c) return true;
	else return false;
}

int dfs(int a, int b, int c){
	if (!isValid(a,b,c)) return 0;
	else {
		int temp = 1;
		vis[a][b] = true;
		
		temp += dfs(a-1,b,c);
		temp += dfs(a+1,b,c);
		temp += dfs(a,b-1,c);
		temp += dfs(a,b+1,c);
		
		return temp;
	}
}

void runtuhkan(){
	for (int i = 0; i < m; i++){
		vector<int> isi;
		for (int j = n-1; j >= 0; j--){
			if (arr[j][i] > 0) isi.push_back(arr[j][i]);
		}
		int sz = isi.size();
		int cnt = 0;
		for (int j = n-1; j >=0; j--){
			arr[j][i] = 0;
		}
		
		for (int j = n-1; j >= 0; j--){
			if (cnt == sz) break;
			arr[j][i] = isi[cnt];
			cnt++;
		}
	}
}

void dfs2(int a, int b, int c){
	if (isValid(a,b,c)){
		vis[a][b] = true;
		
		arr[a][b] = 0;
		dfs2(a-1,b,c);
		dfs2(a+1,b,c);
		dfs2(a,b-1,c);
		dfs2(a,b+1,c);
	}
}

int main(){

	cin >> n >> m;
	
	pair<int, int> titik = make_pair(0,0);
	int maks = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!vis[i][j]){
				int temp = dfs(i,j,arr[i][j]);
				temp *= (temp-1);
				if (temp > maks){
					maks = temp;
					titik = make_pair(i,j);
				}
			}
		}
	}
	
	memset(vis, false, sizeof vis);
	
	int x = titik.first, y = titik.second;
	
	dfs2(x,y,arr[x][y]);

	runtuhkan();

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (arr[i][j] == 0) cout << ".";
			else cout << arr[i][j];
			
			if (j < m-1) cout << " ";
			else cout << endl;
		}
	}

	return 0;
}

