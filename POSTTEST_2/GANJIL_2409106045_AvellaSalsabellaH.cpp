#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

Item* head = nullptr;
string nama;
string nim;

map<string, string> tipeItem = {
    {"Glowing Wand", "Tongkat"},
    {"Enchanted Talisman", "Jimat"},
    {"Immortality", "Perisai"},
    {"Thunder Belt", "Armor"},
    {"Oracle's", "Jubah"},
    {"Antique Cuirass", "Armor"},
    {"Demon Boots", "Sepatu"},
    {"Rapid Boots", "Sepatu"},
    {"Cursed Helmet", "Helm"},
    {"War Axe", "Kapak"},
    {"Corrosion Scythe", "Sabit"},
    {"Endless Battle", "Tombak"},
    {"Hunter Strike", "Pisau"},
    {"Malefic Gun", "Pistol"},
    {"Blade of Despair", "Pedang"}
};

int jumlahAwalItem() {
    if ((int)nim.length() >= 2) {
        string lastTwo = nim.substr(nim.length() - 2);
        try {
            return stoi(lastTwo);
        } catch (...) {
            return 0;
        }
    }
    try {
        return stoi(nim);
    } catch (...) {
        return 0;
    }
}

int posisiSisipItem() {
    if (nim.empty()) return 1;
    char last = nim[nim.length() - 1];
    if (!isdigit(last)) return 1;
    return (last - '0') + 1;
}

int hitungItem() {
    int count = 0;
    Item* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void tampilkanInventory() {
    if (head == nullptr) {
        cout << "\nInventory kosong!\n";
        return;
    }

    cout << "\n+===================== DAFTAR INVENTORY =====================+\n";
    cout << left << setw(5) << "No"
         << setw(30) << "Nama Item"
         << setw(10) << "Jumlah"
         << setw(15) << "Tipe" << "\n";
    cout << "--------------------------------------------------------------\n";

    Item* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << left << setw(5) << i++
             << setw(30) << temp->namaItem
             << setw(10) << temp->jumlah
             << setw(15) << temp->tipe << "\n";
        temp = temp->next;
    }
    cout << "+============================================================+\n";
}

