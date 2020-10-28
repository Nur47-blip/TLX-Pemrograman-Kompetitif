#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, m, k;
	cin >> n >> m >> k;
	
	int arr[n][m];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	int kans = INT_MAX; //kolom answer
	int bans = INT_MAX; //baris answer
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int kemenarikan = 1;
			if (i > 0) kemenarikan *= arr[i-1][j];
			if (i < n-1) kemenarikan *= arr[i+1][j];
			if (j > 0) kemenarikan *= arr[i][j-1];
			if (j < m-1) kemenarikan *= arr[i][j+1];
			
			if (kemenarikan == k){
				if (j < kans){
					bans = i;
					kans = j;
				}
				else if (j==kans){
					bans = min(i, bans);
				}
			}
		}
	}
	
	if (kans != INT_MAX) cout << bans+1 << " " << kans+1 << endl;
	else cout << 0 << " " << 0 << endl;

	return 0;
}

