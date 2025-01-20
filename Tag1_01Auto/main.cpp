#include <iostream>

[[nodiscard]]
auto sinnseslebes(bool value)->double{

    if(value)
        return 3.14;
    return 3UL;
}

auto main()->int  {



    auto a = sinnseslebes(false);
    auto b = a + 1;
    auto c = a + b;


    return 0;
}
