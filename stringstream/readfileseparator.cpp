#include <iostream>
#include <fstream>
#include <sstream>

using std::cout, std::ifstream, std::string, std::getline, std::istringstream;

int main()
{
   //creating an input file stream
   ifstream ifile("text2.txt");
   
   //if we can't open the file
   if(!ifile.is_open())
   {
      cout << "Couldn't open the file!\n";
      return -1;
   };

   string line;
   
   //getline -- reading a line into std::string line
   //and add separator
   while(getline(ifile, line, ','))
   {
      //validating
      //// giving a string to instance of std::istringstream
      istringstream str(line);

      string word;
      while(str >> word)
      {
         cout << word << " ";
      };
      cout << '\n';
   };

   return 0;
};
