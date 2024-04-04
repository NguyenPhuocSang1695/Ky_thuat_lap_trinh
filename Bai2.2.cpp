//Bai 2
#include <bits/stdc++.h>

using namespace std;

struct Information{
    long long mssv;
    string HovaTen;
    float dmcb;
    float dmcn1;
    float dmcn2;
};
//Cau a
void Input(Information *infor, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
        cout << "Nhap ma so sinh vien: ";
        cin >> (infor + i)->mssv;
        cin.ignore();
        cout << "Nhap Ho va Ten: ";
        getline(cin, (infor + i)->HovaTen);
        cout << "Nhap diem mon co ban: ";
        cin >> (infor + i)->dmcb;
        cout << "Nhap diem mon chuyen nganh 1: ";
        cin >> (infor + i)->dmcn1;
        cout << "Nhap diem mon chuyen nganh 2: ";
        cin >> (infor + i)->dmcn2;
        cout << "\n";
    }
    cout << endl;
}
//Cau b
void Output (Information* &infor, int n){
    for (int i = 0; i < n; i++) {
        cout << "Thong tin sinh vien thu " << i+1 << endl;
        cout << "Ma so sinh vien: " << (infor + i)->mssv << "\n";
        cout << "Ho va Ten: " << (infor+i)->HovaTen << "\n";
        cout << "Diem mon co ban: " << (infor + i)->dmcb << "\n";
        cout << "Diem mon chuyen nganh 1: " << (infor + i)->dmcn1 << "\n";
        cout << "Diem mon chuyen nganh 2: " << (infor + i)->dmcn2 << "\n";
        cout << "Diem tong 3 mon: " << (infor+i)->dmcb+ (infor+i)->dmcn1+ (infor+i)->dmcn2 <<"\n";
        cout << "\n";
    }
    cout << endl;
}
//Cau c
void SearchSv(Information* infor, int n){
	bool found= false; // kiem tra thoa dieu kien khong
	for (int i=0; i<n; i++){
		if ((infor + i)->dmcb< 5.00|| (infor + i)->dmcn1 <5.00|| (infor + i)->dmcn2 <5.00){
		found= true;
        cout << "Ma so sinh vien: " << (infor + i)->mssv << "\n";
        cout << "Ho va Ten: " << (infor+i)->HovaTen << "\n";
        cout << "Diem mon co ban: " << (infor + i)->dmcb << "\n";
        cout << "Diem mon chuyen nganh 1: " << (infor + i)->dmcn1 << "\n";
        cout << "Diem mon chuyen nganh 2: " << (infor + i)->dmcn2 << "\n";
        cout << "Diem tong 3 mon: " << (infor+i)->dmcb+ (infor+i)->dmcn1+ (infor+i)->dmcn2 <<"\n";
        cout << "\n";
		}
		if (!found){
			cout << "Khong tim thay!\n";
		}
	}
}

//Cau d
bool Checkmax(Information* infor, int n, float& diemmax, int& vtmax){ //vtmax: vi tri cua sinh vien co diem lon nhat, diemmax: tong diem lon nhat
	diemmax= 0.00;
	vtmax=-1;
	for (int i=0; i< n; i++){
		//tong: tong diem hien tai
		int tong= (infor+ i)->dmcb+ (infor+ i)->dmcn1+ (infor+ i)->dmcn2;
		if (tong> diemmax){
			diemmax= tong;
			vtmax= i;
		}
	}
	return diemmax> 0.00;
}


void SearchMax (Information *infor, int n){
	float diemmax;
	int vtmax;
		if(Checkmax(infor, n, diemmax, vtmax)){
		cout << "Thi sinh co diem ba mon lon nhat la"<< endl << endl;
		cout << "Ma so sinh vien: " << (infor + vtmax)->mssv << "\n";
        cout << "Ho va Ten: " << (infor+ vtmax)->HovaTen << "\n";
        cout << "Diem mon co ban: " << (infor + vtmax)->dmcb << "\n";
        cout << "Diem mon chuyen nganh 1: " << (infor + vtmax)->dmcn1 << "\n";
        cout << "Diem mon chuyen nganh 2: " << (infor + vtmax)->dmcn2 << "\n";
        cout << "Diem tong 3 mon: " << (infor+vtmax)->dmcb+ (infor+vtmax)->dmcn1+ (infor+ vtmax)->dmcn2 <<"\n";
        cout << "\n";
		} else {
			cout << "Not found\n" << endl;
	}
}

//Cau e
//ham doi cho
void swap (int *a, int *b){
	int *tmp;
	*tmp=*a;
	*a=*b;
	*b=*tmp;
}
// sap xep chuoi
void sapxep(Information* &infor, int n) {
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if ((infor + j)->dmcn1 + (infor + j)->dmcn2 > (infor + j + 1)->dmcn1 + (infor + j + 1)->dmcn2) {
        swap(*(infor + j), *(infor + j + 1));
        swapped = true;
      }
    }
    if (swapped == false) {
      break;
    }
  }
}

int main(){
    Information* infor;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    infor = new Information[n];
    //Cau a
    Input(infor, n);
    cout << "\n===============================\n";
    //Cau b
    Output(infor, n);
    cout << "\n===============================\n";
    //Cau c
    cout << "Sinh vien duoi trung binh 1 mon\n ";
    SearchSv(infor, n);
    cout << "\n===============================\n";
    //Cau d
    SearchMax (infor, n);
    cout << "\n===============================\n";
    //Cau e
    int l, r;
    sapxep(infor, n);
    cout << "Chuoi sau khi sap xep\n ";
    Output (infor, n);
    
    delete[] infor;
    return 0;
}