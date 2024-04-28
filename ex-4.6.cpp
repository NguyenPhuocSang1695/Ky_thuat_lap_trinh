#include <bits/stdc++.h>
using namespace std;

int a[100][100], k[100], b[100][100], c[100][100], d[100], e[100], m, n;

void nhap (){
	for (int i=0; i< m; i++){
		for (int j=0; j< n; j++){
			cin >> a[i][j];
		}
	}
}

//cau a
void findsum () {
	for (int i=0; i< m; i++){
		int min= a[0][0];
		for (int j=1; j< n; j++){
			if (a[i][j]< min){
				min= a[i][j];
			}
		}
		k[i]= min;
	}
	int sum= 0;
	for (int i=0; i< m; i++){
		for (int j= 0; j< n; j++){
			b[i][j]= a[i][j]* k[i];
			sum+= b[i][j];
		}
	}
	cout << sum << endl;
}

//cau b
//kiem tra so nguyen toii
bool snt (int n){
	if (n< 2)
	return false;
	for (int i=2; i<= sqrt(n); i++){
		if (n%i== 0)
		return false;
	}
	return true;
}

//chuyen ve so nguyen to truoc num
int truoc (int num){
	if (num< 2){
		return 2;
	}
	
 for (int i = num - 1; i > 1; i--) {
        bool isprime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) {
            return i;
        }
    }
    return 1; // Neu khong tim thay so nguyen nho hon
}

//chuyen ve so nguyen to sau num
int sau (int num){
	 for (int i = num + 1; ; i++) {
        bool isprime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) {
            return i;
        }
    }
}

//kiem tra khoang cach tu num toi so truoc va so sau coi so nao lon hon va tra ve theo dieu kien
int check (int num){
	int be = truoc(num);
    int af = sau(num);
    if (num - be <= af - num) {
        return be;
    } else {
        return af;
    }
}

//chuyen doi va in ra mang 
void chuyen (){
	int sum= 0;
	for (int i=0; i< m; i++){
		for (int j=0; j< n; j++){
			c[i][j]= check(a[i][j]);
			sum+= c[i][j];
		}
	}
	cout<< sum << endl;
}

//cau c
// max dong, min cot
void cauc() {
    int x, y; // luu toa do phan tu yen ngua
	int maxdong;
    for (int i=0; i< m; i++){ // tim max dong
    	maxdong= a[i][0];
    	for (int j= 1; j< n; j++){
    		if (a[i][j]> maxdong){
    			maxdong= a[i][j];
			}
		}
		d[i]= maxdong; // day maxdong vao d
	}
	
	for (int i=0; i< n; i++){ // tim min cot
		int mincot= a[0][i];
		for (int j= 1; j< m; j++){
			if (mincot> a[j][i]){
				mincot= a[j][i];
			}
		}
		e[i]= mincot; //day mincot vao e
	}
	
	//tim va in ra phan tu yen ngua
	for (int i=0; i< m; i++){
		for (int j=0; j< m; j++){
			if (d[i]== e[j]){
				x= i;
				y= j;
				cout << e[j] << " " << x+1 << " " << y+1;
				break;
			}
		}
	}
}

int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-5-6\\TABLE.INP", "r", stdin);
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-5-6\\TABLE.OUT", "w", stdout);
	cin >> m >> n;
	nhap();
	//cau a
	cout << "CAU a: ";
	findsum();
	//cau b
	cout << "CAU b: ";
	chuyen ();
	//cau c
	cout << "CAU c: ";
	cauc();
	return 0;
}
