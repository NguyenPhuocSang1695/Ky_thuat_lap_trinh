#include <bits/stdc++.h>
using namespace std;

int a[100][100], b[100], m, n; 

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
void timmin (){
	//tim phan tu nho nhat
	for (int i=0; i< m; i++){
		int min= INT_MAX; // gan min= gia tri lon nhat
		for (int j=0; j< n; j++){
			if (min> a[i][j]){
				min= a[i][j];
			}
		}
		b[i]= min; // dua min vao b[i]
	}
	
	//tim phan tu lon nhat trong cac phan tu nho nhat
	int max= INT_MIN; //gan max= gia tri nho nhat
	for (int i= 0; i< m; i++){
		if (max< b[i]){
			max= b[i];
		}
	}
	cout << max << endl;
}		
                    
//cau b
void timvitrinhonhat() {
    int khoangcachnhonhat = INT_MAX; //khoang cach nho nhat
    int i1, j1, i2, j2; //vi tri 2 diem co khaong cach nho nhat
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            //so sanh voi cac phan tu con lai trong cung hang
            for(int l = j + 1; l < n; l++) {
                int khoang_cach = abs(a[i][j] - a[i][l]);
                if(khoangcachnhonhat > khoang_cach) {
                    khoangcachnhonhat = khoang_cach;
                    i1 = i; j1 = j; i2 = i; j2 = l;
                }
            }
            //so sanh voi cac han ben duoi
            for(int k = i + 1; k < m; k++) {
                for(int l = 0; l < n; l++) {
                    int khoang_cach = abs(a[i][j] - a[k][l]);
                    if(khoangcachnhonhat > khoang_cach) {
                        khoangcachnhonhat = khoang_cach;
                        i1 = i; j1 = j; i2 = k; j2 = l;
                    }
                }
            }
        }
    }
    cout << khoangcachnhonhat << " " << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
}

int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-5-6\\TABLE.INP", "r", stdin);
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-5-6\\TABLE.OUT", "w", stdout);
	cin >> m >> n;
	nhap ();
	cout << "CAU a: ";
	timmin();
	cout << "CAU b: ";
	timvitrinhonhat();
	return 0;
}
