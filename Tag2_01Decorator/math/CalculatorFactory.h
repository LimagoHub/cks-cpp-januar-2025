//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once
#include<memory>
#include "Calculator.h"
#include "CalculatorImpl.h"
#include "CalculatorLogger.h"
#include "CalculatorSecure.h"

using Calc = std::unique_ptr<math::Calculator>;
namespace math {

    class CalculatorFactory {
        static inline bool logger{false};
        static inline bool secure{false};
    public:
        static bool isLogger() {
            return logger;
        }

        static void setLogger(bool logger) {
            CalculatorFactory::logger = logger;
        }

        static bool isSecure() {
            return secure;
        }

        static void setSecure(bool secure) {
            CalculatorFactory::secure = secure;
        }

        static auto create() -> Calc {
            Calc result;
            result = std::make_unique<CalculatorImpl>();
            if(logger) result = std::make_unique<CalculatorLogger>(std::move(result));
            if (secure)result = std::make_unique<CalculatorSecure>(std::move(result));
            return result;
        }
    };

} // math
