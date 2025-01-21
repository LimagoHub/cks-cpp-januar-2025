//
// Created by JoachimWagner on 21.01.2025.
//

#include <iostream>
#include "Calculator.h"

using Calc = std::unique_ptr<math::Calculator>;
namespace math {

    class CalculatorSecure : public Calculator{

        Calc calculator_;
    public:

        explicit CalculatorSecure(Calc calculator) : calculator_(std::move(calculator)) {}

        ~CalculatorSecure() override = default;

        auto add(double a, double b) -> double override {
            std::cout << "Du kommst hier rein" << std::endl;
            return calculator_->add(a, b);
        }

        auto sub(double a, double b) -> double override {
            return calculator_->sub(a, b);
        }
    };
} // math
