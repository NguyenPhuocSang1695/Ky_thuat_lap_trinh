//Bai 1
#include <iostream>
#include <cmath>
using namespace std;

void Inputarr(int *a, int n){
	for (int i=0; i<n; i++){
		cin >> *(a+i);
	}
}
void Outputarr (int *a, int &n){
	for (int i=0; i<n; i++){
		cout << *(a+i)<< " ";
	}
	cout << endl;
}
//Cau a
void deletetext (int *a, int &n, int k){
	if (k>= 0&&k<n){
		for (int i=k; i<n-1; i++){
			*(a+i)= *(a+i+1);
		}	n--;
	} else {
		cout << "Vi tri khong hop le\n";
	}	
}

//Cau b
void Inserttext (int *a, int &n, int k){
	cout << "Nhap vi tri can chen: ";
	cin >> k;
	k=k-1;
	int x;
	cout << "Nhap ki tu can chen ";
	cin >> x;
	if (k<0 || k>n){
		cout << "Loi ";
		return;
	}
	for (int i=n-1; i>= k; i--)
		 *(a+i+1)= *(a+i);
	 *(a+k)=x;
	n++;
}

//Cau c
// kiem tra so nguyen to
bool CheckPrime (int num) {
    if (num< 2)
    return false;
	for (int i=2 ; i<= sqrt(num); i++){
    	if (num%i==0){
    		return false;
		}
	}
	return true;
}
  // xoa so nguyen to
void DeletePrimes(int* a, int &n) {
    int i=0;
	while (i< n){
    	if (CheckPrime( *(a+i))){
    		deletetext(a, n, i);
		}
		else {
			i++;
		}
	}
}

int main () {
	int n, k;
	cout << "Nhap so luong ki tu ";
	cin >> n;
	int *a= new int[n];
	cout << "Nhap mang ";
	Inputarr (a, n);
	cout << "Chuoi truoc khi xoa ";
	Outputarr (a, n);
	// Cau a
	cout << "k= ";
	cin >> k;
	k=k-1;
	deletetext (a, n, k);
	cout << "Chuoi sau khi xoa: ";
	Outputarr (a, n);
	//Cau b
	Inserttext (a, n, k);
	cout << "Chuoi sau khi chen: ";
	Outputarr (a, n);
	//Cau c
	cout <<"Chuoi sau khi xoa so nguyen to: ";
	DeletePrimes (a, n);
	Outputarr (a, n);
	
	
	delete [] a; 
	return 0;
}

