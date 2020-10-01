#include<bits/stdc++.h>
using namespace std;



void fuck() {
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i <n; i++) 
		cin>>a[i];
	int naya[n];
	int j = 0;
	for(int k = 0; k < n; k++){
		int t = 1;
		for(int i = 0; i < n; i++) {
			if (i != j) {
				t *= a[i];
			}
			else
				j += 1;
		}
		naya[k] = t;
	}
	for(int i = 0; i<n; i++) {
		cout<<naya[i];
	}
}
int f(int* a, int b) {
	b = b-1;
	if (b == 0) return 1;
	*a = *a +1;
	cout<< f(a, b)<<"   "<<*a<<endl;
	return f(a, b)*(*a);
}
int main() {
	int a = 3;
	int b = 5;
	int gand =  f(&a, b);
	cout<<gand;
	return 0;
}
