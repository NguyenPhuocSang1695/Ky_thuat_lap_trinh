//Bai 3
#include <iostream>
using namespace std;

void nhapchuois(string &s) {
   getline(cin, s);
}
//Cau a
void xoa(string s, int p, int l){
	if (p> s.length()|| p< 0)
		cout << "Vi tri xoa khong hop le!\n";
	else 
	for (int i=p; i< s.length(); i++){
		s[i]=s[i+l]; // gan phan tu thu i+l cho phan tu thu i
	}
	cout << "Chuoi sau khi xoa\n" << s << endl;
}
//Cau b
void nhapchuois1 (string &s1) { //Nhap chuoi s1
   getline(cin, s1);
}
void nhapchuois2 (string &s2) { // Nhap chuoi s2
   getline(cin, s2);
}
void chen (string s1, string s2, int p){
	string temp; // Tao chuoi tam de luu ket qua sau khi chen
    for (int i = 0; i < p; i++) {
        temp.push_back(s1[i]); // Sao chep ki tu tu chuoi s1 den vi tri p
    }
    temp.append(s2); // Chen chuoi b vao chuoi s2
   
    for (int i = p; i < s1.length(); i++) {
        temp.push_back(s1[i]);  // Sao chep cac ky tu tu vi tri p cua chuoi s1 vao chuoi tam
    }

    // Gan ket qua tu chuoi tam vao chuoi a
    s1 = temp;
    cout << "Chuoi sau khi chen\n" << s1;
}

int main (){
	string s;
	cout << "Nhap chuoi s\n";
	nhapchuois(s);
	//Cau a
	int p, l;
	cout << "Nhap vi tri can xoa "; cin >> p;
	cout << "Nhap so luong ki tu can xoa "; cin >> l;
	xoa (s, p, l);
	cout << "\n\n========================\n\n";
	//Cau b
	string s1, s2;
	cout << "Nhap chuoi s1\n"; cin.ignore();
	nhapchuois1(s1);
	cout << "Nhap chuoi s2\n";
	nhapchuois1(s2);
	cout << "Nhap vi tri can chen "; cin >> p;
	chen(s1, s2, p);
	return 0;
}