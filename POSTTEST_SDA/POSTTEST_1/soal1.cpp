#include <iostream>

void balikArray(int* arr, int ukuran) {
    int* awal = arr;
    int* akhir = arr + ukuran - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

void tampilkanArray(const char* pesan, int* arr, int ukuran) {
    std::cout << pesan << ": ";
    for (int i = 0; i < ukuran; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int data[7] = {2, 3, 5, 7, 11, 13, 17};
    int ukuran = 7;

    tampilkanArray("Array sebelum dibalik", data, ukuran);

    balikArray(data, ukuran);

    tampilkanArray("Array setelah dibalik", data, ukuran);

    return 0;
}