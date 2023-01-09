#include <iostream>
#include <iomanip>
#include <assert.h>
#include <string>      
#include <sstream>
/*
    Класс Number -- класс положительных больших чисел

    Большое число будет храниться в динамическом массиве data
    Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления
    (так как base = 100)
    По сути, каждый элемент data хранит две цифры числа в десятичной записи

    Значение 100 для системы счисления выбрано как компромис между
    эффективностью и удобством написания программы.
    Если выбрать значения базы 10 - то программа будет не так эффективна по памяти
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
    то алгоритм печати на экран сильно усложнится
    В качестве альтернативы, можно было выбрать базу 1e9, 
    изменив при этом тип элементов c char на int

    capacity - размер массива data
    size - сколько ячеек занимет число в массиве data
    size <= capacity

    Для удобства разряды числа хранятся в обратном порядке
    Например, число 12345678 соответствует массиву
    data = {78, 56, 34, 12}
    (это упрощает многие алгоритмы с такими числами)
*/


class Number 
{
private:
    static const int base = 100;
    std::size_t size;
    std::size_t capacity;
    char* data;

public:
        Number()
    {
        capacity = 1;
        size = 1;
        data = (char*)calloc(capacity, sizeof(char));
        data[0] = 0;
    }

    Number(int capacitya, int sizea)
    {
        capacity = capacitya;
        size = sizea;
        data = (char*)calloc(capacity, sizeof(char));
        data[0] = 0;
    }

    Number(const Number& n)
    {
        size = n.size;
        capacity = n.capacity;
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = n.data[i];
        }
    }
    Number(std::string str)
    {
        int i1 = 0;
        while (str[i1] != 0) {
            i1++;
        }
        capacity = i1 / 2 + i1 % 2;
        size = i1 / 2 + i1 % 2;
        bool dec = true;
        int d, n, num;

        data = new char[capacity];

        for (int i2 = i1 - 1; i2 > -1; --i2) {
            if (dec) {
                d = str[i2] - '0';
                dec = false;
            } else {
                n = str[i2] - '0';
                num = n * 10 + d;
                data[size - 1 - (i2 + 1) / 2] = (char)num;
                dec = true;
            }
        }
        if (!dec) 
            data[size - 1] = d;
    }
    Number(const char* str)
    {
        int i1 = 0;
        while (str[i1] != 0) {
            i1++;
        }
        capacity = i1 / 2 + i1 % 2;
        size = i1 / 2 + i1 % 2;
        bool dec = true;
        int d, n, num;

        data = new char[capacity];

        for (int i2 = i1 - 1; i2 > -1; --i2) {
            if (dec) {
                d = str[i2] - '0';
                dec = false;
            } else {
                n = str[i2] - '0';
                num = n * 10 + d;
                data[size - 1 - (i2 + 1) / 2] = (char)num;
                dec = true;
            }
        }
        if (!dec) 
            data[size - 1] = d;
    }
     Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0) 
            capacity = 1;

        // Выделяем память и записывем число a в массив data
        // Например, число 12345678 представится в виде массива [78, 56, 34, 12]
        
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }
    

    ~Number() 
    {
        delete [] data;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& right);
    Number& operator=(const Number& right) {
        if (capacity < right.capacity) {
            data = (char*)calloc(capacity, sizeof(char));
        }
        capacity = right.capacity;
        size = right.size;

        for (int i1 = 0; i1 < size; i1++) {
            data[i1] = right.data[i1];
        }
        return *this;
    }

    int max(int a, int b) {
        if (a >= b)
            return a;
        return b;
    }

    Number operator+(const Number& right) {
        int max_size = max(size, right.size);
        Number r = Number(max_size + 1, max_size);
        int i1, t_1, t_2, ost = 0;
        for (i1 = 0; i1 < max_size; i1++) {
            if (size > i1) {
                t_1 = data[i1];
            } else {
                t_1 = 0;
            }
            if (right.size > i1) {
                t_2 = right.data[i1];
            } else {
                t_2 = 0;
            }
            r.data[i1] = (t_1 + t_2 + ost) % 100;
            ost = (t_1 + t_2 + ost) / 100;
        }
        if (ost != 0) {
            r.data[i1] = ost;
            r.size++;
        }
        return r;
    }

    Number operator+=(const Number& right) {
        *this = *this + right;
        return *this;
    }

    Number base_mult(int num, int zeros) const{
        Number r = Number(zeros + 1 + size, zeros + size);
        int i1, t_1, ost = 0;
        for (i1 = 0; i1 < size; i1++) {
            t_1 = data[i1];
            r.data[i1 + zeros] = (t_1 * num + ost) % 100;
            ost = (t_1 * num + ost) / 100;
        }
        if (ost != 0) {
            r.data[i1 + zeros] = ost;
            r.size++;
        }
        return r;
    }

    Number div10() {
        std::stringstream ss;
        ss << (*this);
        std::string st = ss.str();
        st = st.substr(0, st.size() - 1);
        return Number(st);
    }

    Number div2() {
        return (*this).base_mult(5, 0).div10();
    }

    bool isEven() {
        return (data[0] % 2 == 0);
    }

Number operator*(const Number& right) { 
    int max_size = max(size, right.size);
    Number r = Number(size + right.size, max_size);
    for (int i1 = 0; i1 < size; i1++) {
        r += right.base_mult(data[i1], i1);
    }
    return r;
}

bool operator>(const Number& right) {
    if (size != right.size)
        return size > right.size;
    int i1 = size - 1;

    while(data[i1] == right.data[i1] && i1 > 0)
        i1--;
    
    return data[i1] > right.data[i1];
}

bool operator==(const Number& right) {
    if (right.size == size) {
        for (int i1 = 0; i1 < size; i1++) {
            if (data[i1] != right.data[i1]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}
}; 


std::ostream& operator<<(std::ostream& stream, const Number& right)
{
    // Печатаем самый большой разряд
    stream << (int)right.data[right.size - 1];
    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw это то же самое, что и в языке C спецификатор %02d
    for (std::size_t i = 0; i < right.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << (int)right.data[right.size - 2 - i];
    return stream;
}


void fib_n(const int n) {
    assert(n > 1);
    Number x = Number("0");
    Number y = Number("1");
    Number z = Number();
    for (int i1 = 0; i1 < n - 1; i1++) {
        z = x + y;
        x = y;
        y = z;
    }
    std::cout << "F(1000) = " << z << std::endl;
}

void factorial(const int n) {
    Number x = Number("1");
    for (int i1 = 1; i1 <= n; i1++) {
        x = x * Number(i1);
    }
    std::cout << n << "! = " << x << std::endl;
}

void grad(const Number n) {
    Number iter = n;
    Number maxNumber = Number(1);
    int step = 0;
    Number one = Number(1);
    Number three = Number(3);
    while(!(iter == one)) {
        step++;
        if (iter.isEven()) {
            iter = iter.div2();
        } else {
            iter = iter * three + one;
        }
        if (iter > maxNumber) {
            maxNumber = iter;
        }
    }
    std::cout << "n = " << n << std::endl;
    std::cout << "steps = " << step << " max_num = " << maxNumber << std::endl;
}
int main() 
{
    fib_n(1000);
    factorial(1000);
    grad(Number(7));
    grad(Number(256));
    grad(Number("1117065"));
    grad(Number("4761963248413673697"));
}