#include "longmath.h"

int main()
{
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
    c.write();
  }

  return 0;
}
