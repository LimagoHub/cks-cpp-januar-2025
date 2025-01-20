#include <iostream>
#include <functional>


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



};


auto main() -> int
{


    MyClass c;

    


    std::cout << demo()()  << "Hello World!\n";
}