#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;
	
	vector<int> bebek(n);
	
	for (int i = 0; i < n; i++){
		cin >> bebek[i];
	}
	
	int q;
	cin >> q;
	for (int i = 0 ; i < q; i++){
		int x, y;
		cin >> x >> y;
		int atas, bawah;
		atas = upper_bound(bebek.begin(), bebek.end(), y)-bebek.begin();
		bawah = upper_bound(bebek.begin(), bebek.end(), x)-bebek.begin();
		
		cout << atas-bawah << endl;
	}

	return 0;
}

