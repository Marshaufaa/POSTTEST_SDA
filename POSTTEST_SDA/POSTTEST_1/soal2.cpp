#include <iostream>

int main() {
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int baris = 3;
    int kolom = 3;

    int jumlahBarisGenap = 0;

    std::cout << "Matriks 3x3:" << std::endl;
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            std::cout << matriks[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < baris; ++i) {
        if ((i + 1) % 2 == 0) {
            for (int j = 0; j < kolom; ++j) {
                jumlahBarisGenap += matriks[i][j];
            }
        }
    }

    std::cout << "\nJumlah elemen pada baris genap (baris ke-2): " << jumlahBarisGenap << std::endl;

    return 0;
}