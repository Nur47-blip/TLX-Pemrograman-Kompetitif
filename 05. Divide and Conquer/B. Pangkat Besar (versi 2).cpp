#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define int long long
#define se second

const int mod = 1e6;

int pangkat(int a, int b){
	if (b==0) return 1;
	if (b==1) return a;
	else if (b&1) {
		return (a*pangkat(a,b-1))%mod;
	}
	else {
		int temp = pangkat(a,b/2); //kompleksitas O(LogB)
		return (temp*temp)%mod;
	}
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a, b;
	cin >> a >> b;
	int temp = 1, pangkattemp = b;
	while (temp <= 999999 and pangkattemp > 0){
		temp *= a;
		pangkattemp--;
	}
	
	bool ok;
	if (temp > 999999) ok = false;
	else ok = true;
	
	a%=mod;
	int ans = pangkat(a,b);

	if (ok) cout << ans << endl;
	else {
		string x = to_string(ans);
		int len = x.length();
		for (int i = 0; i < 6-len; i++){
			cout << '0';
		}
		cout << x << endl;
	}
	
	
	return 0;
}
