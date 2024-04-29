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
//tim phan tu lon nhat
int findmax () {
	int max= INT_MIN; 
	int count= 0;
	for (int i=0; i< m; i++){
		int j;
		for (j=0; j< n; j++){
			if (max<= a[i][j])
			max= a[i][j];
		}	
	}
	return max;
}

//dem so luong phan tu bang max
int dem(){
	int max= findmax();
	int count= 0;
	for(int i=0; i< m; i++){
		for (int j=0; j< n; j++){
			if (a[i][j]== max){
				count++;
			}
		}	
	}
	return count; // coi phan tu dau tien tim duoc bang max chinh la max-> khong dem
}

//cau b
//tinh tong cot
void tongcot() {
    for (int i = 0; i < n; i++) {
	int sumcot = 0;         
        for (int j = 0; j < m; j++) {
            sumcot += a[j][i];
        }
        cout << sumcot << " ";
    }
    cout << endl;
}

//cau c
//kiem tra so nguyen to
bool isprimes (int n){
	if (n< 2)
	return false;
	for (int i=2; i< sqrt(n); i++){
		if (n%i==0)
			return false;
	}
	return true;
}

void timmax (){
	int sum; 
	for (int i=0; i< m; i++){
		sum= 0; // khoi tao gia tri va tra tong ve 0 khi tinh tong hinh vuong tiep theo
		for (int j=0; j< n; j++){
			if (isprimes(a[i][j])&& isprimes(a[i][j+1])&& isprimes(a[i+1][j+1])&& isprimes(a[i+1][j])){ // neu phan tu cua hinh vuong la so nguyen to
					sum= a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]; // tong cac phan tu cua hinh vuong
					b[i]= sum; // day tong vao chuoi de so sanh tim max
			}
		}
	}
	//tim tong lon nhat
	int max= b[0];
	for (int i=1; i< m; i++){
		if (max< b[i]){
			max= b[i];
		}
	}
	cout << max;
}

int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-3-4\\table.inp", "r", stdin);
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-3-4\\table.out", "w", stdout);
	cin >> m >> n;
	nhap ();
	//cau a
	cout << findmax() << " " << dem() << endl;
	//cau b
	tongcot();
	//cau c
	timmax();
	return 0;
}
