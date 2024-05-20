#include <iostream>
#include <vector>

void quickSort(std::vector<int>& a, int left, int right) {
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    do {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }

        if (i <= j) {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) {
        quickSort(a, left, j);
    }
    if (i < right) {
        quickSort(a, i, right);
    }
}

void printVector(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите размер массива: ";
    int size;
    std::cin >> size;

    std::vector<int> a(size);


    for (int i = 0; i < size; i++) {
        std::cout << "Введите элемент массива: ";
        std::cin >> a[i];
    }

    quickSort(a, 0, size - 1);

    printVector(a);

    return 0;
}
