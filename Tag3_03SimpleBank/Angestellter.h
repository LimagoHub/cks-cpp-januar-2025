//
// Created by JoachimWagner on 22.01.2025.
//

#pragma once
#include "Bank.h"

class Angestellter {
private:
    Bank &bank;
    int von;
    int nach;
    int betrag;

public:
    Angestellter(Bank &bank, int von, int nach, int betrag) : bank(bank), von(von), nach(nach), betrag(betrag) {

    }

    void run() {
        std::thread{[this]() { bank.ueberweisen(von, nach, betrag); }}.detach();
    };
};