#pragma once
#include "Deck.hpp"

class Dealer {

    public:
        Dealer(int stopAt): stopAt(stopAt) {}
        int drawFirstTwoCards();
        int drawFinalCard();
        void printDeck();

    private:
        int stopAt;
        Deck deck;
};