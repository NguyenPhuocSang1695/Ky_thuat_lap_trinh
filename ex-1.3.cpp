#include <iostream>
using namespace std;
float y(float n);

//Cau a
float x(float n) {
    if (n == 0.0)
        return 1.0;
    else
        return x(n - 1.0) / 3.0 + y(n - 1.0) / 2.0 + 27.0;
}
float y(float n) {
    if (n == 0.0)
        return 2.0;
    else
        return x(n - 1.0) / 5.0 + y(n - 1.0) / 7.0 + 11.0; 
}

//cau b
float x2(float n) {
    float tempx = 1.0;  // x(0)
    float tempy = 2.0;  // y(0)
    float x2, y2;

    for (int i = 1; i <= n; ++i) {
        x2 = tempx / 3.0 + tempy / 2.0 + 27.0;
        y2 = tempx / 5.0 + tempy / 7.0 + 11.0;
        tempx = x2;
        tempy = y2;
    }

    return tempx;
}

float y2(float n) {
    float tempx = 1.0;  // x(0)
    float tempy = 2.0;  // y(0)
    float x2, y2;

    for (int i = 1; i <= n; ++i) {
        x2 = tempx / 3.0 + tempy / 2.0 + 27.0;
        y2 = tempx / 5.0 + tempy / 7.0 + 11.0;
        tempx = x2;
        tempy = y2;
    }

    return tempy;
}

int main() {
    float n;
    cout << "Enter n: ";
    cin >> n;
    cout << x(n) << endl;
    cout << y(n) << endl;
    cout << "\n\n";
    cout << x2(n) << endl;
    cout << y2(n) << endl;
    return 0;
}
