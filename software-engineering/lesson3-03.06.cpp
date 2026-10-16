
// 03.06 (03.16)
// Доработайте ваше предыдущее решение задачи 03.02 таким образом, чтобы реализация использовала иерархию классов геометрических фигур вместо отдельных классов. Реализуйте абстрактный базовый класс Shape для представления интерфейса геометрических фигур. Реализуйте в классе Shape виртуальный деструктор и публичные чисто виртуальные функции вычисления периметра и площади соответственно. Реализуйте производный абстрактный базовый класс Polygon для представления многоугольников, который является наследником интерфейса класса Shape. Реализуйте производные классы Triangle и Rectangle для представления треугольников и прямоугольников соответственно, которые являются наследниками интерфейса класса Polygon. Реализуйте производный класс Square для представления квадратов, который является наследником интерфейса класса Rectangle. Не создавайте в классе Square поле для хранения длины стороны квадрата. Реализуйте в классе Square только пользовательский конструктор, который передает аргументы конструктору класса Rectangle. Используйте спецификатор override при переопределении наследуемых виртуальных функций-членов perimeter и area в классах Circle, Triangle и Rectangle. Используйте спецификатор final для запрета наследования от классов Circle и Square и для переопределения наследуемых виртуальных функций-членов perimeter и area в наследниках классов Circle и Square. Используйте стандартный контейнер std::vector для хранения экземпляров классов Circle, Triangle и Square через указатели на класс Shape. Продемонстрируйте работу динамического полиморфизма.

#include <cmath>
#include <numbers>
#include <print>
#include <vector>

class Shape {
public:
	virtual ~Shape() = default;
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
};

class Circle final : public Shape {
	double r;
public:
	explicit Circle(double r) : r(r) {}
	double perimeter() const final { return 2.0 * std::numbers::pi * r; }
	double area() const final { return std::numbers::pi * r * r; }
};

class Polygon : public Shape {};   //остаётся абстрактным

class Triangle : public Polygon {
	double a, b, c;
public:
	Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
	double perimeter() const override { return a + b + c; }
	double area() const override {   //Герон
		double p = perimeter() / 2.0;
		return std::sqrt(p * (p - a) * (p - b) * (p - c));
	}
};

class Rectangle : public Polygon {
	double w, h;
public:
	Rectangle(double w, double h) : w(w), h(h) {}
	double perimeter() const override { return 2.0 * (w + h); }
	double area() const override { return w * h; }
};

class Square final : public Rectangle {   //без своего поля
public:
	explicit Square(double s) : Rectangle(s, s) {}
	double perimeter() const final { return Rectangle::perimeter(); }
	double area() const final { return Rectangle::area(); }
};

int main() {
	std::vector<Shape*> shapes;
	shapes.push_back(new Circle(1.0));
	shapes.push_back(new Triangle(3.0, 4.0, 5.0));
	shapes.push_back(new Rectangle(2.0, 3.0));
	shapes.push_back(new Square(2.0));

	for (Shape* s : shapes)   //динамический полиморфизм
		std::print("perimeter = {}, area = {}\n", s->perimeter(), s->area());

	for (Shape* s : shapes)
		delete s;   //виртуальный деструктор
	return 0;
}
