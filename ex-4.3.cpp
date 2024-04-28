#include <bits/stdc++.h>
using namespace std;

int a[100][100], b[100], c[100], m, n, k;

//Nhap mang
void nhap(){
	for(int i=0; i<m; i++){
		for (int j=0; j< n; j++){
			cin >> a[i][j];
		}
	}
}

//xuat mang
void xuat(){
	for(int i=0; i<m; i++){
		for (int j=0; j< n; j++){
			cout << a[i][j] << "  ";
		}
		cout << endl; 
	}
}

//cau a
//kiem tra so nguyen to
bool isprimes (int n){
	if (n< 2){
		return false;
	}
	for (int i=2; i< n; i++){
		if (n%i==0)
		return false;
	}
	return true;
}


//dem so nguyen to
int demprimes() {
    bool appeared[1000] = {false}; // M?ng d? danh d?u cac s? nguyen t? da xu?t hi?n
    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isprimes (a[i][j]) && !appeared[a[i][j]]) {
                appeared[a[i][j]] = true;
                count++;
            }
        }
    }
    return count;
}


//cau b
//tong cac phan tu cua dong
void tongdong() {
    for (int i = 0; i < m; i++) {
        int sum = 0; // Reset sum for each row
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
        b[i] = sum; // Store the sum for each row in array b
    }
}

void maxdong () {
	int max= b[0];
	for (int i=0; i< m; i++){
		if (b[i]> max){
			max= b[i];
		}
	}
	cout << max << endl;
}


//cau c
//tinh tong cot
void tongcot() {
    for (int i = 0; i < n; i++) {
        int sumcot = 0; 
        for (int j = 0; j < m; j++) {
            sumcot += a[j][i];
        }
        c[i] = sumcot;
    }
}

//min cot
void mincot () {
	int min= c[0];
	for (int i=0; i< n; i++){
		if (c[i]< min){
			min= c[i];
		}
	}
	cout << min << endl;
}

int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-3-4\\table.inp", "r", stdin);
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-3-4\\table.out", "w", stdout);
	cin >> m >> n;
	nhap ();
	//cau a
	int cnt= demprimes ();
	cout << cnt << endl;
	//cau b
	tongdong();
	maxdong();
	//cau c
	tongcot();
	mincot();


	return 0;
}
