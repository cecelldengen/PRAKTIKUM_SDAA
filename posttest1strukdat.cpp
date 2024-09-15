#include <iostream>
using namespace std;

// Fungsi rekursif untuk memindahkan piringan dari menara asal ke menara tujuan
// dengan menggunakan menara sementara sebagai perantara.
void pindahkanPiringan(int jumlah_piringan, char menara_asal, char menara_tujuan, char menara_sementara) {
    // Basis Kasus:
    // Jika hanya ada satu piringan, pindahkan langsung dari menara asal ke menara tujuan.
    if (jumlah_piringan == 1) {
        cout << "Pindahkan piringan 1 dari " << menara_asal << " ke " << menara_tujuan << endl;
        return;
    }
    
    // Langkah Rekursif:
    // 1. Pindahkan n-1 piringan dari menara asal ke menara sementara.
    // Menara tujuan berfungsi sebagai penyangga.
    pindahkanPiringan(jumlah_piringan - 1, menara_asal, menara_sementara, menara_tujuan);
    
    // 2. Pindahkan piringan terbesar (yang sekarang berada di menara asal) ke menara tujuan.
    cout << "Pindahkan piringan " << jumlah_piringan << " dari " << menara_asal << " ke " << menara_tujuan << endl;
    
    // 3. Pindahkan n-1 piringan dari menara sementara ke menara tujuan.
    // Menara asal berfungsi sebagai penyangga.
    pindahkanPiringan(jumlah_piringan - 1, menara_sementara, menara_tujuan, menara_asal);
}

// Fungsi utama program
int main() {
    // Jumlah piringan yang ingin dipindahkan
    int jumlah_piringan = 3;
    
    // Menara asal (A), menara tujuan (C), dan menara sementara (B)
    char menara_asal = 'A';
    char menara_tujuan = 'C';
    char menara_sementara = 'B';
    
    // Memanggil fungsi untuk memindahkan piringan dari menara asal ke menara tujuan
    pindahkanPiringan(jumlah_piringan, menara_asal, menara_tujuan, menara_sementara);
    
    return 0;
}