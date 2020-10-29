#include <bits/stdc++.h>

using namespace std;

bool bisagakya;

void solve(int a, int b, int k, int skor[], int arr[]){
	if (a == k-1){
		bool flag = true;
//		
//		for (int i = 0; i < k; i++){
//			cout << skor[i] << " ";
//		}
		
		for (int i = 0; i < k; i++){
			if (skor[i] != arr[i]){
				flag = false;
			}
		}
		if (flag) bisagakya = true;
//		cout << bisagakya << endl;
	}
	else if (b==k){
		solve(a+1, a+2, k, skor, arr);
	}
	else {
		// a menang lawan b
		skor[a] += 3;
		solve(a, b+1, k, skor, arr);
		
		skor[a] -=3;
		// a kalah lawan b
		skor[b] += 3;
		solve(a, b+1, k, skor, arr);
		
		skor[b] -= 3;
		//a seri lawan b;
		skor[a] += 1;
		skor[b] += 1;
		solve(a, b+1, k, skor, arr);
		skor[a] -= 1;
		skor[b] -= 1;
	}
}

int main(){

	int t;
	cin >> t;
	
	while (t--){
		int n;
		cin >> n;
		
		int arr[n];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		int skor[n];
		memset(skor, 0, sizeof skor);
		
		bisagakya = false;
		solve(0, 1, n, skor, arr);
		
		if (bisagakya) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}

