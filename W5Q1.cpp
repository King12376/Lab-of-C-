#include <iostream> 
#include <vector> 
#include <cmath>

using namespace std;

int Reverse(int n)  {

  int r = 0; vector<int> num; while(n)  {
  num.push_back(n % 10);
	n /= 10;

 	}

for (int i = 0; i < num.size(); i++)  {

 	r += num[i] * pow(10, num.size()-i-1);

 	}

return r;

}


bool Palindrome(int n)  {

vector<int> num; while(n) {

 	num.push_back(n % 10);
 	n /= 10;

 	}

for (int i = 0; i < num.size() / 2; i++)  {

if(num[i] != num[num.size()-i-1]) return false;

 	}

return true;

}


int main()  {

int n;
cin >> n; while(n--)
 	{

int t = 0, num; cin >> num; while(true) {
  num += Reverse(num);
  t++;

if(Palindrome(num)) break;

 	}

cout << t << " " << num << endl;

 	}

return 0;

}


