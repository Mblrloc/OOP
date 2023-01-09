/*
    На прошлом семинаре мы писали свой класс удобной строки String.
    Для этого класса мы написали множество удобных конструкторов, перегруженных операторов и других методов.
    Таким образом, пользоваться строками стало намного более удобно, чем в языке C, где приходилось для хранения
    строк использовать массивы элементов типа char.


    Но писать свой класс для строки необязательно, ведь в стандартной библиотеке языка C++ уже написан класс для строки.
    А именно строка std::string из библиотеки string.
    Стандартная строка std::string в целом похожа на строку String, которую мы написали на прошлом семинаре.
    Объекты класса std::string также можно удобно складывать, присваивать, сравнивать друг с другом, брать символ по индексу и т. д.
    При этом не нужно заботиться о выделении памяти, так как класс std::string будет автоматически выделять необходимую память.


    std::string также поддерживает операции со строками в стиле C (то есть с объктами типа const char*).
    Это означает, что объектам типа std::string можно присвоить/прибавить строки из языка C.
    В частности, к объектам типа std::string можно присвоить/прибавить строковые литералы.


    !!  Не стоит путать библиотеку string языка C++, которая содержит std::string 
        с библиотекой string.h языка C, которая содержит функции для работы с C-строками,
        такие как strlen, strcpy и другие.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;



int main()
{
    std::string a = "Hello";
    std::string b = "World";

    std::string c = a + " " + b;
    c += "!";

    cout << c << endl;
}

/*
    Задача:

        Напищите программу, которая будет считывать слова (используйте std::cin) в бесконечном цикле и каждый
        раз печатать сумму всех слов. Например, если пользователь ввёл Hello, то программа должна напечатать
        Hello и запросить следующее слово. Если затем пользователь введёт World, то программа должна будет
        напечатать HelloWorld и запросить следуещее слово и так далее.
        Программа должна останавливаться если пользователь ввёл слово "quit".

        Для хранения строки используйте класс std::string
*/