#include<iostream>
using namespace std;

int a(int n, int i, int sum= 0){
	if (i== n){
		return sum;
	}
	sum+= (n-i)*a(n+1, i, sum);
	return a(n, i+1, sum);
}

int b(int n){
	return a(n, 0, 0);
}

int main(){
    int n; cin >> n;
    cout << b(n);
    return 0;
}