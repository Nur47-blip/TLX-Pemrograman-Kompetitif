#include <bits/stdc++.h>

using namespace std;

int main(){

	string a, b;
	cin >> a >> b;
	
	int lena = a.length();
	int lenb = b.length();
	
	if (lena != lenb+1) cout << "Wah, tidak bisa :(\n";
	else {
		bool bisa = false;
		for (int i = 0; i < lena; i++){
			string temp = "";
			for (int j = 0; j < lena; j++){
				if (i==j) continue;
				else temp += a[j];
			}
			if (temp == b){
				bisa = true;
				break;
			}
		}
		
		if (bisa) cout << "Tentu saja bisa!\n";
		else cout << "Wah, tidak bisa :(\n";
	}

	return 0;
}

