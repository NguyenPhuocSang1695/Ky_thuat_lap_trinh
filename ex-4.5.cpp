#include <bits/stdc++.h>
using namespace std;

int a[100][100], b[100], m, n, minn; //i1, j1, i2, j2;

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
//tim phan tu nho nhat
void timmin (){
	int min= a[0][0];
	for (int i=0; i< m; i++){
		for (int j=1; j< n; j++){
			if (min> a[i][j]){
				min= a[i][j];
			}
		}
		b[i]= min; // dua min vao b[i]
	}
}		
   
//phan tu lon nhat trong so phan tu nho nhat
void minmax (){
	int max= b[0];
	for (int i=0; i< m; i++){
		if (max< b[i]){
			max= b[i];
		}
	}
	cout<< max << endl;
}

//cau b
void findminspace() {
	int spamin;
	int i1, j1, i2, j2;
    spamin = abs(a[0][0] - a[0][1]); // khoang cach nho nhat
    i1 = j1 = i2 = j2 = 0; // min cua i1,2 va j1,2
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = i; k < m; k++) {
                int j1 = (k == i ? j + 1 : 0);
                for(int l = j1; l < n; l++) {
                    int khcach = abs(a[i][j] - a[k][l]);
                    if(spamin > khcach) {
                        spamin = khcach;
                        i1 = i;
                        j1 = j;
                        i2 = k;
                        j2 = l;
                    }
                }
            }
        }
    }
    cout << minn << " " << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
}

int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-5-6\\TABLE.INP", "r", stdin);
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-5-6\\TABLE.OUT", "w", stdout);
	cin >> m >> n;
	nhap ();
	cout << "CAU a: ";
	timmin();
	minmax();
	cout << "CAU b: ";
	findminspace();
	return 0;
}
