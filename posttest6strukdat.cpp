#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct AlatMusik {
    string nama;
    string kategori;
    int harga;  // Harga sebagai integer
    string asalNegara;
    int stok;
    AlatMusik* next;
};

AlatMusik* head = nullptr;

// Fungsi menambah data alat musik
void tambahAlatMusik(string nama, string kategori, int harga, string asalNegara, int stok) {
    AlatMusik* newNode = new AlatMusik{nama, kategori, harga, asalNegara, stok, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        AlatMusik* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    cout << "Alat musik berhasil ditambahkan!" << endl;
}

// Fungsi menampilkan semua alat musik
void tampilkanAlatMusik() {
    if (head == nullptr) {
        cout << "Tidak ada alat musik yang terdaftar." << endl;
        return;
    }
    AlatMusik* temp = head;
    cout << "Daftar Alat Musik:" << endl;
    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << ", Harga: " << temp->harga << endl;
        temp = temp->next;
    }
}

// Fungsi menghitung panjang linked list
int getLength(AlatMusik* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

// ====== Fibonacci Search ======
int fibonacciSearch(int target) {
    int size = getLength(head);
    int fib2 = 0, fib1 = 1;  // F(n-2) dan F(n-1)
    int fib = fib2 + fib1;   // F(n)

    while (fib < size) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;
    AlatMusik* temp = head;

    while (fib > 1) {
        int i = min(offset + fib2, size - 1);

        // Akses node ke-i
        AlatMusik* current = head;
        for (int j = 0; j < i; j++)
            current = current->next;

        if (current->harga < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (current->harga > target) {
            fib = fib2;
            fib1 -= fib2;
            fib2 = fib - fib1;
        } else {
            return i;  // Ditemukan
        }
    }

    return -1;  // Tidak ditemukan
}

// ====== Jump Search ======
int jumpSearch(int target) {
    int n = getLength(head);
    int step = sqrt(n);
    AlatMusik* prev = nullptr;
    AlatMusik* temp = head;

    while (temp != nullptr && temp->harga < target) {
        prev = temp;
        for (int i = 0; i < step && temp != nullptr; i++)
            temp = temp->next;
    }

    while (prev != nullptr && prev->harga < target) {
        prev = prev->next;
    }

    if (prev != nullptr && prev->harga == target) {
        return 1;  // Ditemukan
    }

    return -1;  // Tidak ditemukan
}

// ====== Boyer-Moore String Search ======
int boyerMooreSearch(const string& text, const string& pattern) {
    int m = pattern.size();
    int n = text.size();

    if (m > n) return -1;

    int badChar[256];
    fill(begin(badChar), end(badChar), -1);

    for (int i = 0; i < m; i++) {
        badChar[(int)pattern[i]] = i;
    }

    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            return shift;  // Ditemukan
        } else {
            shift += max(1, j - badChar[(int)text[shift + j]]);
        }
    }

    return -1;  // Tidak ditemukan
}

// ====== Menu Utama ======
int main() {
    int pilihan;
    do {
        cout << "\nMenu Manajemen Toko Alat Musik:\n";
        cout << "1. Tambah Alat Musik\n";
        cout << "2. Tampilkan Alat Musik\n";
        cout << "3. Cari Harga (Fibonacci Search)\n";
        cout << "4. Cari Harga (Jump Search)\n";
        cout << "5. Cari Nama (Boyer-Moore Search)\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama, kategori, asalNegara;
                int harga, stok;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                cout << "Masukkan Harga (integer): ";
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
                int harga;
                cout << "Masukkan harga yang dicari: ";
                cin >> harga;
                int result = fibonacciSearch(harga);
                if (result != -1)
                    cout << "Harga ditemukan pada indeks: " << result << endl;
                else
                    cout << "Harga tidak ditemukan." << endl;
                break;
            }
            case 4: {
                int harga;
                cout << "Masukkan harga yang dicari: ";
                cin >> harga;
                int result = jumpSearch(harga);
                if (result != -1)
                    cout << "Harga ditemukan!" << endl;
                else
                    cout << "Harga tidak ditemukan." << endl;
                break;
            }
            case 5: {
                string nama;
                cout << "Masukkan nama alat musik yang dicari: ";
                cin.ignore();
                getline(cin, nama);
                AlatMusik* temp = head;
                bool found = false;
                while (temp != nullptr) {
                    if (boyerMooreSearch(temp->nama, nama) != -1) {
                        cout << "Alat musik ditemukan: " << temp->nama << endl;
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (!found)
                    cout << "Nama alat musik tidak ditemukan." << endl;
                break;
            }
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 6);

    return 0;
}