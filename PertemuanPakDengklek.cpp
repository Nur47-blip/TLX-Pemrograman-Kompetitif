#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
	if (a.length() < b.length()) return true;
	else if (a.length() == b.length()){
		if (a < b) return true;
		else return false;
	}
	else return false;
}

int main(){

	int n; 
	cin >> n;
	
	string arr[n];
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+n, cmp);
	
	for (int i = 0; i < n; i++){
		cout << arr[i] << endl;
	}

	return 0;
}

