#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, q;
	cin >> n >> q;
	
	map<string, string> halo;
	
	for (int i = 0; i < n; i++){
		string nama, telp;
		cin >> nama >> telp;
		
		halo.insert(make_pair(nama, telp));
	}
	
	for (int i = 0; i < q; i++){
		string x;
		cin >> x;
		
		if (halo.find(x) != halo.end()) cout << halo[x] << endl;
		else cout << "NIHIL\n";
	}

	return 0;
}

