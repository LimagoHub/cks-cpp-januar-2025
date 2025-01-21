cmake_minimum_required(VERSION 3.30)
project(Tag2_01Decorator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_01Decorator main.cpp
        math/CalculatorImpl.h
        cllient/CalcClient.h
        math/CalculatorLogger.h
        math/CalculatorSecure.h
        math/CalculatorFactory.h)
