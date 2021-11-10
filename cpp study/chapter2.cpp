#include <iostream>
using namespace std;

void constEx() {
	int val1, val2, val3 = 5;
	const int num = 10;
	const int* ptr1 = &val1;
	int* const ptr2 = &val2;
	const int* const ptr3 = &val3;
}

void boolEx() {
	if (true) cout << "True!" << endl;
	cout << sizeof(0) << endl; // 4byte
	cout << sizeof(true) << endl; // 1byte
}

void refEx() {
	int num1 = 100;
	int& num2 = num1;
	num2 = 200;
	cout << num1 << endl; // 200
	cout << num2 << endl; // 200

	int arr[3] = { 1, 2, 3 };
	int& ref1 = arr[0]; // 배열 요소는 변수 성향을 지니므로 참조 가능

	int num = 10;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr; // ptr도 변수
	int** (&dpref) = dptr;  // dptr도 변수
	cout << ref << endl; // 10
	cout << *pref << endl; // 10
	cout << **dpref << endl; // 10
}

// Call-by-value
void SwapByValue(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

// Call-by-reference
void SwapByRef(int* ptr1, int* ptr2) {
	int tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

void SwapByRef2(int& ref1, int& ref2) {
	int tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}

int& RefRetFuncOne(int& ref) {
	ref++;
	return ref;
}

int RefRetFuncTwo(int& ref) {
	ref++;
	return ref;
}

void constRef() {
	const int& ref = 30;
}

void newAndDelete() {
	int* ptr1 = new int;
	double* ptr2 = new double;
	int* arr1 = new int[3];
	double* arr2 = new double[10];

	delete ptr1;
	delete ptr2;
	delete[]arr1;
	delete[]arr2;
}

int main(void) {
	int val1 = 10;
	int val2 = 20;
	SwapByRef2(val1, val2);
	cout << val1 << endl; // 20
	cout << val2 << endl; // 10

	/* 반환형 = 참조, 반환 = 참조 */
	int num1 = 1;
	int& num2 = RefRetFuncOne(num1); // 1 -> 2
	num1++; // 2 -> 3
	num2++; // 3 -> 4
	cout << num1 << endl; // 4
	cout << num2 << endl; // 4

	/* 반환형 = 참조, 반환 = 변수 */
	int num3 = 1;
	int num4 = RefRetFuncOne(num3); // 2
	num3 += 1; // 2 -> 3
	num4 += 100; // 2 -> 102
	cout << num3 << endl; // 3
	cout << num4 << endl; // 102

	/* 반환형 = 값 */
	int num5 = 1;
	int num6 = RefRetFuncTwo(num5); // 2
	num5 += 1; // 2 -> 3
	num6 += 100; // 2 -> 102
	cout << num5 << endl; // 3
	cout << num6 << endl; // 102

	return 0;
}