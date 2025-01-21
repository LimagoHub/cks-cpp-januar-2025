//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once

#include "Calculator.h"

namespace math {

    class CalculatorImpl : public Calculator {

    public:
        virtual ~CalculatorImpl()= default;

        auto add(double a, double b) -> double override {
            return  a +b;
        }

        auto sub(double a, double b) -> double override {
            return  a -b ;
        }
    };

} // math
