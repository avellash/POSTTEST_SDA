#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
    if (front == nullptr) {
        front = rear = newNode;
    }

    // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // 1. Simpan data dari front node
    Node* temp = front;
    string data = temp->document;

    // 2. Geser front ke front->next
    front = front->next;
    
    // 3. Jika front menjadi nullptr, set rear juga ke nullptr
    if (front == nullptr) {
        rear = nullptr;
    }

    // 4. Delete node lama dan return data
    delete temp;
    return data;

    return ""; // Placeholder
}

void processAllDocuments(Node*& front, Node*& rear) {

    // Loop hingga queue kosong, dequeue dan print setiap dokumen
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl; // Format: "Memproses: [nama_dokumen]
    }

}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}

// Buat implementasi Queue manual menggunakan linked list untuk simulasi antrian printer yang memproses dokumen berdasarkan urutan kedatangan (FIFO).
// Struktur Data:

// ```c++
// #include <iostream>
// #include <string>
// using namespace std;

// struct Node {
//     string document;
//     Node* next;
// };
// ```

// Lengkapi Fungsi berikut:

// ```c++
// void enqueue(Node*& front, Node*& rear, string document) {
//     Node* newNode = new Node{document, nullptr};

//     // --- LENGKAPI DI SINI ---
//     // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
//     // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
//     // --- LENGKAPI DI SINI ---
// }

// string dequeue(Node*& front, Node*& rear) {
//     if (front == nullptr) return ""; // Queue kosong

//     // --- LENGKAPI DI SINI ---
//     // 1. Simpan data dari front node
//     // 2. Geser front ke front->next
//     // 3. Jika front menjadi nullptr, set rear juga ke nullptr
//     // 4. Delete node lama dan return data
//     // --- LENGKAPI DI SINI ---

//     return ""; // Placeholder
// }

// void processAllDocuments(Node*& front, Node*& rear) {
//     // --- LENGKAPI DI SINI ---
//     // Loop hingga queue kosong, dequeue dan print setiap dokumen
//     // Format: "Memproses: [nama_dokumen]"
//     // --- LENGKAPI DI SINI ---
// }

// int main() {
//     Node* front = nullptr;
//     Node* rear = nullptr;

//     enqueue(front, rear, "Document1.pdf");
//     enqueue(front, rear, "Report.docx");
//     enqueue(front, rear, "Presentation.pptx");

//     cout << "Memulai pemrosesan antrian printer:" << endl;
//     processAllDocuments(front, rear);

//     return 0;
// }
// ```

// Hanya Info:

// Queue menggunakan prinsip FIFO (First-In, First-Out). Dokumen yang pertama masuk antrian akan diproses pertama kali. Pointer front menunjuk ke elemen yang akan dikeluarkan, dan rear menunjuk ke posisi untuk elemen baru.

// Output:

// ```c++
// Memulai pemrosesan antrian printer:
// Memproses: Document1.pdf
// Memproses: Report.docx
// Memproses: Presentation.pptx