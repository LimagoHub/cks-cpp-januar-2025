#include <chrono>
#include <iostream>
#include <random>
#include <thread>

void MyFunc(std::string message)
{
	std::random_device rn;
	std::mt19937 engine{ rn() };
	std::uniform_int_distribution<int> dice{ 0, 1000 };

	for(int i = 0; i < 10; i ++)
	{
    	std::cout << message << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(dice(engine)));
	}



}
void foo() {
    std::thread bar{[](){
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }};
    bar.detach();
}
int main() {

    foo();

    /*MyFunc("Wau");
    MyFunc("Miau");
    MyFunc("Piep");*/

    /*std::thread hund {MyFunc, "Wau"};
    std::thread katze {MyFunc, "Miau"};

    katze.join();
    std::thread maus {MyFunc, "Piep"};

    hund.join();
    maus.join();
     */
    std::cout << "Programmende" << std::endl;
    return 0;
}

