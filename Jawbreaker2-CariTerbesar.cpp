#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[50][50];
bool vis[50][50];

bool isValid(int a, int b, int c){
	if (a>=0 and a < n and b>=0 and b < m and vis[a][b] == false and arr[a][b] == c) return true;
	else return false;
}

int dfs(int a, int b, int c){
	
	if (!isValid(a,b,c)) return 0;
	else {
		vis[a][b] = true;
		
		int temp = 1;
		
		temp += dfs(a-1,b,c);
		temp += dfs(a+1,b,c);
		temp += dfs(a,b+1,c);
		temp += dfs(a,b-1,c);
		
		return temp;
	}
	
}

int main(){
	
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	int maks = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!vis[i][j]) {
				int temp = dfs(i,j,arr[i][j]);
				temp *= (temp - 1);
				maks = max(temp, maks);
			}
		}
	}

	cout << maks << endl;

	return 0;
}

