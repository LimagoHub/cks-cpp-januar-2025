//
// Created by JoachimWagner on 21.01.2025.
//

#pragma once
#include <memory>
#include <string>
#include <optional>
namespace container {

    class MyList {



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

        std::optional<std::string> get() {
            if(isEmpty()) return std::nullopt;
            //if(isEmpty()) return {};
            return std::optional<std::string>{akt->data};
            //return akt->data;
        }

        void clear() {
            while(remove());
        }

        bool remove() {
            if (isEmpty()) return false;
            if(isBol() && isEol()) {
                start = akt = nullptr;
                return true;
            }
            if(isBol()) {
                moveToNext();
                start = akt;
                start->vor.reset();
                return true;
            }
            if(isEol()) {
                moveToPrevious();
                akt->nach.reset();
                return true;
            }
            akt->vor.lock()->nach = akt->nach;
            akt->nach->vor = akt->vor;
            moveToNext();
            return true;


        }

        bool moveToFirst() {
            if(isEmpty()) return false;
            while(moveToPrevious()){}
            return true;
        }
        bool moveToLast() {
            if(isEmpty()) return false;
            while(moveToNext()){}
            return true;
        }
        bool moveToPrevious() {
            if(isBol()) return false;
            akt = akt->vor.lock();
            return true;
        }
        bool moveToNext() {
            if(isEol()) return false;
            akt = akt->nach;
            return true;
        }

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
