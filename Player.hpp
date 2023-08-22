#pragma once
#include "Deck.hpp"

class Player
{
    public:
        Player(Deck& cardDeck): deck(cardDeck) {};
        void drawCard();
        void resetHand();
        int getCardSum();

        bool hasAnAce = false;

    private:
        Deck deck;
        int currentCardSum = 0;
        int nrCardsDrawn = 0;
};

