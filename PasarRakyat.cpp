#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;
	
	long long ans = 1;
	
	for (int i = 0; i < n; i++){
		long long x;
		cin >> x;
		ans = x*ans/__gcd(x, ans);
	}
	
	cout << ans << endl;

	return 0;
}

