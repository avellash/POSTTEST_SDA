#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
    // 1. Jika data < head_ref->data, sisipkan sebelum head dan update head_ref
    if (data < head_ref->data) {
        Node* last = head_ref->prev;

        newNode->next = head_ref;
        newNode->prev = last;
        last->next = newNode;
        head_ref->prev = newNode;

        head_ref = newNode; // update head
        return;
    }

    // Kasus 3: Cari posisi yang tepat (tengah/akhir)
    // 1. Gunakan pointer current mulai dari head_ref
    Node* current = head_ref;

    // 2. Loop: while (current->next != head_ref && current->next->data < data)
    while (current->next != head_ref && current->next->data < data) {
    current = current->next;
    }
    
    // 3. Setelah loop, sisipkan newNode setelah current
    newNode->next = current->next;
    newNode->prev = current;

    // 4. Pastikan update semua pointer next dan prev dengan benar
    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);

    return 0;
}

// Anda memiliki sebuah circular doubly linked list yang datanya sudah terurut (ascending). Buatlah fungsi untuk menyisipkan sebuah node baru ke dalam list tersebut sehingga urutannya tetap terjaga.

// Struktur Data:

// ```c++
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };
// ```

// Lengkapi Fungsi berikut:

// ```c++
// /*
//  * Fungsi ini menerima referensi ke pointer head dan data yang akan disisipkan.
//  * Pointer head bisa berubah jika data baru menjadi elemen terkecil.
//  */
// void sortedInsert(Node *&head_ref, int data) {
//     Node* newNode = new Node{data, nullptr, nullptr};

//     // Kasus 1: List masih kosong
//     if (head_ref == nullptr) {
//         newNode->next = newNode;
//         newNode->prev = newNode;
//         head_ref = newNode;
//         return;
//     }

//     // --- LENGKAPI DI SINI ---
//     // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
//     // 1. Jika data < head_ref->data, sisipkan sebelum head dan update head_ref

//     // Kasus 3: Cari posisi yang tepat (tengah/akhir)
//     // 1. Gunakan pointer current mulai dari head_ref
//     // 2. Loop: while (current->next != head_ref && current->next->data < data)
//     // 3. Setelah loop, sisipkan newNode setelah current
//     // 4. Pastikan update semua pointer next dan prev dengan benar
//     //
//     // CATATAN: Jika data sama dengan existing data, sisipkan setelahnya
//     // --- LENGKAPI DI SINI ---
// }

// void printList(Node *head_ref)
// {
//     if (head_ref == nullptr)
//     {
//         cout << "List kosong" << endl;
//         return;
//     }

//     Node *current = head_ref;
//     do
//     {
//         cout << current->data << " ";
//         current = current->next;
//     } while (current != head_ref);
//     cout << endl;
// }

// int main()
// {
//     Node *head = nullptr;

//     // Test sorted insert
//     sortedInsert(head, 30);
//     sortedInsert(head, 10);
//     sortedInsert(head, 40);
//     sortedInsert(head, 20);

//     cout << "Circular Doubly Linked List (sorted): ";
//     // Expected output: 10 20 30 40
//     printList(head);

//     return 0;
// }
// ```

// Hanya Info:

// Karena listnya sirkular dan terurut, kita bisa dengan cepat memeriksa apakah node baru harus diletakkan di awal (lebih kecil dari head) atau di akhir (lebih besar dari tail/head->prev). Jika tidak, kita baru melakukan traversal untuk mencari posisi di tengah.