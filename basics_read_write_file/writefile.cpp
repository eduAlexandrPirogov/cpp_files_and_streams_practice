#include <iostream>
#include <fstream>
#include <string>

int main()
{
   //Open output file stream to write data to file
   std::ofstream ofile("test.txt");
   //if file is created
   if(!ofile)
   {
      std::cout << "File not found!\n";
      return 1;
   };

   //creating some data
   std::string words[7] = {"hello", "mate", "some", "\n", "here", "random", "words"};
   
   //writing in word to the stream
   for(auto& str : words)
      ofile << str << ", ";

   std::cout << "\n writing file is over\n";
   ofile.close();
   return 0;
};
