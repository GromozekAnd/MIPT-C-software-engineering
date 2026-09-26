
// 02.05 вычисление числа пи на основе суммы ряда Лейбница и числа e на основе суммы членов ряда Маклорена при x равном 1 с точностью, заданной числом epsilon. Используй double для промежуточных вычислений и конечных пи и e. Используй while для рядой Лейбница и Маклорена пока очередной член не станет меньше epsilon. Не вычисляй факториалы в знаменатиле членов рядя Маклорена. Используй известное соотношение между членами ряда Маклорена для оптимизации вычисления новых. srd:cin для ввода epsilon, std:print для вывода, без тестов

#include <iostream>
#include <print>

int main() {
	double epsilon = 0.0;
	std::cin >> epsilon;

	double pi4 = 0.0;
	double term = 1.0;
	double denom = 1.0;
	int sign = 1;
	while (term >= epsilon) {   //ряд Лейбница, знак чередуется
		pi4 += sign * term;
		denom += 2.0;
		term = 1.0 / denom;
		sign = -sign;
	}
	double pi = pi4 * 4.0;
	std::print("pi ~ {}\n", pi);

	double e = 1.0;
	double t = 1.0;
	int k = 1;
	while (t >= epsilon) {   //ряд Маклорена, факториал не считаем: t(n)=t(n-1)/n
		t /= static_cast<double>(k);
		e += t;
		++k;
	}
	std::print("e ~ {}\n", e);
	return 0;
}
