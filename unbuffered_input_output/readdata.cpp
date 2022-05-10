#include <iostream>
#include <fstream>

int main()
{
   const int filesize = 10;
   char filebuf[filesize];
   std::string filename{"text.txt"};

   std::ifstream ifile(filename);

   if(!ifile)
   {
      std::cout << "Could not open file!\n";
      return -1;
   };

   ifile.read(filebuf, filesize);

   //get count of received bytes
   auto nread = ifile.gcount(); 
   //ifile.close();

   std::cout << "Read " << nread << " bytes \n";
   std::cout.write(filebuf, nread);
   std::cout << '\n';

   //read file second time
   ifile.read(filebuf, filesize);
   nread = ifile.gcount();
   
   std::cout << "Read second time " << nread << " bytes \n";
   std::cout.write(filebuf, nread);

   std::cout << '\n';
   return 0;
};
