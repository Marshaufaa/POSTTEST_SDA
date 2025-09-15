
#include <iostream>

void tukarNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int nilai1 = 10;
    int nilai2 = 20;

    std::cout << "Sebelum pertukaran:\n";
    std::cout << "Nilai 1: " << nilai1 << std::endl;
    std::cout << "Nilai 2: " << nilai2 << std::endl;

    tukarNilai(nilai1, nilai2);

    std::cout << "\nSetelah pertukaran:\n";
    std::cout << "Nilai 1: " << nilai1 << std::endl;
    std::cout << "Nilai 2: " << nilai2 << std::endl;

    return 0;
}