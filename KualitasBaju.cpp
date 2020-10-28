#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;
	
	int arr[n];
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+n);
	
	cout << setprecision(1) << fixed;
	
	if (n%2==0){
		cout << ((double)arr[n/2]+(double)arr[n/2-1])/2<< endl;
	}
	else cout << (double)arr[n/2] << endl;

	return 0;
}

