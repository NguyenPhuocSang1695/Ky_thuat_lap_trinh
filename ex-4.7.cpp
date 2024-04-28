#include <iostream>
using namespace std;

string s;

void demkitu () {
	int dem[256]= {0};
	
	for (int i= 0; i< s.length(); i++){
		char kitu= s[i];
		if (kitu== ' '){
			continue; //neu la ki tu trong thi chuyen sang lan lap tiep theo
		}
		
		dem[kitu]++;
		
	}
	for (int i= 0; i< 256; i++){
		if (dem[i]!= 0){
			cout << char(i) << " " << dem[i] << endl;
		}
	}
}

int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-7\\input.txt", "r", stdin);
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\exer-7\\output.txt", "w", stdout);
	
	getline (cin, s);
    demkitu();
    return 0;
}
