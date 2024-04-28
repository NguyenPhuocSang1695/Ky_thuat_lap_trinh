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
	for (int i=2; i< sqrt(n); i++){
		if (n%i==0)
		return false;
	}
	return true;
}

//dem so phan so tu va mau so deu la so nguyen to
void cauc (Ps* ps, int n){
	int count= 0;
	for (int i=0; i< n; i++){
		if (isprime(ps[i].tu)&& isprime(ps[i].mau)){
			count++;
		}
	}
	cout << count << endl;
}

//cau d
void phansomax (Ps* ps, int n){
	int maxps= 0.0;
	int x; //
	for (int i=0; i< n; i++){
		float thuong= ps[i].tu/ ps[i].mau;
		if (maxps < thuong){
			x= i;
		}
	}
	cout << ps[x].tu << "/" << ps[x].mau << endl;
}

//cau e
//phan so nho hon 1 lon nhat
void phanson1max (Ps* ps, int n){
	int max= INT_MIN;
	int x= 0;
	for (int i= 0; i< n; i++){
		if (ps[i].tu/ ps[i].mau< 1&& max < ps[i].tu% ps[i].mau){ // ps < 1 thi phan nguyen la 0, nen chi can so sanh phan du
				max= ps[i].tu/ ps[i].mau;
				x= i;
		}
	}
	cout << ps[x].tu << "/" << ps[x].mau << endl;
}

//phan so lon hon 1 nho nhat
void phansol1min (Ps* ps, int n){
	int min= INT_MAX;
	int y= 0;
	for (int i= 0;i< n; i++){
		if (ps[i].tu/ps[i].mau >= 1 && ps[i].tu/ps[i].mau< min || (ps[i].tu/ps[i].mau== min && ps[i].tu% ps[i].mau< min)){
				min= ps[i].tu/ ps[i].mau;
				y= i;
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
	cauc (ps, n);
	phansomax (ps, n);
	phanson1max (ps, n);
	phansol1min (ps, n);
	float e= trbcong (ps, n);
	demphansotoigian (ps, n);
	cout << e;

	return 0;
}