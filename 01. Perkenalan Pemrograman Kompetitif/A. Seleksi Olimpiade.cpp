#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>> b){
	if (a.second.second.second > b.second.second.second) return true;
	else if (a.second.second.second < b.second.second.second) return false;
	else {
		if (a.second.second.first > b.second.second.first) return true;
		else if (a.second.second.first < b.second.second.first) return false;
		else {
			if (a.second.first > b.second.first) return true;
			else return false;
		}
	}
}

int main(){

	int t;
	cin >> t;
	
	while (t--){
		int n, m;
		cin >> n >> m;
		
		string x;
		cin >> x;
		
		vector<pair<string, pair<int, pair<int, int>>>> peserta;
		
		for (int i = 0; i < n; i++){
			string s;
			int a, b, c;
			cin >> s >> a >> b >> c;
			peserta.push_back(make_pair(s, make_pair(a, make_pair(b,c))));
		}
		
		sort(peserta.begin(), peserta.end(), cmp);
		
		int posisi = 0;
		for (int i = 0; i < n; i++){
			if (peserta[i].first == x){
				posisi = i;
				break;
			}
		}
		
		if (posisi+1 <= m) cout << "YA\n";
		else cout << "TIDAK\n";
	}

	return 0;
}

