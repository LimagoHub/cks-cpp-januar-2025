#include <iostream>
#include <functional>

typedef int(*MyPtrType)(int, int);

auto add(int a, int b)-> long {
    return a + b;
}

auto sub(int a, int b)-> long {
    return add(a , -b);
}

auto xyz()-> std::function<long(int,int)> {
    int z =10;

    //MyPtrType x = add;
    std::function<long(int,int)> x = [&](int a, int b)->long{return (a + z) * b;};

    return x;
}

int main() {

    auto a = xyz()(1,3);
    std::cout << a << std::endl;
}

