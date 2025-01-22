#include <iostream>
#include "list/MyList.h"



int main() {

    container::MyList list;


    std::cout << "Empty: " << list.isEmpty() << ", Bol: " << list.isBol() << ", Eol: " << list.isEol() << std::endl;

    std::cout << list.get().value_or("# kein Treffer. Liste ist leer") << std::endl;


    list.append("Hallo");

    std::cout << "Empty: " << list.isEmpty() << ", Bol: " << list.isBol() << ", Eol: " << list.isEol() << std::endl;
    list.append("Welt");

    list.moveToFirst();

    std::cout << "Empty: " << list.isEmpty() << ", Bol: " << list.isBol() << ", Eol: " << list.isEol() << std::endl;

    std::cout << list.get().value_or("# kein Treffer. Liste ist leer") << std::endl;

    return 0;
}

