#include <iostream>
#include <vector>
#include <chrono>

// Поиска пары различных элементов, сумма которых равна заданному числу
bool findPairWithSum(const std::vector<int>& arr, int sum) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == sum) {
                return true; // Пара найдена
            }
        }
    }
    return false; // Пара не найдена
}

// Измерение времени
template<typename Function, typename... Args>
long long measureTime(Function func, Args&&... args) {
    const int repetitions = 1000; 
    bool dummy = false; 

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < repetitions; ++i) {

        dummy |= func(std::forward<Args>(args)...);
    }
    auto end = std::chrono::high_resolution_clock::now();

    if (dummy) {
        std::cout << ""; 
    }

    return std::chrono::duration_cast<std::chrono::nanoseconds>((end - start) / repetitions).count();
}





//запуск
int main() {
    // Размеры 
    std::vector<int> dataSizes = {10, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}; 
    for (int size : dataSizes) {
        std::vector<int> arr(size);
        // Заполняем вектор последовательными числами
        for (int i = 0; i < size; ++i) arr[i] = i;

        // Измеряем время выполнения алгоритма 
        long long time = measureTime(findPairWithSum, arr, size - 1); 

        std::cout << "Size: " << size << ", Execution Time: " << time << " ns\n";
    }

    return 0;
}