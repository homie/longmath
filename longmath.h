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
    longNumber() { idx = 0; number[0] = 0; }
    longNumber(const longNumber &lN) { idx = lN.idx; memcpy(number, lN.number, idx * sizeof(int)); }
    const longNumber& operator= (const longNumber &lN) { if(this != &lN){ idx = lN.idx; memcpy(number, lN.number, idx * sizeof(int)); } return *this; }
    const longNumber& operator+=(const longNumber &lN) { for(int i = 0; i < idx; i++) number[i] = number[i] + lN.number[i]; } //wrong operator implementation
    const longNumber operator+(const longNumber &lN) const { longNumber answer; int max_len = max(idx, lN.idx); memset(answer.number, 0, max_len * sizeof(int)); for(int i = 0; i < max_len; i++) { answer.number[i + 1] = (answer.number[i] + number[i] + lN.number[i]) / 1000; answer.number[i] = (answer.number[i] + number[i] + lN.number[i]) % 1000;} if(answer.number[max_len] == 0) answer.idx = max_len; else answer.idx = max_len + 1; return answer; }
    bool read(const string &st);
    bool write(void);
    int get_index(void) {return idx;}

  private:
	  int number[NUMLIMIT];
	  int idx;
};

#endif
