
// 03.03 ( 03.05 )
// Реализуйте класс List для представления односвязного списка. Реализуйте структуру Node для представления узлов односвязного списка как приватную вложенную структуру в классе List. Реализуйте в структуре Node два поля: поле типа int для хранения значения текущего узла списка и указатель типа Node * для хранения адреса следующего узла списка. Реализуйте в классе List два приватных указателя типа Node * для хранения адресов первого и последнего узлов списка. Не создавайте в классе List поле для хранения текущего размера списка и пользовательские конструкторы. Реализуйте в классе List публичную функцию‑член empty для проверки наличия хотя бы одного узла в списке. Реализуйте в классе List публичную функцию‑член show для вывода в терминал значений всех текущих узлов списка посредством стандартной функции std::print. Реализуйте в классе List публичные функции‑члены push_front и push_back для вставки новых узлов с пользовательскими значениями в начало и в конец списка соответственно. Используйте оператор new для динамического выделения памяти. Реализуйте в классе List публичные функции‑члены pop_front и pop_back для удаления узлов из начала и из конца списка соответственно. Используйте оператор delete для освобождения памяти. Реализуйте в классе List публичную функцию‑член get для получения значения текущего среднего узла списка. Используйте один цикл для обхода списка в функции‑члене get класса List. Реализуйте в классе List пользовательский деструктор, который корректно освободит память, выделенную при создании узлов списка. Выполните модульное и интеграционное тестирование для всех реализованных функций‑членов класса List.

#include <cassert>
#include <print>

class List {
	struct Node {   //узел списка
		int value;
		Node* next;
	};
	Node* head = nullptr;
	Node* tail = nullptr;

public:
	bool empty() const { return head == nullptr; }

	void show() const {
		std::print("[ ");
		for (Node* p = head; p != nullptr; p = p->next)
			std::print("{} ", p->value);
		std::print("]\n");
	}

	void push_front(int v) {
		head = new Node{v, head};
		if (tail == nullptr) tail = head;
	}

	void push_back(int v) {
		Node* n = new Node{v, nullptr};
		if (empty()) head = tail = n;
		else { tail->next = n; tail = n; }
	}

	void pop_front() {
		Node* n = head;
		head = head->next;
		if (head == nullptr) tail = nullptr;
		delete n;
	}

	void pop_back() {
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}
		Node* n = head;
		while (n->next != tail)   //ищем предпоследний
			n = n->next;
		delete tail;
		tail = n;
		tail->next = nullptr;
	}

	int get() const {   //средний узел одним циклом, медленный/быстрый указатели
		Node* slow = head;
		Node* fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow->value;
	}

	~List() {
		while (!empty())
			pop_front();
	}
};

int main() {
	//модульные тесты
	List l;
	assert(l.empty());
	l.push_front(2);
	assert(!l.empty());
	l.push_front(1);
	l.push_front(0);
	assert(l.get() == 1);   //[0 1 2]
	l.push_back(3);
	l.push_back(4);
	assert(l.get() == 2);   //[0 1 2 3 4]
	l.show();
	l.pop_front();
	assert(l.get() == 3);   //[1 2 3 4]
	l.pop_back();
	assert(l.get() == 2);   //[1 2 3]
	l.pop_back();
	assert(l.get() == 2);   //[1 2], верхний средний
	l.pop_back();
	assert(l.get() == 1);   //[1]
	l.pop_front();
	assert(l.empty());

	{   //деструктор с живыми узлами
		List l3;
		l3.push_back(1);
		l3.push_back(2);
		l3.push_back(3);
	}

	//интеграционный тест
	List l2;
	l2.push_back(10);
	l2.push_front(20);
	l2.push_back(30);
	l2.push_front(40);
	assert(l2.get() == 10);   //[40 20 10 30]
	l2.show();
	l2.pop_front();
	l2.pop_back();
	assert(l2.get() == 10);   //[20 10]
	l2.pop_front();
	l2.pop_back();
	assert(l2.empty());

	std::print("все тесты пройдены\n");
	return 0;
}
