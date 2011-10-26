#include "longmath.h"

bool longNumber::read(const string &st)
{
  int len = st.length() - 1;
  int num = 0;

  while(len >= 0){
    int p = 1, counter = 3;
    char ch;

    while(counter > 0 && len >= 0){
      ch = st[len] - '0';
      num = num + ch * p;
      p = p * 10;
      len--;
      counter--;
    }
    number[idx] = num;
    num = 0;
    idx++;
  }

  return true;
}

bool longNumber::write(void)
{
  int p = 100;
  int len = 0;
  int num = number[idx - 1];
  string st;

  while(p != 0){
    int c = 0;
    c = num / p;
    num -= c * p;
    if(c != 0 || len != 0){
      st.push_back(c + '0');
      len++;
    } 
    p /= 10;
  }

  idx -= 2;
  while(idx >= 0){
    int p = 100, counter = 3;
    char c;

    while(counter > 0){
      c = number[idx] / p;
      st.push_back(c + '0');
      number[idx] -= c * p;
      len++; p = p / 10;
      counter--;
    }
    idx--;
  }

  cout << st << endl;

  return true;
}