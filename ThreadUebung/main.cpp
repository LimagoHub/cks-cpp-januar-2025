#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

class Demo {
private:
    size_t availableProcessors;
    std::vector<std::thread> threadHolder_;

    auto worker(int id, long time) -> void{
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::cout << "Threa Nr. " << id << " ist fertig" << std::endl;
    }
public:
    Demo() {
        availableProcessors = std::thread::hardware_concurrency();

    }

    auto run() -> void {
        for(size_t i = 0; i < availableProcessors; ++i) {
            threadHolder_.emplace_back(&Demo::worker, this,i, 100);
        }
        for (auto& thread : threadHolder_) {
            thread.join();
        }
    }

};

class schwein
{
private:
    std::string name;
    volatile int gewicht;

    void fressen_impl()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        gewicht++;
    }
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
        std::thread{ [this]() {fressen_impl(); } }.detach();
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

   /* schwein piggy{"Miss Piggy"};
    std::cout << piggy << std::endl;
    piggy.fressen();
    std::cout << piggy << std::endl;
    while(piggy.get_gewicht()< 11);
    std::cout << piggy << std::endl;

    */

   Demo d;
   d.run();
    return 0;
}

