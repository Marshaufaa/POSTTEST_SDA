#include <iostream>
#include <string>

using namespace std;

const string NIM = "116";

// struct data untuk setiap jadwal penerbangan
struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    JadwalPenerbangan* next;
};

JadwalPenerbangan* head = nullptr;

void tampilkanMenu();
void tambahJadwal();
void sisipkanJadwal();
void hapusJadwalAwal();
void updateStatus();
void tampilkanSemuaJadwal();
string buatKodePenerbangan();
int hitungJumlahNode();
int getPosisiSisip();

int counterKodePenerbangan = 0;

int main() {
    int pilihan;

    do {
        tampilkanMenu();
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambahJadwal();
                break;
            case 2:
                sisipkanJadwal();
                break;
            case 3:
                hapusJadwalAwal();
                break;
            case 4:
                updateStatus();
                break;
            case 5:
                tampilkanSemuaJadwal();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem penerbangan ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 0);

    return 0;
}

// menu
void tampilkanMenu() {
    cout << "+------------------------------------------------------------+" << endl;
    cout << "|                 FLIGHT SCHEDULE SYSTEM                     |" << endl;
    cout << "|              [NAMA ANDA - " << NIM << "]                   |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
    cout << "| 1. Tambah Jadwal Penerbangan                               |" << endl;
    cout << "| 2. Sisipkan Jadwal Penerbangan                             |" << endl;
    cout << "| 3. Hapus Jadwal Paling Awal                                |" << endl;
    cout << "| 4. Update Status Penerbangan                               |" << endl;
    cout << "| 5. Tampilkan Semua Jadwal                                  |" << endl;
    cout << "| 0. Keluar                                                  |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
}

// membuat kode nama penerbangan yg unik
string buatKodePenerbangan() {
    string kodeDasar = "JT-" + NIM;
    if (counterKodePenerbangan == 0) {
        counterKodePenerbangan++;
        return kodeDasar;
    } else {
        return kodeDasar + "-" + to_string(counterKodePenerbangan++);
    }
}

// untuk nambahin jadwal diakhir list
void tambahJadwal() {
    JadwalPenerbangan* baru = new JadwalPenerbangan();
    baru->kodePenerbangan = buatKodePenerbangan();

    cout << "Masukkan Tujuan: ";
    getline(cin, baru->tujuan);
    cout << "Masukkan Status (contoh: Tepat Waktu, Terlambat, Naik Pesawat): ";
    getline(cin, baru->status);

    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        JadwalPenerbangan* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Jadwal berhasil ditambahkan dengan kode: " << baru->kodePenerbangan << endl;
}

// untuk ngitung jumlah node dalam list
int hitungJumlahNode() {
    int count = 0;
    JadwalPenerbangan* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// untuk mendapatkan posisi sisip berdasarkan nim
int getPosisiSisip() {
    int lastDigit = stoi(NIM) % 10;
    if (lastDigit == 0) {
        return 2; // 0 + 2 = 2
    } else {
        return lastDigit + 1;
    }
}

//menyisipkan jadwal
void sisipkanJadwal() {
    int posisiSisip = getPosisiSisip();
    int jumlahNode = hitungJumlahNode();

    if (posisiSisip > jumlahNode + 1 || posisiSisip <= 0) {
        cout << "Posisi sisip tidak valid karena melebihi jumlah jadwal." << endl;
        return;
    }

    JadwalPenerbangan* baru = new JadwalPenerbangan();
    baru->kodePenerbangan = buatKodePenerbangan();

    cout << "Masukkan Tujuan: ";
    getline(cin, baru->tujuan);
    cout << "Masukkan Status (contoh: Tepat Waktu, Terlambat, Naik Pesawat): ";
    getline(cin, baru->status);

    if (posisiSisip == 1) {
        baru->next = head;
        head = baru;
    } else {
        JadwalPenerbangan* temp = head;
        for (int i = 1; i < posisiSisip - 1; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
    }

    cout << "Jadwal berhasil disisipkan di posisi " << posisiSisip << " dengan kode: " << baru->kodePenerbangan << endl;
}

// untuk hapus jadwal paling awal
void hapusJadwalAwal() {
    if (head == nullptr) {
        cout << "Daftar jadwal kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    JadwalPenerbangan* temp = head;
    head = head->next;
    cout << "Jadwal dengan kode " << temp->kodePenerbangan << " berhasil dihapus." << endl;
    delete temp;
}

// untuk perbarui status penerbangan
void updateStatus() {
    if (head == nullptr) {
        cout << "Daftar jadwal kosong." << endl;
        return;
    }

    string kode;
    cout << "Masukkan kode penerbangan yang akan diupdate: ";
    getline(cin, kode);

    JadwalPenerbangan* temp = head;
    while (temp != nullptr && temp->kodePenerbangan != kode) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Kode penerbangan tidak ditemukan." << endl;
    } else {
        string statusBaru;
        cout << "Masukkan status baru: ";
        getline(cin, statusBaru);
        temp->status = statusBaru;
        cout << "Status untuk kode penerbangan " << kode << " berhasil diperbarui." << endl;
    }
}

// untuk tampilkan semua jadwal
void tampilkanSemuaJadwal() {
    if (head == nullptr) {
        cout << "Daftar jadwal kosong." << endl;
        return;
    }

    JadwalPenerbangan* temp = head;
    cout << "=== DAFTAR JADWAL PENERBANGAN ===" << endl;
    while (temp != nullptr) {
        cout << "Kode Penerbangan: " << temp->kodePenerbangan << endl;
        cout << "Tujuan          : " << temp->tujuan << endl;
        cout << "Status          : " << temp->status << endl;
        cout << "-------------------------------" << endl;
        temp = temp->next;
    }
}
