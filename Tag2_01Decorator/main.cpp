#include <iostream>
#include "cllient/CalcClient.h"
#include "math/Calculator.h"
#include "math/CalculatorFactory.h"



using Client = client::CalcClient;

int main() {


    math::CalculatorFactory::setLogger(true);
    math::CalculatorFactory::setSecure(true);
    math::CalculatorFactory::setBenchmark(true);
    Client client{math::CalculatorFactory::create()};

    client.go();

    return 0;
}
