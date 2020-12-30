#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long

int mod;

int modex(int a, int b){
	if (b==0) return 1;
	else if (b==1) return a;
	else if (b%2==1){
		return (a*modex(a,b-1))%mod;
	}
	else {
		int temp = (modex(a,b/2))%mod;
		return (temp*temp)%mod;
	}

}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	mod = d;
	a %= d;
	
	int res = modex(a,b);
	
	for (int i = 0; i < c-1; i++){
		res = modex(res,b);
	}
	
	cout << res+1 << endl;

	return 0;
}
