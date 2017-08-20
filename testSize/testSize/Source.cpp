#include <iostream>
using namespace std;
class A {
public:
	int b;
	char c;
	//virtual void print() {
	//	cout << "this is father¡¯s fuction! " << endl;
	//}
};
class B : A {
public:
	virtual void print() {
		cout << "this is children¡¯s fuction! " << endl;
	}
};
int main(int argc, char * argv[]) {
	//cout << sizeof(A) << "" << sizeof(char) << endl;
	double arr[10] = {0.1,0.2,0.3};
	for (size_t i = 3; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	cout << sizeof(arr) << " " <<sizeof(arr[0]) << endl;
	cout << '\011' << endl;

	int x = 1 + 1 / 2;
	cout << "x: " << x <<endl;
	return 0;
}