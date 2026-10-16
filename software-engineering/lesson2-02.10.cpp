
// 02.10 ( 02.44 )
// Доработайте пример 02.44 таким образом, чтобы реализация использовала алгоритм быстрой сортировки вместо алгоритма сортировки слиянием. Реализуйте метод Хоара. Используйте медиану первого, среднего и последнего элементов как опорный элемент. Обоснуйте временную сложность данного алгоритма сортировки.

#include <iostream>
#include <print>
#include <utility>
#include <vector>

int partition(std::vector<int>& a, int lo, int hi) {
	int mid = lo + (hi - lo) / 2;
	if (a[mid] < a[lo]) std::swap(a[mid], a[lo]);
	if (a[hi] < a[lo]) std::swap(a[hi], a[lo]);
	if (a[hi] < a[mid]) std::swap(a[hi], a[mid]);
	std::swap(a[lo], a[mid]);   //опорный - медиана из трёх, ставим в начало
	int p = a[lo];
	int i = lo - 1, j = hi + 1;
	while (true) {
		do { ++i; } while (a[i] < p);
		do { --j; } while (a[j] > p);
		if (i >= j) return j;
		std::swap(a[i], a[j]);
	}
}

void quicksort(std::vector<int>& a, int lo, int hi) {
	if (lo >= hi) return;
	int j = partition(a, lo, hi);
	quicksort(a, lo, j);
	quicksort(a, j + 1, hi);
}

// В среднем O(n log n): каждое разбиение O(n), уровней рекурсии ~log n. Худший случай O(n^2),
// если разбиения всё время 1 : (n-1); медиана из трёх убирает самый частый плохой случай
// (уже отсортированный или обратно отсортированный массив). Память O(1) дополнительно.
int main() {
	std::vector<int> a;
	int x;
	while (std::cin >> x)
		a.push_back(x);
	if (!a.empty())
		quicksort(a, 0, static_cast<int>(a.size()) - 1);
	for (int v : a)
		std::print("{} ", v);
	std::print("\n");
	return 0;
}
