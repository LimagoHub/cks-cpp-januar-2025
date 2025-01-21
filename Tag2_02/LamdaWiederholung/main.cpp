#include <iostream>
#include <functional>
#include <string>

auto ausgabe(std::string message)->void {
    std::cout << message << std::endl;
}
class XYZ {
public:
    virtual const int foo(double x) const noexcept{

    }

    virtual auto bar(double x) const noexcept -> const int {

    }
};

class XYZChild : public XYZ {
public:
    const int foo(double x) const noexcept final {
        return XYZ::foo(x);
    }

    auto bar(double x) const noexcept -> const int override {
        return XYZ::bar(x);
    }
};

int main() {

    int sinnlos = 5;
    std::function<void(std::string)> fptr = ausgabe;
    auto fptr1 = ausgabe;
    std::function<void(std::string)> fptr2 = [peter=sinnlos](std::string text)->void {
        std::cout << text << peter << std::endl;
    };
    sinnlos = 100;
    auto fptr3 = [](std::string text)->void {
        std::cout << text << std::endl;
    };

    fptr2("Hallo");

    return 0;
}

