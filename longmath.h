#ifndef LONGMATH_CPP
#define LONGMATH_CPP
#include <iostream>
#include <string>

#define NUMLIMIT 1000
using namespace std;

class	longNumber
{
  public:
    longNumber() { idx = 0; number[0] = 0; cout << "longNumber object was created" << endl; }
    bool read(const string &st);
    bool write(void);

  private:
	  int number[NUMLIMIT];
	  int idx;
};

#endif
