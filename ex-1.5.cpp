#include <bits/stdc++.h>
using namespace std;

int x(int n){
	if (n==1)
	return 1;
	if (n==2)
	return 2;
	return n*(x(n-1)+(x(n-1))/(n-1));
}

int main(){
	int n; cin >> n;
	cout << x(n);
	return 0;
}
