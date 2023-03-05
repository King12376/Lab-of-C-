#include <iostream>
#include <string>
using namespace std;

int main() {
  string text;
  string substr;

  cin >> text;
  cin >> substr;

  auto isFound = text.find(substr);
  if (isFound != string::npos) {
    cout << "Yes";
  }
  else
  cout << "No" <<endl;

  return 0;
}