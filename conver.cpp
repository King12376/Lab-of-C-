#include <iostream> 
#include <string>

using namespace std;
 
string decToBinary(int num1);
 
int main() 
{
    int num1;
 
    cout << "Enter a non-negative integer value: ";
    cin >> num1;

  if (num1 == 0)
    cout << 0;
   
	if (num1 < 0)
	{
	cout << endl << "Invalid Entry." << endl << endl;
	}
	else 
	{
        cout << endl << "Decimal " << num1 << " = ";
        decToBinary(num1);
        cout << endl << endl;
        }

	return 0;
}
 
string decToBinary( int num1 )
{
   if( num1 == 0 )
   {
      return "0";
   }

   decToBinary( num1/2 );
   cout << num1 % 2;
}