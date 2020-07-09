#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int sz=0;

int getpar(int x){
	return ((x-1)/2);
}

int getleft(int x){
	return (2*x+1);
}

int getright(int x){
	return (2*x+2);
}

void ppush(int x){
	arr[sz]=x;
	sz++;
	//benerin binary heap
	int i=sz-1;
	while (i>0 and arr[getpar(i)]<arr[i]){
		swap(arr[getpar(i)],arr[i]);
		i=getpar(i);
	}
}

void ppop(){
	swap(arr[0],arr[sz-1]);
	sz--;
	//benerin binary heap
	int i=0;
	bool swapped=true;
	while (swapped){
		int temp=i;
		if (arr[getleft(i)]>arr[i] and getleft(i)<sz) temp=getleft(i);
		if (arr[getright(i)]>arr[temp] and getright(i)<sz) temp=getright(i);
		if (arr[temp]==arr[i]) swapped=false; else swapped=true;
		swap(arr[temp],arr[i]);
		i=temp;
	}
	
}

int main(){

	int n;
	cin>>n;
	
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		if (x==1){
			int t;
			cin>>t;
			ppush(t);
		}
		else if (x==2) cout<<arr[0]<<endl;
		else ppop();
	}

	return 0;
}
