# std::stringstream

`stringstream` -- класс, позволяющий связать поток ввода-вывода со строкой в памяти и позволяет эту строку эффективно обрабатывать.

Класс `istringstream` позволяет считывать данные в поток.
Класс `ostringstream` позволяет выводить данные из потока.

Для работы с классом требуется добавить `#include <sstream>`
___
Пример программы, которая считывает данные с терминала и затем выводит.

`ostringstreamreadwords.cpp`
```cpp
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
```
___
`stringstream` удобен для преобразования типов:

`formatstringstream.cpp`
```cpp
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
```
___
Поскольку `stringstream` -- поток, то к нему можно применять операторы `<<` и `>>` (в зависимости от того, `istringstream` или `ostringstream`)

`stringstream.str()` возвращает копию `string`, которая хранится внутри `stringstream`. 

Следующая программа считывает файл и обрабатывает те линии строк, длина которых больше 7.

`readfilestringstream.cpp`

```cpp
int main()
{
   //creating an input file stream
   ifstream ifile("text1.txt");
   
   //if we can't open the file
   if(!ifile.is_open())
   {
      cout << "Couldn't open the file!\n";
      return -1;
   };

   string line;
   
   //getline -- reading a line into std::string line
   while(getline(ifile, line))
   {
      //validating
      if(line.size() < 7)  
      {
         cout << "We're not gonna process short lines :) ";
      } else {
	 // giving a string to instance of std::istringstream
         istringstream str(line);

         string word;
         while(str >> word)
         {
            cout << word << ", ";
         };
      }
      cout << '\n';
   };

   return 0;
};
```
___
Метод `getline` считывает линию строки из входящего потока и заносит копию в переменную `line`. При этом, можно добавить третий аргумент, который указывает,
как разделять линии строк, с помощью какого символа.

```cpp
while(getline(ifile, line, ','))
```

