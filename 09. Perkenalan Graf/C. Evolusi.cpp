#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	map<string, vector<string>> graf;
	
	for (int i = 0; i < m; i++){
		string a, b;
		cin >> a >> b;
		
		graf[a].pb(b);
	}
	
	map<string, string> prev;
	
	string a, b;
	cin >> a >> b;
	
	stack<string> s;
	s.push(a);
	bool ok = false;
	
	while (!s.empty()){
		string x = s.top(); s.pop();
		
		if (x==b){
			ok = true;
			break;
		}
		
		int sz = graf[x].size();
		for (int i = 0; i < sz; i++){
			prev[graf[x][i]] = x;
			s.push(graf[x][i]);
		}
	}
	
	vector<string> ans;
	if (ok){
		string last = b;
		while (last != a){
			ans.pb(last);
			last = prev[last];
		}
		ans.pb(a);
		reverse(ans.begin(), ans.end());
		int sz = ans.size();
		for (int i = 0; i < sz; i++){
			cout << ans[i] << endl;
		}
		return 0;
	}
	
	while (!s.empty()) s.pop();
	s.push(b);
	prev.clear();
	
	while (!s.empty()){
		string x = s.top(); s.pop();
		
		if (x == a){
			ok = true;
			break;
		}
		
		int sz = graf[x].size();
		for (int i = 0; i < sz; i++){
			prev[graf[x][i]] = x;
			s.push(graf[x][i]);
		}
	}
	
	if (ok){
		string last = a;
		while (last != b){
			ans.pb(last);
			last = prev[last];
		}
		ans.pb(b);
		reverse(ans.begin(), ans.end());
		int sz = ans.size();
		for (int i = 0; i < sz; i++){
			cout << ans[i] << endl;
		}
	}
	else cout << "TIDAK MUNGKIN\n";

	return 0;
}
