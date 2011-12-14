#include "longmath.h"

bool longNumber::read(const string &st)
{
  int len = st.length() - 1;
  int num = 0;

	if(idx != 0){
		memset(number, 0, idx * sizeof(int));
		idx = 0;
	}

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
  int size = idx; 

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

  size -= 2;
  while(size >= 0){
    int p = 100, counter = 3;
    char c;
    int digit = number[size];

    while(counter > 0){
      c = digit / p;
      st.push_back(c + '0');
      digit -= c * p;
      len++; p = p / 10;
      counter--;
    }
    size--;
  }

  cout << st << endl;

  return true;
}

longNumber::longNumber(const longNumber &lN)
{ 
	cout << idx << endl;
	if(idx != 0)
		memset(number, 0, idx * sizeof(int));
	idx = lN.idx; 
	memcpy(number, lN.number, idx * sizeof(int));
}

const longNumber& longNumber::operator= (const longNumber &lN) 
{ 
	if(this != &lN){
		memset(number, 0, idx * sizeof(int));
		idx = lN.idx; 
		memcpy(number, lN.number, idx * sizeof(int)); 
	}
 
	return *this; 
}

const longNumber& longNumber::operator+=(const longNumber &lN)
{
	int maxLen = max(idx, lN.idx);
	for(int i = 0; i < maxLen; i++){
		number[i + 1] += (number[i] + lN.number[i]) / 1000;
		number[i] = (number[i] + lN.number[i]) % 1000;
	}

	if(number[maxLen] == 0)
		idx = maxLen;
	else
		idx = maxLen + 1;
}

const longNumber longNumber::operator+(const longNumber &lN) const
{
	longNumber answer;
	answer = *this;
	answer += lN;
	return answer;
}
