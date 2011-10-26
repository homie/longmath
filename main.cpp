#include "longmath.h"

int main()
{
	string number;
	longNumber foo;
	cout << "Enter a long number:" << endl;
	getline(cin, number);
	foo.read(number);
	foo.write();

	return 0;
}
