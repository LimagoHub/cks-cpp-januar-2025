//
// Created by JoachimWagner on 22.01.2025.
//

#pragma once

template<class T, size_t size>
class Stapel {
    T data[size];
    int index{0};
public:
    Stapel() {}

    void push(T value) {
        if(isFull()) return;
        data[index ++] = value;
    }

    T pop() {
        if(isEmpty()) return {};
        return data[--index];
    }

    bool isEmpty() {
        return index == 0;
    }
    bool isFull() {
        return index >= size;
    }

};
