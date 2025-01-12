#include <iostream>
auto return_two_args() {
    return std::tuple(1.0, 2);
}
int main() {

    auto [a, b] = return_two_args();

    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}
