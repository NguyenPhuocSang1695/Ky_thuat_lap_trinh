//Bai 7
#include <bits/stdc++.h>
using namespace std;
struct Danhsachnhanvien{
	int manhanvien;
	string hovaten;
	string ngaysinh;
	float luongcoban;
	float thuong;
	float thuclanh;
};
// CAu a  
void nhap(Danhsachnhanvien nv[], int n){
	for (int i=0; i< n; i++){
		cout << "Nhap thong tin nhan vien thu " << i+1 << endl;
		cout << "Nhap ma nhan vien: ";
    	cin >> nv[i].manhanvien;
    	cin.ignore(); 
    	cout << "Nhap ho va ten: ";
    	getline(cin, nv[i].hovaten);
    	cout << "Nhap ngay sinh: ";
    	getline(cin, nv[i].ngaysinh);
    	cout << "Nhap luong co ban: ";
    	cin >> nv[i].luongcoban;
   		cout << "Nhap thuong: ";
    	cin >> nv[i].thuong;
    	//tinh luong thuc lanh 
    	nv[i].thuclanh = nv[i].luongcoban + nv[i].thuong;
	}
}

void xuatt(Danhsachnhanvien nv[], int n){
	cout << "Thong tin nhan vien" << endl;
	for (int i=0; i< n; i++){
		cout << "Ma nhan vien: ";
    	cout << nv[i].manhanvien << endl;
    	cout << "Ho va ten: ";
    	cout << nv[i].hovaten<< endl;
    	cout << "Ngay sinh: ";
    	cout << nv[i].ngaysinh<< endl;
    	cout << "Luong co ban: ";
    	cout << nv[i].luongcoban<< endl;
   		cout << "Thuong: ";
    	cout << nv[i].thuong<< endl;
    	//luong thuc lanh 
    	 cout << "Thuc lanh: " << nv[i].thuclanh << endl;
    	 cout << endl;
	}
	cout << endl;
}

void swap (int &a, int &b){
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
//Cau b
void sapxep(Danhsachnhanvien nv[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (nv[j].luongcoban < nv[j + 1].luongcoban) {
                swap(nv[j+1], nv[j]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
//Cau c
void sapxep2(Danhsachnhanvien nv[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (nv[j].manhanvien > nv[j + 1].manhanvien) {
                swap(nv[j], nv[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
int main(){
	int n;
	cout << "Nhap so luong nhan vien: "; cin >>n;
	Danhsachnhanvien nv[n];
	//Cau a
	nhap(nv, n);
	cout << "\n\n=============\n\n";
	xuatt(nv, n);
	//Cau b
	sapxep (nv, n);
	cout << "\n\n== Sau khi sap xep theo luong ==\n\n";
	xuatt (nv, n);
	//Cau c
	cout << "\n\n== Sau khi sap xep theo ma nhan vien==\n\n";
	sapxep2 (nv, n);
	xuatt (nv, n);

	return 0;
}
