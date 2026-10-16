
// 03.02 ( 03.04 )
// Реализуйте класс Circle для представления окружностей. Реализуйте в классе Circle приватное поле типа double для хранения радиуса. Реализуйте класс Triangle для представления треугольников. Реализуйте в нём три приватных поля типа double для хранения длин трёх сторон. Реализуйте класс Square для представления квадратов. Реализуйте в классе Square приватное поле типа double для хранения длины одной стороны. Реализуйте в классах Circle, Triangle и Square необходимые пользовательские конструкторы и публичные функции-члены perimeter и area для вычисления периметра и площадей соответственно. Используйте стандартную константу std::numbers::pi в функциях-членах perimeter и area класса Circle.

#include <cmath>
#include <iostream>
#include <numbers>
#include <print>

class Circle {
	double r;
public:
	explicit Circle(double r) : r(r) {}
	double perimeter() const { return 2.0 * std::numbers::pi * r; }
	double area() const { return std::numbers::pi * r * r; }
};

class Triangle {
	double a, b, c;
public:
	Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
	double perimeter() const { return a + b + c; }
	double area() const {   //Герон
		double p = perimeter() / 2.0;
		return std::sqrt(p * (p - a) * (p - b) * (p - c));
	}
};

class Square {
	double s;
public:
	explicit Square(double s) : s(s) {}
	double perimeter() const { return 4.0 * s; }
	double area() const { return s * s; }
};

int main() {
	double r = 0.0, a = 0.0, b = 0.0, c = 0.0, s = 0.0;
	std::cin >> r >> a >> b >> c >> s;
	Circle ci(r);
	Triangle tr(a, b, c);
	Square sq(s);
	std::print("circle: perimeter = {}, area = {}\n", ci.perimeter(), ci.area());
	std::print("triangle: perimeter = {}, area = {}\n", tr.perimeter(), tr.area());
	std::print("square: perimeter = {}, area = {}\n", sq.perimeter(), sq.area());
	return 0;
}
