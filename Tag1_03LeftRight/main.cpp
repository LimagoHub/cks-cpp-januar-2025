#include <iostream>

auto foo(int &x) -> void {
    x ++;
    std::cout << "LValue: " <<  x << std::endl;
}

auto foo(int &&x) -> void {
    x ++;
    std::cout << "RValue: " <<  x << std::endl;
}

class MyString {

    char * data{nullptr};
    int lenght {0};
public:
    explicit MyString(int lenght) : lenght{lenght} {
        data = new char[lenght];
    }
    virtual ~MyString() {
        delete [] data;
    }
    explicit MyString(const Mystring &other)  {
        lenght = other.lenght;
        data = new char[lenght];
        memcpy(data, other.data, sizeof(char) * lenght);
    }

    const MyString * operator= (const Mystring &other) {
        delete [] data;
        lenght = other.lenght;
        data = new char[lenght];
        memcpy(data, other.data, sizeof(char) * lenght);
        return this;
    }

    explicit MyString(Mystring &&other)  {
        lenght = other.lenght;
        data = other.data;
        other.lenght = 0;
        other.data = nullptr;
    }
    const MyString * operator= (Mystring &&other) {
        delete [] data;
        data = other.data;
        other.lenght = 0;
        other.data = nullptr;
        return this;
    }

};

int main() {




    std::string a = " Hallo";
    std::string b = std::move(a);

    std::cout << "A: " << a << "!" << std::endl;
    std::cout << "B: " << b << "!" << std::endl;

    return 0;
}