
// 03.01 ( 03.02 )
// Реализуйте структуру Rectangle для представления прямоугольников со сторонами, которые параллельны осям координатной плоскости. Реализуйте в структуре Rectangle четыре поля типа int для хранения координат левого верхнего и правого нижнего углов прямоугольника. Используйте систему координат, в которой ось абсцисс направлена вправо, а ось ординат — вниз. Реализуйте алгоритм вычисления площади пересечения нескольких прямоугольников. Рассмотрите случаи пустого и вырожденного пересечения прямоугольников. Прямоугольник считается ограничивающим, если он полностью содержит все остальные прямоугольники. Используйте стандартный контейнер std::vector для хранения экземпляров структуры Rectangle.

#include <algorithm>
#include <iostream>
#include <print>
#include <vector>

struct Rectangle {
	int left, top;      //левый верхний угол
	int right, bottom;  //правый нижний угол
};

int main() {
	std::vector<Rectangle> rs;
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		Rectangle r{};
		std::cin >> r.left >> r.top >> r.right >> r.bottom;
		rs.push_back(r);
	}
	if (rs.empty()) {
		std::print("прямоугольников нет\n");
		return 0;
	}

	Rectangle in = rs[0];   //пересечение: левые/верхние побольше, правые/нижние поменьше
	for (const Rectangle& r : rs) {
		in.left = std::max(in.left, r.left);
		in.top = std::max(in.top, r.top);
		in.right = std::min(in.right, r.right);
		in.bottom = std::min(in.bottom, r.bottom);
	}
	if (in.left > in.right || in.top > in.bottom)
		std::print("пересечение пустое\n");
	else if (in.left == in.right || in.top == in.bottom)
		std::print("пересечение вырожденное, площадь 0\n");
	else
		std::print("площадь пересечения = {}\n", (in.right - in.left) * (in.bottom - in.top));

	Rectangle b = rs[0];   //ограничивающий - содержит все остальные
	for (const Rectangle& r : rs) {
		b.left = std::min(b.left, r.left);
		b.top = std::min(b.top, r.top);
		b.right = std::max(b.right, r.right);
		b.bottom = std::max(b.bottom, r.bottom);
	}
	std::print("площадь ограничивающего = {}\n", (b.right - b.left) * (b.bottom - b.top));
	return 0;
}
