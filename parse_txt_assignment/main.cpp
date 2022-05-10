#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct language
{
   std::string lang;
   std::string designer;
   int date;
};

int main()
{
   //open input filestream
   std::ifstream ifile("language.txt", std::ios::in);
   if(!ifile.is_open())
   {
     std::cout << "File is not found!\n";
     return 1;
   };

   std::vector<std::string> tokens;

   std::string line;
   std::stringstream ss;
   //foreach line
   while(std::getline(ifile, line, '\n'))
   {
      std::string row;
      std::stringstream tmp (line);
      //foreach word devided by space
      while(std::getline(tmp, row, ' '))
      {
         tokens.push_back(row);
      };
   };

   std::vector<language> languages;
   int count = tokens.size();

   for(int i = 0; i < count ; i+=3)
   {
      language* lang = new language();
      lang->lang = tokens[i];
      lang->designer = tokens[i+1];
      lang->date = std::atoi(tokens[i+2].c_str());
      languages.push_back(*lang);
   };

   for(auto& item : languages)
   {
      std::cout << item.lang << ", " << item.designer << ", " << item.date << '\n';
   };
};
