// Bai 6
#include <iostream>

using namespace std;

struct Sinhvien {
  int sobaodanh;
  string ho;
  string ten;
};

// Nhap thong tin sinh vien

void nhap (Sinhvien sinhvien[], int n){
	for (int i=0; i<n ;i++){
		cin.ignore();
		cout << "Nhap thong tin sinh vien thu  " << i+1 << endl;	
		cout << "Nhap so bao danh: ";
		cin >> sinhvien[i].sobaodanh;
		cin.ignore();
		cout << "Nhap ho: ";
		getline( cin, sinhvien[i].ho);
		cout << "Nhap ten: ";
		getline( cin, sinhvien[i].ten);
	}
}
  //Sap xep danh sach theo ten
void swap (int &a, int &b){
	int tmp= a;
	a=b;
	b= tmp;
}

void sapxep (Sinhvien sinhvien[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (sinhvien[j].ten > sinhvien[j + 1].ten) 
            	swap(sinhvien[j], sinhvien[j + 1]);  
} 

//In danh sach sinh vien
void In (Sinhvien sinhvien[], int n){
	cout << "\n=================================\n";
	cout << "Danh sach sap xep theo ten:" << endl;
	for (int i = 0; i < n; i++) {
    cout << "Sinh vien thu " << i + 1 << endl;
    cout << "So bao danh: " << sinhvien[i].sobaodanh << endl;
    cout << "Ho va ten: " << sinhvien[i].ho << " " << sinhvien[i].ten << endl;
  }
}

int main() {
  int n;
  cout << "Nhap so luong sinh vien: ";
  cin >> n;
  Sinhvien *ds = new Sinhvien[n];
  nhap (ds, n);
  sapxep (ds, n);
  In (ds, n);
  
  delete[] ds;
  return 0;
}