#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n >> n;
	
	int arr[n][n];
	int brr[n][n];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}

	cin >> n >> n;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> brr[i][j];
		}
	}
	
	//cek identik
	bool flag = true;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j]!=brr[i][j]){
				flag = false;
			}
		}
	}

	if (flag){
		cout << "identik\n";
		return 0;
	}
	
	//cek horizontal
	flag = true;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j] != brr[n-i-1][j]){
				flag = false;
			}
		}
	}

	if (flag){
		cout << "horisontal\n";
		return 0;
	}

	//cek vertikal
	flag = true;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j] != brr[i][n-j-1]){
				flag = false;
			}
		}
	}
	
	if (flag){
		cout << "vertikal\n";
		return 0;
	}
	
	//diagonal kanan bawah
	flag = true;
	
	for (int i = 0; i < n ; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j] != brr[j][i]){
				flag = false;
			}
		}
	}

	if (flag){
		cout << "diagonal kanan bawah\n";
		return 0;
	}
	
	//diagonal kiri bawah
	flag = true;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j] != brr[n-j-1][n-i-1]){
				flag = false;
			}
		}
	}
	
	if (flag){
		cout << "diagonal kiri bawah\n";
		return 0;
	}

	cout << "tidak identik\n";

	return 0;
}

