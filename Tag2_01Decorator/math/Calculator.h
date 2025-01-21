//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once

namespace math {

    class Calculator {

    public:
        virtual ~Calculator() = default;
        virtual auto add(double a, double b) -> double = 0;

        virtual auto sub(double a, double b) -> double = 0;
    };

} // math
