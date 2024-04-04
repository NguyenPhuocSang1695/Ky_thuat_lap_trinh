#include <iostream>
#include <string>
using namespace std;

void nhapchuois(string &s) {
    getline(cin, s);
}

void nhapchuoix(string &x) {
    getline(cin, x);
}
// Cau a
int kiemtra(string s, string x) {
    //chay toi s.length - x.length de neu so ki tu chuoi s it hon x thi ko xet
    for (int i = 0; i <= s.length() - x.length(); ++i) {
    	int j;
        for (j = 0; j < x.length(); ++j) {
            if (s[i + j] != x[j]) {
                break;
            }
   		}
        if (j == x.length()) {
            return i; // Tra ve vi tri dau tien cua x trong s
        }
    }
    return -1; // Khong tim thay chuoi x trong s
}

void In (string s, string x){
	int result = kiemtra(s, x);
    if (result != -1) { // tim thay chuoi
        cout << "Chuoi x xuat hien tai vi tri: " << result << endl;
    } else {
        cout << "Khong tim thay chuoi x trong chuoi s." << endl;
    }
}
 //Cau b
int dem (string s, string x){
	int cnt=0;
	for (int i = 0; i <= s.length() - x.length(); ++i) {
        int j;
        for (j = 0; j < x.length(); ++j) {
            if (s[i + j] != x[j]) {
                break;
            }
        }
        if (j == x.length()) {
            cnt++;
        }
    }
    return cnt++;
}

void Incnt (string s, string x){
	int p= dem(s, x);
	cout << "So lan xuat hien cua chuoi x la: " << p << endl;
}

int main() {
    string s, x;
    cout<<"Nhap chuoi s\n";
    nhapchuois(s);
    cout<<"Nhap chuoi x\n";
    nhapchuoix(x);
    //Cau a
    kiemtra (s, x);
    In (s, x);
    //Cau b
    dem(s, x);
    Incnt(s, x);
    return 0;
}