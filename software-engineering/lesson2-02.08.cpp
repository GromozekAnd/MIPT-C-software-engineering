
// 02.08 ( 02.31 ) // M. VanCleave, The Modern C++ Challenge
// Реализуйте алгоритм вычисления наибольшей длины последовательности Коллатца среди всех последовательностей, начинающихся со значений от 1 до 100. Используйте тип unsigned long long int для значений последовательностей Коллатца и стандартный тип std::size_t для их длин. Используйте стандартный контейнер std::vector для кэширования длин последовательностей Коллатца и оптимизации вычисления длин на основе предыдущих последовательностей. Используйте стандартную функцию std::print для вывода в терминал наибольшей длины последовательности Коллатца из рассмотренных, а также значения, с которого она начинается. Не сопровождайте ваше решение данной задачи тестами.

#include <print>
#include <vector>

int main() {
	std::vector<std::size_t> cache(101, 0);   //cache[i] = длина последовательности со старта i
	std::size_t bestLen = 0;
	unsigned long long bestStart = 1;
	for (unsigned long long start = 1; start <= 100; ++start) {
		unsigned long long v = start;
		std::size_t len = 1;
		while (v != 1) {
			if (v <= 100 && cache[v] != 0) {   //уже посчитали раньше
				len += cache[v] - 1;
				break;
			}
			v = (v % 2 == 0) ? v / 2 : 3 * v + 1;
			++len;
		}
		cache[start] = len;
		if (len > bestLen) {
			bestLen = len;
			bestStart = start;
		}
	}
	std::print("start = {}, length = {}\n", bestStart, bestLen);
	return 0;
}
