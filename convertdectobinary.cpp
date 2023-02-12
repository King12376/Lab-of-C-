#include<iostream>
#include <string>

using namespace std;

string decInt (int x) {
  if (x == 0)
    return "0";
  else if (x == 1)
  {
    return "1";
  }
  else
  
    return decInt(x/2) + decInt(x%2);
}

int main() {

  int x;
  cin >> x;

  cout << decInt(x);

  return 0;
}