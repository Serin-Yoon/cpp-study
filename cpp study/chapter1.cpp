#include <iostream>

int def(int a = 1, int b = 2);

int basicInOut(void) {
	char name[100];
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Welcome " << name << std::endl;
	return 0;
}

int overload(int a) {
	return a;
}

int overload(int a, int b) {
	return a + b;
}

inline int SQUARE(int x) {
	return x * x;
}

namespace Space1 {
	void func(void) {
		std::cout << "Space1" << std::endl;
	}
}

namespace Space2 {
	void func(void) {
		std::cout << "Space2" << std::endl;
	}
}

namespace Space3 {
	void func(void);
}

int main(void) {
	basicInOut();
	std::cout << overload(10) << ' ' << overload(10, 20) << std::endl;
	std::cout << def(5) << std::endl;
	std::cout << SQUARE(3) << std::endl;
	Space1::func();
	Space2::func();
	Space3::func();
}

int def(int a, int b) {
	return a + b;
}

void Space3::func(void) {
	std::cout << "Space3" << std::endl;
}