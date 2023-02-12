#include<iostream>

using namespace std;

int main() {

  int x, y;
  cin>>x;
  y = x;

    //checks if y is even
    if (y > 0) {
      while( y % 2 == 0) {
        y = y / 2;
      }
    }
    //checks if y is a pow of 2
    if (y == 1) 
      cout << "Yes";
    else
      cout << "No";
  

  return 0;
}