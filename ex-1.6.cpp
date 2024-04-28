#include<iostream>
using namespace std;

int calculate(int n, int i= 0, int sum= 0){
    if(n == 1 || n == 0)
        return 1;
    else{
        if (i== n){
        	return sum;
		}
        sum += (n - i) * calculate(i);
        return calculate (n, i+1, sum);
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << "x" << n << " = " << calculate(n) << endl;
}
