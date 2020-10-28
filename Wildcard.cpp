#include <bits/stdc++.h>

using namespace std;

int main(){

	string s;
	cin >> s;
	
	int len = s.length();
	
	int n; 
	cin >> n;

	string prefix = "";
	string suffix = "";

	int posisi = s.find('*');
	for (int i = 0; i < posisi; i++){
		prefix += s[i];
	}

	for (int i = posisi+1; i < len; i++){
		suffix += s[i];
	}
	
	int plen = prefix.length();
	int slen = suffix.length();
	
	for (int i = 0; i < n; i++){
		string x;
		cin >> x;
		
		int sz = x.length();
		if (sz < plen+slen) continue;
		
		bool flag = true;
		for (int j = 0; j < plen; j++){
			if (prefix[j]!=x[j]) flag = false;
		}
		
		int cnt = sz-1;
		for (int j = slen-1; j>=0; j--){
			if (suffix[j]!=x[cnt]) flag = false;
			cnt--;
		}
		
		if (flag) cout << x << endl;
	}
	

	

	

	return 0;
}

