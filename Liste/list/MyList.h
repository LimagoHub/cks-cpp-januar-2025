//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once
#include <memory>
#include <string>
namespace container {

    struct MyList {



        struct Item {
            std::weak_ptr<Item> vor;
            std::shared_ptr<Item> nach;
            std::string data;
            Item(std::string data):data{data}{
                vor.reset();
                nach.reset();
            }
        };

        std::shared_ptr<Item> start;
        std::shared_ptr<Item> akt;
    public:
        void append(std::string text) {
            auto item = std::make_shared<Item>(text);
            if(isEmpty()) {
                start = item;
            } else 
            {
                moveToLast();
                akt->nach = item;
                item->vor =akt;
            }
            akt = item;
        }

        std::string get() {

        }

        bool remove() {

        }

        bool moveToFirst() {}
        bool moveToLast() {}
        bool moveToPrevious() {}
        bool moveToNext() {}

        bool isEmpty(){
            return start == nullptr;
        }
        bool isBol(){
            return start == akt;
        }
        bool isEol(){
            return isEmpty() || akt->nach== nullptr;
        }
    };

} // container
