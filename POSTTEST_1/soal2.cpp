#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N] = {
        {9, 2, -3},
        {0, 4, -1},
        {2, 1, 3}
    };

    int jumlahDiagonalUtama = 0, jumlahDiagonalSekunder = 0;

    for (int i = 0; i < N; i++) {
        jumlahDiagonalUtama += matriks[i][i];        
        jumlahDiagonalSekunder += matriks[i][N-i-1]; 
    }

    cout << "matriks 3x3:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "jumlah diagonal utama = " << jumlahDiagonalUtama << endl;
    cout << "jumlah diagonal sekunder = " << jumlahDiagonalSekunder << endl;
    cout << "hasil total = " << (jumlahDiagonalUtama + jumlahDiagonalSekunder) << endl;
    cout << "terima kasih (; " << endl;

    return 0;
}


// Soal 2. Array 2D
// Buat program untuk menyimpan matriks 3x3.
// Ganjil: hitung jumlah diagonal utama + diagonal sekunder
// Genap: hitung jumlah elemen baris genap saja
// Kemudian:
// Cetak hasil perhitungan beserta matriksnya.
