#include <iostream>

void balikArray(int* arr, int ukuran) {
    int* awal = arr;
    int* akhir = arr + ukuran - 1;
    int temp;

    
    while (awal < akhir) {
        temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}


void tampilkanArray(int* arr, int ukuran) {
    for (int i = 0; i < ukuran; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int UKURAN_ARRAY = 7;
    int data[UKURAN_ARRAY] = {2, 3, 5, 7, 11, 13, 17};

    std::cout << "Array sebelum dibalik: ";
    tampilkanArray(data, UKURAN_ARRAY);

    balikArray(data, UKURAN_ARRAY);

    std::cout << "Array setelah dibalik: ";
    tampilkanArray(data, UKURAN_ARRAY);

    return 0;
}