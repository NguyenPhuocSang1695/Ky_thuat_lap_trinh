#include <iostream>
using namespace std;

//kiem tra 2 chuoi giong nhau khong
bool kiemtra(string &s, int bd, string &x) {
    int lenx = x.size();
    for (int i = 0; i < lenx; i++) {
        if (s[bd + i] != x[i]) {
            return false;
        }
    }
    return true;
}

// thay x bang y trong s
void thaythechuoi(string &s, string &x, string &y) {
    int lens = s.size();
    int lenx = x.size();
    int leny = y.size();
     // kiem tra x trong s
    bool found = false;
    for (int i = 0; i <= lens - lenx; i++) {
        if (kiemtra(s, i, x)) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay chuoi x trong chuoi s." << endl;
        return;
    }

    // thay x bang y
    string kq = "";
    for (int i = 0; i < lens;) {
        if (kiemtra(s,i,x)) {
            kq += y; //them y vao kq
            i += lenx; // di chuyen i qua moi x
        } else {
            kq += s[i]; // them ki tu tu s vao kq
            i++;
        }
    }
    cout << "Chuoi sau khi thay the la: " << kq << endl;
}

int main() {
    string s, x, y;
    cout << "Nhap chuoi S:";
    getline(cin, s);
    cout << "Nhap chuoi x: ";
    getline(cin, x);
    cout << "Nhap chuoi y: ";
    getline(cin, y);
    thaythechuoi(s, x, y);
    return 0;
}