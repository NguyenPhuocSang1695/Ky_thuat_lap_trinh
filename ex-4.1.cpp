#include <bits/stdc++.h>
using namespace std;

//nhap mang so nguyen
void enter (int a[], int n){
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
}

//ham xuat mang 
void print (int a[], int n){
	for (int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
//Kiem tra so nguyen to
bool isprimes (int n){
	if (n< 2)
	return false;
	for (int i=2; i< n; i++){
		if (n%i==0)
		return false;
	}
	return true;
}

//dem so nguyen to
int countprimes (int a[], int n){
	int cnt=0;
	for (int i=0; i< n; i++){
		if (isprimes(a[i])){
			cnt++;
		}
	}
	return cnt;
}

// doi cho phan tu
void swap (int &a, int &b){
	int temp= a;
	a=b;
	b=temp;
}

//ham sap xep
void sort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main(){
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\NUM.INP", "r", stdin);
	freopen("D:\\C++\\Chapter-4-exercise programing techniques\\NUM.OUT", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	enter(a, n);
	cout << countprimes(a, n)<< endl;
	
	sort(a, n);
	print(a, n);

	return 0;
}
