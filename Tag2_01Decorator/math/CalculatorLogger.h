//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once

#include <iostream>
#include "Calculator.h"

using Calc = std::unique_ptr<math::Calculator>;
namespace math {

    class CalculatorLogger : public Calculator{

        Calc calculator_;
    public:

        explicit CalculatorLogger(Calc calculator) : calculator_(std::move(calculator)) {}

        ~CalculatorLogger() override = default;

        auto add(double a, double b) -> double override {
            std::cout << "Add wurde gerufen" << std::endl;
            return calculator_->add(a, b);
        }

        auto sub(double a, double b) -> double override {
            return calculator_->sub(a, b);
        }
    };

} // math
