import matplotlib.pyplot as plt


file_path = '/points (1).txt'

# Списки для хранения считанных данных
sizes = []
linear_search_times = []
binary_search_times = []

# Чтение данных из файла
with open(file_path, 'r') as file:
    for line in file:
        # Пропуск пустых строк
        if not line.strip():
            continue
        parts = line.split(',')
        sizes.append(int(parts[0].split(':')[1].strip()))
        linear_search_times.append(int(parts[1].split(':')[1].strip().split(' ')[0]))
        binary_search_times.append(int(parts[2].split(':')[1].strip().split(' ')[0]))

# Построение графика
plt.figure(figsize=(10, 6))
plt.plot(sizes, linear_search_times, label='Linear Search Time (ns)', marker='o')
plt.plot(sizes, binary_search_times, label='Binary Search Time (ns)', marker='s')
plt.xscale('log')
plt.yscale('log')
plt.title('Search Time Comparison')
plt.xlabel('Array Size')
plt.ylabel('Time (ns)')
plt.legend()
plt.grid(True, which="both", ls="--")
plt.show()
