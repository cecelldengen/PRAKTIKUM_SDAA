#include <iostream>
#include <string>
using namespace std;

struct AlatMusik {
    string nama;
    string kategori;
    float harga;
    string asalNegara;
};

AlatMusik listAlatMusik[100];  // Array untuk menyimpan data alat musik
int jumlahAlatMusik = 0;        // Jumlah alat musik yang terdaftar

// Fungsi untuk menambahkan alat musik baru
void tambahAlatMusik(string nama, string kategori, float harga, string asalNegara) {
    listAlatMusik[jumlahAlatMusik].nama = nama;
    listAlatMusik[jumlahAlatMusik].kategori = kategori;
    listAlatMusik[jumlahAlatMusik].harga = harga;
    listAlatMusik[jumlahAlatMusik].asalNegara = asalNegara;
    jumlahAlatMusik++;
    cout << "Alat musik berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua alat musik
void tampilkanAlatMusik() {
    if (jumlahAlatMusik == 0) {
        cout << "Tidak ada alat musik yang terdaftar." << endl;
    } else {
        cout << "Daftar Alat Musik: " << endl;
        for (int i = 0; i < jumlahAlatMusik; i++) {
            cout << i + 1 << ". Nama: " << listAlatMusik[i].nama
                 << ", Kategori: " << listAlatMusik[i].kategori
                 << ", Harga: " << listAlatMusik[i].harga
                 << ", Asal Negara: " << listAlatMusik[i].asalNegara << endl;
        }
    }
}

// Fungsi untuk mengupdate data alat musik berdasarkan index
void updateAlatMusik(int index, string nama, string kategori, float harga, string asalNegara) {
    if (index >= 0 && index < jumlahAlatMusik) {
        listAlatMusik[index].nama = nama;
        listAlatMusik[index].kategori = kategori;
        listAlatMusik[index].harga = harga;
        listAlatMusik[index].asalNegara = asalNegara;
        cout << "Alat musik berhasil diperbarui!" << endl;
    } else {
        cout << "Indeks tidak valid!" << endl;
    }
}

// Fungsi untuk menghapus alat musik berdasarkan index
void hapusAlatMusik(int index) {
    if (index >= 0 && index < jumlahAlatMusik) {
        for (int i = index; i < jumlahAlatMusik - 1; i++) {
            listAlatMusik[i] = listAlatMusik[i + 1];
        }
        jumlahAlatMusik--;
        cout << "Alat musik berhasil dihapus!" << endl;
    } else {
        cout << "Indeks tidak valid!" << endl;
    }
}

// Fungsi utama
int main() {
    int pilihan;
    do {
        cout << "\nMenu:\n";
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
            tambahAlatMusik(nama, kategori, harga, asalNegara);
        } else if (pilihan == 2) {
            tampilkanAlatMusik();
        } else if (pilihan == 3) {
            int index;
            string nama, kategori, asalNegara;
            float harga;
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
            updateAlatMusik(index - 1, nama, kategori, harga, asalNegara);
        } else if (pilihan == 4) {
            int index;
            cout << "Masukkan indeks alat musik yang akan dihapus: ";
            cin >> index;
            hapusAlatMusik(index - 1);
        }
    } while (pilihan != 5);

    return 0;
}