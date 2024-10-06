#include <iostream>
#include <string>
using namespace std;

struct AlatMusik {
    string nama;
    string kategori;
    float harga;
    string asalNegara;
    int stok;
    AlatMusik* next;
};

AlatMusik* head = nullptr;

class Stack {
private:
    AlatMusik* top;

public:
    Stack() : top(nullptr) {}

    void push(AlatMusik* alat) {
        alat->next = top;
        top = alat;
        cout << "Alat musik " << alat->nama << " berhasil ditambahkan ke Stack!" << endl;
    }

    AlatMusik* pop() {
        if (top == nullptr) {
            cout << "Stack kosong!" << endl;
            return nullptr;
        }
        AlatMusik* temp = top;
        top = top->next;
        cout << "Alat musik " << temp->nama << " berhasil dihapus dari Stack!" << endl;
        return temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack kosong!" << endl;
            return;
        }
        AlatMusik* temp = top;
        cout << "Isi Stack: " << endl;
        while (temp != nullptr) {
            cout << "- " << temp->nama << endl;
            temp = temp->next;
        }
    }
};

class Queue {
private:
    AlatMusik* front;
    AlatMusik* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(AlatMusik* alat) {
        alat->next = nullptr;
        if (rear == nullptr) {
            front = rear = alat;
        } else {
            rear->next = alat;
            rear = alat;
        }
        cout << "Alat musik " << alat->nama << " berhasil ditambahkan ke Queue!" << endl;
    }

    AlatMusik* dequeue() {
        if (front == nullptr) {
            cout << "Queue kosong!" << endl;
            return nullptr;
        }
        AlatMusik* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "Alat musik " << temp->nama << " berhasil dihapus dari Queue!" << endl;
        return temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue kosong!" << endl;
            return;
        }
        AlatMusik* temp = front;
        cout << "Isi Queue: " << endl;
        while (temp != nullptr) {
            cout << "- " << temp->nama << endl;
            temp = temp->next;
        }
    }
};

void tambahAlatMusik(string nama, string kategori, float harga, string asalNegara, int stok) {
    AlatMusik* newNode = new AlatMusik;
    newNode->nama = nama;
    newNode->kategori = kategori;
    newNode->harga = harga;
    newNode->asalNegara = asalNegara;
    newNode->stok = stok;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        AlatMusik* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Alat musik berhasil ditambahkan!" << endl;
}

void tampilkanAlatMusik() {
    if (head == nullptr) {
        cout << "Tidak ada alat musik yang terdaftar." << endl;
        return;
    }

    AlatMusik* temp = head;
    int index = 1;
    cout << "Daftar Alat Musik: " << endl;
    while (temp != nullptr) {
        cout << index++ << ". Nama: " << temp->nama
             << ", Kategori: " << temp->kategori
             << ", Harga: " << temp->harga
             << ", Asal Negara: " << temp->asalNegara
             << ", Stok: " << temp->stok << endl;
        temp = temp->next;
    }
}

void updateAlatMusik(int index, string nama, string kategori, float harga, string asalNegara, int stok) {
    AlatMusik* temp = head;
    int count = 1;

    while (temp != nullptr && count < index) {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr && count == index) {
        temp->nama = nama;
        temp->kategori = kategori;
        temp->harga = harga;
        temp->asalNegara = asalNegara;
        temp->stok = stok;
        cout << "Alat musik berhasil diperbarui!" << endl;
    } else {
        cout << "Indeks tidak valid!" << endl;
    }
}

void hapusAlatMusik(int index) {
    if (head == nullptr) {
        cout << "Tidak ada alat musik yang bisa dihapus." << endl;
        return;
    }

    if (index == 1) {
        AlatMusik* temp = head;
        head = head->next;
        delete temp;
        cout << "Alat musik berhasil dihapus!" << endl;
        return;
    }

    AlatMusik* temp = head;
    AlatMusik* prev = nullptr;
    int count = 1;

    while (temp != nullptr && count < index) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp != nullptr && count == index) {
        prev->next = temp->next;
        delete temp;
        cout << "Alat musik berhasil dihapus!" << endl;
    } else {
        cout << "Indeks tidak valid!" << endl;
    }
}

int main() {
    int pilihan;
    Stack stack;
    Queue queue;

    do {
        cout << "\nMenu Manajemen Toko Alat Musik:\n";
        cout << "1. Tambah Alat Musik\n";
        cout << "2. Tampilkan Alat Musik\n";
        cout << "3. Update Alat Musik\n";
        cout << "4. Hapus Alat Musik\n";
        cout << "5. Tambah Alat Musik ke Stack\n";
        cout << "6. Hapus Alat Musik dari Stack\n";
        cout << "7. Tampilkan Stack\n";
        cout << "8. Tambah Alat Musik ke Queue\n";
        cout << "9. Hapus Alat Musik dari Queue\n";
        cout << "10. Tampilkan Queue\n";
        cout << "11. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama, kategori, asalNegara;
                float harga;
                int stok;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                cout << "Masukkan Harga: ";
                cin >> harga;
                cout << "Masukkan Asal Negara: ";
                cin.ignore();
                getline(cin, asalNegara);
                cout << "Masukkan Stok: ";
                cin >> stok;
                tambahAlatMusik(nama, kategori, harga, asalNegara, stok);
                break;
            }
            case 2:
                tampilkanAlatMusik();
                break;
            case 3: {
                int index;
                string nama, kategori, asalNegara;
                float harga;
                int stok;
                cout << "Masukkan indeks alat musik yang akan diupdate: ";
                cin >> index;
                cout << "Masukkan Nama baru: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Kategori baru: ";
                getline(cin, kategori);
                cout << "Masukkan Harga baru: ";
                cin >> harga;
                cout << "Masukkan Asal Negara baru: ";
                cin.ignore();
                getline(cin, asalNegara);
                cout << "Masukkan Stok baru: ";
                cin >> stok;
                updateAlatMusik(index, nama, kategori, harga, asalNegara, stok);
                break;
            }
            case 4: {
                int index;
                cout << "Masukkan indeks alat musik yang akan dihapus: ";
                cin >> index;
                hapusAlatMusik(index);
                break;
            }
            case 5: {
                int index;
                cout << "Masukkan indeks alat musik yang akan ditambahkan ke Stack: ";
                cin >> index;
                AlatMusik* temp = head;
                int count = 1;
                while (temp != nullptr && count < index) {
                    temp = temp->next;
                    count++;
                }
                if (temp != nullptr && count == index) {
                    stack.push(temp);
                } else {
                    cout << "Indeks tidak valid!" << endl;
                }
                break;
            }
            case 6: {
                AlatMusik* alat = stack.pop();
                if (alat != nullptr) {
                    delete alat;
                }
                break;
            }
            case 7:
                stack.display();
                break;
            case 8: {
                int index;
                cout << "Masukkan indeks alat musik yang akan ditambahkan ke Queue: ";
                cin >> index;
                AlatMusik* temp = head;
                int count = 1;
                while (temp != nullptr && count < index) {
                    temp = temp->next;
                    count++;
                }
                if (temp != nullptr && count == index) {
                    queue.enqueue(temp);
                } else {
                    cout << "Indeks tidak valid!" << endl;
                }
                break;
            }
            case 9: {
                AlatMusik* alat = queue.dequeue();
                if (alat != nullptr) {
                    delete alat;
                }
                break;
            }
            case 10:
                queue.display();
                break;
            case 11:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 11);

    while (head != nullptr) {
        hapusAlatMusik(1);
    }

    return 0;
}