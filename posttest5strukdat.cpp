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

void splitList(AlatMusik* source, AlatMusik** front, AlatMusik** back) {
    AlatMusik* fast = source->next;
    AlatMusik* slow = source;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

AlatMusik* mergeSortedLists(AlatMusik* a, AlatMusik* b) {
    if (!a) return b;
    if (!b) return a;

    AlatMusik* result = nullptr;
    if (a->harga <= b->harga) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }
    return result;
}

void mergeSort(AlatMusik** headRef) {
    AlatMusik* head = *headRef;
    if (head == nullptr || head->next == nullptr) return;

    AlatMusik* front = nullptr;
    AlatMusik* back = nullptr;
    splitList(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = mergeSortedLists(front, back);
}

AlatMusik* getTail(AlatMusik* cur) {
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

AlatMusik* partition(AlatMusik* head, AlatMusik* end, AlatMusik** newHead, AlatMusik** newEnd) {
    AlatMusik* pivot = end;
    AlatMusik* prev = nullptr;
    AlatMusik* cur = head;
    AlatMusik* tail = pivot;

    while (cur != pivot) {
        if (cur->harga >= pivot->harga) {
            if (*newHead == nullptr) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            AlatMusik* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (*newHead == nullptr) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

AlatMusik* quickSortRecur(AlatMusik* head, AlatMusik* end) {
    if (!head || head == end) return head;

    AlatMusik* newHead = nullptr;
    AlatMusik* newEnd = nullptr;

    AlatMusik* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        AlatMusik* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;
        newHead = quickSortRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(AlatMusik** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

void tambahAlatMusik(string nama, string kategori, float harga, string asalNegara, int stok) {
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

int main() {
    int pilihan;
    do {
        cout << "\nMenu Manajemen Toko Alat Musik:\n";
        cout << "1. Tambah Alat Musik\n";
        cout << "2. Tampilkan Alat Musik\n";
        cout << "3. Urutkan (Merge Sort Ascending)\n";
        cout << "4. Urutkan (Quick Sort Descending)\n";
        cout << "5. Keluar\n";
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
            case 3:
                mergeSort(&head);
                cout << "Data diurutkan secara ascending berdasarkan harga!" << endl;
                break;
            case 4:
                quickSort(&head);
                cout << "Data diurutkan secara descending berdasarkan harga!" << endl;
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 5);

    return 0;
}