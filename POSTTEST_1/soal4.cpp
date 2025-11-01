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

// Soal 4. Pointer pada Fungsi
// Buat fungsi untuk menukar dua variabel integer.
// Ganjil: gunakan double pointer (int **) dalam fungsi untuk melakukan pertukaran nilai.
// Genap: gunakan reference (&) dalam fungsi untuk melakukan pertukaran nilai.
// Kemudian:
// Uji fungsi tersebut dengan dua nilai input dan tampilkan hasil sebelum dan sesudah pertukaran.