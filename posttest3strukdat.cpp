#include <iostream>
#include <string>
using namespace std;

struct AlatMusik {
    string nama;
    string kategori;
    float harga;
    string asalNegara;
    int stok;
    AlatMusik* next; // Pointer to the next node in the list
};

AlatMusik* head = nullptr; // Head of the linked list

// Fungsi untuk menambahkan alat musik baru ke dalam linked list
void tambahAlatMusik(string nama, string kategori, float harga, string asalNegara, int stok) {
    AlatMusik* newNode = new AlatMusik;  // Membuat node baru
    newNode->nama = nama;
    newNode->kategori = kategori;
    newNode->harga = harga;
    newNode->asalNegara = asalNegara;
    newNode->stok = stok;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode; // Jika list kosong, set newNode sebagai head
    } else {
        AlatMusik* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Traverse hingga akhir list
        }
        temp->next = newNode; // Tambahkan node baru di akhir list
    }
    cout << "Alat musik berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua alat musik
void tampilkanAlatMusik() {
    if (head == nullptr) {
        cout << "Tidak ada alat musik yang terdaftar." << endl;
    } else {
        AlatMusik* temp = head;
        int index = 1;
        cout << "Daftar Alat Musik: " << endl;
        while (temp != nullptr) {
            cout << index << ". Nama: " << temp->nama
                 << ", Kategori: " << temp->kategori
                 << ", Harga: " << temp->harga
                 << ", Asal Negara: " << temp->asalNegara
                 << ", Stok: " << temp->stok << endl;
            temp = temp->next;
            index++;
        }
    }
}

// Fungsi untuk mengupdate data alat musik berdasarkan index
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

// Fungsi untuk menghapus alat musik berdasarkan index
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

// Fungsi utama
int main() {
    int pilihan;
    do {
        cout << "\nMenu Manajemen Toko Alat Musik:\n";
        cout << "1. Tambah Alat Musik\n";
        cout << "2. Tampilkan Alat Musik\n";
        cout << "3. Update Alat Musik\n";
        cout << "4. Hapus Alat Musik\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
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
        } else if (pilihan == 2) {
            tampilkanAlatMusik();
        } else if (pilihan == 3) {
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
        } else if (pilihan == 4) {
            int index;
            cout << "Masukkan indeks alat musik yang akan dihapus: ";
            cin >> index;
            hapusAlatMusik(index);
        }
    } while (pilihan != 5);

    return 0;
}