#include <iostream>
#include <vector>
#include <chrono>

// Функция для поиска пары различных элементов, сумма которых равна заданному числу
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

// Модифицированная функция для измерения времени выполнения
template<typename Function, typename... Args>
long long measureTime(Function func, Args&&... args) {
    const int repetitions = 1000; // Количество повторений для небольших задач
    bool dummy = false; // Переменная для хранения результата и предотвращения оптимизации

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < repetitions; ++i) {
        // Вызываем функцию и сохраняем результат в переменной dummy для предотвращения оптимизации
        dummy |= func(std::forward<Args>(args)...);
    }
    auto end = std::chrono::high_resolution_clock::now();

    // Используем переменную dummy, чтобы гарантировать, что компилятор не оптимизирует вызов функции
    if (dummy) {
        std::cout << ""; // Это ничего не делает, но использует переменную `dummy` для предотвращения оптимизации
    }

    return std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count() / repetitions;
}

int main() {
    // Вектор размеров данных для тестирования
    std::vector<int> dataSizes = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}; // Измените при необходимости
    for (int size : dataSizes) {
        std::vector<int> arr(size);
        // Заполняем вектор последовательными числами
        for (int i = 0; i < size; ++i) arr[i] = i;

        // Измеряем время выполнения алгоритма полного перебора
        long long time = measureTime(findPairWithSum, arr, size); // Используем сумму, гарантирующую "худший" случай

        std::cout << "Size: " << size << ", Execution Time: " << time << " ns\n";
    }

    return 0;
}

