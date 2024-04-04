// Bai 3
#include <iostream>
#include <cmath>
using namespace std;

struct DonThuc {
  float heSo;
  int soMu;
};

void nhapDaThuc(DonThuc* daThuc, int n) {
  for (int i = 0; i < n; i++) {
  	cout << "Nhap da thuc thu " << i+1 << endl;
    cout << "Nhap he so cua don thuc thu " << i + 1 << ": ";
    cin >> (daThuc+ i)->heSo;
    cout << "Nhap so mu cua don thuc thu " << i + 1 << ": ";
    cin >> (daThuc+ i)->soMu;
    cout << endl;
  }
}

void tinhGiaTriDaThuc(const DonThuc* daThuc, float x, int n) {
  float giaTri=0;
  for (int i = 0; i < n; i++) {
    giaTri = (daThuc+i)->heSo * pow(x, (daThuc+ i)->soMu)+ (daThuc+ i)->heSo*x; //giaTri= heso* x^so mu + heso* x
    cout << "Gia tri cua da thuc " << giaTri << endl;
  }
}


int main() {
  int n;
  cout << "Nhap so don thuc: ";
  cin >> n;
  DonThuc* daThuc = new DonThuc[n];
  nhapDaThuc(daThuc, n);
  float x;
  cout << "Nhap gia tri x: ";
  cin >> x;  
  tinhGiaTriDaThuc(daThuc, x, n);
  delete[] daThuc;
  return 0;
}
