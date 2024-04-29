#include <iostream>
#include <string>

using namespace std;

//ki tu la chu cai
bool isalpha (char s){
	return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
}

// Câu a
// tim tu dai nhat
string tudainhat(string &str) {
    string tudainhat = "";
    string tudangxet = "";

    for (char ch : str) {
        if (isalpha(ch)) { //kiem tra ki tu do la chu cai khong
            tudangxet += ch; //ghep tudangxet voi ch
        } else {
            if (tudangxet.length() > tudainhat.length()) {
                tudainhat = tudangxet;
            }
            tudangxet = "";
        }
    }
    //so sanh do dai chuoi
    if (tudangxet.length() > tudainhat.length()) {
        tudainhat = tudangxet;
    }
    return tudainhat;
}

// Câu b
//tim tu ben phai
string tubenphai(string s) {
    string kq = "";
    for (int i = s.length(); i >= 0; i--) {
        if (s[i] != ' ') {
            kq = s[i] + kq;              
        } else { // sau khi gap ki tu khoang trang thi dung
            break;
        }
    }
    return kq;
}

//tim tu ben trai
string tubentrai(string s) {
    string kq = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' || i == s.length() - 1) {
            kq += s[i];
        } else { // sau khi gap ki tu khoang trang thi dung
            break;
        }
    }
    return kq;
}

// Câu c
// Chuoi dai nhat
void chuoidainhat(string s, string& dainhat) {
    if (s.length() > dainhat.length()) {
        dainhat = s;
    } else if (s.length() == dainhat.length()) { //chuoi bang chuoi dai nhat thi in ra luon chuoi do
        cout << dainhat << endl;
        cout << s << endl;
    }
}

// Câu d
// dem so luong phan tu cua moi chuoi
int demtu (string s) {
    int count = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    return count;
}

// Câu e
// dem so luong tu your
int demtucandem(string s, string tucandem) {
    int count = 0;
    if (tucandem.length() == 0) { //neu chuoi rong
        return 0;
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == tucandem[0]) { //ki tu thu i giong voi tu "y"
            bool datimthay = true;
            for (int j = 0; j < tucandem.length(); j++) { //so sanh ki tu sau i voi uor
                if (s[i + j] != tucandem[j]) {
                    datimthay = false; // ki tu sau i khac our
                    break;
                }
            }
            if (datimthay) { // tu giong tu your
                count++;
            }
        }
    }
    return count;
}

int main() {
    freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-10\\STR.INP", "r", stdin);
    freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-10\\STR.OUT", "w", stdout);
    
    int n;
    cin >> n;
    cin.ignore();

    string s[1000];
    
    int size= 0; // kich thuoc cua chuoi
    
    //nhap chuoi va tang kich thuoc tung chuoi
    for (int i= 0; i< n && size < 1000; i++){
    	getline (cin, s[size++]);
	}
	
	//cau a. tu dai nhat
	cout << "CAU a:" << endl;
    for (int i = 0; i < size;i++){ 
        cout << tudainhat(s[i]) << endl;
    }
    
    //cau b. tu ben trai va tu ben phai
    cout << "CAU b:" << endl;
    for (int i= 0; i< size; i++){
    	cout << tubentrai(s[i]) << " " << tubenphai(s[i]) << endl;      
	}
    
    //cau c. chuoi dai nhat
    cout << "CAU c" << endl;
    string dainhat; // chuoi dai nhat
    dainhat = "";
    for (int i= 0; i< size; i++){
    	chuoidainhat(s[i], dainhat);
	}
    cout << dainhat << endl;
    
    //cau d. so luong tu trong n chuoi
    cout << "CAU d:" << endl;
    int soluongchu= 0;
    int soluongtuyour= 0;
    for (int i= 0; i< n; i++){
    	soluongchu+= demtu(s[i]);
    	soluongtuyour+= demtucandem(s[i], "your");
	}
    cout << soluongchu <<endl;
    
    //cau e. so luong tu "your"
    cout << "CAU e:" << endl;
    cout << soluongtuyour<< endl;
    return 0;
}
