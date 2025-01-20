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

//using MyClassPointer = std::shared_ptr<MyClass>;

int main() {

    /*
    //std::shared_ptr<MyClass> myPtr = std::shared_ptr<MyClass>(new MyClass{5}) ;
    auto myPtr = std::make_shared<MyClass>(5);

    std::cout << myPtr.use_count() << std::endl;
    {
        std::shared_ptr<MyClass> otherPtr = myPtr;
        std::cout << myPtr.use_count() << std::endl;
    }
    std::cout << myPtr.use_count() << std::endl;
    myPtr->foo();
    */

    //std::unique_ptr<MyClass> myPtr = std::unique_ptr<MyClass>(new MyClass);
    auto myPtr = std::make_unique<MyClass>();
    {
        auto otherPtr = std::move(myPtr);
    }
    myPtr->foo();
    std::cout <<"Ende" << std::endl;
    return 0;
}

