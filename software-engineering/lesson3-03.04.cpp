
// 03.04 ( 03.09 )
// Реализуйте систему внешнего тестирования приватных функций‑членов некоторого класса. Реализуйте класс Entity с приватными функциями‑членами test_v1 и test_v2, которые необходимо протестировать. Вспомните о первом принципе SOLID — принципе единственной ответственности. Реализуйте дружественные для класса Entity классы Tester_v1 и Tester_v2 для представления тестировщиков функций‑членов test_v1 и test_v2 класса Entity соответственно, чтобы получить прямой доступ к приватной секции класса Entity и избежать использования публичного интерфейса класса Entity. Используйте паттерн Attorney-Client для ограничения доступа классов Tester_v1 и Tester_v2 к приватной секции класса Entity.

#include <cassert>
#include <print>

class Entity {
private:
	int base_ = 0;
	int test_v1(int x) { return base_ + x; }
	int test_v2(int x) { return base_ * x; }
	//Entity доверяет только адвокатам
	friend class Attorney_v1;
	friend class Attorney_v2;
public:
	explicit Entity(int base) : base_(base) {}
};

class Attorney_v1 {   //пускает Tester_v1 только к test_v1
	static int call_v1(Entity& e, int x) { return e.test_v1(x); }
	friend class Tester_v1;
};

class Attorney_v2 {   //только к test_v2
	static int call_v2(Entity& e, int x) { return e.test_v2(x); }
	friend class Tester_v2;
};

class Tester_v1 {   //отвечает только за test_v1 (принцип единственной ответственности)
public:
	static void test(Entity& e) {
		assert(Attorney_v1::call_v1(e, 5) == 15);
		assert(Attorney_v1::call_v1(e, 0) == 10);
		std::print("Tester_v1 ok\n");
	}
};

class Tester_v2 {
public:
	static void test(Entity& e) {
		assert(Attorney_v2::call_v2(e, 3) == 30);
		assert(Attorney_v2::call_v2(e, 0) == 0);
		std::print("Tester_v2 ok\n");
	}
};

int main() {
	Entity e(10);
	Tester_v1::test(e);
	Tester_v2::test(e);
	return 0;
}
