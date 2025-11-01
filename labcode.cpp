// GRAPH

// Buatlah program C++ untuk merepresentasikan Graph menggunakan Adjacency Matrix. Kode bisa diingat kembali berdasarkan Modul 7 yang membahas Graph

#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>>& mat, int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void displayMatrix(vector<vector<int>>& mat) {
    int V = mat.size();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, 0));
    
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);
    
    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);
    
    return 0;
}

// Lengkapilah kode dibawah ini
// #include <iostream>
// #include <vector>
// using namespace std;

// void addEdge(vector<vector<int>>& mat, int i, int j) {
//     mat[i][j] = 1;
//     mat[j][i] = 1;
// }

// void displayMatrix(vector<vector<int>>& mat) {
//     int V = mat.size();
//     for (int i = 0; i < _; i++) {
//         for (int j = 0; j < _; j++) {
//             cout << mat[_][_] << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     int V = 4;
//     vector<vector<int>> _(V, vector<int>(V, 0));
    
//     _(mat, 0, 1);
//     _(mat, 0, 2);
//     _(mat, 1, 2);
//     _(mat, 2, 3);
    
//     cout << "Adjacency Matrix Representation" << endl;
//     displayMatrix(_);
    
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>>& mat, int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void displayMatrix(vector<vector<int>>& mat) {
    int V = mat.size();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, 0));
    
    _(mat, 0, 1);
    _(mat, 0, 2);
    _(mat, 1, 2);
    _(mat, 2, 3);
    
    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);
    
    return 0;
}

// // TREE
// Lengkapilah kode dibawah ini

// void preorderTraversal(Node* root) {
//     if (root == nullptr) {
//         return;
//     }
//     cout << _->data << " ";
//     preorderTraversal(root->_);
//     preorderTraversal(root->_);
// }

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Fungsi dibawah ini adalah fungsi untuk mencari node dengan nilai terkecil. Lengkapi bagian yang kosong dibawah agar fungsi dapat berjalan dengan benar.

// Node* findMinValueNode(Node* node) {
//     Node* current = node;
//     while (current && current->__ != nullptr) {
//         current = current->left;
//     }
//     return ___;
// }

Node* findMinValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// QUEUE SALAH
// Lengkapi kode dibawah, kode dibawah digunakan untuk menambahkan data sesuai konsep Queue yang sudah kalian pelajari di Modul 5

// void enqueue(int value) {
//     if (isFull()) {
//         cout << "Queue overflow" << endl;
//         return;
//     }
//     if (front __) {
//         front = 0;
//     }
//     rear++;
//     queue[rear] = ___;
//     cout << value << " enqueued into queue" << endl;
// }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue overflow" << endl;
        return;
    }
    if (front -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    cout << value << " enqueued into queue" << endl;
}

// Lengkapilah potongan kode Dequeue dibawah ini

// #include <iostream>
// #define MAX 100
// using namespace std;

// int queue[MAX];
// int front = -1, rear = -1;

// bool isFull() {
//     return rear == MAX - 1;
// }

// bool isEmpty() {
//     return front == -1 || front > rear;
// }

// int dequeue() {
//     if (_()) {
//         cout << "Queue underflow" << endl;
//         return -1;
//     }
//     int value = queue[front];
//     __++;
//     if (isEmpty()) {
//         front = _ = -1;
//     }
//     return _;
// }

#include <iostream>
#define MAX 100
using namespace std;

int queue[MAX];
int front = -1, rear = -1;

bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int value = queue[front];
    front++;
    if (isEmpty()) {
        front = rear = -1;
    }
    return value;
}

// STACK
// struct Mahasiswa {
//     string nama;
//     int nim;
//     double ipk;
// };

// struct Node {
//     Mahasiswa data;
//     Node* next;
// };

// Node* createNode() {
//     Node* newNode = new Node();
//     cout << "Masukan nama : ";
//     cin >> newNode->data.nama;
//     cout << "Masukan nim : ";
//     cin >> newNode->data.nim;
//     cout << "Masukan ipk : ";
//     cin >> newNode->data.ipk;
//     return _;
// }

