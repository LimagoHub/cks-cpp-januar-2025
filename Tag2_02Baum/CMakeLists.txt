cmake_minimum_required(VERSION 3.30)
project(Tag2_02Baum)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_02Baum main.cpp
        composite/AbstractNode.h
        composite/Leaf.h
        composite/Node.h)
