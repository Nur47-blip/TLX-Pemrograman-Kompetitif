#include <bits/stdc++.h>

using namespace std;

int n, r, y, j;
int juri[2000];
int skor[2000];
bool pernah[20];
vector<int> hasil;
vector<pair<int, char>> gerakan;
bool meyakinkan = false;

void solve(int k, char x, int nilai){
	if (k==0){
		for (int i = 0; i < n; i++){
			if (gerakan[i].second=='Y'){
				meyakinkan = true;
				pernah[i] = true;
				nilai += gerakan[i].first;
				solve(1, 'Y', nilai);
				meyakinkan = false;
				pernah[i] = false;
				nilai -= gerakan[i].first;
			}
			else {
				pernah[i] = true;
				solve(1, gerakan[i].second, nilai+gerakan[i].first);
				pernah[i] = false;
			}
		}
	}
	else if (k==r){
		hasil.push_back(nilai);
	}
	else {
		for (int i = 0; i < n; i++){
			int temp = nilai;
			if (pernah[i]) continue;
			if (x=='B' or x=='Y'){
				temp += gerakan[i].first;
				pernah[i] = true;
				if (gerakan[i].second == 'Y') meyakinkan = true;
				else if (meyakinkan) temp += y;
				solve(k+1, gerakan[i].second, temp);
				if (gerakan[i].second == 'Y') meyakinkan = false;
				pernah[i] = false;
			}
			else if (x=='P'){
				temp += (gerakan[i].first*2);
				pernah[i] = true;
				if (gerakan[i].second == 'Y') meyakinkan = true;
				else if (meyakinkan) temp += y;
				solve(k+1, gerakan[i].second, temp);
				if (gerakan[i].second == 'Y') meyakinkan = false;
				pernah[i] = false;
			}
			else if (x=='L'){
				temp += (gerakan[i].first/2);
				pernah[i] = true;
				if (gerakan[i].second == 'Y') meyakinkan = true;
				else if (meyakinkan) temp += y;
				solve(k+1, gerakan[i].second, temp);
				if (gerakan[i].second == 'Y') meyakinkan = false;
				pernah[i] = false;
			}
		}
	}
}


int main(){

	string s;
	getline(cin , s);
	
	memset(pernah, false, sizeof pernah);
	
	cin >> n >> r >> y >> j;

	for (int i = 0; i < n; i++){
		int a;
		char x;
		cin >> a >> x;
		gerakan.push_back(make_pair(a,x));
	}
	
	memset(skor, 0, sizeof skor);
	
	for (int i = 0; i < j; i++){
		cin >> juri[i];
	}
	
	solve(0, 'c', 0);
	
	sort(hasil.begin(), hasil.end());
	
	long long sz = hasil.size();
	
	for (int i = 0; i < j; i++){
		long long ans;
		ans = upper_bound(hasil.begin(), hasil.end(), juri[i]) - hasil.begin();
		cout << sz - ans << endl;
	}
	

	return 0;
}

