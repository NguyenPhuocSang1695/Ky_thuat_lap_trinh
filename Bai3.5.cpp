//Bai 5
#include <bits/stdc++.h>
using namespace std;

void check (const string s[], int n){
	int cntw[7] = {0}; // dem so luong tu
	for (int i=0; i< n; i++){ // lap qua tung tu va gan cho x
		int cnt = s[i].length();// dem do dai tung tu
		cntw[cnt-1]++;
	}

	//vi tri nao xuat hien nhieu nhat
	int max = 0;
	for (int i=0; i<7; i++){
		if (cntw[i] > cntw[max]){
			max = i;
		}
	}

	cout<<"Tu loai " << max+1 << " xuat hien nhieu nhat\n";
	cout <<"Xuat hien "<<cntw[max] << " lan";
}
int main(){
	int n; 
	cout << "Nhap so luong tu "; cin>>n;
	string s[n];
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	check (s, n);
	
	return 0;
}
