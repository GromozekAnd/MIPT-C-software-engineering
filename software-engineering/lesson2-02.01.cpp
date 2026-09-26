
// 02.01 Реализовать алгоритм вычисления Nго числа Фибоначчи формулой Бине. double для промежуточных вычислений, int для финала получается static_cast. Используй константы для значений d ajhvekt <byt/ используй std::sqrt std::pow std::roubd. В комментарии в коде кратко обоснуй формулу Бине. Используй std::cin для ввода номера N, std::print для вывода, тесты не нужны

#include <cmath>
#include <iostream>
#include <print>

int main() {
	const double sqrt5 = std::sqrt(5.0);
	const double phi = (1.0 + sqrt5) / 2.0;   //золотое сечение 
	const double psi = (1.0 - sqrt5) / 2.0;
	int n = 0;
	std::cin >> n;

	double result = (std::pow(phi, n) - std::pow(psi, n)) / sqrt5; //F(n)=(phi^n-psi^n)/sqrt5, phi,psi корни t^2=t+1
	int fib = static_cast<int>(std::round(result));
	std::print("{}\n", fib);
	return 0;
}
