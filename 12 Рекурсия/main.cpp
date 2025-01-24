#include <iostream>
#include <vector>
#include <ctime>

void printReverse(int n) {
    if (n < 10) {
        std::cout << n;
        return;
    }
    std::cout << n % 10;
    printReverse(n / 10);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int first() {
    int N;
    std::cout << "Введите натуральное число: ";
    std::cin >> N;
    
    if (N > 0) {
        printReverse(N);
        std::cout << std::endl;
    } else {
        std::cout << "Введите корректное натуральное число." << std::endl;
    }

    return 0;
}

int second() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> arrCopy = arr;

    std::cout << "Исходный массив: ";
    printArray(arr);

    clock_t start = clock();
    quickSort(arr, 0, arr.size() - 1);
    clock_t end = clock();
    std::cout << "Отсортированный массив (быстрая сортировка): ";
    printArray(arr);
    std::cout << "Время быстрой сортировки: " << double(end - start) / CLOCKS_PER_SEC << " секунд." << std::endl;

    start = clock();
    bubbleSort(arrCopy);
    end = clock();
    std::cout << "Отсортированный массив (сортировка обменами): ";
    printArray(arrCopy);
    std::cout << "Время сортировки обменами: " << double(end - start) / CLOCKS_PER_SEC << " секунд." << std::endl;

    return 0;
}

