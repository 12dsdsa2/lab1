#include <iostream>
#include <vector>
#include <chrono>

// Функция линейного поиска
bool linearSearch(const std::vector<int>& arr, int target) {
    for (int element : arr) {
        if (element == target) {
            return true;
        }
    }
    return false;
}

// Функция бинарного поиска

bool binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; //деление попопал отрезка 

        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}


// Измерение времени
template<typename Function, typename... Args>
long long measureTime(Function func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

int main() {
    std::vector<int> dataSizes = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 1000000000};
    for (int size : dataSizes) {
        std::vector<int> arr(size);
        // заполнить вектор отсортированными данными
        for (int i = 0; i < size; ++i) arr[i] = i;

        int target = arr.size() / 2; // Target всегда находится в массиве, чтобы избежать наихудших сценариев

        // измререние времени линейного поиска
        long long linearTime = measureTime(linearSearch, arr, target);

        // измеренеи времени бинарного поиска
        long long binaryTime = measureTime(binarySearch, arr, target);

        std::cout << "Size: " << size << ", Linear Search Time: " << linearTime << " ns, Binary Search Time: " << binaryTime << " ns\n";
    }

    return 0;
}
