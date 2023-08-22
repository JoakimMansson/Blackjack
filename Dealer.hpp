#pragma once
#include "Deck.hpp"
#include <vector>

class Dealer {

    public:
        Dealer(Deck& deck): deck(deck) {};
        void drawCard();
        void printDeck();
        int getCardSum();
        void resetHand();

    private:
        int stopAt;
        int currentCardSum = 0;
        int nrCardsDrawn = 0;
        Deck deck;
};