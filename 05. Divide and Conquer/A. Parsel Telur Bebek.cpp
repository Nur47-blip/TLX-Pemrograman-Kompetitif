#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	
	vector<int> v(n);
	for (auto &i: v) cin >> i;
	
	int lower = -1;
	int l = 0, r = LLONG_MAX;
	while (l <= r){
		int mid = l+((r-l)/2);
		int cur = 0;
		for (int i = 0; i < n; i++){
			cur += (mid/v[i]);
		}
		if (cur == x){
			lower = mid;
			r = mid-1;
		}
		else if (cur < x){
			l = mid+1;
		}
		else r = mid-1;
	}

	int upper = -1;
	l = 0, r = LLONG_MAX;
	while (l <= r){
		int mid = l+((r-l)/2);
		int cur = 0;
		for (int i = 0; i < n; i++){
			cur += (mid/v[i]);
		}
		if (cur == x){
			upper = mid;
			l = mid+1;
		}
		else if (cur < x){
			l = mid+1;
		}
		else r = mid-1;
	}
	
	if (upper>-1) cout << upper-lower+1 << endl;
	else cout << 0 << endl;

	return 0;
}
