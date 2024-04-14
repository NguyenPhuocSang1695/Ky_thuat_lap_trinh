#include <iostream>
using namespace std;

// Cau a
int a (int n){
	if (n==1)
	return n;
	return n+ a(n-1);
}

// Cau b
int a (int n){
	if (n==1)
	return n;
	return n*n+ a(n-1);
}

//Cau c
int a(int n){
	if (n==1)
	return 1;
	return n*a(n-1);
}

int sum(int n){
	if (n==1) return 1;
	return a(n)+ sum (n-1);
}

//Cau d
long long product(int s, int e) {
    if (s > e) return 1;
    return s * product(s + 1, e);
}
long long sum(int n) {
    if (n == 1) return 2;
    return product(n, 2*n) + sum(n - 1);
}

int main (){
	int n; cin >> n;
	int p= sum(n);
	cout << p;
	return 0;
}