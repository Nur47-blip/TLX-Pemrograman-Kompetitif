#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

int n;
bool terurut(string s){
	for (int i = 1; i < n; i++){
		if (s[i]<s[i-1]) return false;
	}
	return true;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	string s = "";
	for (int i = 0; i < n; i++){
		s += to_string(v[i]);
	}
	
	set<string> sudah;
	queue<pair<string, int>> q;
	q.push(mp(s,0));
	bool ok = false;
	int k; cin >> k;
	int ans;
	while (!q.empty()){
		string ss = q.front().fi;
		int langkah = q.front().se;
		q.pop();
		if (terurut(ss)){
			ans = langkah;
			ok = true;
			break;
		}
		
		if (sudah.find(ss)!=sudah.end()) continue;
//		cout << ss << " " << langkah << endl;
		sudah.insert(ss);
		
		for (int i = 0; i <= (n-k); i++){
			string sss = ss;
			reverse(sss.begin()+i, sss.begin()+i+k);
//			cout << sss << endl;
			if (sudah.find(sss)==sudah.end()){
				q.push(mp(sss,langkah+1));
			}
		} 
	}

	if (ok) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}
