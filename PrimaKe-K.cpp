#include <bits/stdc++.h>

using namespace std;

vector<long long> prima;
vector<bool> bilangan(990000, true);

void sieve(){
	prima.push_back(1);
	int bil = 2;
	int cnt = 0;
	while (cnt < 77777){
		if (bilangan[bil] == false){
			bil++;
			continue;
		}
		cnt++;
		prima.push_back(bil);
		for (int i = 2*bil; i <= 989999; i += bil){
			bilangan[i] = false;
		}
		bil++;
	}
}

int main(){

	int n;
	cin >> n;
	
	sieve();
	
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		
		cout << prima[x] << endl;
	}

	return 0;
}

