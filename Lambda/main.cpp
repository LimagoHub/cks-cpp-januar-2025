#include <iostream>
#include <functional>

using IntConsumer = std::function<void(int n)>;
struct MyClass
{
    int* feld;

    MyClass()
    {
        feld = new int[4];
        for(auto i = 0; i < 4; i++)
        {
            feld[i] = i * 10;
        }
    }

    void for_each(IntConsumer consumer) {
        for (int i = 0; i < 4; ++i) {
            consumer(feld[i]);
        }

    }

};

class Summe {
    int sum{0};

public:
    void operator () (int n) {
        sum += n;
    }

    int getSum() const {
        return sum;
    }
};


auto main() -> int
{


    MyClass c;

    Summe s;

    IntConsumer x = s;

    s(1);
    s(10);
    s(100);
    //c.for_each(s);

    std::cout << s.getSum() << std::endl;


}