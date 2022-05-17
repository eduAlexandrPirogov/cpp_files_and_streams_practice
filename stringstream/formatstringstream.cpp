#include <iostream>
#include <fstream>
#include <sstream>

using std::cout, std::ifstream, std::string, std::getline, std::stringstream;

int main()
{
   int k = 0;
   double pi = 0.0;
   string tmp = "hello!";

   stringstream ss;

   ss << "100";
   ss >> k;

   ss << "3.14159";
   ss >> pi;

   ss << "string";
   ss >> tmp;

   cout << "int k = " << k << '\n';
   cout << "double pi = " << pi << '\n';
   cout << "string tmp = " << tmp << '\n';
};
