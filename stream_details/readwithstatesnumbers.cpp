#include <iostream>

using namespace std;

int main()
{
   std::cout << "Print some numbers please:) \n";

   int number = -1;

   while (number != 0)
   {
      cin >> number;
      if(cin.good())
      {
         cout << "We've read data successfully! You've printed number " << number << '\n';
      } else if (cin.fail())
      {
         cout << "Fail! We've couldn't read int data correctly...\n";
      } else {
         cout << "Wooops...Somthing bad....\n";
      }
    
   };
};
