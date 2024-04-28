#include <iostream>
#include <string>

using namespace std;

//tinh do dai cua chuoi
int strlen(char s[]) {
    int i = 0;
    while (1) {
        if (s[i] == '\0') {
            return i; //gia tri cuoi cung
        }
        i++;
    }
}
//cau a
//tim tu dai nhat
void tudainhat(const char s[]) {
    char temp[256]; //luu tu hien tai dang xet
    char tudainhat[256];
    int dodaitudainhat = 0;
    int vitribatdau = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ' || s[i + 1] == '\0') {
            int len = i - vitribatdau + 1;
            for (int j = 0; j < len; ++j) {
                temp[j] = s[vitribatdau + j];
            }
            temp[len] = '\0';
            if (len > dodaitudainhat) {
                dodaitudainhat = len;
                for (int j = 0; j < len; ++j) {
                    tudainhat[j] = temp[j];
                }
                tudainhat[len] = '\0';
            }
            vitribatdau = i + 1;
        }
    }
    cout << tudainhat << endl;
}


//cau b
//tu ben phai
string tubenphai (char s[]){
	string kq= " ";
	for (int i= strlen(s)- 1; i>=0; i--){
		if (s[i]!= ' '){
			kq= s[i]+ kq; // ghep s[i] voi kq
		} else {
			break;
		}
	}
	return kq;
}

//tu ben trai
string tubentrai (char s[]){
	string kq= " "; // luu ki tu dau ben trai cua chuoi
	for (int i= 0; s[i]!= '\0'; i++){
		if (s[i] != ' ' || s[i=1]== '\0'){
			kq= kq + s[i]; //ghep chuoi kq voi s[i]
		} else {
			break;
		}
	}
	return kq;
}


//cau c
//chuoi dai nhat
void chuoidainhat(char s[], int n, string& dainhat) {
    int dodaimax = dainhat.length(); //do dai cua tu dai nhat
    int len = strlen(s); //do dai

    if (len > dodaimax) {
        dainhat = s; //gan s cho chuoi dainhat neu do dai cua s lon hon dodaimax
    } else if (len == dodaimax) {
        cout << dainhat << endl;
        cout << s << endl; //in ra chuoi co do dai bang chuoi dai nhat
    }
}

//cau d
//dem so luong phan tu cua chuoi
int count (char s[]){
	if (strlen(s)== 0){ //neu chuoi rong
		return 0;
	}
	
	int cnt= 1;
	for (int i= 0; i< strlen(s); i++){
		if (s[i]== ' '){
			cnt++;
		}
	}
	return cnt;
}

//cau e
//dem so luong tu your
int demtucandem(char s[], const char* tucandem) {
    int count = 0;
    int len = strlen(tucandem);
    bool datimthay; //danh dau tim kiem
    
    if (len== 0){
    	return 0;
	}
	
	for (int i= 0; s[i]!= '\0'; i++){
		if (s[i]== tucandem[0]){ //s[i] giong voi ki tu dau tien cua tu can tim
			datimthay= true;
			for (int j= 0; j< len; j++){ // so sanh ki tu con lai cua s[i] voi tu can tim
				if (s[i+j]!= tucandem[j]){
					datimthay= false; // nhung tu phia sau khac voi tu can tim
					break;
				}
			}
			if (datimthay){ //ki tu sau s[i] giong voi tu con lai
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

    char s[256];
    string dainhat;
    
    for (int i= 0; i< n; i++){
    	cin.getline(s, 256);
    	tudainhat (s);
    	cout << tubentrai(s) << " " << tubenphai(s) << endl;
	}
    
    return 0;
}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			