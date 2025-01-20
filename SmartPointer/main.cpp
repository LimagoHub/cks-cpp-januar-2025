#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int n = 0) {
        std:: cout << "Ctor" << std::endl;
    }

    virtual ~MyClass() {
        std:: cout << "Dtor" << std::endl;
    }
    auto foo() -> void {
        std:: cout << "foo" << std::endl;
    }
};

[[nodiscard]]
auto source() -> std::unique_ptr<MyClass> {
    auto result = std::make_unique<MyClass>();
    return result;
}

auto sink(std::unique_ptr<MyClass> otto) {
    otto->foo();

}

int main() {

    std::unique_ptr<MyClass> myPtr = source();

    sink(std::move(myPtr));



    std::cout <<"Ende" << std::endl;
    return 0;
}

