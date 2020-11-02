#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;
	
	priority_queue<int> arr;
	
	while (t--){
		int x;
		cin >> x;
		if (x==1){
			int z;
			cin >> z;
			arr.push(z);
		}
		if (x==2){
			cout << arr.top() << endl;
		}
		if (x==3){
			arr.pop();
		}
	}


	return 0;
}

