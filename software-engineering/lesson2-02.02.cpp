
// 02.02 алгоритм вычисления корней алг уравнения второй степени с коэффами a,b,c - double. if для проверки значения a и дискриминанта. Использовать epsilon и std:abs для сравнения double с точностью, допускать отричательный ноль. std::cin для ввода a,b,c std:print для вывода корней в терминал, тесты не нужны

#include <cmath>
#include <iostream>
#include <print>

int main() {
	const double eps = 1e-9;
	double a = 0.0, b = 0.0, c = 0.0;
	std::cin >> a >> b >> c;

	if (std::abs(a) < eps) {
		if (std::abs(b) < eps) {
			if (std::abs(c) < eps)
				std::print("x - любой\n");
			else
				std::print("корней нет\n");
		} else {
			double x = -c / b;   //линейное уравнение
			if (x == 0.0) x = 0.0;
			std::print("линейное уравнение: x = {}\n", x);
		}
		return 0;
	}

	double D = b * b - 4.0 * a * c;   //дискриминант
	if (std::abs(D) < eps) {
		double x = -b / (2.0 * a);
		if (x == 0.0) x = 0.0;
		std::print("один корень кратности два: x = {}\n", x);
	} else if (D > 0.0) {
		double sqrtD = std::sqrt(D);
		double x1 = (-b + sqrtD) / (2.0 * a);
		double x2 = (-b - sqrtD) / (2.0 * a);
		if (x1 == 0.0) x1 = 0.0;
		if (x2 == 0.0) x2 = 0.0;
		std::print("два корня: x1 = {}, x2 = {}\n", x1, x2);
	} else {
		std::print("действительных корней нет\n");
	}
	return 0;
}
