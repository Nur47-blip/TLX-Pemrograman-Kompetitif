#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	
	for (int i = 0 ; i < n; i++){
		cin >> v[i];
		if (i>0) v[i]+=v[i-1];
	}
	
	int t; cin >> t;
	while (t--){
		int x; cin >> x;
		
		int l = 0, r = n-1;
		int ans;
		while (l <= r){
			int mid = (l+r)/2;
			if (x <= v[mid]){
				ans = mid;
				r = mid-1;
			}
			else {
				l = mid+1;
			}
		}
		cout << ans+1 << endl;
	}

	return 0;
}
