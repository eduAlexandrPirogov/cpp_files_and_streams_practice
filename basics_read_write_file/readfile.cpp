#include <iostream>
#include <fstream>
#include <string>

int main()
{
   //Open file input stream to read file
   std::ifstream ifile("test.txt");

   //If file not found
   if(!ifile)
   {
      std::cout << "File not found!\n";
      return 1;
   };

   std::string word;
   //while we're getting words like using cin...
   while(ifile >> word)
      std::cout << word;

   std::cout << "\n Reading file is over\n";
   ifile.close();
   return 0;
};
