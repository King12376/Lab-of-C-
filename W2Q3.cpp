#include <iostream>

using namespace std ;

  int myXor(int a, int b)
{
    int x = a & ~b;  // bits set in a but not in b
    int y = ~a & b;  // bits set in b but not in a
    int z = x | y;   // bits set in either x or y
    return z;
}

int main()
{
    int a, b ;
    cin >> a >> b ;
    cout << myXor(a, b) ;
    return 0 ;
}

