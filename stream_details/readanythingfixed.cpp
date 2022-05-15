#include <fstream>
#include <iostream>

using namespace std;

int main()
{
   cout << "Print some numbers please :)\n";

   int n = -1;
   

   bool reading = true;
   while(reading)
   {
      cin >> n;
      if(cin.good()) // stream read data successfully
      {
         cout << "Good! You printed: " << n << '\n';
         if (n == 0)
	 {
            reading = false;
	 };
      }
      else if (cin.fail()) //stream couldn't read data successfully
      {
	 cout << "Seems like you've printed not a nubmer...\n";
	 cout << "Clearing buffer...\n";
	 cin.clear(); // make stream valid and DOESN\'t change buffer
	 cin.ignore(20, '\n'); // ignore next 20 input characters until newline
			       // actually you can write instead of 20 --> numeric_limits<streamsize>::max() 
      }else
      {
	 cout << "Damn...\n";
	 reading = false;
      }
   };
   cout << "You've printed zero!\n";
   return 0;
};
