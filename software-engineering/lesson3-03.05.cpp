
// 03.05 (03.15) // H. Sutter, Exceptional C++
// Реализуйте систему раздельного переопределения множественно наследуемых виртуальных функций-членов с одинаковыми сигнатурами и разными реализациями. Реализуйте базовые классы Entity_v1 и Entity_v2. Реализуйте производный класс Client, который является наследником интерфейсов классов Entity_v1 и Entity_v2. Обратите внимание, что раздельное переопределение наследуемых виртуальных функций-членов test в классе Client невозможно из-за совпадения их сигнатур. Реализуйте производные классы Adapter_v1 и Adapter_v2 для представления посредников, которые являются наследниками интерфейсов классов Entity_v1 и Entity_v2 соответственно. Реализуйте производный класс Client, который является наследником интерфейсов классов Adapter_v1 и Adapter_v2. Реализуйте в классах Adapter_v1 и Adapter_v2 виртуальные функции-члены test_v1 и test_v2 соответственно, которые вызываются из переопределяемых наследуемых виртуальных функций-членов test и раздельно переопределяются в классе Client.

#include <print>

class Entity_v1 {
public:
	virtual void test() = 0;
};

class Entity_v2 {
public:
	virtual void test() = 0;
};

// class Client : public Entity_v1, public Entity_v2 {
//     void test() override;  //один test() на оба интерфейса, раздельно переопределить нельзя
// };

class Adapter_v1 : public Entity_v1 {
public:
	void test() override { test_v1(); }
protected:
	virtual void test_v1() = 0;
};

class Adapter_v2 : public Entity_v2 {
public:
	void test() override { test_v2(); }
protected:
	virtual void test_v2() = 0;
};

class Client : public Adapter_v1, public Adapter_v2 {
public:
	void test_v1() override { std::print("Client::test_v1\n"); }
	void test_v2() override { std::print("Client::test_v2\n"); }
};

int main() {
	Client c;
	Entity_v1* e1 = &c;
	Entity_v2* e2 = &c;
	e1->test();   //Client::test_v1
	e2->test();   //Client::test_v2
	return 0;
}
