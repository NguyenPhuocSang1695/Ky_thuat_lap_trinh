#include <bits/stdc++.h>
using namespace std;

//Cau a
float F(float n){
	if (n==1.0 ||n==2.0)
	return 1.0;
	return F(n-2)+ F(n-1);
}

float S(int n) {
    if (n == 1)
    return 1.0 / (1.0 + F(1)); 
    return n / (1.0 + F(n)) + S(n-1);
}

//Cau b
float f(float n) {
    float fi=1.0;
    float se=1.0;
    float to;
    if (n==1|| n==2)
    	return 1;
	for (int i=3; i<=n; i++){
		to= fi+se;
		fi=se;
		se=to;
	}
	return to;
}

float s(float n){
	float total= 0.0;		
	for (int i=0; i<= n; i++){
		total += i / (1.0 + f(i));
	}
	return total;
}

int main(){
	float n; cin >> n;
	cout << S(n);
	cout << "\n\n";
	cout << s(n);
	return 0;
}
