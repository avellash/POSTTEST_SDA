#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 5; 
    Mahasiswa mhs[N];

    cout << "input 5 mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "\nmahasiswa ke-" << i+1 << endl;
        cin.ignore(); 
        cout << "nama = "; getline(cin, mhs[i].nama);
        cout << "nim = "; getline(cin, mhs[i].nim);
        cout << "IPK = "; cin >> mhs[i].ipk;
    }

    int idx = 0;
    for (int i = 1; i < N; i++) {
        if (mhs[i].ipk > mhs[idx].ipk) idx = i;
    }

    cout << "\nmahasiswa dengan IPK tertinggi:\n";
    cout << "nama = " << mhs[idx].nama << endl;
    cout << "nim = " << mhs[idx].nim << endl;
    cout << "IPK = " << mhs[idx].ipk << endl;

    return 0;
}
