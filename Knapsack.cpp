#include <bits/stdc++.h>

using namespace std;

int n,k;
int w[1001],h[1001],dp[1001][2001];

int main(){

	cin>>n>>k;
	for (int i=1;i<=k;i++){
		cin>>w[i]>>h[i];
	}
	
	//dp bottom-up
	for (int i = 0;i <= k; i++){
		for (int j = 0; j <= n; j++){
			if (i == 0 or j == 0) dp[i][j] = 0;
			else {
				dp[i][j] = dp[i-1][j];
				if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + h[i]);
			}
		}
	}

	int wtemp = n;
	int res = dp[k][n];
	stack <int> hasil;
	
	for (int i=0;i<=n;i++) {
		if (dp[k][i]==dp[k][n]) {
			wtemp=i;
			break;
		}
	}
	
	//backtracking hasil
	for (int i = k; i > 0 and res > 0; i--) {
		if (res == dp[i-1][wtemp]) continue;
		else {
			hasil.push(i);
			wtemp = wtemp - w[i];
			res = res - h[i];
		}
	}
	
	while (!hasil.empty()) {
		cout<<hasil.top()<<endl;
		hasil.pop();
	} 
	
	//print tabel dp
//	cout<<"X"<<" ";
//	for (int i=0;i<=n;i++) cout<<i<<" ";
//	cout<<endl;
//	for (int i=0;i<=k;i++) {
//		cout<<i<<" ";
//		for (int j=0;j<=n;j++) {
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}

	return 0;
}
