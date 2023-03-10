#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl, std::string;



class Cat
{
private:
    string mname {};
    int mage     {};

public:
    Cat()   {cout << "Cat Default Constructor (" << mname << ")" << endl;}
    ~Cat()  {cout << "Cat Destructor ("          << mname << ")" << endl;}
    Cat(const Cat& c)                : mname(c.mname), mage(c.mage) {cout << "Cat Copy Constructor (" << mname << ")" << endl;}
    Cat(const string& name, int age) : mname(name),    mage(age)    {cout << "Cat Constructor ("      << mname << ")" << endl;}
    void setName(const std::string& name) {mname = name;};
    void say(){cout << "Meow, I am " << mname << endl;}
};



int main()
{
    void* p = malloc(sizeof(Cat));
    Cat* qa = new(p) Cat {"Alice", 10};
    qa->say();
    qa->~Cat();
    free(p);


    char buffer[sizeof(Cat)];
    Cat* qb = new(buffer) Cat {"Bob", 10};
    qb->say();
    qb->~Cat();
}