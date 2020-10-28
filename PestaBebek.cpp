#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;
	
	vector<string> hai;
	
	for (int i = 0; i < n; i++){
		string x;
		cin >> x;
		
		hai.push_back(x);
		sort(hai.begin(), hai.end());

		for (int j = 0; j <= i; j++){
			if (hai[j] == x){
				cout << j+1 << endl;
				break;
			}
		}
	}

	

	return 0;
}

