#include <iostream>
using namespace std;

// Deklarasi struktur untuk merepresentasikan barang
struct Barang {
    string nama;
    int stok;
    double harga;
};

int MAX_BARANG = 100; // Jumlah maksimum barang yang dapat disimpan

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "===== APLIKASI MANAJEMEN INVENTARIS TOKO =====\n";
    cout << "1. Tambah Barang" << endl;
    cout << "2. Lihat Barang" << endl;
    cout << "3. Sorting Barang" << endl;
    cout << "4. Keluar" << endl;
}

// Fungsi untuk menambahkan barang ke dalam daftar
void tambahBarang(Barang daftarBarang[], int &jumlahBarang) {
    if (jumlahBarang < MAX_BARANG) {
        cout << "Masukkan Nama Barang: ";
        cin >> daftarBarang[jumlahBarang].nama;
        cout << "Masukkan Stok Barang: ";
        cin >> daftarBarang[jumlahBarang].stok;
        cout << "Masukkan Harga Barang: ";
        cin >> daftarBarang[jumlahBarang].harga;
        jumlahBarang++;
        cout << "Barang berhasil ditambahkan!\n";
    } else {
        cout << "Inventaris penuh. Tidak dapat menambahkan barang lagi.\n";
    }
}

// Fungsi untuk menampilkan daftar barang
void lihatBarang(Barang daftarBarang[], int jumlahBarang) {
    cout << "===== DAFTAR BARANG =====\n";
    for (int i = 0; i < jumlahBarang; i++) {
        cout << "Nama: " << daftarBarang[i].nama << " | Stok: " << daftarBarang[i].stok << " | Harga: " << daftarBarang[i].harga << endl;
    }
}

// Fungsi untuk sorting barang berdasarkan harga (menggunakan bubble sort)
void sortingBarang(Barang daftarBarang[], int jumlahBarang) {
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = 0; j < jumlahBarang - i - 1; j++) {
            if (daftarBarang[j].harga > daftarBarang[j + 1].harga) {
                swap(daftarBarang[j], daftarBarang[j + 1]);
            }
        }
    }
    cout << "Barang berhasil diurutkan berdasarkan harga.\n";
}
int main() {
    Barang daftarBarang[MAX_BARANG];
    int jumlahBarang = 0;

    int pilihan;
    string namaBarang;

    do {
        tampilkanMenu();
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBarang(daftarBarang, jumlahBarang);
                break;
            case 2:
                lihatBarang(daftarBarang, jumlahBarang);
                break;
            case 3:
                sortingBarang(daftarBarang, jumlahBarang);
                break;
            case 4:
                cout << "Terima kasih, keluar dari aplikasi.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}
