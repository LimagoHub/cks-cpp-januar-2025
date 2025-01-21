//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once
#include "AbstractNode.h"
namespace composite {

    class Node:public AbstractNode {
    public:
        explicit Node(const std::string &label) : AbstractNode(label) {}

        auto getChildren() -> Children override {
            return children;
        }

        auto append(AbstractNodeShared child) {
            children.push_back(child);
            child->setParent(weak_from_this());
        }

    private:
        Children children;
    };

} // composite
