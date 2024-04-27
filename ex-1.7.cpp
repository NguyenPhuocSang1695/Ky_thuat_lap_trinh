#include <bits/stdc++.h>
using namespace std;
void nhap (int a[], int n){
	for (int i=0; i< n; i++){
		cin >> a[i];
	}
}
//Cau a
int total (int a[], int n){
	if (n== 0)
	return a[0];
	return a[n]+ total(a, n-1);
}

//Cau b
int daundmax (int a[], int n){
	if (n==1)
	return a[0];
	if (a[n-1]> daundmax (a, n-1))
	return a[n-1];
	return daundmax (a, n-1);
}

//Cau c
int ktnt (int n, int dau, int cuoi){
	if (n<= 1) return false;
	if (cuoi< dau)
	return 1;
	if (n%dau==0)
	return 0;
	return ktnt (n, dau+1, cuoi);
}
int sont (int n){
	return ktnt (n, 2, sqrt(n));
}

int count(int a[], int n, int i){
	if (i==n)
	return 0;
	return sont(a[i]) + count(a, n, i+ 1);
}

int main(){
	int n; cin >> n;
	int a[n];
	nhap (a, n);
	//Cau a
	cout << "Cau a\n";
	cout << "Tong cua mang la "<< total (a, n) << endl;
	//Cau b
	cout << "Cau b\n";
	cout << "Gia tri lon nhat mang la " << daundmax(a, n) << endl;
	//Cau c
	cout << "Cau c\n";
	cout << "So luong so nguyen to la "<< count (a, n, 0);
	return 0;
}
