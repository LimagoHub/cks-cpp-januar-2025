#include <chrono>
#include <iostream>
#include <random>
#include <thread>
class schwein
{
private:
    std::string name;
    volatile int gewicht;


public:
    schwein(std::string name = "Nobody") :name(name), gewicht(10){}

    int get_gewicht()
    {
        return gewicht;
    }

    std::string get_name()
    {
        return name;
    }

    void set_name(std::string name)
    {
        this->name = name;
    }

    void fressen()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        gewicht ++;
    }

    void ausgabe()
    {
        std::cout << "Name: " << name << ", Gewicht: " << gewicht << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }
};

int main() {

    schwein piggy{"Miss Piggy"};
    std::cout << piggy << std::endl;
    piggy.fressen();
    std::cout << piggy << std::endl;
    while(piggy.get_gewicht()< 11);
    std::cout << piggy << std::endl;
    return 0;
}

