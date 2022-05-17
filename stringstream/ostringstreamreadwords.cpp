#include <iostream>
#include <sstream>

using std::cout, std::cin, std::ostringstream, std::string;

int main()
{
   cout << "Input some words please :)\n";

   //creating instance of out string stream
   ostringstream os;
   string word;
   
   while (word != "exit") 
   {
      cin >> word;
      if(word != "exit")
         os << word << " ";
   };
   //str() -- returns copy of stream's string
   string result = os.str();

   cout << result << '\n';
   
   return 0;
};
