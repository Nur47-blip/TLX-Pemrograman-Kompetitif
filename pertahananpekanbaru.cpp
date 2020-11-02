#include <bits/stdc++.h>

using namespace std;

int main(){

	string s;
	cin >> s;
	
	long long int n, a, b;
	cin >> n >> a >> b;
	
	priority_queue<pair<long long int, long long int>> arr;
	vector<pair<long long int, pair<long long int,long long int>>> v(n);
	
	long long int ans = 0;
	
	for (long long int i = 0; i < n-1; i++){
		long long int x,y,z;
		cin >> x >> y >> z;
		
		v[i] = (make_pair(x,make_pair(y,z)));
		
		
		if (a < x){
			if (arr.empty()){
				cout << -1 << endl;
				return 0;
			}
			else {
				while (a < x and !arr.empty()){
					long long int ia = arr.top().first;
					long long int ib = arr.top().second;
					ans += v[ib].second.second;
					a++;
					ans -= v[ib].second.first;
					arr.pop();
				}
				if (a < x){
					cout << -1 << endl;
					return 0;
				}
			}
		}
		
		if (y >= z){
			a++;
			ans += z;
		}
		else {
			arr.push(make_pair(y-z,i));
			ans += y;
		}
	}
	
	if (a < b){
		if (arr.empty()){
			cout << -1 << endl;
			return 0;
		}
		else {
			while (a < b and !arr.empty()){
				long long int ia = arr.top().first;
				long long int ib = arr.top().second;
				ans -= v[ib].second.first;
				a++;
				ans += v[ib].second.second;
				arr.pop();
			}
			if (a < b){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	cout << ans << endl;
		
	return 0;
}

