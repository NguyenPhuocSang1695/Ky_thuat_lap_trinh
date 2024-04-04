
#include <bits/stdc++.h>

using namespace std;

bool islower(char c) {
	return c >= 'a' && c <= 'z';
}

bool isupper(char c) {
	return c >= 'A' && c <= 'Z';
}

char tolower(char c) {
	if (isupper(c)) {
		return c + 32;
	}
	return c;
}

char toupper(char c) {
	if (islower(c)) {
		return c - 32;
	}
	return c;
}

//Câu a
void demKiTu(char a[]) {
  int cnthoa = 0;
  int cntthuong = 0;
  for (int i = 0; a[i] != '\0'; i++) {
    if (isupper(a[i])) {
      cnthoa++; //Tang so luong chu in hoa
    } else if (islower(a[i])){
      cntthuong++; // Tang so luong chu thuong
    }
  }
  cout << "So ki tu la chu hoa: " << cnthoa << endl;
  cout << "So ki tu la chu thuong: " << cntthuong << endl;
}

//Câu b
void ascii (char a[]){
  for (int i=0; a[i] != '\0'; i++){
    cout << "Ma ascii cua " << a[i] << " la " << int (a[i]) /* ma ascii cua phan tu a[i] */ << endl;
  }
}

//Câu c
void chuyenkitu(char a[]) {
  for (int i = 0; a[i] != '\0'; i++) {
    //Chuyen ki tu dau tien thanh in hoa
    if (i == 0 || a[i - 1] == ' ') {
      a[i] = toupper(a[i]);
    } else {
      // Chuyen ki tu con lai thanh chu thuong
      a[i] = tolower(a[i]);
    }
  }
  cout << "Chuoi sau khi chuyen doi: ";
  cout << a;
}

//Cau d
int demsoluongtu (char a[]){
	int cnt=1; // dem so luonh tu
	for (int i=0; a[i] != '\0'; i++){
		if (a[i]== ' '){
			cnt++;
		} 
	}
	return cnt++;
}

//Cau e
void dslkt (char* a) {
    int sokytu = 0; // dung de dem so ki tu trong tu
    bool trongtu = false; // xac nhan van con trong tu hay khong

    for (int i = 0; a[i] != '\0'; ++i) {
        if (a[i] != ' ') {
            ++sokytu;
            trongtu = true;
        } else if (trongtu) {
            cout << "So ky tu trong tu la: " << sokytu << endl;
            sokytu = 0;
            trongtu = false;
        }
    }

    if (trongtu) { // in ra so ki tu cua tu sau khoang trong
        cout << "So ky tu trong tu la: " << sokytu << endl;
	}
}

//Cau f
void timtu (char a[]) {
    int n = strlen(a);
    // gan bang -1 de danh dau chua tim thay ki tu khoang trong
    // khong gan bang 0 vi 0 cung la vi tri hop le trong chuoi gan co the se bi loi
    int dau_cach_dau = -1;
    int dau_cach_cuoi = -1;

    // tim vi tri dau cach dau tien va dau cach cuoi cung
    for (int i = 0; i < n; ++i) {
        if (a[i] == ' ' && dau_cach_dau == -1) {
            dau_cach_dau = i;
        }
        if (a[i] == ' ') {
            dau_cach_cuoi = i;
        }
    }

    if (dau_cach_dau != -1 && dau_cach_cuoi != -1) {
        // in tu dau tien
        cout << "tu dau tien trong chuoi la: ";
        for (int i = 0; i < dau_cach_dau; ++i) {
            cout << a[i];
        }
        cout << "\n";

        // in tu cuoi cung
        cout << "tu cuoi cung trong chuoi la: ";
        for (int i = dau_cach_cuoi + 1; i < n; ++i) {
            cout << a[i];
        }
    }
    cout << endl;
}


int main (){
  char a[100];
  int n;
  cout << "Nhap chuoi: ";
  cin.getline(a, 100);
  n = strlen(a);
  //Câu a
  demKiTu(a);
  cout << "\n======================\n";
  //Câu b
  ascii(a);
  cout << "\n======================\n";
  //Câu c
  chuyenkitu(a);
  cout << "\n======================\n";
  //Cau d
  int p= demsoluongtu(a);
  cout << "So luong tu cua chuoi la: " << p;
  cout << "\n======================\n";
  //Cau e
  dslkt (a);
  cout << "\n======================\n";  
  //Cau f
  timtu (a);
  return 0;
}






