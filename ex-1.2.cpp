#include <bits/stdc++.h>
using namespace std;

int a(int n){
	if (n==1 || n==2)
	return 1;
	else
	return a(n-1)+(n-1)*a(n-2);
}

int b(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    int c = 1; //a(n-1)
    int d = 1; //a(n-2)
    int sum = 0; 
    for (int i = 3; i <= n; ++i) {
        sum = c + (i - 1) * d;
        d = c; 
        c = sum;
    }
    return sum;
}

int main() {
    int n; cin >> n;
    cout << a(n) << endl;
    cout << b(n);
    return 0;
}