string pilihItemDariDaftar() {
    vector<string> keys;
    for (auto &it : tipeItem) keys.push_back(it.first);

    cout << "\n===== Daftar Item Tersedia =====\n";
    for (int i = 0; i < (int)keys.size(); i++) {
        cout << setw(3) << i+1 << ". " 
             << setw(25) << left << keys[i] 
             << " (" << tipeItem[keys[i]] << ")\n";
    }
    cout << "================================\n";

    int pil;
    while (true) {
        cout << "Pilih nomor item: ";
        if (cin >> pil && pil >= 1 && pil <= (int)keys.size()) {
            cin.ignore(1000, '\n');
            return keys[pil - 1];
        } else {
            cout << "Pilihan tidak valid, coba lagi.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

void tambahItem(const string &namaItem) {
    int jumlahAwal = jumlahAwalItem();
    string tipe = tipeItem[namaItem]; // langsung ambil dari map

    Item* temp = head;
    while (temp != nullptr) {
        if (temp->namaItem == namaItem) {
            temp->jumlah += jumlahAwal;
            cout << "Item \"" << namaItem << "\" sudah ada. Jumlah ditambah +"
                 << jumlahAwal << ". Total sekarang: " << temp->jumlah << "\n";
            tampilkanInventory();
            return;
        }
        temp = temp->next;
    }

    Item* baru = new Item{namaItem, jumlahAwal, tipe, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Item* p = head;
        while (p->next != nullptr) p = p->next;
        p->next = baru;
    }

    cout << "Item \"" << namaItem << "\" berhasil ditambahkan dengan jumlah "
         << jumlahAwal << "!\n";
    tampilkanInventory();
}

void sisipItem(const string &namaItem) {
    int jumlahAwal = jumlahAwalItem();
    string tipe = tipeItem[namaItem]; // langsung ambil dari map

    Item* baru = new Item{namaItem, jumlahAwal, tipe, nullptr};
    int posisi = posisiSisipItem();
    int total = hitungItem();

    cout << "Mencoba menyisip pada posisi: " << posisi
         << " (total item saat ini: " << total << ")\n";

    if (head == nullptr || posisi <= 1) {
        baru->next = head;
        head = baru;
        cout << "Item \"" << namaItem << "\" disisipkan di posisi awal.\n";
        tampilkanInventory();
        return;
    }

    Item* temp = head;
    int idx = 1;
    while (temp->next != nullptr && idx < posisi - 1) {
        temp = temp->next;
        idx++;
    }

    if (temp->next == nullptr && idx < posisi - 1) {
        temp->next = baru;
        cout << "Posisi lebih besar dari jumlah item. Item ditambahkan di akhir.\n";
    } else {
        baru->next = temp->next;
        temp->next = baru;
        cout << "Item \"" << namaItem << "\" berhasil disisipkan di posisi " << (idx + 1) << "!\n";
    }

    tampilkanInventory();
}

void hapusItem() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    if (head->next == nullptr) {
        cout << "Item \"" << head->namaItem << "\" dihapus dari inventory.\n";
        delete head;
        head = nullptr;
        return;
    }

    Item* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    cout << "Item \"" << temp->next->namaItem << "\" dihapus dari inventory.\n";
    delete temp->next;
    temp->next = nullptr;
}

void gunakanItem() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    tampilkanInventory();

    cout << "Pilih nomor item yang ingin digunakan: ";
    int pilihan;
    if (!(cin >> pilihan)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid.\n";
        return;
    }
    cin.ignore(1000, '\n');

    Item* temp = head;
    Item* prev = nullptr;
    int idx = 1;

    while (temp != nullptr && idx < pilihan) {
        prev = temp;
        temp = temp->next;
        idx++;
    }

    if (temp == nullptr) {
        cout << "Nomor item tidak valid!\n";
        return;
    }

    temp->jumlah--;

    if (temp->jumlah <= 0) {
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        cout << "Item \"" << temp->namaItem << "\" habis dan dihapus dari inventory.\n";
        delete temp;
    } else {
        cout << "Item \"" << temp->namaItem << "\" digunakan. Sisa: " << temp->jumlah << "\n";
    }
}

int main() {
    cout << "Masukkan Nama: ";
    getline(cin, nama);

    while (true) {
        cout << "Masukkan 3 digit terakhir NIM: ";
        cin >> nim;
        bool ok = (nim.length() == 3);
        for (char c : nim) if (!isdigit(c)) ok = false;
        if (ok) break;
        cout << "NIM harus 3 digit angka! Coba lagi.\n";
    }
    cin.ignore();

    int pilihan;
    string namaItem;

    do {
        cout << "\n<3---------------------------------------<3\n";
        cout << "|        * GAME INVENTORY MANAGEMENT *   |\n";
        cout << "|            [ " << nama << " - " << nim << " ]          |\n";
        cout << "<3---------------------------------------<3\n";
        cout << "| <3 1. Tambah Item Baru                * |\n";
        cout << "| <3 2. Sisipkan Item                   * |\n";
        cout << "| <3 3. Hapus Item Terakhir             * |\n";
        cout << "| <3 4. Gunakan Item                    * |\n";
        cout << "| <3 5. Tampilkan Inventory             * |\n";
        cout << "| <3 0. Keluar                          * |\n";
        cout << "<3---------------------------------------<3\n";
        cout << "Pilih menu: ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Silakan coba lagi.\n";
            continue;
        }
        cin.ignore();

        switch (pilihan) {
            case 1:
                namaItem = pilihItemDariDaftar();
                tambahItem(namaItem);
                break;
            case 2:
                namaItem = pilihItemDariDaftar();
                sisipItem(namaItem);
                break;
            case 3:
                hapusItem();
                break;
            case 4:
                gunakanItem();
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan program inventory, " << nama << "! <3\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    while (head != nullptr) {
        Item* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
