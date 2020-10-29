#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	double x = (double) a.second / a.first;
	double y = (double) b.second / b.first;
	
	return (x > y);
}

int main(){

	int n, x;
	cin >> n >> x;
	
	cout << setprecision(5) << fixed;
	
	vector<pair<int, int>> arr(n);
	
	for (int i = 0; i < n; i++){
		int inp;
		cin >> inp;
		arr[i].first = inp;
	}
	
	for (int i = 0; i < n; i++){
		int inp;
		cin >> inp;
		arr[i].second = inp;
	}
	
	sort(arr.begin(), arr.end(), cmp);

	double coin = 0;
	int sisa = x;
	for (int i = 0; i < n; i++){
		if (arr[i].first <= sisa){
			coin += (double) arr[i].second;
			sisa -= (double) arr[i].first;
		}
		else {
			coin += (double) arr[i].second / arr[i].first * sisa;
			break;
		}
	}
	
	cout << coin << endl;

	return 0;
}

