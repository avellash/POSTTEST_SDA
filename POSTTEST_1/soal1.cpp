#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    const int N = 7;
    
    int arr[N] = {3, 6, 9, 12, 15, 18, 21};

    cout << "sebelum dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    balikArray(arr, N);

    cout << "sesudah dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "terima kasih >.< " << endl;

    return 0;
}

// Soal 1. Array + Pointer
// Buat program untuk menyimpan 7 data integer dalam array.
// Ganjil: isi dengan kelipatan 3
// Genap: isi dengan bilangan prima
// Kemudian:
// Buat fungsi dengan parameter pointer untuk membalik urutan array.
// Tampilkan array sebelum dan sesudah dibalik.