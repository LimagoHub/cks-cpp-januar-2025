#include <iostream>
#include "composite/Node.h"
#include "composite/Leaf.h"

using namespace composite;
void travers(std::shared_ptr<composite::AbstractNode> myNode) {
    std::cout << myNode->getLabel() << std::endl;
    for(auto & child : myNode->getChildren()){
        travers(child);
    }
}
int main() {
    auto root =std::make_shared<Node>("root");

    auto e1 = std::make_shared<Node>("e1");
    auto e2 = std::make_shared<Node>("e2");
    auto e3 = std::make_shared<Node>("e3");
    auto e3_1 = std::make_shared<Node>("e3_1");
    auto e3_2 = std::make_shared<Node>("e3_2");
    auto e3_3 = std::make_shared<Node>("e3_3");

    auto e2_1 = std::make_shared<Leaf>("e2_1");

    if(! e1->getParent().expired())
        e1->getParent().lock()->getLabel();

    root->append(e1);
    root->append(e2);
    root->append(e3);

    e3->append(e3_1);
    e3->append(e3_2);
    e3->append(e3_3);

    travers(root);


    return 0;
}

