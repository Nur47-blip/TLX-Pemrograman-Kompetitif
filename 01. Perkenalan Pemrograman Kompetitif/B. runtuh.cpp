#include <bits/stdc++.h>

using namespace std;

char arr[30][30];
int n, m;

vector<int> hilang;

bool adayangpenuh(){
	hilang.clear();
	bool ada = false;
	for (int i = 0; i < n; i++){
		bool flag = true;
		for (int j = 0; j < m; j++){
			if (arr[i][j]!='1'){
				flag = false;
				break;
			}
		}
		if (flag) {
			ada = true;
			hilang.push_back(i);
			for (int j = 0; j < m; j++){
				arr[i][j] = '0';
			}
		}
	}
	return ada;
}

int main(){

	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	while (adayangpenuh()){
		int s = hilang.size();
		int sz = hilang[s-1];
		for (int i = 0; i < m; i++){
			int cnt = 0;
			for (int j = 0; j < sz; j++){
				if (arr[j][i] == '1') cnt++;
			}
			
			int terakhir = sz;
			for (int j = sz+1; j < n; j++){
				if (arr[j][i] == '1'){
					break;
				}
				else {
					terakhir = j;
				}
			}
			
			while (cnt--){
				arr[terakhir][i] = '1';
				terakhir--;
			}
			for (int j = terakhir; j >= 0; j--){
				arr[j][i] = '0';
			}
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}

