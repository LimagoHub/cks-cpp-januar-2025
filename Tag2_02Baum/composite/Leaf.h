//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once
#include "AbstractNode.h"
namespace composite {

    class Leaf: AbstractNode {
    public:
        explicit Leaf(const std::string &label) : AbstractNode(label) {}

    };

} // composite
