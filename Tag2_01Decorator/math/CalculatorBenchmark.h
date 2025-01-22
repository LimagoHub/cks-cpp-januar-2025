//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once

#include <chrono>
#include <iostream>
#include <thread>

#include "Calculator.h"

using Calc = std::unique_ptr<math::Calculator>;
using Clock = std::chrono::system_clock;
using namespace std::chrono;
namespace math {

    class CalculatorBenchmark : public Calculator{

        Calc calculator_;
    public:

        explicit CalculatorBenchmark(Calc calculator) : calculator_(std::move(calculator)) {}

        ~CalculatorBenchmark() override = default;

        auto add(double a, double b) -> double override {
            auto start = Clock::now();
            auto result =  calculator_->add(a, b);
            auto end = Clock::now();
            duration<double, std::ratio<1>> dur = duration_cast<milliseconds>(end - start);
            std::cout << "Duration: " << dur.count() << std::endl;
            return result;
        }

        auto sub(double a, double b) -> double override {
            return calculator_->sub(a, b);
        }
    };

} // math