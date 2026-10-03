
// 02.07 ( 02.30 )
// Доработайте ваше предыдущее решение задачи 02.06 таким образом, чтобы реализация использовала встроенный динамический массив вместо встроенного статического массива. Предполагайте, что размер коллекции чисел неизвестен. Реализуйте алгоритм увеличения емкости встроенного динамического массива в процессе его использования. Реализуйте выделение нового блока памяти размером в два раза больше предыдущего, копирование всех данных из предыдущего блока памяти в новый и освобождение предыдущего блока памяти.

#include <cmath>
#include <iostream>
#include <print>

int main() {
	std::size_t cap = 1;
	std::size_t n = 0;
	double* a = new double[cap];

	double x;
	while (std::cin >> x) {
		if (n == cap) {   //ёмкости не хватает - удваиваем
			double* b = new double[cap * 2];
			for (std::size_t i = 0; i < n; ++i)
				b[i] = a[i];
			delete[] a;
			a = b;
			cap *= 2;
		}
		a[n++] = x;
	}
	if (n == 0) return 0;

	for (std::size_t i = 0; i < n - 1; ++i)
		for (std::size_t j = 0; j < n - 1 - i; ++j)
			if (a[j] > a[j + 1]) { double t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }

	double min = a[0];
	double max = a[n - 1];
	double median = (n % 2) ? a[n / 2] : (a[n / 2 - 1] + a[n / 2]) / 2.0;

	double sum = 0.0;
	for (std::size_t i = 0; i < n; ++i)
		sum += a[i];
	double mean = sum / n;

	double s2 = 0.0;
	for (std::size_t i = 0; i < n; ++i)
		s2 += (a[i] - mean) * (a[i] - mean);
	double stddev = std::sqrt(s2 / n);

	std::print("min = {}\nmax = {}\nmedian = {}\nmean = {}\nstddev = {}\n", min, max, median, mean, stddev);
	delete[] a;
	return 0;
}
