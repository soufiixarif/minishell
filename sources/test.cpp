#include <iostream>

class test
{
    protected:
        int m;
    public:
        test(){};
        ~test();
};

class test1:  virtual public test
{
    public:
        test1();
        ~test1();
};

test1::test1()
{
}

test1::~test1()
{
}

test::~test()
{
}
class test2 :  virtual public test
{
    public:
        test2();
        ~test2();
};

test2::test2()
{
}

test2::~test2()
{
}

class x: public test1, public test2
{
    public:
        x();
        ~x();
        void    ht()
        {
            m = 0;
            std::cout << "n : " << m << "\n";
        }
};

x::x()
{
}

x::~x()
{
}

int main()
{
    x xel;
    // xel.m;
    xel.ht();
}
