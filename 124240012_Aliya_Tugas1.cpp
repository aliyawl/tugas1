#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Kendaraan {
    string plat;
    string jenis;
    string merk;
    string model;
    string nama;
    int tahun;
};

Kendaraan dataKendaraan[100];
int jumlahKendaraan = 0;

void inputData() {
    if (jumlahKendaraan >= 100) {
        cout << "Data kendaraan penuh!" << endl;
        return;
    }
    cout << "\nINPUT DATA KENDARAAN\n";
    cout << "PLAT    = "; cin >> dataKendaraan[jumlahKendaraan].plat;
    cout << "Jenis Kendaraan (mobil/motor) = "; cin >> dataKendaraan[jumlahKendaraan].jenis;
    cout << "Merk Kendaraan = "; cin >> dataKendaraan[jumlahKendaraan].merk;
    cout << "Model Kendaraan = "; cin >> dataKendaraan[jumlahKendaraan].model;
    cout << "Nama Pemilik = "; cin >> dataKendaraan[jumlahKendaraan].nama;
    cout << "Tahun Produksi = "; cin >> dataKendaraan[jumlahKendaraan].tahun;
    jumlahKendaraan++;
    cout << "Data berhasil ditambahkan!\n";
}

void tampilData() {
    if (jumlahKendaraan == 0) {
        cout << "Tidak ada data kendaraan.\n";
        return;
    }
    cout << "\nDaftar Kendaraan:\n";
    cout << "------------------------------------------------------------------------------------------\n";
    cout << "| No | PLAT        | Jenis          | Merk       | Model      | Pemilik      | Tahun     |\n";
    cout << "------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "| " << setw(2) << (i + 1) << " | "
             << setw(10) << dataKendaraan[i].plat << " | "
             << setw(12) << dataKendaraan[i].jenis << " | "
             << setw(12) << dataKendaraan[i].merk << " | "
             << setw(12) << dataKendaraan[i].model << " | "
             << setw(15) << dataKendaraan[i].nama << " | "
             << setw(5) << dataKendaraan[i].tahun << " |\n";
    }
    cout << "------------------------------------------------------------------------------------------\n";
}

void bubbleSort() {
    for (int i = 0; i < jumlahKendaraan - 1; i++) {
        for (int j = 0; j < jumlahKendaraan - i - 1; j++) {
            if (dataKendaraan[j].tahun > dataKendaraan[j + 1].tahun) {
                swap(dataKendaraan[j], dataKendaraan[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Tahun (Bubble Sort).\n";
}

void quickSort(int low, int high) {
    if (low < high) {
        int pivot = dataKendaraan[high].tahun;
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (dataKendaraan[j].tahun < pivot) {
                i++;
                swap(dataKendaraan[i], dataKendaraan[j]);
            }
        }
        swap(dataKendaraan[i + 1], dataKendaraan[high]);
        int pi = i + 1;
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void cariData() {
    cout << "Pilih metode pencarian:\n";
    cout << "1. Cari berdasarkan Nama Pemilik\n";
    cout << "2. Cari berdasarkan Jenis Kendaraan\n";
    int pilihan;
    cin >> pilihan;
    
    string kunci;
    cout << "Masukkan kata kunci: ";
    cin >> kunci;

    bool found = false;
    for (int i = 0; i < jumlahKendaraan; i++) {
        if ((pilihan == 1 && dataKendaraan[i].nama == kunci) || 
            (pilihan == 2 && dataKendaraan[i].jenis == kunci)) {
            cout << "Data ditemukan!\n";
            cout << "------------------------------------------------------------------------------------------\n";
            cout << "| PLAT        | Jenis          | Merk       | Model      | Pemilik      | Tahun     |\n";
            cout << "------------------------------------------------------------------------------------------\n";
            cout << "| " 
                 << setw(10) << dataKendaraan[i].plat << " | "
                 << setw(12) << dataKendaraan[i].jenis << " | "
                 << setw(12) << dataKendaraan[i].merk << " | "
                 << setw(12) << dataKendaraan[i].model << " | "
                 << setw(15) << dataKendaraan[i].nama << " | "
                 << setw(5) << dataKendaraan[i].tahun << " |\n";
            cout << "------------------------------------------------------------------------------------------\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Data tidak ditemukan!\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n Menu\n";
        cout << "1. Input Data Kendaraan\n";
        cout << "2. Tampilkan Seluruh Data Kendaraan\n";
        cout << "3. Urutkan Data Kendaraan (Bubble Sort)\n";
        cout << "4. Urutkan Data Kendaraan (Quick Sort)\n";
        cout << "5. Cari Data Kendaraan (Sequential Search)\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: inputData(); break;
            case 2: tampilData(); break;
            case 3: bubbleSort(); break;
            case 4: 
                quickSort(0, jumlahKendaraan - 1);
                cout << "Data berhasil diurutkan berdasarkan Tahun (Quick Sort).\n";
                break;
            case 5: cariData(); break;
            case 6: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid! Silakan coba lagi.\n"; break;
        }
    } while (pilihan != 6);
    return 0;
}
