#include <iostream>
#include "Stapel.h"


#define MAX(a,b) a>b?a:b
template<class HERBERT>
inline HERBERT max(HERBERT a, HERBERT b) {
    static_assert(std::is_arithmetic<HERBERT>::value, "Not an arithmetic type");
    return a>b?a:b;
};

int main() {

    Stapel<int, 10> s;

    for(int i = 0; i < 10; ++i) {
        if(! s.isFull())
            s.push(i);
    }
    while(! s.isEmpty())
        std::cout << s.pop() << std::endl;

   /* int a = 1;
    int b = 2;
    int c = MAX(++a,++b);
    std::cout << c << std::endl;
   c = max(++a,++b);
    std::cout << c << std::endl;
    */
    return 0;
}

