#ifndef LONGMATH_CPP
#define LONGMATH_CPP
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define NUMLIMIT 1000
using namespace std;

class	longNumber
{
  public:
    longNumber() { idx = 0; memset(number, 0, NUMLIMIT * sizeof(int)); }
    longNumber(const longNumber &lN); 
    const longNumber& operator= (const longNumber &lN);
    const longNumber& operator+=(const longNumber &lN);
    const longNumber operator+(const longNumber &lN) const; 
    bool read(const string &st);
    bool write(void);
    int get_index(void) {return idx;}

  private:
	  int number[NUMLIMIT];
	  int idx;
};

#endif
