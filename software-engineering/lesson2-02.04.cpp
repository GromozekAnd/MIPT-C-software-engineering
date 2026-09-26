
// 02.04 теперь вычисление всех трехзначных чисел Армстронга. Используй тройной вложенный цикл for для перебора. Не используй std::pow. std::print для вывода, без теста

#include <print>

int main() {
	for (int i = 1; i <= 9; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k <= 9; ++k) {
				int n = i * 100 + j * 10 + k;
				int sum = i * i * i + j * j * j + k * k * k;
				if (sum == n)
					std::print("{}\n", n);   //сумма кубов цифр равна числу
			}
		}
	}
	return 0;
}
