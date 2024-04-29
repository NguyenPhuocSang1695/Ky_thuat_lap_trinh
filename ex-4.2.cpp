#include <bits/stdc++.h>
using namespace std;

int a[100],kq[100], n, kt, m;
#define Sn for(int i=0; i< n; i++)

//nhap mang so nguyen
void enter (){
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
}

//ham xuat mang 
void print (){
	for (int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

//cau a) gia tri lon nhat 
int findmax (){
	int max= 0;
	Sn{
	if (max < a[i]){
			max= a[i];
		}
	}
	return max;
}

//cau b) 
//gia tri lon nhat giua 2 so
int max(int a, int b) {
    return (a > b) ? a : b;
}

//do dai cua chuoi con tang dan dai nhat
int daycon() {
    int dainhat = 0; // do dai day con tang dai nhat
    int dodaichuoicon = 0; //do dai day con tang hien tai
    Sn {
        if (a[i] <= a[i+ 1]) {
            dodaichuoicon++; // tang chieu dai
        } else if (dodaichuoicon > dainhat){ //cap nhat do dai dai nhat
        	dainhat= dodaichuoicon;
            dodaichuoicon = 1; //khi khong thoa a[i] <= a[i+ 1]
        }
    }
    return dainhat;
}

//cau c
//dem so cap x y co tong bang m
void demtongbangm() {
    int count = 0;
    bool apped[1000][1000] = {false}; // danh dau da xuat hien cap (x, y)

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == m || a[j] + a[i] == m) {
                if (!apped[a[i]][a[j]] && !apped[a[j]][a[i]]) {
                    count++;
                    apped[a[i]][a[j]] = true;
                    apped[a[j]][a[i]] = true;
                }
            }
        }
    }

    cout << count;
}

//cau d	
//sap xep
void sort (){
	int i, j;
	bool swapped;
	for (i=0; i<n-1; i++){
		swapped= false;
		for (j=0; j< n-i-1; j++){
			if (a[j] > a[j+1])
			swap (a[j], a[j+1]);
			swapped= true;
		}
		if (swapped == false){
			break;
	}
}
}



int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\NUM.INP", "r", stdin);
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\NUM.OUT", "w", stdout);
	cin >> n;
	enter ();
	//Cau a
	cout << findmax() << endl;
	//Cau b
	cout << daycon() << endl;
	//Cau c
	cin >> m;
	demtongbangm ();
	//Cau d
	sort();
	cout << endl << a[n/2];
	return 0;
}
