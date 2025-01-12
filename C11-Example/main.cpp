#include <iostream>
#include <memory>

class Foo {
public:
    Foo() {
        std::cout << "Ctor Foo\n";
    }
    virtual ~Foo() {
        std::cout << "Dtor Foo\n";
    }
};

int main() {

    auto ptr = std::make_shared<Foo>();


    return 0;
}
