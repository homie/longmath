#ifndef LONGMATH_CPP
#define LONGMATH_CPP
#include <iostream>
#include <string>
#include <cstring>

#define NUMLIMIT 1000
using namespace std;

class	longNumber
{
  public:
    longNumber() { idx = 0; number[0] = 0; }
    longNumber(const longNumber &lN) { idx = lN.idx; memcpy(number, lN.number, idx * sizeof(int)); }
    const longNumber& operator= (const longNumber &lN) { if(this != &lN){ idx = lN.idx; memcpy(number, lN.number, idx * sizeof(int)); } return *this; }
    const longNumber& operator+=( const longNumber &lN) { for(int i = 0; i < idx; i++) number[i] = number[i] + lN.number[i]; } //wrong operator implementation
    bool read(const string &st);
    bool write(void);
    int get_index(void) {return idx;}

  private:
	  int number[NUMLIMIT];
	  int idx;
};

#endif
