#include <iostream>
#include<string>
using namespace std;


int main() {

  string roman;
  int interger;
  int piece;

  cin>>interger;

  if ((interger >= 4000) || (interger <= 0)) {
    cout<<"Invalid";
  }
  else {
//1000s
    if (interger >= 1000) {
        piece = (interger / 1000);

      for (int i = 0; i < piece; i++) {
        roman += 'M';  
    }
      interger %= 1000;
   }
      //100s
          if (interger >= 100) {
            piece =(interger / 100);

            if (piece == 9) {
              roman += "CM";
            }
            else if (piece >= 5) {
              roman += 'D';

              for (int i = 0; i < piece -5; i++) {
                roman += 'C'; 
              }

            }
          else if (piece == 4) {
                roman += "CD";
          }
          else if (piece >= 1 ) {

            for (int i =0; i < piece; i++) {
                roman += 'C';
            }
          }
          interger %= 100;
          }
            //10s
              if (interger >= 10) {
                piece = (interger / 10);

                if (piece == 9) {
                  roman += "XC";
                }
                else if (piece >= 5) {
                  roman += 'L';

                  for (int i = 0; i < piece -5; i++) {
                    roman += 'X';
                  }

                }
              else if (piece == 4) {
                  roman += "XL";
              } 
                else if (piece >= 1) {

                  for (int i =0; i < piece; i++) {
                        roman += 'X'; 
                  }
                }
                interger %= 10;
              } 
    //1s
    if (interger >= 1) {
      piece = interger;

      if (piece == 9) {
        roman += "IX";
      }
      else if (piece >= 5) {
        roman += "V";

        for (int i = 0; i < piece -5; i++) {
          roman += 'I';
      }
    }
    else if (piece == 4) {
      roman += "IV";
    }
    else if (piece >= 1) {

      for (int i =0; i < piece; i++) {
          roman += 'I';
    }
    }
    cout << roman <<endl;
  }
  }
  return 0;
}