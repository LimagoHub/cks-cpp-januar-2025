//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include "../math/Calculator.h"


using Calc = std::unique_ptr<math::Calculator>;

namespace client {

    class CalcClient {
        Calc calculator_;

    public:
        explicit CalcClient(Calc calculator) : calculator_(std::move(calculator)) {}

        auto go()-> void {
            std::cout << calculator_->add(3,4) << std::endl;
        }

    };

} // client
