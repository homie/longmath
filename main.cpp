#include "longmath.h"

int main()
{
#if 0
	string number;
	longNumber foo;
	cout << "Enter a long number:" << endl;
	getline(cin, number);
	foo.read(number);
	foo.write();
  longNumber baz(foo);
  baz.write();
  longNumber bar;

  bar = foo + baz; 

  bar.write();
#endif

  string number = "0";
  longNumber a, b, c;
  a.read(number); 
  c = a;
  number = "1";
  b.read(number); 

  for(int i = 0; i < 110; i++){
    c = a + b;
    a = b;
    b = c;
  }

  c.write();

	return 0;
}
