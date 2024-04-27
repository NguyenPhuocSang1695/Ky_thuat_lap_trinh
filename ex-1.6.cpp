#include<iostream>
using namespace std;

void tinh(int a, int mang[], int i = 0, int x = 0) {
    if (i < a) {
        x += mang[i] * (a - i); // cong thuc tong quat
        tinh(a, mang, i + 1, x);
    } else {
        mang[a] = x;
    }
}

void ham(int a, int mang[]) {
	int i= 0, x= 0;
	if(a>2) // a= 0 va a= 1 thi ham bang 1
	{
	a=a-1;
	ham(a, mang);
	tinh(a, mang, i, x);
	}
}


int main() {
	int mang1[8];
	mang1[0]=1;
	mang1[1]=1;
	int n;
	ham(8, mang1);
	cout << "So x7 la: " << mang1[7] <<endl;
	int n; cin >> n;
	int mang2[n]; 
	mang2[0]=1; // dieu kien ban dau cua ham
	mang2[1]=1; // dieu kien ban dau cua ham
	ham(n+1, mang2);
	cout << "Gia tri so x" << n << " la: ";
	cout << mang2[n];
	return 0;
}
