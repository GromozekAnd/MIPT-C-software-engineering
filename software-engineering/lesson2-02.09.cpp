
// 02.09 ( 02.43 ) // M. VanCleave, The Modern C++ Challenge
// Реализуйте алгоритмы вычисления наибольшего общего делителя двух натуральных чисел типа int на основе рекурсивного и итерационного подходов, а также алгоритм вычисления наименьшего общего кратного двух натуральных чисел типа int. Используйте стандартные функции std::gcd и std::lcm для валидации результатов.

#include <iostream>
#include <numeric>
#include <print>

int gcdRec(int a, int b) { return b == 0 ? a : gcdRec(b, a % b); }

int gcdIter(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int lcmOwn(int a, int b) { return a / gcdRec(a, b) * b; }

int main() {
	int a = 0, b = 0;
	std::cin >> a >> b;
	std::print("gcd(рекурсивный) = {}\ngcd(итерационный) = {}\nlcm = {}\n", gcdRec(a, b), gcdIter(a, b), lcmOwn(a, b));
	std::print("std::gcd = {}\nstd::lcm = {}\n", std::gcd(a, b), std::lcm(a, b)); //должно совпасть
	return 0;
}
