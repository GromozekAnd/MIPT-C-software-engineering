
// 02.03 реализуй классифицкаию символов типа char ASCII с кодами от 32 до 127 на Заглавные, строчные, десятичные цифры, знаки препинания, прочее. Используй switch с проваливанием и метками типа char в case. default для пятого класса. std::cin для ввода, std::print для вывода, без теста. Протестриуй нестандартные расширения g++ и флаг Wpedantic

#include <iostream>
#include <print>

int main() {
	char ch = '\0';
	std::cin >> ch;

	switch (ch) {
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H':
		case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P':
		case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
		case 'Y': case 'Z':
			std::print("Заглавная буква\n");
			break;
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h':
		case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p':
		case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x':
		case 'y': case 'z':
			std::print("Строчная буква\n");
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			std::print("Десятичная цифра\n");
			break;
		case '!': case '"': case '#': case '$': case '%':
		case '&': case '\'': case '(': case ')': case '*':
		case '+': case ',': case '-': case '.': case '/':
		case ':': case ';': case '<': case '=': case '>':
		case '?': case '@': case '[': case '\\': case ']':
		case '^': case '_': case '`': case '{': case '|':
		case '}': case '~':
			std::print("Знак препинания\n");
			break;
		default:
			std::print("Прочее\n");   //пробел и DEL сюда, std::cin>>ch их не вводит
			break;
	}
	return 0;
}
