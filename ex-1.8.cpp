#include<iostream>
using namespace std;

//tam gia pascal
int pascal (int k, int n) {
 if (k == 0 || k == n) return 1;
 if (k == 1) return n;
 return C(k - 1, n - 1) + C(k, n - 1);
}

int main(){
 int h;
 cin >> h;
 	for (int i = 0; i < h; i++) {
 		for (int j = h; j > i; j--)
 			cout << " ";
 				for (int j = 0; j <= i; j++) {
 				cout << pascal (j, i) << " ";
 			}
 		cout << endl;
 	}
 return 0;
}