// void push(Node** _) {
//     Node* nodeBaru = _();
//     nodeBaru->_ = *top;
//     *top = nodeBaru;
// }

// void pop(Node** top) {
//     if (*top == _) {
//         cout << "Stack underflow\n";
//         return;
//     }
//     Node* temp = *top;
//     *top = (*top)->_;
// }

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    double ipk;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

Node* createNode() {
    Node* newNode = new Node();
    cout << "Masukan nama : ";
    cin >> newNode->data.nama;
    cout << "Masukan nim : ";
    cin >> newNode->data.nim;
    cout << "Masukan ipk : ";
    cin >> newNode->data.ipk;
    return newNode;
}

void push(Node** top) {
    Node* nodeBaru = createNode();
    nodeBaru->next = *top;
    *top = nodeBaru;
}

void pop(Node** top) {
    if (*top == nullptr) {
        cout << "Stack underflow\n";
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
}

// Buatlah program yang menggunakan konsep Stack. Data yang digunakan adalah data Laptop (processor, ram, storage). Utamakan untuk membuat program yang efisien seperti di modul yang kalian pelajari
// SALAH

#include <iostream>
#include <string>
using namespace std;

// Struktur data Laptop
struct Laptop {
    string processor;
    int ram;
    int storage;
};

// Konstanta ukuran maksimum stack
const int MAX = 5;

// Stack dan variabel top
Laptop stackLaptop[MAX];
int top = -1;

// Mengecek apakah stack penuh
bool isFull() {
    return top == MAX - 1;
}

// Mengecek apakah stack kosong
bool isEmpty() {
    return top == -1;
}

// Menambahkan data ke stack (push)
void push(Laptop data) {
    if (isFull()) {
        cout << "Stack penuh! Tidak bisa menambahkan data lagi.\n";
        return;
    }
    top++;
    stackLaptop[top] = data;
    cout << "Data laptop berhasil ditambahkan ke stack.\n";
}

// Menghapus data dari stack (pop)
void pop() {
    if (isEmpty()) {
        cout << "Stack kosong! Tidak ada data untuk dihapus.\n";
        return;
    }
    cout << "Menghapus data laptop dengan processor: " 
         << stackLaptop[top].processor << endl;
    top--;
}

// Menampilkan isi stack
void display() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "\n=== Data Laptop di Stack ===\n";
    for (int i = top; i >= 0; i--) {
        cout << "Laptop ke-" << i + 1 << endl;
        cout << "Processor : " << stackLaptop[i].processor << endl;
        cout << "RAM        : " << stackLaptop[i].ram << " GB" << endl;
        cout << "Storage    : " << stackLaptop[i].storage << " GB\n";
        cout << "-----------------------------\n";
    }
}

int main() {
    int pilihan;
    Laptop data;

    do {
        cout << "\n=== MENU STACK LAPTOP ===\n";
        cout << "1. Tambah Data (Push)\n";
        cout << "2. Hapus Data (Pop)\n";
        cout << "3. Tampilkan Data (Display)\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan data laptop:\n";
                cout << "Processor : ";
                cin >> data.processor;
                cout << "RAM (GB)  : ";
                cin >> data.ram;
                cout << "Storage (GB): ";
                cin >> data.storage;
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}

// CIRCULAR LINKED LIST
// Lengkapi kode Circular Single Linked List, yaitu operasi delete last berikut:

// void deleteLast(Node *&head)
// {
//     if (____)
//     {
//         cout << "Linked List Kosong" << endl;
//         return;
//     }

//     if (head->___ == head)
//     {
//         delete head;
//         head = nullptr;
//         cout << "Berhasil hapus" << endl;
//         return;
//     }

//     Node *temp = ___;
//     while (___->next->next != head)
//     {
//         temp = temp->___;
//     }

//     Node *lastNode = temp->next;
//     temp->next = head;
//     delete __;
//     cout << "Berhasil hapus" << endl;
// }

void deleteLast(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Linked List Kosong" << endl;
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        cout << "Berhasil hapus" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    Node *lastNode = temp->next;
    temp->next = head;
    delete lastNode;
    cout << "Berhasil hapus" << endl;
}