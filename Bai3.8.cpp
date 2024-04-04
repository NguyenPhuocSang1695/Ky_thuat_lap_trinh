 #include <bits/stdc++.h>
using namespace std;

struct Thisinh {
	string sobaodanh;
	string hovaten;
	float diemnn;
	float diemcb;
	float diemcs;
};

void nhap(Thisinh ts[], int n){
	for (int i=0;i< n; i++){
		cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
		cin.ignore();
		cout << "Nhap so bao danh: ";
		getline (cin, ts[i].sobaodanh);
		cout << "Nhap Ho va Ten: ";
		getline (cin, ts[i].hovaten);
		cout << "Nhap diem mon ngoai ngu: ";
		cin >> ts[i].diemnn;
		cout << "Nhap diem mon co ban: ";
		cin >> ts[i].diemcb;
		cout << "Nhap diem mon co so: ";
		cin >> ts[i].diemcs;
		cout << endl;
	}
}

void xuat(Thisinh ts[], int n){
	for (int i=0;i< n; i++){
		cout << "Thong tin sinh vien thu " << i+1 << endl;
		cout << "So bao danh: ";
		cout << ts[i].sobaodanh << endl;
		cout << "Ho va Ten: ";
		cout << ts[i].hovaten << endl;
		cout << "Diem mon ngoai ngu ";
		cout << ts[i].diemnn << endl;
		cout << "Diem mon co ban: ";
		cout << ts[i].diemcb << endl;
		cout << "Diem mon co so: ";
		cout << ts[i].diemcs << endl;
		cout << endl;
	}
}
//Cau a
void timkiem(Thisinh ts[], int n){
	bool found= false; // kiem tra tim thay hay khong
	for (int i=0; i<n; i++){
		if(ts[i].diemnn< 5|| ts[i].diemcb< 5|| ts[i].diemcs< 5){
			found= true; // tim thay va in ra sinh vien da tim thay
		cout << "Sinh vien thu " << i+1 << " co diem thi be hon 5"<< endl;
		cout << "So bao danh: ";
		cout << ts[i].sobaodanh << endl;
		cout << "Ho va Ten: ";
		cout << ts[i].hovaten << endl;
		cout << "Diem mon ngoai ngu ";
		cout << ts[i].diemnn << endl;
		cout << "Diem mon co ban: ";
		cout << ts[i].diemcb << endl;
		cout << "Diem mon co so: ";
		cout << ts[i].diemcs << endl;
		cout << endl;
		} if (!found){ // khong tim thay
			cout << "Khong tim thay thi sinh!\n";
		}
	}
}

//Cau b
void dem(Thisinh ts[], int n){
	int cnt=0; // tao bien dem
	bool found= false;
	for (int i=0; i< n; i++){
		if (ts[i].diemnn>= 5&& ts[i].diemcb>= 5&& ts[i].diemcs>= 5&& ts[i].diemcb+ ts[i].diemcs>= 12){
			cnt++;
		}
	}
	cout << "Co "<< cnt << " thi sinh thoa yeu cau\n";
}  
// Cau c
// tim sinh vien co diemmax tai vtmax
bool Checkmax(Thisinh* ts, int n, float& diemmax, int& vtmax){ //vtmax: vi tri cua sinh vien co diem lon nhat, diemmax: tong diem lon nhat
	diemmax= 0.00;
	vtmax=-1;
	for (int i=0; i< n; i++){
		//tongnow: tong diem hien tai
		int tongnow= ts[i].diemnn+ ts[i].diemcb+ ts[i].diemcs;
		if (tongnow> diemmax){
			diemmax= tongnow;
			vtmax= i;
		}
	}
	return diemmax> 0.00;
}
//In ra thi sinh co tong lon nhat
void Inmax (Thisinh* ts, int n){
	float diemmax;
	int vtmax;
		if(Checkmax(ts, n, diemmax, vtmax)){
		cout << "Sinh vien thu co diem thi lon nhat la"<< endl << endl;
		cout << "So bao danh: ";
		cout << ts[vtmax].sobaodanh << endl;
		cout << "Ho va Ten: ";
		cout << ts[vtmax].hovaten << endl;
		cout << "Diem mon ngoai ngu ";
		cout << ts[vtmax].diemnn << endl;
		cout << "Diem mon co ban: ";
		cout << ts[vtmax].diemcb << endl;
		cout << "Diem mon co so: ";
		cout << ts[vtmax].diemcs << endl;
		cout << endl;
		} else {
			cout << "Khong tim thay thi sinh !\n" << endl;
	}
}

//Cau d
void timdiemx(Thisinh ts[], int n) {
	string x;
    cout << "Nhap so bao danh can tim: ";
    cin.ignore();
    getline(cin, x);

    bool timed = false; // kiem tra tim thay khong
    for (int i = 0; i< n; i++) {
        if (x == ts[i].sobaodanh) {
        	timed= true;
            cout << "Diem thi cua sinh vien can tim la:" << endl;
            cout << "Diem mon ngoai ngu: " << ts[i].diemnn << endl;
            cout << "Diem mon co ban: " << ts[i].diemcb << endl;
            cout << "Diem mon co so: " << ts[i].diemcs << endl;
            break;
        }
    }
    if (!timed) {
        cout << "So bao danh khong ton tai!\n";
    }
}
//Cau e
void swap (int &a, int &b){
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}

void sapxepsbd(Thisinh ts[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (ts[j].sobaodanh > ts[j + 1].sobaodanh) {
                swap(ts[j], ts[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main(){
	int n;
	cout << "Nhap so luong thi sinh: "; cin >>n;
	Thisinh *ts= new Thisinh[n];
	nhap(ts, n);
	//Cau a;
	cout << "\n\n============= Cau a ===============\n\n";
	timkiem (ts, n);
	//Cau b
	cout << "\n\n============= Cau b ===============\n\n";
	dem (ts, n);
	//Cau c
	cout << "\n\n============= Cau c ===============\n\n";
	Inmax(ts, n);
	//Cau d
	cout << "\n\n============= Cau d ===============\n\n";
	timdiemx (ts, n);
	// Cau e
	cout << "\n\n============= Cau e ===============\n\n";
	sapxepsbd(ts, n);
	xuat(ts, n);
	
	delete[] ts;
	return 0;
}
