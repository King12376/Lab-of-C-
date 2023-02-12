#include <iostream> 
using namespace std;
 
void decToBinary(int num1);
 
int main() 
{
    int num1;
 
    cout << "Enter a non-negative integer value: ";
    cin >> num1;
   
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
 
void decToBinary( const int num1 )
{
   if( num1 == 0 )
   {
      return;
   }

   decToBinary( num1/2 );
   cout << num1 % 2;
}