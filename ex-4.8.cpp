#include <bits/stdc++.h>
using namespace std;

struct Ps {
	int tu;
	int mau;
};

void nhap (Ps* ps, int n) {
	for (int i=0; i< n; i++){
		cin >> ps[i].tu;
		cin >> ps[i].mau;
	}
}

//cau a
//dem phan so nho hon 1
void caua (Ps* ps, int n){
	int count= 0;
	for (int i= 0; i< n; i++){
		if (ps[i].tu/ps[i].mau< 1){
			count++;
		}
	}
	cout << count << endl;
}

//cau b
//dem so phan so tu chia het cho mau
void caub (Ps* ps, int n){
	int count= 0;
	for (int i=0; i< n; i++){
		if (ps[i].tu%ps[i].mau== 0){
			count++;
		}
	}
	cout << count << endl;
}

//cau c
//kiem tra so nguyen to
bool isprime(int n){
	if (n< 2){
		return false;
	}
	for (int i=2; i<= sqrt(n); i++){
		if (n%i==0)
		return false;
	}
	return true;
}

//dem so phan so tu va mau so deu la so nguyen to
int cauc (Ps* ps, int n){
	int count= 0;
	bool found;
	for (int i=0; i< n; i++){
		if (isprime (ps[i].tu)){
			found= true;
			if (!isprime(ps[i].mau)){
				found= false;
			}
			if (found== true){
			count++;
			}
		}
	}
	return count;
}

//cau d
//phan so co gia tri lon nhat
void phansomax (Ps* ps, int n){
	float maxps= 0.0; // gia tri lon nhat
	int x; // luu toa do phan so
	for (int i=0; i< n; i++){
		float thuong= float (ps[i].tu)/ ps[i].mau;
		if (maxps < thuong){
			maxps= thuong;
			x= i;
		}
	}
	cout << ps[x].tu << "/" << ps[x].mau << endl;
}

//cau e
//phan so nho hon 1 lon nhat
void phanson1max (Ps* ps, int n){
	float max= 0.0; // gia tri lon nhat
	int x= 0; //toa do phan so lon nhat
	for (int i= 0; i< n; i++){
		if (ps[i].tu/ ps[i].mau< 1&& max < float (ps[i].tu)/ ps[i].mau){ 
				max= float (ps[i].tu)/ ps[i].mau; //cap nhat gia tri cua max
				x= i; //cap nhat toa do phan so lon nhat
		}
	}
	cout << ps[x].tu << "/" << ps[x].mau << " ";
}

//phan so lon hon 1 nho nhat
void phansol1min (Ps* ps, int n){
	float min= INT_MAX; //gia tri nho nhat
	int y= 0; //toa do phan tu gia tri nho nhat
	for (int i= 0;i< n; i++){
		if (ps[i].tu/ps[i].mau >= 1 && float (ps[i].tu)/ps[i].mau< min){
				min= float (ps[i].tu)/ ps[i].mau; //cap nhat gia tri nho nhat
				y= i; // cap nhat toa do gia tri nho nhat
		}
	}
	cout << ps[y].tu << "/" << ps[y].mau << endl; 
}

//cau f
// tim uoc chung lon nhat
int ucln (int &a, int &b){
	if (a== 0|| b== 0){
		return a+b;
	}
	while (a != b){
		if (a> b){
			a= a-b;
		} else {
			b= b-a;
		}
	}
	return a;
}

 //dem phan so toi gian
void demphansotoigian (Ps* ps, int n){
	int count= 0;
	for (int i= 0; i< n; i++){
		//ucln la 1 tuc la hai phan so da toi gian
		if (ucln (ps[i].tu, ps[i].mau) == 1 ||ucln (ps[i].tu, ps[i].mau)== 1){
			count++;
		}
	}
	cout << count << endl;
}


//cau g
//tinh trung binh cong
float trbcong(Ps ps[],int n){
	float tong=0.0;
	for(int i=0 ;i< n;i++){
		tong+=(float)(ps[i].tu)/ps[i].mau;
		}
		return (float)tong/n;
}


int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-8\\fraction.txt", "r", stdin) ;
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-8\\fraction.out", "w", stdout);
	int n; cin >> n;
	Ps* ps= new Ps[n];
	nhap (ps, n);
	caua(ps, n);
	caub (ps, n);
	cout << cauc (ps, n) << endl;
	cout << "cau d" << endl;
	phansomax (ps, n);
	phanson1max (ps, n);
	phansol1min (ps, n);
	float e= trbcong (ps, n);
	demphansotoigian (ps, n);
	cout << e;

	return 0;
}
