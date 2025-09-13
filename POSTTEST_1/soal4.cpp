#include <iostream>
using namespace std;

void doublePointer(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;
    cout << "masukkan bilangan pertama: ";
    cin >> x;

    cout << "masukkan bilangan kedua: ";
    cin >> y;

    cout << "sebelum ditukar -> x = " << x << ", y = " << y << endl;

    int *px = &x, *py = &y;
    doublePointer(&px, &py);

    cout << "sesudah ditukar -> x = " << x << ", y = " << y << endl;
    cout << "terima kasih <3 " << endl;

    return 0;
}

