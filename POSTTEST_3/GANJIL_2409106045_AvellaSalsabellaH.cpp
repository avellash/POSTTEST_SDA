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
    Item* prev;
};

Item* head = nullptr;
Item* tail = nullptr;
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

    cout << "\n+=====<3=============== DAFTAR INVENTORY =========**==========+\n";
    cout << left << setw(5) << "No"
         << setw(30) << "Nama Item"
         << setw(10) << "Jumlah"
         << setw(15) << "Tipe" << "\n";
    cout << "------------------------------------------------------------>>\n";

    Item* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << left << setw(5) << i++
             << setw(30) << temp->namaItem
             << setw(10) << temp->jumlah
             << setw(15) << temp->tipe << "\n";
        temp = temp->next;
    }
    cout << "+=================**============================<3============+\n";
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
    string tipe = tipeItem[namaItem]; 

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

    Item* baru = new Item{namaItem, jumlahAwal, tipe, nullptr, nullptr};
    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }

    cout << "Item \"" << namaItem << "\" berhasil ditambahkan!\n";
    tampilkanInventory();
}

void sisipItem(const string &namaItem) {
    int jumlahAwal = jumlahAwalItem();
    string tipe = tipeItem[namaItem]; 
    Item* baru = new Item{namaItem, jumlahAwal, tipe, nullptr, nullptr};

    int posisi = posisiSisipItem();
    int total = hitungItem();

    if (head == nullptr || posisi <= 1) {
        baru->next = head;
        if (head != nullptr) head->prev = baru;
        head = baru;
        if (tail == nullptr) tail = baru;
        cout << "Item \"" << namaItem << "\" disisipkan di awal.\n";
        tampilkanInventory();
        return;
    }

    if (posisi > total) {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        cout << "Posisi lebih besar, item ditaruh di akhir.\n";
    } else {
        Item* temp = head;
        int idx = 1;
        while (temp->next != nullptr && idx < posisi - 1) {
            temp = temp->next;
            idx++;
        }
        baru->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = baru;
        temp->next = baru;
        baru->prev = temp->next; 
        if (baru->next == nullptr) tail = baru;
        cout << "Item \"" << namaItem << "\" disisipkan di posisi " << (idx+1) << "!\n";
    }

    tampilkanInventory();
}

void hapusItem() {
    if (tail == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "Item \"" << tail->namaItem << "\" dihapus.\n";
    Item* hapus = tail;
    tail = tail->prev;
    if (tail != nullptr) tail->next = nullptr;
    else head = nullptr;
    delete hapus;
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
    int idx = 1;
    while (temp != nullptr && idx < pilihan) {
        temp = temp->next;
        idx++;
    }

    if (temp == nullptr) {
        cout << "Nomor item tidak valid!\n";
        return;
    }

    temp->jumlah--;
    if (temp->jumlah <= 0) {
        cout << "Item \"" << temp->namaItem << "\" habis dan dihapus.\n";
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        else tail = temp->prev;
        delete temp;
    } else {
        cout << "Item \"" << temp->namaItem << "\" digunakan. Sisa: " << temp->jumlah << "\n";
    }
}

void tampilkanDariBelakang() {
    if (tail == nullptr) {
        cout << "\nInventory kosong!\n";
        return;
    }

    cout << "\n+======**======= DAFTAR INVENTORY (Dari Belakang) =======<3=======+\n";
    cout << left << setw(5) << "No"
         << setw(30) << "Nama Item"
         << setw(10) << "Jumlah"
         << setw(15) << "Tipe" << "\n";
    cout << "---------------------------------------------------------------->>\n";

    Item* temp = tail;
    int i = 1;
    while (temp != nullptr) {
        cout << left << setw(5) << i++
             << setw(30) << temp->namaItem
             << setw(10) << temp->jumlah
             << setw(15) << temp->tipe << "\n";
        temp = temp->prev;
    }
    cout << "+==================<3=========================**==================+\n";
}

void detailItem(const string& keyword) {
    Item* temp = head;
    while (temp != nullptr) {
        if (temp->namaItem == keyword) {
            cout << "\nDetail Item:\n";
            cout << "Nama   : " << temp->namaItem << "\n";
            cout << "Tipe   : " << temp->tipe << "\n";
            cout << "Jumlah : " << temp->jumlah << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Item \"" << keyword << "\" tidak ditemukan!\n";
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
        cout << "|         [ " << nama << " - " << nim << " ]          |\n";
        cout << "<3---------------------------------------<3\n";
        cout << "| <3 1. Tambah Item Baru                * |\n";
        cout << "| <3 2. Sisipkan Item                   * |\n";
        cout << "| <3 3. Hapus Item Terakhir             * |\n";
        cout << "| <3 4. Gunakan Item                    * |\n";
        cout << "| <3 5. Tampilkan Inventory             * |\n";
        cout << "| <3 6. Tampilkan dari Belakang         * |\n";
        cout << "| <3 7. Cari Detail Item                * |\n";
        cout << "| <3 0. Keluar                          * |\n";
        cout << "<3---------------------------------------<3\n";
        cout << "Pilih menu: ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid.\n";
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
            case 6:
                tampilkanDariBelakang();
                break;
            case 7: {
                string cari;
                cout << "Masukkan nama item: ";
                getline(cin, cari);
                detailItem(cari);
                break;
            }
            case 0:
                cout << "\nTerima kasih telah menggunakan program ini <3, " << nama << "! >_<\n";
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
