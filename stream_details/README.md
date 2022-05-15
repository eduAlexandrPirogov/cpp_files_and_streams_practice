
# Good, fail, bad...

Рассмотрим следующий пример. Допустим мы хотим считать целочисленные числа с консоли:

```cpp
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
```

Мы считываем целочисленные типы с консоли, пока не получим `0`. Но если мы введем `q`, `252525252525252525252525`, '1.2', то есть **не целочисленный тип**,  программа уйдет в бесконечный цикл или завершится непременно.

У потока (stream) имеются следующие состояния
1. bool good() -- возвращает true, если считал данные успешно
2. bool fail() -- возвращает true, если не смогу считать данные
3. bool bad() -- возвращает true,случилось что-то совсем плохое...

Изменим существующий пример `readnumber.cpp`:

`readwithstatesnumber.cpp`

```cpp
int main()
{
   std::cout << "Print some numbers please:) \n";

   int number = -1;

   while (number != 0)
   {
      cin >> number;
      if(cin.good())
      {
         cout << "We've read data successfully! You've printed number " << number << '\n';
      } else if (cin.fail())
      {
         cout << "Fail! We've couldn't read int data correctly...\n";
      } else {
         cout << "Wooops...Somthing bad....\n";
      }
    
   };
};
```

При вводе 1, 2, 3, 'q' получим следующее:
```
We've read data successfully! You've printed number 1
We've read data successfully! You've printed number 2
We've read data successfully! You've printed number 3
Fail! We've couldn't read int data correctly...
```

## Создадим программу, чтобы она считывала любые символы с терминала

```cpp
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
```

Работает следующим образом. Считваем введенный симвов с терминала. Если считали успешно `(cin.good() == true)` -- выводим в терминал, что все отлично :)
Если напечатали дробное число, букву, слово или символ -- выводим, что ввели не числа. При этом обратим внимание на следующие вещи:
1. `cin.clear()` -- метод возвращает поток в валидное состояние, но **не освобождает буфер**. Об этом в другой части.
2. `cin.ignore(20, '\n')` -- метод, игнорирующий введенные следующий символы. Первый параметр говорит, сколько следующий символов игнорировать. Второй -- до какого спец-символа. Для удобства, первый параметр можно заменить на `numeric_limits<streamsize>::max()`.
