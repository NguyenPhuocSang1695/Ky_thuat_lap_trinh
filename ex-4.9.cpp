#include <bits/stdc++.h>
using namespace std;

//tinh do dai cua chuoi
int strlen (char s[]){
	int i= 0;
	while (1){
		if (s[i]== '\0'){ //gap ki tu ket thuc chuoi
		 return i;
		}
		i++;
	}
}

//tim tu ben phai
string findright(char s[]) {
    string kq = ""; 
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            kq = s[i] + kq; //gep s[i] cho kq va gan cho kq
        } else {
            break;
        }
    }
    return kq;
}

//dem do dai cua 1 cuoi
int count(char str[]) {
	if (strlen(str)== 0){
		return 0;
	}
	
    int cnt = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            cnt++;
        }
    }
    return cnt;
}


int main() {
    freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-9\\str.inp", "r", stdin);
    freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-9\\str.out", "w", stdout);
	int n; cin >> n; cin.ignore();
	char s[256];
	int sum= 0;
	for (int i= 0; i< n; ++i){
		cin.getline (s, 256);
		//cau a
		cout << findright(s) << endl;
		sum+= count(s); // tong do cua tat ca cac chuoi
	}
	//cau b
	cout  << sum;
    return 0;
}
