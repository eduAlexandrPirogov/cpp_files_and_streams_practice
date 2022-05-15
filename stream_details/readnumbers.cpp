#include <iostream>

using namespace std;

int main()
{
   std::cout << "Print some numbers please:) \n";

   int number = -1;

   while (number != 0)
   {
      cin >> number;
      cout << "You've printed number " << number <<'\n';
   };
};
