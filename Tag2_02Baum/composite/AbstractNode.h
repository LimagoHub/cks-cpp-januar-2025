//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once

#include <string>
#include <memory>
#include <vector>



namespace composite {


    class AbstractNode : public std::enable_shared_from_this<AbstractNode>{
    public:
        using AbstractNodeShared = std::shared_ptr<AbstractNode>;
        using WeakPointer = std::weak_ptr<AbstractNode>;
        using Children = std::vector<AbstractNodeShared> ;




        explicit AbstractNode(const std::string &label) : label{label} {}

        const std::string &getLabel() const {
            return label;
        }

        void setLabel(const std::string &label) {
            AbstractNode::label = label;
        }

        const WeakPointer &getParent() const {
            return parent;
        }

        void setParent(WeakPointer parent) {
            AbstractNode::parent = parent;
        }

        virtual auto getChildren() -> Children {
            static Children result;
            return result;
        }
    private:
        std::string label;
        WeakPointer parent;
    };

} // composite
