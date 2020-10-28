#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, x;
	cin >> n >> x;
	
	int ans = INT_MAX;
	int jarak = INT_MAX;
	
	for (int i = 0; i < n; i++){
		int s;
		cin >> s;
		
		if (abs(s-x) < jarak){
			jarak = abs(s-x);
			ans = s;
		}
		else if (abs(s-x) == jarak){
			ans = min(s, ans);
		}
	}
	
	cout << ans << endl;

	return 0;
}

